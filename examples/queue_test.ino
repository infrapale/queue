#include <Arduino.h>
#include "TaHa.h" 
#include "queue.h"



uint8_t qtx[10][1];
uint8_t qrx[10][1];
uint8_t qaled[3][5];




queue_struct q_aled = {0, 0, 0, sizeof(qaled)/sizeof(qaled[0]), sizeof(qaled[0]), &qaled[0][0]};




void setup() {
    delay(2000);
    //while (!Serial); // wait until serial console is open, remove if not tethered to computer
    Serial.begin(115200); 
    Serial.println("queue test 2020");
    Serial.println(sizeof(qtx));
    Serial.println(sizeof(qtx[0]));
    Serial.println(sizeof(qtx)/sizeof(qtx[0]));
    Serial.println(sizeof(queues[0]));
    Serial.println(sizeof(queues[1]));
    Serial.println(qindx_tx);
    queue_reset(&q_aled);
    
    uint8_t b1[5][5] = {
      {11,22,33,44,55},  
      {12,22,33,44,55},
      {13,22,33,44,55},
      {14,22,33,44,55},
      {15,22,33,44,55}
    };  
    uint8_t b2[5]; 
    q_ret_status ret; 
    queue_reset(&q_aled);
    Serial.println("Reset");
    queue_debug(&q_aled);
    ret = queue_put(&q_aled,b1[0]);
    Serial.println("put msg ");
    Serial.println(ret);
    queue_debug(&q_aled);
    ret = queue_get(&q_aled,b2);
    Serial.println("get msg ");
    Serial.println(ret);
    queue_debug(&q_aled);
    
    Serial.println("Fill buffer:");
    for (uint8_t i = 0; i < 5; i++){
      ret = queue_put(&q_aled,b1[i]);
      Serial.println(ret);
      queue_debug(&q_aled);
    };
  

    Serial.println("Read buffer:");
    for (uint8_t i = 0; i < 5; i++){
      ret = queue_get(&q_aled,b2);
      Serial.println(ret);
      queue_debug(&q_aled); 
    }  
   

    Serial.println(queue_available( &q_aled));
    Serial.println("put one msg");
    ret = queue_put(&q_aled,b1[4]);
    Serial.println(ret);
    Serial.println(queue_available( &q_aled));

    queue_debug(&q_aled);
    Serial.println("get one msg");
    ret = queue_get(&q_aled,b2);
    Serial.println(ret);
    Serial.println(queue_available( &q_aled));
    queue_debug(&q_aled);

}

void loop() {
  // put your main code here, to run repeatedly:

}
