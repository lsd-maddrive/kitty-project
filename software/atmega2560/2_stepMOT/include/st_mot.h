#ifndef ST_MOT_H_
#define ST_MOT_H_

//#include "i2c_basics.h"
#include "utils.h"
#include "adc.h"
//#include "gpio_expander.h"

//DIRECT defined connection
#define ST_MOT_PUL_DDR DDRA
#define ST_MOT_PUL_PORT PORTA
#define ST_MOT_DIR_DDR DDRA
#define ST_MOT_DIR_PORT PORTA
//st_mot #1
#define DD_PUL1 DDA0
#define PORT_PUL1 PA0
#define DD_DIR1 DDA1
#define PORT_DIR1 PA1
//st_mot #2
#define DD_PUL2 DDA2
#define PORT_PUL2 PA2
#define DD_DIR2 DDA3
#define PORT_DIR2 PA3
//st_mot #3
#define DD_PUL3 DDA4
#define PORT_PUL3 PA4
#define DD_DIR3 DDA5
#define PORT_DIR3 PA5
//st_mot #4
#define DD_PUL4 DDA6
#define PORT_PUL4 PA6
#define DD_DIR4 DDA7
#define PORT_DIR4 PA7

//general settings
#define POS_CENTER 512
#define POS_ERR 5
#define MAX_ANGLE 90
#define MIN_ANGLE -90
#define MODE 16 //step divide by n
#define STEPS (360/(1.8/MODE))*2
#define ANGLE_TO_STEPS STEPS/360

//#define SINGLE_MOT //SINGLE_MOT / ALL_MOT 
//#define DIRECT //DIRECT / i2c MODULE

//void StMotTim0Init(void);
void StMotTim1Init(void);
void StMotInit(void);

float* GetInfo(void);
float GetMotPos(void);
void StMotPul(void);
void StMotDir(float direction);
void StMotGo();
void SetAngle(float angle);


#ifdef SINGLE_MOT

void StMotGo(float angle, uint8_t st_mot_num);
void StMotPul(void);
void StMotDir(float direction);
void StMotCorrectPos(void);

#endif
#ifdef ALL_MOT

void StMotGo(float angle);
void StMotPul(uint8_t st_mot_chosen);
void StMotDir(uint8_t st_mot_chosen);
void StMotCorrectPos(uint8_t st_mot_chosen);

#endif

#ifdef ORIGIN

void StMotGo(float angle);
void StMotPul(uint8_t st_mot_chosen);
void StMotDir(uint8_t st_mot_chosen);
void StMotCorrectPos(uint8_t st_mot_chosen);

#endif

#endif /* ST_MOT_H_ */