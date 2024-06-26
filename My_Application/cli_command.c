#include <stdint.h>
#include "cli_command.h"
#include "tempperature_cli.h"
#include "cli_command_table.h"
#include "cli_types.h"
#include <stdio.h>
#include <string.h>
#include "tempperature_cli.h"
#include <string.h>
extern const cli_command_entry_t command_entry_table[];
const cli_command_info_t *find_command_infor(char*cmd){
	const cli_command_entry_t  *command_entry =command_entry_table;
	while(command_entry->command_infor!=NULL){
		if(strstr(command_entry->name,cmd)!=0){
			return command_entry->command_infor;
		}
		command_entry++;
	}
	return NULL;
}
void cli_command_excute(char *uart_buff,int *len){
	char *argv[10];
	char arg_num=0;
	char*ptr;
	ptr=strtok(uart_buff," ");
	while(ptr!=NULL){
	argv[arg_num]=ptr;
	ptr=strtok(NULL," ");
	arg_num++;
	}
	const cli_command_info_t *command_infor=find_command_infor(argv[0]);
	if(command_infor!=NULL){
		command_infor->function(argv,arg_num);
	}else{
	response_print("find not found command\n");
	}
	memset(uart_buff,0,strlen(uart_buff));
	*len=0;
}

