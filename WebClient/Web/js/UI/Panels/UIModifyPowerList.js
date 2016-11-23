define(['require', 'jquery', 'jquery-ui' , 'bootstrap', 'underscore',
        'objManager',
        'text!templates/ListEditorMenu.html',
        'text!templates/ListEditorAddList.html'
        ],function ( require) {

	var objManager = require('objManager');
	
	var ListEditorMenuTemplate = require('text!templates/ListEditorMenu.html');
	var ListEditorAddListTemplate = require('text!templates/ListEditorAddList.html');
	
	var _spellbook = null;
	var _powers = null;
	var _onsave = null;
	var _dom = null;
	var _addButton = null;
	var _removeButton = null;
	var _saveButton = null;
	var _selectList = null;
	
	//add menu
	var _addSelectList = null;
	var _addListInsertPoint = null;
	
	function close() {
		//remove all previous edits
		while (_dom && _dom.firstChild) {
			_dom.removeChild(_dom.firstChild);
		}
		_dom = null;
	}

	function insert(powerid) {
		var a = "<option id=\"<%= id %>\" value=\"<%= value %>\"><%= value %></option>";
		var powerObj = objManager.getObjById(powerid);
		if (powerObj) {
    		tmpdom = $.parseHTML($.trim(_.template(a, "text/html")(
    				{'value': powerObj.compPowerBase.powerName,
    				 'id': powerid})))[0];
    		_selectList.appendChild(tmpdom);
		}
	}

	function addSave() {
	    var selectedValues = [];    
	    $(".ListEditorAddList :selected").each(function(){
	    	var g = this;
	        selectedValues.push(this); 
	    });
	    for (b in selectedValues) {
	    	insert(selectedValues[b].powerObj.id);
	    	_spellbook.addPower(selectedValues[b].powerObj.id);
	    }
	}

	function fillAddList() {
		var powerObjs = objManager.getTemplateObjs();
		var a = "<option id=\"<%= id %>\" value=\"<%= value %>\"><%= value %></option>";
		for (i in powerObjs) {
			if ('compPowerBase' in powerObjs[i]) {
        		tmpdom = $.parseHTML($.trim(_.template(a, "text/html")(
        				{'value': powerObjs[i].compPowerBase.powerName,
        				 'id': powerObjs[i].template})))[0];
        		_addSelectList.appendChild(tmpdom);
        		tmpdom['powerObj'] = powerObjs[i];
			}
		}
	}

	function openAdd() {
		while (_addListInsertPoint && _addListInsertPoint.firstChild) {
			_addListInsertPoint.removeChild(_addListInsertPoint.firstChild);
		}
		_addSelectList = null;

		tmpdom = $.parseHTML($.trim(_.template(ListEditorAddListTemplate, "text/html")(
				{})))[0];
		_addListInsertPoint.appendChild(tmpdom);
		_addSelectList = $('.ListEditorAll .AddList #list')[0];
		_addOk = $('.ListEditorAddList #save')[0];
		_addOk.onclick = addSave;
		fillAddList();
	}
	
	function remove() {
	    var selectedValues = [];    
	    $(".ListEditorMenu :selected").each(function(){
	    	var g = this;
	        selectedValues.push(this); 
	    });
		for (b in selectedValues) {
			_selectList.removeChild(selectedValues[b]);
		}
		_spellbook.removePower(selectedValues[b].id);
	}

	function save() {
		close();
		_onsave();
	}

	function open(dom) {
		_dom = dom;
		tmpdom = $.parseHTML($.trim(_.template(ListEditorMenuTemplate,
			"text/html")({})))[0];
		_dom.appendChild(tmpdom);
		_addButton = $('.ListEditorMenu #add')[0];
		_addButton.onclick = openAdd;
		_removeButton = $('.ListEditorMenu #remove')[0];
		_removeButton.onclick = remove;
		_saveButton = $('.ListEditorMenu #save')[0];
		_saveButton.onclick = save;
		_selectList = $('.ListEditorMenu #list')[0];
		_addListInsertPoint = $('.ListEditorAll .AddList')[0];

		for (i in _powers) {
			insert(_powers[i].template);
		}
	}

	function active() {
		if (_dom)
			return true;
		return false;
	}

    function init(spellbook, dom, onsave) {
    	_spellbook = spellbook;
    	_powers = _spellbook.powers;
    	_onsave = onsave;
    	close();
    	open(dom);
		var ret= {'save': save,
				  'active': active};
		return ret;
    }

    return init;
});
