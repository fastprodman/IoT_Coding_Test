#include "command_parser.h"

int isStringAllDigits(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 1; // Not all characters are digits
        }
        str++;
    }
    return 0; // All characters are digits
}

uint8_t call_echo(char *str, uint16_t len){

	char *arr;
	uint8_t chr_count;

	arr = strtok(str, " ");
	arr = strtok(NULL, ",");

	if(isStringAllDigits(arr)){
		return 1;
	}

	chr_count = atoi(arr);

	if(chr_count < 0 || chr_count >= 300){
		return 1;
	}

	arr = strtok(NULL, "\r");

	write_str("data: ", 6);
	if(chr_count != 0){
		write_str(arr, len-9);
	}
	write_str("\r\n", 2);

	return 0;
}

uint8_t call_set_led(char *str){

	char *arr;
	uint8_t led_id;
	uint16_t time_ms;

	arr = strtok(str, " ");
	arr = strtok(NULL, ",");

	if(isStringAllDigits(arr)){
		return 1;
	}

	led_id = atoi(arr);

	if(led_id != 0 && led_id != 1){
		return 1;
	}

	arr = strtok(NULL, "\r");

	if(isStringAllDigits(arr)){
		return 1;
	}

	time_ms = atoi(arr);

	if(time_ms < 1 || time_ms >= 5000){
		return 1;
	}

	led_on(led_id, time_ms);

	return 0;
}

void write_error(void){
	write_str("ERROR\r\n", 7);
}

void write_ok(void){
	write_str("OK\r\n", 4);
}

void parse_string(char *str, uint16_t len){
//	uint8_t delim = 0;
//	while(!(str[delim]==' '||delim==len||delim>7)){
//		delim++;
//	}

	if(!strncmp(str, "echo", 4)){
		if(call_echo(str, len)){
			write_error();
		}else{
			write_ok();
		}
		return;
	}

	if(!strncmp(str, "set-led", 7)){
		if(call_set_led(str)){
			write_error();
		}else{
			write_ok();
		}
		return;
	}

	write_error();

//	str = (str+delim);
//	len=len-delim;
//	delim=0;
//
//	while(!(str[delim]==','||delim==len)){
//		delim++;
//	}
//	write_str(str, delim);
//
//	str = (str+delim);
//	len=len-delim;
//	delim=0;
//
//	while(!(str[delim]=='\r'||delim==len)){
//		delim++;
//	}
//	write_str(str, delim);

}
