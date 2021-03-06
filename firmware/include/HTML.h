#ifndef HTML_H
#define HTML_H

#include <Arduino.h>

#define CARD_FACILITY_EVENT "card_facility"
#define CARD_NUMBER_EVENT "card_number"
#define CARD_FORMAT_EVENT "card_format"

const char homePage[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    /* Skeleton framework */
    .container{position:relative;width:100%;max-width:960px;margin:0 auto;padding:0 20px;box-sizing:border-box}.column,.columns{width:100%;float:left;box-sizing:border-box}@media (min-width:400px){.container{width:85%;padding:0}}@media (min-width:550px){.container{width:80%}.column,.columns{margin-left:4%}.column:first-child,.columns:first-child{margin-left:0}.one.column,.one.columns{width:4.66666666667%}.two.columns{width:13.3333333333%}.three.columns{width:22%}.four.columns{width:30.6666666667%}.five.columns{width:39.3333333333%}.six.columns{width:48%}.seven.columns{width:56.6666666667%}.eight.columns{width:65.3333333333%}.nine.columns{width:74%}.ten.columns{width:82.6666666667%}.eleven.columns{width:91.3333333333%}.twelve.columns{width:100%;margin-left:0}.one-third.column{width:30.6666666667%}.two-thirds.column{width:65.3333333333%}.one-half.column{width:48%}.offset-by-one.column,.offset-by-one.columns{margin-left:8.66666666667%}.offset-by-two.column,.offset-by-two.columns{margin-left:17.3333333333%}.offset-by-three.column,.offset-by-three.columns{margin-left:26%}.offset-by-four.column,.offset-by-four.columns{margin-left:34.6666666667%}.offset-by-five.column,.offset-by-five.columns{margin-left:43.3333333333%}.offset-by-six.column,.offset-by-six.columns{margin-left:52%}.offset-by-seven.column,.offset-by-seven.columns{margin-left:60.6666666667%}.offset-by-eight.column,.offset-by-eight.columns{margin-left:69.3333333333%}.offset-by-nine.column,.offset-by-nine.columns{margin-left:78%}.offset-by-ten.column,.offset-by-ten.columns{margin-left:86.6666666667%}.offset-by-eleven.column,.offset-by-eleven.columns{margin-left:95.3333333333%}.offset-by-one-third.column,.offset-by-one-third.columns{margin-left:34.6666666667%}.offset-by-two-thirds.column,.offset-by-two-thirds.columns{margin-left:69.3333333333%}.offset-by-one-half.column,.offset-by-one-half.columns{margin-left:52%}}html{font-size:62.5%}body{font-size:1.5em;line-height:1.6;font-weight:400;font-family:Raleway,HelveticaNeue,"Helvetica Neue",Helvetica,Arial,sans-serif;color:#222}h1,h2,h3,h4,h5,h6{margin-top:0;margin-bottom:2rem;font-weight:300}h1{font-size:4rem;line-height:1.2;letter-spacing:-.1rem}h2{font-size:3.6rem;line-height:1.25;letter-spacing:-.1rem}h3{font-size:3rem;line-height:1.3;letter-spacing:-.1rem}h4{font-size:2.4rem;line-height:1.35;letter-spacing:-.08rem}h5{font-size:1.8rem;line-height:1.5;letter-spacing:-.05rem}h6{font-size:1.5rem;line-height:1.6;letter-spacing:0}@media (min-width:550px){h1{font-size:5rem}h2{font-size:4.2rem}h3{font-size:3.6rem}h4{font-size:3rem}h5{font-size:2.4rem}h6{font-size:1.5rem}}p{margin-top:0}a{color:#1eaedb}a:hover{color:#0fa0ce}.button,button,input[type=button],input[type=reset],input[type=submit]{display:inline-block;height:38px;padding:0 30px;color:#555;text-align:center;font-size:11px;font-weight:600;line-height:38px;letter-spacing:.1rem;text-transform:uppercase;text-decoration:none;white-space:nowrap;background-color:transparent;border-radius:4px;border:1px solid #bbb;cursor:pointer;box-sizing:border-box}.button:focus,.button:hover,button:focus,button:hover,input[type=button]:focus,input[type=button]:hover,input[type=reset]:focus,input[type=reset]:hover,input[type=submit]:focus,input[type=submit]:hover{color:#333;border-color:#888;outline:0}.button.button-primary,button.button-primary,input[type=button].button-primary,input[type=reset].button-primary,input[type=submit].button-primary{color:#fff;background-color:#33c3f0;border-color:#33c3f0}.button.button-primary:focus,.button.button-primary:hover,button.button-primary:focus,button.button-primary:hover,input[type=button].button-primary:focus,input[type=button].button-primary:hover,input[type=reset].button-primary:focus,input[type=reset].button-primary:hover,input[type=submit].button-primary:focus,input[type=submit].button-primary:hover{color:#fff;background-color:#1eaedb;border-color:#1eaedb}input[type=email],input[type=number],input[type=password],input[type=search],input[type=tel],input[type=text],input[type=url],select,textarea{height:38px;padding:6px 10px;background-color:#fff;border:1px solid #d1d1d1;border-radius:4px;box-shadow:none;box-sizing:border-box}input[type=email],input[type=number],input[type=password],input[type=search],input[type=tel],input[type=text],input[type=url],textarea{-webkit-appearance:none;-moz-appearance:none;appearance:none}textarea{min-height:65px;padding-top:6px;padding-bottom:6px}input[type=email]:focus,input[type=number]:focus,input[type=password]:focus,input[type=search]:focus,input[type=tel]:focus,input[type=text]:focus,input[type=url]:focus,select:focus,textarea:focus{border:1px solid #33c3f0;outline:0}label,legend{display:block;margin-bottom:.5rem;font-weight:600}fieldset{padding:0;border-width:0}input[type=checkbox],input[type=radio]{display:inline}label>.label-body{display:inline-block;margin-left:.5rem;font-weight:400}ul{list-style:circle inside}ol{list-style:decimal inside}ol,ul{padding-left:0;margin-top:0}ol ol,ol ul,ul ol,ul ul{margin:1.5rem 0 1.5rem 3rem;font-size:90%}li{margin-bottom:1rem}code{padding:.2rem .5rem;margin:0 .2rem;font-size:90%;white-space:nowrap;background:#f1f1f1;border:1px solid #e1e1e1;border-radius:4px}pre>code{display:block;padding:1rem 1.5rem;white-space:pre}td,th{padding:12px 15px;text-align:left;border-bottom:1px solid #e1e1e1}td:first-child,th:first-child{padding-left:0}td:last-child,th:last-child{padding-right:0}.button,button{margin-bottom:1rem}fieldset,input,select,textarea{margin-bottom:1.5rem}blockquote,dl,figure,form,ol,p,pre,table,ul{margin-bottom:2.5rem}.u-full-width{width:100%;box-sizing:border-box}.u-max-full-width{max-width:100%;box-sizing:border-box}.u-pull-right{float:right}.u-pull-left{float:left}hr{margin-top:3rem;margin-bottom:3.5rem;border-width:0;border-top:1px solid #e1e1e1}.container:after,.row:after,.u-cf{content:"";display:table;clear:both}

    html {
      background: whitesmoke;
      height: 100%;
    }

    .console {
      position: fixed;
      bottom: 10px;
      right: 30px;
    }

    /* Rounded sliders */
    .switch {
      position: relative;
      display: inline-block;
      width: 60px;
      height: 34px;
    }

    .switch input {
      opacity: 0;
      width: 0;
      height: 0;
    }

    .slider {
      position: absolute;
      cursor: pointer;
      top: 0;
      left: 0;
      right: 0;
      bottom: 0;
      background-color: #ccc;
      -webkit-transition: .4s;
      transition: .4s;
    }

    .slider:before {
      position: absolute;
      content: "";
      height: 26px;
      width: 26px;
      left: 4px;
      bottom: 4px;
      background-color: white;
      -webkit-transition: .4s;
      transition: .4s;
    }

    input:checked + .slider {
      background-color: rgb(95, 193, 235);
    }

    input:focus + .slider {
      box-shadow: 0 0 1px rgb(95, 193, 235);
    }

    input:checked + .slider:before {
      -webkit-transform: translateX(26px);
      -ms-transform: translateX(26px);
      transform: translateX(26px);
    }

    .slider.round {
      border-radius: 34px;
    }

    .slider.round:before {
      border-radius: 50%;
    }

  </style>
</head>
<body>
  <div class="container">
    <br>
    <h2>Wiegand Converter</h2>
    <hr>
    <div class="row">
      <div class="seven columns">
        <select class="u-full-width" id="card_select">
          <option><p>HID-26bit</p></option>
          <option><p>HID-26Bit no facility</p></option>
          <option><p>HID-34bit</p></option>
          <option><p>EM4100</p></option>
          <option><p>TK4100</p></option>
        </select>
      </div>
    </div>
    <hr>
    <div class="row">
      <table class="u-full-width">
        <thead>
          <tr>
            <th>Card Type</th>
            <th>Facility Code</th>
            <th>Card Number</th>
            <th>Format</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td id="table_card_type">HID-26bit</td>
            <td id="table_fc">123</td>
            <td id="table_cn">12345</td>
            <td id="table_format">Wiegand 26-bit</td>
          </tr>
        </tbody>
      </table>
    </div>
    <div class="row">
      <div class="seven columns">
        <h5> Enable Wiegand Replay</h5>
      </div>
      <div class="five columns">
        <label class="switch">
          <input type="checkbox" checked>
          <span class="slider round"></span>
        </label>
      </div>
    </div>
  </div>
  <p class="console" id="console"><small>%%CONSOLE%%</small></p>

<script>
  window.onload = function () {
    const cardTypeSelect = document.getElementById('card_select');
    var cardTypeText = document.getElementById("table_card_type");
    var consoleLog = document.getElementById("console");

    cardTypeSelect.addEventListener('change', function(e) {
      var cardTypeIndex = e.target.selectedIndex;
      var cardTypeValue = e.target.value;
      // create an XHR object
      const xhr = new XMLHttpRequest();
      xhr.onload = () => {
        // process response
        if (xhr.status == 200) {
          consoleLog.innerHTML = cardTypeIndex;
          cardTypeText.innerText = cardTypeValue;
        } else {
          consoleLog.innerText = "404";
        }
      };
      xhr.onerror = () => { consoleLog.innerText = "Error on XML request!"; }
      // create a `GET` request
      xhr.open('GET', "/save?type=" + cardTypeIndex, true);
      // send request
      xhr.send();
    });

    if (!!window.EventSource) {
      var source = new EventSource('/events');

      source.addEventListener('open', function(e) {
        console.log("Events Connected");
      }, false);

      source.addEventListener('card_number', function(e) {
        var cardNumberText = document.getElementById("table_cn");
        cardNumberText.innerText = e.data;
        console.log("card_number", e.data);
      }, false);

      source.addEventListener('card_facility', function(e) {
        var facilityCodeText = document.getElementById("table_fc");
        facilityCodeText.innerText = e.data;
        console.log("card_facility", e.data);
      }, false);

      source.addEventListener('card_format', function(e) {
        var cardFormatText = document.getElementById("table_format");
        cardFormatText.innerText = "Wiegand " + e.data + "-bit";
        console.log("card_format", e.data);
      }, false);
    }
  }
</script>
</body>
</html>
)rawliteral";

// const char configPage[] PROGMEM = R"rawliteral(
// <!DOCTYPE HTML>
// <html>
// <head>
//   <title>ESP Web Server</title>
//   <meta name="viewport" content="width=device-width, initial-scale=1">
//   <style>
//      html {
//       font-family: Arial, Helvetica, sans-serif;
//       background: rgb(74,116,44);
//       background: linear-gradient(0deg, rgba(74,116,44,1) 0%, rgba(130,159,109,1) 17%, rgba(159,181,143,1) 36%, rgba(255,255,255,1) 100%);
//       height: 100%;
//     }
//     h1 {
//       text-align: center;
//       margin-top: 10%;
//     }
//     h3 {
//       text-align: center;
//       margin-top: 10%;
//     }
//     p {
//       text-align: center;
//       margin: 2%;
//     }
//     .rules {
//       border-color: black;
//       border-width: 2px;
//       border-style: solid;
//       border-radius: 10px;
//       margin: auto;
//       width: 100%;
//       text-align: center;
//     }
//     .container {
//       margin: auto;
//       margin-top: 50px;
//       width: 100%;
//       text-align: center;
//     }
//     .mybutton{
//       background: #467524;
//       margin-top: 30px;
//       font-family: Arial;
//       color: #FFFFFF;
//       font-size: 20px;
//       letter-spacing: 0em;
//       font-weight: 400;
//       padding: 7px 18px;
//       border: none;
//       border-radius: 10px 10px 10px 10px;
//       transform: translate(0px,0px) rotatex(0deg) rotatey(0deg) rotatez(0deg) skewX(0deg) skewY(0deg) scaleX(1) scaleY(1);
//     }
//     .myarea {
//       padding: 8px;
//       border-radius: 10px;
//       -webkit-appearance:none;
//       -moz-appearance:none;
//       appearance:none;
//       border: 0px solid;
//       font-size: 20px;
//     }
//     .console {
//       position: fixed;
//       bottom: 10px;
//     }
//   </style>
// </head>
// <body>
//   <h1>Network Geocache</h1>
//   <h3>Configuration Page</h3>
//   <div class="rules">
//     <p>
//       <b>(1)</b> Insert, in the box, the <b>Latitude</b> coordinate of the geocache, always positive <small> (Example: 59.28750)</small>. This will be the <i>code</i> geocachers will need to fill in order to open the geocache.
//     </p>
//     <p>
//       <b>(2)</b> Close the geocache manually and click in the button below the coordinate - this will lock the geocache. You can always go back by scanning the QRCode.
//     </p>
//     <p>
//       <b>(3)</b> Once the geocache is closed, you can start hiding it and logging into geocache.com! :)
//     </p>
//   </div>
//   <p></p>
//   <div class="container">
//     <h3><b>Latitude coordinate:</b></h3>
//     <input class="myarea" type="number" id="latitude_code" name="latitude_code">
//     <h3><b>Longitude coordinate:</b></h3>
//     <input class="myarea" type="number" id="longitude_code" name="longitude_code"><br>
//     <button class="mybutton" type="button" id="button">Save coordinates!</button>
//   </div>
//   <p class="console" id="console"><small>%%CONSOLE%%</small></p>

// <script>
//   window.onload = function () {
//   const button = document.getElementById('button');

//   button.addEventListener('click', function() {
//     var consoleLog = document.getElementById("console");
//     var latitudeText = document.getElementById("latitude_code").value;
//     var longitudeText = document.getElementById("longitude_code").value;
//     // create an XHR object
//     const xhr = new XMLHttpRequest();

//     xhr.onload = () => {
//       // process response
//       if (xhr.status == 200) {
//         consoleLog.innerHTML = latitudeText + " " + longitudeText;
//         window.location.replace("http://esp8266.local");
//         alert("Coordinates successfully saved.")
//       } else {
//         if (xhr.status == 204) {
//           consoleLog.innerText = "204";
//           alert("Wrong latitude length. Please try again.");
//         }
//       }
//     };

//     xhr.onerror = () => {
//       consoleLog.innerText = "Error on XML request!";
//     }

//     // create a `GET` request
//     xhr.open('GET', "/configuration?lat=" + latitudeText + "&long=" + longitudeText, true);

//     // send request
//     xhr.send();
//   });
// }
// </script>
// </body>
// </html>
// )rawliteral";


#endif
