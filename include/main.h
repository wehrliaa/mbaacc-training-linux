// main.h: Big big global include
#pragma once

#include <windows.h>
#include "tlhelp32.h"

#include <conio.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <memory>
#include <iostream>
#include <psapi.h>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>

#include "process_handling.h"
#include "memory_block.h"
#include "cli.h"
#include "savestatemanager.h"
#include "gamestatemanager.h"
#include "actionhandler.h"

//extern struct Process gProc;
//extern struct Process gProc = wait_process("MBAA.exe");
//printf("name=%s baddr=%ld\n", gProc.name, gProc.baddr);
