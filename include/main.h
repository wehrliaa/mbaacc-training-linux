// main.h: Big big global include
#pragma once

#include <windows.h>
#include "tlhelp32.h"

#include <conio.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>
#include <psapi.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "process.h"
#include "memory.h"
#include "cli.h"
#include "savestate.h"
#include "gamestate.h"
#include "actionhandler.h"

//extern struct Process gProc;
//extern struct Process gProc = wait_process("MBAA.exe");
//printf("name=%s baddr=%ld\n", gProc.name, gProc.baddr);
