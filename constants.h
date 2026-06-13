#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <time.h>

#define SQ_SIZE 15
#define PROB 10
#define MAX_AMMO 100
#define ACTIVE 		(1 << 2)
#define YAXIS 		(1 << 1) 	
#define INCREMENT 	(1 << 0)
#define MAX_ENEMIES	100


typedef enum {
	TO_LEFT,
	TO_RIGHT,
	TO_UP,
	TO_DOWN
} Direction;

typedef struct {
	int row;
	int col;
	unsigned int direction : 2;	// MSB? y:x ; LSB? increment: decrement
} Player ;
extern int xoffset[4] ;
extern int yoffset[4] ;

typedef struct {
	int row;
	int col;
	int alive;
	time_t lastMove;
	time_t lastShoot;
} Enemy;


typedef struct {
	int row;
	int col;
	unsigned int direction: 3; // MSB: active, i<<1: y-axis, LSB: increment;
} Bullet ;
#endif

