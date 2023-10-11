
#include <Servo.h>

//int DETECT = 2;   //적외선 센서 2번
Servo pin1;     // 라인 1번 아래쪽 정면 오른쪽
Servo pin2;    // 라인 1번 아래쪽 정면 왼쪽
Servo pin3;   //라인 1번 위쪽 정면 오른쪽
Servo pin4;   //라인 1번 위쪽 정면 왼쪽
//Servo pin5;   //라인에 넣어 주는거

// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ.....char data[8];     //분류 데이타
int num[8] = {0,0,0,0,0,0,0,0};
char cmd; // 파이썬이랑 시리얼 통신용 파이썬으로 그래프 출력 //적용 안함
const int line1servo1 = 10;   //스텝 모터 10번 pwm
const int line1servo2 = 9;    //스텝 모터 9번  pwm
const int line1servo3 = 7;    //스텝 모터 7번  pwm
const int line1servo4 = 8;    //스텝 모터 8번  pwm
//const int line1servo5 = 6;    //스텝 모터 6번  pwmㄲ

void setup() {
  //pinMode(DETECT, INPUT); //적외선 센서
  
  pin1.attach(line1servo1);   
  pin2.attach(line1servo2);
  pin3.attach(line1servo3);
  pin4.attach(line1servo4);
  //pin5.attach(line1servo5);
  Serial.begin(9600);   //시리얼 통신 - 제어 및 파이썬 통신용
  
  // put your setup code here, to run once:
  //Serial.println(random(10,20));
  //data set
  /*
  data[0] = 'pepsi';
  data[1] = 'cola';
  data[2] = 'pocari';
  data[3] = 'cider';
  data[4] = 'icis';
  data[5] = '2%';
  data[6] = 'toreta';
  data[7] = 'hwanta';
  */
  pin1.write(0);  //기본 정렬
  pin2.write(190);  // 기본 정렬
  pin3.write(0);
  pin4.write(190);
  //pin5.write(0);
  
}



void loop() {
  

 /*
  
 if(digitalRead(DETECT) == LOW)    //적외선 센서 물체 탐지시에 리셋 신호.
    {
      Serial.println("정지");
      pin1.write(0);  //기본 정렬
      pin2.write(190);  // 기본 정렬
      pin3.write(0);
      pin4.write(190);
      pin5.write(330);
      delay(500);  //0.5초
    }
    */
  delay(10);

  //cmd = random(1,9);        //랜덤으로 입력 받아서 제어
  cmd = Serial.read();    //시리얼 모듈로 제어                                                                          
  //Serial.println(cmd);
    
  delay(50);
  /*
  //자동으로 제어
   if(cmd == 1)
  {
    pin1.write(0);  // 분류 1번
    pin2.write(125); // 0도
    pin3.write(0);
    pin4.write(190);
    delay(800);
    num[0]++;
    //Serial.println("펩시");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    
    delay(800);
  }
   if(cmd == 2)
   {
    pin1.write(130);  // 분류 2번
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190); 
    delay(800);
    num[1]++;
    //Serial.println("콜라");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(800);
   }
    if(cmd == 3){
    pin1.write(0);  // 분류 3번
    pin2.write(40);  
    pin3.write(0);
    pin4.write(190);
    delay(800);
    num[2]++;
    //Serial.println("포카리");
    pin1.write(0);    // 분류후 정렬
    pin2.write(190);    
    pin3.write(0);
    pin4.write(190);
    delay(800);
    }

    if(cmd == 4)
    {
    pin1.write(80);   // 분류 4번
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    delay(800);
    num[3]++;
    //Serial.println("사이다");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(800);
    }

    if(cmd == 5)
    {
    pin1.write(0);  // 분류 1번
    pin2.write(190); // 0도
    pin3.write(0);
    pin4.write(125);
    delay(800);
    num[4]++;
    //Serial.println("아이시스");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    
    delay(800);
    }
    
    if(cmd == 6)
    {
    pin1.write(0);  // 분류 6번
    pin2.write(190); 
    pin3.write(130);
    pin4.write(190); 
    delay(800);
    num[5]++;
    //Serial.println("2프로");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(800);
    }

    if(cmd == 7)
    {
    pin1.write(0);  // 분류 7번
    pin2.write(190);  
    pin3.write(0);
    pin4.write(40);
    delay(800);
    num[6]++;
    //Serial.println("토레타");
    pin1.write(0);    // 분류후 정렬
    pin2.write(190);    
    pin3.write(0);
    pin4.write(190);
    delay(800);
    }

    if(cmd == 8)
    {
    pin1.write(00);   // 분류 4번
    pin2.write(190);  
    pin3.write(70);
    pin4.write(190);
    delay(800);
    num[7]++;
    //Serial.println("환타");
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(800);
    }
    */
    
    
      //시리얼 모듈
  if(cmd == '1')  
  {
    pin1.write(0);  // 분류 1번
    pin2.write(125); // 0도
    pin3.write(0);
    pin4.write(190);
    Serial.println("sucess");
    delay(2500);
    num[0]++;
    
    pin1.write(0);  // 분류후 정렬
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
  }
  
   if(cmd == '2')
   {
    pin1.write(135);  // 분류 2번
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190); 
    Serial.println("sucess");
    delay(2500);
    num[1]++;
    
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
   }
   
    if(cmd == '3'){
    pin1.write(0);  // 분류 3번
    pin2.write(40);  
    pin3.write(0);
    pin4.write(190);
    Serial.println("sucess");
    delay(2500);
    num[2]++;
    
    pin1.write(0);    // 분류후 정렬
    pin2.write(190);    
    pin3.write(0);
    pin4.write(190);
    delay(500);
   
    }

    if(cmd == '4')
    {
    pin1.write(70);   // 분류 4번
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    Serial.println("sucess");
    delay(2500);
    num[3]++;
    
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(500);
   
    }

    if(cmd == '5')
    {
    pin1.write(0);  // 분류 5번
    pin2.write(190); // 0도
    pin3.write(0);
    pin4.write(125);
    Serial.println("sucess");
    delay(2300);
    num[4]++;
    pin1.write(0);  // 분류후 정렬
    pin2.write(190);  
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
    }
    
    if(cmd == '6')
    {
    pin1.write(0);  // 분류 6번
    pin2.write(190); 
    pin3.write(150);
    pin4.write(190); 
    Serial.println("sucess");
    delay(2500);
    num[5]++;
    
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
    }

    if(cmd == '7')
    {
    pin1.write(0);  // 분류 7번
    pin2.write(190);  
    pin3.write(0);
    pin4.write(40);
    Serial.println("sucess");
    delay(2500);
    num[6]++;
  
    pin1.write(0);    // 분류후 정렬
    pin2.write(190);    
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
    }

    if(cmd == '8')
    {
    pin1.write(00);   // 분류 8번
    pin2.write(190);  
    pin3.write(60);
    pin4.write(190);
    Serial.println("sucess");
    delay(2500);
    num[7]++;
    
    pin1.write(0);  // 분류후 정렬
    pin2.write(190); 
    pin3.write(0);
    pin4.write(190);
    delay(500);
    
    }
    /*
    delay(30);
    for(int i = 0; i<8; i++)
    {
      if(i < 7)
      {
      Serial.print(num[i]);
      Serial.print(",");
      }
      else
      Serial.println(num[i]);
    }
    delay(30);
    */
  // put your main code here, to run repeatedly:

}
