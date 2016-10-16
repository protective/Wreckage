define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'Model/CompPowerBase',
        'objManager',
        'obj',
        'text!templates/powerList.html',
        'text!templates/powerEditor.html'],function ( require) {

	var powerListTable = require('text!templates/powerList.html');
	var powerEditor = require('text!templates/powerEditor.html');

	var objManager = require('objManager');
    var powerListPanel = null;

	function get_powers(){
		//alert("hest");
		var tmp = objManager.getObjs();
		var ret = [];
		for (var ob in tmp){
			if (tmp[ob].isTemplate)
				if ('compPowerBase' in tmp[ob]){
					ret.push(tmp[ob].compPowerBase)
				}
		}
		return ret;
	}

	function createNewPower(name, description, src) {
		var callback = function(obj){
			var callback2 = function(power) {
				power.compPowerBase.saveAll(
						name,
					    description,
					    src);
				powerListPanel = null;
			};
			objManager.modAddCompPowerBase(obj, callback2);
		};
		objManager.createObj(callback);
	}

	function updatePowerEditor(power) {
		var name = $('#powerEditor_name')[0];
		var description = $('#powerEditor_desc')[0];
		var src = $('#powerEditor_src')[0];
		var savebtn = $('#powerEditor_submit')[0];

		if (power) {
			name.value = power.powerName;
			description.value = power.description;
			src.value = power.programSrc;

			savebtn.onclick = function(){
				power.saveAll(name.value,
						      description.value,
						      src.value);
			}
		} else {
			name.value = "";
			description.value = "";
			src.value = "";

			savebtn.onclick = function(){
				createNewPower(name.value,
					      description.value,
					      src.value);
			}
		}
	}

	function init(UIMain) {
		UIMain['UI_show_powers_list'] = function (compower_list) {
			if (powerListPanel)
				return;
			var powers  = get_powers();
		    var a = {'ids' : powers};
		    var ui_bars = _.template(powerListTable)(a);
		    var parser = new DOMParser();
		    var doc = parser.parseFromString(ui_bars, "text/html");

		    var overlay = doc.firstChild.lastChild.firstChild;
		    UIMain.maindiv.appendChild(overlay);
		    powerListPanel = overlay;
        	var tmp2 = $('body');
        	tmp2.on('click', '.clickThis', function(e) {
        		var id = parseInt(e.target.id);
        		if (id >= 0)
        			updatePowerEditor(powers[id]);
        		else
        			updatePowerEditor(null);
        	});
		};
		UIMain['UI_hidepowers_list'] = function () {
			UIMain.maindiv.removeChild(powerListPanel);
			powerListPanel = null;
		};
	}

	return init;
});