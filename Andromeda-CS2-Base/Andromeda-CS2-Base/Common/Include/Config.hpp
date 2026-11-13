#pragma once

// Project Configuration:

#define LOG_FILE					"debug.log"
#define GUI_FILE					"gui.ini"
#define CONFIG_FILE					"config.json"

#define CHEAT_NAME					"Andromeda CS2 Base"
#define CHEAT_VERSION				"2.0.2"

// Project Buid Config:

#define RELEASE_BUILD				1

#if RELEASE_BUILD == 1

#define ENABLE_CONSOLE_DEBUG		0
#define DISABLE_INVENTORY			0

#define LOG_SDK						1
#define LOG_SDK_PATTERN				0

#define DUMP_SCHEMA_SCOPE_LIST		0
#define DUMP_SCHEMA_ALL_OFFSET		0

#else

#define ENABLE_CONSOLE_DEBUG		1
#define DISABLE_INVENTORY			1

#define LOG_SDK						1
#define LOG_SDK_PATTERN				0

#define DUMP_SCHEMA_SCOPE_LIST		0
#define DUMP_SCHEMA_ALL_OFFSET		0

#endif

