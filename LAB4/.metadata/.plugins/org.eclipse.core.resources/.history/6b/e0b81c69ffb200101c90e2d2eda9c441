/*
 * schedule.h
 *
 *  Created on: Oct 27, 2025
 *      Author: ASUS
 */
#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define SCH_MAX_TASKS 10

#define NO_ERROR 0
#define ERROR_SCH_INVALID_INDEX 101
#define ERROR_SCH_TOO_MANY_TASKS 102
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 103
#define ERROR_SCH_WAITING_FOR_START_CMD_MASTER 104
#define ERROR_SCH_ONE_OR_MORE_SLAVES_NOT_STARTED 105
#define ERROR_SCH_LOST_SLAVE 106
#define ERROR_SCH_CAN_BUS_ERROR 107
#define ERROR_I2C_WRITE_BYTE_AT24C64 108

typedef struct {
void (*funcPtr)(void);
uint32_t delay;
uint32_t period;
uint8_t runme;
uint8_t taskID;
bool isEmpty;
bool isOneShot;
} Tasks;

extern Tasks taskList[SCH_MAX_TASKS];
extern uint8_t currentTasks;
extern uint32_t ERROR_CODE_G;

void SCH_Init(void);
uint32_t SCH_Add_Task(void (*task)(void), uint32_t delay, uint32_t period);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Delete_Task(uint32_t taskID);
void SCH_Delete_All_Tasks(void);

#endif /* INC_SCH_H_ */
