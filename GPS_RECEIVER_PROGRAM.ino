#include<SoftwareSerial.h>;
#include<TinyGPS.h>;SoftwareSerialmySerial(10,11);IIRX,TX
TinyGPSgps;IIcreategpsobject
voidsetup(){
IIOpenserialcommunicationsandwaitforporttoopen:Serial.begin(57600);
while(!Serial);IIwaitfortheserial
porttoconnect.NeededfornativeUSBportonly
Serial.println("TIFLABS");
mySerial.begin(9600);IIsetthedata

ratefortheSoftwareSerialport
mySerial.println("AB HINANDAN");
}
voidloop(){
IIrunoverandover
if(mySerial.available()){charc=mySerial.read(); Serial.write(c);
if(gps.encode(c)){
IIencodegpsdata
gps.get_position(&lat,&lon);IIgetlatitudeandlongitude
Serial.print("Position:");11displayposition
Serial.print("Lat:");
Serial.print(lat);IIprintlatitude

Serial.print(lat);//printlatitudeSerial.print("Lon:");Serial.println(lon);//printlongitude
}
}
}
