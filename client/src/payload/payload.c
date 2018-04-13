#include "payload.h"

int send_payload(struct Payload payload) {
	SOCKET sock;
	if (init_socket(&sock))
		return 1;

	char* system_guid = get_system_guid();
	json_object_dotset_string(json_value_get_object(payload.json_value_payload), "system_guid", system_guid);
	char* json_payload = json_serialize_to_string(payload.json_value_payload);
	free(system_guid);

	char* buf = malloc(CLIENT_BUFFER_SIZE);
	memset(buf, 0, CLIENT_BUFFER_SIZE);

	memcpy(buf, &payload.client_payload_type, sizeof(payload.client_payload_type));
	memcpy(&(buf[4]), json_payload, strlen(json_payload));

	int bytes_sent = 0;

	while (bytes_sent < CLIENT_BUFFER_SIZE) {
		int send_ret = send(sock, buf, CLIENT_BUFFER_SIZE, 0);

		if (send_ret == SOCKET_ERROR) {
			log_message("Failed to send payload\n");
			free(buf);

			return 1;
		}

		bytes_sent += send_ret;
	}

	json_free_serialized_string(json_payload);
	json_value_free(payload.json_value_payload);
	free(buf);
	close_socket(&sock);

	return 0;
}

void attach_system_guid(JSON_Value* json_value_payload) {

}
