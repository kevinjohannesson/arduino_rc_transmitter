void controller() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getButtonClick(SQUARE)) {
      Serial.println(F("\r\nSquare"));
      lightsOn = !lightsOn;
      send();
    }

    int reading = PS4.getAnalogButton(R2);
    if(reading != oldR2Value){
      oldR2Value = reading;
      if (reading) {
        accelerationPWM = reading;
        send();
      }
      else {
        accelerationPWM = 0;
        send();
      }
    }

  int stickReading = PS4.getAnalogHat(LeftHatX);
  if (stickReading != oldStickValue){
    oldStickValue = stickReading;
    if (stickReading > 137 || stickReading < 117 ) {     
      isSteering = true;
      steeringAngle = map(stickReading, 0, 255, 0, 180);
      send();
    }
    else {
      if(isSteering){
        isSteering = false;
        steeringAngle = 90;
        send();
      } 
    }
  }
}
}
