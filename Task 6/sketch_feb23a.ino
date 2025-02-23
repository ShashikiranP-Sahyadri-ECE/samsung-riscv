// ESP32 UART Communication (Respond to "Start" Command)
#include <HardwareSerial.h>

HardwareSerial MySerial(1); // Use UART1

void setup() {
    Serial.begin(115200);            // Debug output
    MySerial.begin(9600, SERIAL_8N1, 16, 17); // RX=GPIO16, TX=GPIO17
    Serial.println("ESP32 Ready");
}

void loop() {
    if (MySerial.available()) {
        String received = MySerial.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(received);

        if (received == "Start") {
            MySerial.println("Process Started");
            Serial.println("Sent: Process Started");
        }
    }

    delay(100);
}
