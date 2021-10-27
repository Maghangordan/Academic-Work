const button = document.querySelector("button");
const body = document.querySelector("body");

button.addEventListener("click", function () {
  var myform = document.createElement("table");
  myform.className = "myform";
  for (i = 0; i < 3; i++) {
    var tr = document.createElement("tr");
    tr.id = i;
    for (j = 0; j < 3; j++) {
      var td = document.createElement("td");
      td.id = j;
      
      td.addEventListener("click", function () {
        cellFunction(tr.id, td.id);
      });
      var text = document.createTextNode("Test");
      td.appendChild(text);
      tr.appendChild(td);
    }
    myform.appendChild(tr);
  }
  body.appendChild(myform);
});
function cellFunction(i, j) {
  console.log(i, j);
}
