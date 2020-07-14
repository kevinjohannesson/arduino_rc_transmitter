void controller() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getButtonClick(CIRCLE)) {
      Serial.println(F("\r\nCircle"));
      send();
//      const char text[] = "Hello World";
//      radio.write(&text, sizeof(text));
    }
    if (PS4.getButtonClick(SQUARE)) {
      Serial.println(F("\r\nSquare"));
      if(lightsOn){
        lightsOn = 0;
      } else {
        lightsOn = 1;
      }
      send();
//      const char text[] = "Hello World";
//      radio.write(&text, sizeof(text));
    }
  }
}
