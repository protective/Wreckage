define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'Model/CompPowerBase',
        'objManager',
        'obj',
        'text!templates/powerEditor.html'], function ( require) {
	
	var PowerEditorTemplate = require('text!templates/powerEditor.html');
	var objManager = require('objManager');

	var UIEditorItemField = null;
	var activeUIEditorItemField = null;
	
	function setUIEditorItemField(dom){
		UIEditorItemField = dom;
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
    
    function get_powers(){
        //alert("hest");
        var tmp = objManager.getTemplateObjs();
        var ret = {};
        for (var ob in tmp) {
            if ('compPowerBase' in tmp[ob]) {
                ret[tmp[ob].id] = tmp[ob].compPowerBase;
            }
        }
        return ret;
    }
    
    function getPowerItems() {
    	var ret = {'-1': "new power"};
    	var powers = get_powers();
    	for (id in powers) {
    		ret[id] = powers[id].powerName;
    	}
    	return ret;
    }

    function updatePowerEditor(powerId) {
    	
    	dom = $.parseHTML($.trim(_.template(PowerEditorTemplate, "text/html")({})))[0];
    	if (activeUIEditorItemField)
    		if (UIEditorItemField.contains(activeUIEditorItemField))
    			UIEditorItemField.removeChild(activeUIEditorItemField);
    	activeUIEditorItemField = dom;
    	UIEditorItemField.appendChild(dom);
    	
        var name = $('#powerEditor_name')[0];
        var description = $('#powerEditor_desc')[0];
        var src = $('#powerEditor_src')[0];
        var savebtn = $('#powerEditor_submit')[0];
        var obj = objManager.getObjById(powerId);
        var power = null;
        if (obj) {
        	if ('compPowerBase' in obj)
        		power = obj.compPowerBase;
        }
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

            savebtn.onclick = function() {
                createNewPower(name.value,
                          description.value,
                          src.value);
            }
        }
    }

    return {
    	'getItems': getPowerItems,
    	'itemOnClick': updatePowerEditor,
    	'setUIEditorItemField': setUIEditorItemField
    	};
});