
var config = {
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
var yl = firebase.database().ref().child("Đèn vàng");
red.on('value', function (red) //đọc dữ liệu đèn đỏ 
{

    test.innerText = red.val();
    console.log(red.val());
   if (red.val() !=0) {
       console.log("test")
       document.getElementById('cr1').style.backgroundColor= 'red'// set màumàu
   } else {
       console.log("ket thuc")
       document.getElementById('cr1').style.backgroundColor= 'White'
   }


})
gr.on('value', function (gr)// đọc dữ liệu đèn xanhxanh
{
    test.innerText = gr.val();
    console.log(gr.val());
    if (gr.val() !=0) {
        console.log("test")
        document.getElementById('cr2').style.backgroundColor= 'green' // set màumàu
    } else {
        console.log("ket thuc")
        document.getElementById('cr2').style.backgroundColor= 'White'
    }

})
yl.on('value', function (yl)//đọc dữ liệu đèn vàng
{
    test.innerText = yl.val();
    console.log(yl.val());
    if (yl.val() !=0) {
        console.log("test")
        document.getElementById('cr3').style.backgroundColor= 'yellow'//set màu 
    } else {
        console.log("ket thuc")
        document.getElementById('cr3').style.backgroundColor= 'White'
    }

})




