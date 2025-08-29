#include <IRremote.h>
#include <IRRemoteControl.h>
const byte IR_RECEIVE_PIN = 2;

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11

void setup()
{
  Serial.begin(115200);
  Serial.println("IR Receive test");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop()
{
  if (IrReceiver.decode())
  {
    String ir_code = String(IrReceiver.decodedIRData.command, HEX);
    Serial.println(ir_code);

    if (ir_code == "4")
      digitalWrite(LED1, HIGH);
    else if (ir_code == "2")
      digitalWrite(LED1, LOW);

    if (ir_code == "5")
      digitalWrite(LED2, HIGH);
    else if (ir_code == "2")
      digitalWrite(LED2, LOW);

    if (ir_code == "6")
      digitalWrite(LED3, HIGH);
    else if (ir_code == "2")
      digitalWrite(LED3, LOW);

    if (ir_code == "7")
      digitalWrite(LED4, HIGH);
    else if (ir_code == "2")
      digitalWrite(LED4, LOW);

    if (ir_code == "3")
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
    }
    else if (ir_code == "2")
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }

    IrReceiver.resume();
  }
}
