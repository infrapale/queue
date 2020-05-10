#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <Arduino.h>

typedef struct queue_struct {
  uint8_t wr_indx;
  uint8_t rd_indx;
  uint8_t items;
  uint8_t queue_len;
  uint8_t msg_len;
  uint8_t *buf;
};

enum q_ret_status {
  q_ok =   0,
  q_full = 1,
  q_empty= 2
};

void queue_reset(queue_struct *pq);
q_ret_status queue_put( queue_struct *pq, uint8_t *msg);
q_ret_status queue_get( queue_struct *pq, uint8_t *msg);
boolean queue_available( queue_struct *pq);
boolean queue_available( queue_struct *pq);
#endif
