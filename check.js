
if ($("#prendidoA").is(":checked")) {
        $("#prendido").val("1");
        $(".ocultar").css('z-index', -1);
        $("#dSwitch2").css('z-index', -2);
        $("#dSwitch2 input:checked[type='checkbox']").css('box-shadow', 'none');


        

}  
 else if ($("#prendidoA").is(":not(checked)")) {
        $("#prendido").val("0");
        $(".ocultar").css('z-index', 1);
         $("#dSwitch2").css('z-index', 2);
          $("#dSwitch2 input:checked[type='checkbox']").css('box-shadow', '0px 0px 100px 1px #DB1E54');
}    

if ($("#reposoA").is(":checked")) {
    $("#reposo").val("1");
}  
else if ($("#reposoA").is(":not(checked)")) {
    $("#reposo").val("0");
}  

$("#prendidoA").click(corroborar);
$("#reposoA").click(corroborar);

function corroborar(){

    if ($("#prendidoA").is(":checked")) {
        $("#prendido").val("1");
        $(".ocultar").css('z-index', -1);
         $("#dSwitch2").css('z-index', -2);
        $("#dSwitch2 input[type='checkbox']").css('box-shadow', 'none');


}  
 else if ($("#prendidoA").is(":not(checked)")) {
        $("#prendido").val("0");
        $(".ocultar").css('z-index', 1);
         $("#dSwitch2").css('z-index', 2);
        $("#dSwitch2 input:checked[type='checkbox']").css('box-shadow', '0px 0px 100px 1px #DB1E54');

         
        

}       

if ($("#reposoA").is(":checked")) {
    $("#reposo").val("1");

}  
else if ($("#reposoA").is(":not(checked)")) {
    $("#reposo").val("0");
    $("#dSwitch2 input[type='checkbox']").css('box-shadow', 'none');

}       

}


//var mediaqueryList = window.matchMedia("(max-width: 920px)");
//mediaqueryList.addListener( function(EventoMediaQueryList) {
//  if(EventoMediaQueryList.matches) {
//    // Realizamos las acciones cuando cambia el estado de la mediaquery y ahora cumple su valor
//    alert('Ahora has pasado a modo portrait, con tu pantalla orientada en vertical');
//  } else {
//    alert('Ahora has pasado a modo landscape, con tu pantalla orientada en horizontal');
//  }
//});
