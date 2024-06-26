#ifndef CLI_TYPES_H_
#define CLI_TYPES_H_
#include <stdint.h>
#include <stdio.h>
typedef void (*cli_comand_func_t)(char **argv,int nums);
typedef struct {
	cli_comand_func_t function;
	char              *help;
}cli_command_info_t;
typedef struct {
	const char               *name;
	const cli_command_info_t *command_infor;
}cli_command_entry_t;
#endif
