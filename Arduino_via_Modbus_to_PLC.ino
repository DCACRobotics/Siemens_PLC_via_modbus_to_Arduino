#include <DFRobot_DHT11.h>
#include <ModbusRtu.h>

Modbus slave(1,1,6);
uint16_t modbus_array[] = {0,0};

#define DHT11_PIN 5
DFRobot_DHT11 DHT;
float Read_Temp = 0;
float Read_Humi = 0;

void setup()
{
  Serial.begin(9600);
  slave.start();
  DHT.read(DHT11_PIN);
  delay(1000);
}

void loop()
{
  Read_Temp = DHT.temperature;
  Read_Humi = DHT.humidity;
  slave.poll(modbus_array,sizeof(modbus_array)/sizeof(modbus_array[0]));
  modbus_array[0] = Read_Temp;
  modbus_array[1] = Read_Humi;
}
