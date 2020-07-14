void setup() {
  Serial.begin(115200);
//    Serial.begin(9600);

    Serial.println("SimpleTx Starting");
//pinMode(10, OUTPUT);
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openWritingPipe(slaveAddress);

//  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 USB Library Started"));
}
