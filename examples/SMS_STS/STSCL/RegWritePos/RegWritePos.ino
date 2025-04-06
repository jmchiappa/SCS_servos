/*
异步写例子在STS3215中测试通过，舵机出厂速度单位为0.0146rpm，舵机机运行速度V=3400
如果使用的出厂速度单位是0.732rpm，则速度改为V=68，延时公式T=[(P1-P0)/(50*V)]*1000+[(50*V)/(A*100)]*1000
*/

#include <SCServo.h>

SMS_STS st;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000);
  st.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  st.RegWritePosEx(1, 4095, 3400, 50);//舵机(ID1)以最高速度V=3400步/秒，加速度A=50(50*100步/秒^2)，运行至P1=4095位置
  st.RegWritePosEx(2, 4095, 3400, 50);//舵机(ID2)以最高速度V=3400步/秒，加速度A=50(50*100步/秒^2)，运行至P1=4095位
  st.RegWriteAction();
  delay(1884);//[(P1-P0)/V]*1000+[V/(A*100)]*1000

  st.RegWritePosEx(1, 0, 3400, 50);//舵机(ID1)以最高速度V=3400步/秒，加速度A=50(50*100步/秒^2)，运行至P0=0位置
  st.RegWritePosEx(2, 0, 3400, 50);//舵机(ID2)以最高速度V=3400步/秒，加速度A=50(50*100步/秒^2)，运行至P1=0位置
  st.RegWriteAction();
  delay(1884);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
}
