define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'Model/CompPowerBase',
        'objManager',
        'obj',
        'UI/Panels/UIModifyPowerList',
        'text!templates/unitEditor.html'], function (require) {
	
	var UnitEditorTemplate = require('text!templates/unitEditor.html');
	var objManager = require('objManager');

	var UIModifyPowersList = require('UI/Panels/UIModifyPowerList');
	
	var UIEditorItemField = null;
	var UIEditorItemFieldEditor = null;
	var activeUIEditorItemField = null;

	function setUIEditorItemField(dom){
		UIEditorItemField = dom;
	}

	function setUIEditorItemFieldEditor(dom){
		UIEditorItemFieldEditor = dom;
	}

    function createNewUnit(name, description, src) {
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
    
    function get_units(){
        var tmp = objManager.getTemplateObjs();
        var ret = {};
        for (var ob in tmp) {
            if ('compSpellBook' in tmp[ob]) {
                ret[tmp[ob].id] = tmp[ob];
            }
        }
        return ret;
    }

    function getUnitItems() {
    	var ret = {'-1': "new unit"};
    	var units = get_units();
    	for (id in units) {
    		ret[id] = "template Unit1";
    	}
    	return ret;
    }

    function updateUnitEditor(unitId) {

    	var unit = objManager.getObjById(unitId);
    	var spellbook = null;
    	var entry_dict = {'entries': {}};

    	if ('compSpellBook' in unit) {
    		powers = unit.compSpellBook.powers;

    		var ui_modify = null;
    		var onsave = function(){
    			updateUnitEditor(unitId);
    		}
        	var openSpellEdit = function() {
        		if (ui_modify && ui_modify.active()) {
        			ui_modify.save();
        		} else {
            		ui_modify = UIModifyPowersList(
            				unit.compSpellBook,
                			UIEditorItemFieldEditor,
                			onsave);
        		}
    		};

    		tmp = "";
    		for (power in powers) {
    			var powerObj = objManager.getObjById(powers[power].template);
    			if (powerObj)
    				tmp = tmp + powerObj.compPowerBase.powerName + " ";
    		}
    		entry_dict.entries['spells'] = {'value': tmp, 'onClick': openSpellEdit};
    	}

    	dom = $.parseHTML($.trim(_.template(UnitEditorTemplate, "text/html")(entry_dict)))[0];
    	if (activeUIEditorItemField)
    		if (UIEditorItemField.contains(activeUIEditorItemField))
        			UIEditorItemField.removeChild(activeUIEditorItemField);
    	activeUIEditorItemField = dom;
    	UIEditorItemField.appendChild(dom);

    	for (entry in entry_dict.entries) {
    		entry_dom = $('#spells.unitEditorEntry')[0];
    		entry_dom.onclick = entry_dict.entries[entry].onClick;
    	} 
    	
        var savebtn = $('#unitEditor_submit')[0];

        var power = null;
        if (unit && false) {
        	if ('compSpellbook' in unit)
        		power = unit.compPowerBase;
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
        }
    }

    return {
    	'getItems': getUnitItems,
    	'itemOnClick': updateUnitEditor,
    	'setUIEditorItemField': setUIEditorItemField,
    	'setUIEditorItemFieldEditor': setUIEditorItemFieldEditor
    	};
});