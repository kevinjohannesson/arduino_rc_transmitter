void controller() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getButtonClick(CIRCLE)) {
      Serial.print(F("\r\nCircle"));
      send();
//      const char text[] = "Hello World";
//      radio.write(&text, sizeof(text));
    }
  }
}
