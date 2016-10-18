define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'Model/CompPowerBase',
        'objManager',
        'obj',
        'text!templates/powerList.html',
        'text!templates/powerListItem.html',
        'text!templates/powerEditor.html'],function ( require) {

    var powerListTable = require('text!templates/powerList.html');
    var powerListTableItem = require('text!templates/powerListItem.html');
    var powerEditor = require('text!templates/powerEditor.html');

    var objManager = require('objManager');
    var powerListPanel = null;
    var powerListPanelList = null;

    function get_powers(){
        //alert("hest");
        var tmp = objManager.getObjs();
        var ret = {};
        for (var ob in tmp){
            if (tmp[ob].isTemplate)
                if ('compPowerBase' in tmp[ob]){
                    ret[tmp[ob].id] = (tmp[ob].compPowerBase)
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
                addItemToList(power.compPowerBase)
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
    
    function addItemToList(power) {
        var a = {'id': power.obj.id, 'powerName': power.powerName}
        powerListPanelList.appendChild($.parseHTML($.trim(_.template(powerListTableItem, "text/html")(a)))[0]);
    }

    function init(UIMain) {
        UIMain['UI_show_powers_list'] = function (compower_list) {
            if (powerListPanel)
            	return
        	var powers  = get_powers();

            powerListPanel = $.parseHTML($.trim(_.template(powerListTable, "text/html")({})))[0];

			UIMain.maindiv.appendChild(powerListPanel);
            powerListPanelList = $( powerListPanel ).find("#UIPowerList_list" )[0];

            var a = {'id': -1, 'powerName': "new power"};
            powerListPanelList.appendChild($.parseHTML($.trim(_.template(powerListTableItem, "text/html")(a)))[0]);
            updatePowerEditor(null);
            for (power in powers) {
            	addItemToList(powers[power]);
            }
            var tmp2 = $('body');
            tmp2.on('click', '.clickThis', function(e) {
            var id = parseInt(e.target.id);
            if (id >= 0)
                updatePowerEditor(powers[id]);
            else
                updatePowerEditor(null);
            });
        };
        UIMain['UI_togglePowersList'] = function () {
        	if (powerListPanel) {
        		UIMain.maindiv.removeChild(powerListPanel);
        		powerListPanel = null;
        	} else {
        		UIMain['UI_show_powers_list']();
        	}
        };
    }

    return init;
});