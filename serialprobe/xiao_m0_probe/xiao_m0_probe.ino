#include <stdlib.h>

#define SerialProbe Serial1

void setup() {
  Serial.begin(921600);
  SerialProbe.begin(115200);
}

char recv_buffer[30] = {};

void loop() {
  while(Serial.available()){
    char val = Serial.read();
    if (val == '#'){
      Serial.println("#");
      Serial.println("BaudRate Change mode, Provide new baud rate and write # again to apply changes");
      Serial.setTimeout(30000);
      Serial.readBytesUntil('#', recv_buffer, 29);
      Serial.setTimeout(1000);
      char* end;
      int new_baud = strtol(recv_buffer, &end, 10);
      if((new_baud  > 1200) && (new_baud<1000000)){
        SerialProbe.begin(new_baud);
        Serial.println("baudrate updated!");
      }
    }else{
      SerialProbe.write(val);
    }
  }
  while(SerialProbe.available()){
    Serial.write(SerialProbe.read());
  }

}
