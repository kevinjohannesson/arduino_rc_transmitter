
// SimpleTx - the master or the transmitter

//#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Transmitting fails when using pin 9, 10, 4 when using the USB host shield. Working pins found so far are 3 and 5
#define CE_PIN   3
#define CSN_PIN 5

const byte slaveAddress[5] = {'R','x','A','A','A'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[2] = "B";
char txNum = 'B';


unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second






void send() {

    bool rslt;
    
    char lights_buff[2];
    itoa(lightsOn, lights_buff, 10);
    Serial.print("lights_buff: ");
    Serial.println(lights_buff);
    char acceleration_buff[2];
    itoa(accelerationPWM, acceleration_buff, 10);
    Serial.print("acceleration_buff: ");
    Serial.println(acceleration_buff);
    char steering_buff[2];
    itoa(steeringAngle, steering_buff, 10);
    Serial.print("steering_buff: ");
    Serial.println(steering_buff);
    char buff[2] = "<";
    strcat(buff, acceleration_buff);
    strcat(buff, ",");
    strcat(buff, steering_buff);
    strcat(buff, ",");
    strcat(buff, lights_buff);
    strcat(buff, ">");
    Serial.println(buff);
    
    const char text[] = "100,90,1";
    rslt = radio.write( &buff, sizeof(buff) );
            // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    Serial.print(text);
    if (rslt) {
        Serial.println("  Acknowledge received");
        updateMessage();
    }
    else {
        Serial.println("  Tx failed");
    }
}

//================

void updateMessage() {
        // so you can see that new data is being sent
//    txNum += 1;
//    if (txNum > '9') {
//        txNum = '0';
//    }
//    dataToSend = "A";
}
