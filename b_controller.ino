void controller() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getButtonClick(SQUARE)) {
      Serial.println(F("\r\nSquare"));
      lightsOn = !lightsOn;
      send();
    }
  }
}
