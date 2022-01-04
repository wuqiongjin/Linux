#include <iostream>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <cmath>
using namespace std;

#define PATHNAME "/home/wqj/Linux/review/IPC/shm" 
#define PROJ_ID 0x200
#define SIZE 4096
