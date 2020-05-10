#include <Arduino.h>
#include "queue.h"



void queue_reset(queue_struct *pq){
    pq->wr_indx = 0;
    pq->rd_indx = 0;
    pq->items = 0;
}

q_ret_status queue_put( queue_struct *pq, uint8_t *msg){
    uint8_t mindx;
    q_ret_status ret; 
    if(pq->items < pq->queue_len){
        pq->items++;
        mindx = pq->wr_indx;
        for (uint8_t i=0; i< pq->msg_len; i++) {
            pq->buf[mindx*pq->msg_len +i] = msg[i];
        }
        if(++pq->wr_indx >= pq->queue_len) {
            pq->wr_indx = 0;
        }
        ret = q_ok;
    }
    else {
      ret = q_full;
    }
    return ret;
}

q_ret_status queue_get( queue_struct *pq, uint8_t *msg){
    uint8_t mindx;
    q_ret_status ret; 
    if(pq->items > 0 ){
        pq->items--;
        mindx = pq->rd_indx;
        for (uint8_t i=0; i< pq->msg_len; i++) {
             msg[i] =pq->buf[mindx*pq->msg_len +i];
        }
        if(++pq->rd_indx >= pq->queue_len) {
            pq->rd_indx = 0;
        }
        ret = q_ok;
    }
    else {
      ret = q_empty;
    }
    return ret;
}

boolean queue_available( queue_struct *pq){
  return pq->items > 0;
}

void queue_debug(queue_struct *pq){
   Serial.print("queue_len: ");
   Serial.println(pq->queue_len);
   Serial.print("items: ");
   Serial.println(pq->items);
   Serial.print("msg_len: ");
   Serial.println(pq->msg_len);
   Serial.print("wr_indx: ");
   Serial.println(pq->wr_indx);
   Serial.print("rd_indx: ");
   Serial.println(pq->rd_indx);
   Serial.println("buf: ");
   for (uint8_t i = 0; i < pq->queue_len; i++){
     Serial.print(i);    
     Serial.print(" : ");
     for (uint8_t j = 0; j < pq->msg_len; j++){
        Serial.print(pq->buf[i*pq->msg_len +j]);
        Serial.print(",");
     }
     Serial.println();
   }  
}
