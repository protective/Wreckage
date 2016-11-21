define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'Model/CompPowerBase',
        'objManager',
        'obj',
        'UI/Panels/UIPowerEditor',
        'UI/Panels/UIUnitEditor',
        'text!templates/editorList.html',
        'text!templates/editorListItem.html'
        ],function ( require) {

    var EditorListTemplate = require('text!templates/editorList.html');
    var EditorListItemTemplate = require('text!templates/editorListItem.html');

    var UIMain = null;
    var UIPowerEditor = require('UI/Panels/UIPowerEditor');
    var UIUnitEditor = require('UI/Panels/UIUnitEditor');

    var objManager = require('objManager');
    var ActivePanel = null;
    var ActiveDom = null;
    var EditorPanel = null;
    var UIEditorItemListDom = null;

    function addItem(itemId, name) {
        var args = {'id': itemId, 'name': name};
        var a = $.parseHTML($.trim(
    			_.template(EditorListItemTemplate, "text/html")(args)))[0];
        UIEditorItemListDom.appendChild(a);
        a.onclick = function(e) {
            var id = parseInt(e.target.id);
            ActivePanel.itemOnClick(id);
        };
        
    }

    function removeItem() {

    }

    function setActive(panel) {
    	if (ActivePanel) {
    		UIMain.maindiv.removeChild(ActiveDom);
    	}
    	ActivePanel = panel;
    	ActiveDom = $.parseHTML($.trim(_.template(EditorListTemplate, "text/html")({})))[0];
    	
    	UIMain.maindiv.appendChild(ActiveDom);
    	UIEditorItemListDom = $(ActiveDom).find(".UIEditorItemList")[0];
    	ActivePanel.setUIEditorItemField($(ActiveDom).find(".UIEditorItemField")[0]);
    	ActivePanel.setUIEditorItemFieldEditor($(ActiveDom).find(".UIEditorItemFieldEdit")[0]);

    	var panelItems = panel.getItems();
        for (item in panelItems) {
        	addItem(item, panelItems[item]);
        }
    }

    function removeActive() {
    	if (ActivePanel) {
    		UIMain.maindiv.removeChild(ActiveDom);
    		ActivePanel = null;
    		ActiveDom = null;
    	}
    }

    function init(UImain) {
    	UIMain = UImain;
    	var active = '';
        UIMain['UI_togglePowersList'] = function () {
        	if (active == 'power') {
        		removeActive();
        		active = '';
        	} else {
        		active = 'power';
        		setActive(UIPowerEditor);
        	}
        };
        UIMain['UI_toggleUnitList'] = function () {
        	if (active == 'unit') {
        		removeActive();
        		active = '';
        	} else {
        		active = 'unit';
        		setActive(UIUnitEditor);
        	}
        };
    }

    return init;
});