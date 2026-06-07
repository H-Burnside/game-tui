#include <stdlib.h>
#include <time.h>

#include "map.h"

int main(){
	char map[SQ_SIZE][SQ_SIZE*2];
	srand(time(NULL));

	generateMap(map);
	drawMap(map);

	return 0;
}
