define( function( require )
{
	var webSocket = require('Network/webSocket');
	var objManager = require("../objManager");
	
	function CompSpellBook(obj, powers)
	{
		this.obj = obj;
		this.tick = 0;
		this.powers = {};
		
		this.addPower = function(powerTemplateId) {
			webSocket.handlers["sendAddPower"](this.obj, powerTemplateId); 
		};
		this.removePower = function(powerTemplateId) {
			webSocket.handlers["sendRemovePower"](this.obj, powerTemplateId);
		};
	}
	
	CompSpellBook.prototype.setPowers = function(powers) {
		this.powers = powers;
	}

	CompSpellBook.prototype.getKeyValues = function() {
		var a = {};
		
		for (i in this.powers) {
			var b = objManager.getObjById(i);
			if (b)
				a[i] = b.compPowerBase.powerName;
		}
		var onAdd = function() {
			var powerId = a;
			webSocket.handlers.sendAddPower(this.obj, powerId);
		};
		var onRemove = function() {
			var powerId = a;
			webSocket.handlers.sendRemovePower(this.obj, powerId);
		};
		var entries =  {
			'list': {'values': a,
					 'add': onAdd,
			         'remove': onRemove}};

		var tmp = {
			'compName': 'CompSpellBook',
			'entries' : entries
			};
		return tmp;
	}

	CompSpellBook.prototype.castSpellTarget = function castSpellTarget(target, powerid){
		webSocket.handlers["castSpellTarget"](this.obj, target, powerid); 
	}

	return function Init()
	{
		this.compSpellBook = new CompSpellBook(this);
	};
});
