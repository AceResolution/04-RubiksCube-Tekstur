/*


AceResolution's Rubik's Cube Simulator
Muhammad Nizami
Erick Chandra
Fathul Asrar Alfansuri

- dibuat untuk kepentingan pendidikan - 

Built on top of Rubik's Cube Simulator by AnTiKoNs
*/

#include "rotate_animation_threads.h"
#include <stdbool.h>
#include <pthread.h>

void (*__rotate__animation__thread_function_call)(CUBE *) = NULL;
CUBE * __rotate__animation__thread_function_param;

bool running = false;

void * thread_func(void * param){
	__rotate__animation__thread_function_call(__rotate__animation__thread_function_param);
	running = false;
	pthread_exit(NULL);
}

void run_anim_thread(void (*___rotate__animation__thread_function_call)(CUBE *), CUBE * ___rotate__animation__thread_function_param){
	pthread_t threadid;
	if (!running){
		running = true;
		__rotate__animation__thread_function_call = ___rotate__animation__thread_function_call;
		__rotate__animation__thread_function_param = ___rotate__animation__thread_function_param;
		if (pthread_create(  &threadid, NULL, thread_func, NULL)!=0)
			running = false;
	}
}

