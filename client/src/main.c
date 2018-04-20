#define WIN32_LEAN_AND_MEAN

#include "networking/networking.h"
#include <windows.h>
#include "payload/heartbeat.h"

int main(int argc, char* argv[]) {
	init_networking();

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)listen_on_socket, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)heartbeat_loop, 0, 0, 0);

	while (1) // temporary keep alive
		Sleep(5000);

	return 0;
}
