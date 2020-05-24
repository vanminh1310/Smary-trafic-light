
var config ={
    apiKey: "AIzaSyCQDOTIYf6_8FHSbxsckL80gtI8DQfCe6g",
    authDomain: "vvvvv-dc879.firebaseapp.com",
    databaseURL: "https://vvvvv-dc879.firebaseio.com",
    projectId: "vvvvv-dc879",
    storageBucket: "vvvvv-dc879.appspot.com",
    messagingSenderId: "740270975513",
    appId: "1:740270975513:web:f3ad584a819ce129f99888",

};
firebase.initializeApp(config);
var database = firebase.database();
var test = document.getElementById('hi')


var red = firebase.database().ref().child("Đèn đỏ");//tạotạo đọc dữ liệu từ firebase 
var gr = firebase.database().ref().child("Đèn xanh");
var yl= firebase.database().ref().child("Đèn vàng");
red.on('value', function(red) //đọc dữ liệu đèn đỏ 
{

   test.innerText = red.val();
   console.log(red.val());
   if (red.val !=0) {
       console.log("test");
      
   }
 
})
gr.on('value', function(gr)// đọc dữ liệu đèn xanhxanh
{
    test.innerText=gr.val();
    console.log(gr.val());
   
})
yl.on('value',function(yl)//đọc dữ liệu đèn vàng
{
test.innerText=yl.val();
console.log(yl.val());

})


  
