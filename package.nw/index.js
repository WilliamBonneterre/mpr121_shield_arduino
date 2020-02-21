const ab2str = require('arraybuffer-to-string');

nw.Window.get().showDevTools();

let buffer = "";

chrome.serial.getDevices(devices => {
  devices.forEach(device => console.log(device));
});

// let port = "COM3";
let port = "/dev/cu.usbmodem142401";

chrome.serial.connect(port, {bitrate: 1000000}, () => {
  console.log("Serialport connected:" + port);
  chrome.serial.onReceive.addListener(onDataReceived);
});

function onDataReceived(info) {

  let lines = ab2str(info.data).split("\n");
  lines[0] = buffer + lines[0];
  buffer = lines.pop();

  lines.forEach(line => {
    const [type, value] = line.split("=");
    console.log(type, value);
  });

}
