var colorPicker = new iro.ColorPicker("#picker",{
    width: 350
});

var values = document.getElementById("values");

colorPicker.on(["color:init", "color:change"], function(color){
  r.value = [
  color.red
  ].join("<br>");
  
});
colorPicker.on(["color:init", "color:change"], function(color){
  g.value = [
  color.green
  ].join("<br>");
  
});
colorPicker.on(["color:init", "color:change"], function(color){
  b.value = [
  color.blue
  ].join("<br>");
  
});