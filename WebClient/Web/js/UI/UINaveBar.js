define(['require', 'jquery', 'jquery-ui' , 'bootstrap',
        'Model/CompSpellBook',
        'Model/CompTargeted',
        'objManager',
        'obj',
        'text!templates/navbar.html'],function ( require) {

    var navBar = require('text!templates/navbar.html');
    //var navPowerList = require('UI/Panels/UIDevObjInfoPanel');
    var objManager = require('objManager');

    function UI_show_templates(){
        //alert("hest");
        var tmp = objManager.getObjs();
        for (var ob in tmp){
            if (tmp[ob].id < (1 <<24))
                tmp[ob].createObjInfoPanel(tmp[ob]);
        }
    }

    function init(UIMain){

        var parser = new DOMParser();
        var host = parser.parseFromString(navBar, "text/html");
        UIMain.maindiv.appendChild(host.firstChild);

        $("body").on("click", "#UIshowtemplates", function(e){
            UI_show_templates()});
        $("body").on("click", "#UIshowPowerList", function(e){
            UIMain.UI_togglePowersList()});
    }

    return init;
});