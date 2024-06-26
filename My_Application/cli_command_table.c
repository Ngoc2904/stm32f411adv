#include "cli_command_table.h"
#include "cli_types.h"
#include "tempperature_cli.h"
#include <stdio.h>
const cli_command_info_t  cli_command_info_gettemp={
	get_tempperature,
	"get temp form sensor"
};
const cli_command_info_t  cli_command_info_settempmax={
	set_tempperaturemax,
	"set tempperature"
};
const cli_command_info_t  cli_command_info_settempmin={
	set_tempperaturemin,
	"set tempperature min"
};
const cli_command_entry_t command_entry_table[]={
		{"gettemp",&cli_command_info_gettemp},
		{"settempmax",&cli_command_info_settempmax},
		{"settempmin",&cli_command_info_settempmin},
		{NULL,NULL}
};


