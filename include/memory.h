// memory.h: Memory handling utilities
#pragma once

// This class abstracts a value in the game's memory, treating it as an actual
// object that is much easier to manipulate than, say, constants in a huge .h
// file.
class MemoryBlock {
public:
	DWORD address; // Address in memory
	int size;      // Size of the value stored there, in bytes
	int int_data;  // Not sure what this is
	char* data;    // Buffer that holds any data that is read from, or written
	               // to the game

	MemoryBlock(DWORD address, int size) {
		this->address = address;
		this->size = size;
		this->int_data = 0;
		this->data = new char[size]();
	}

	// Write the value currently stored in the program, to the game's memory.
	void
	write_memory(char* data, DWORD addr, bool absolute) {
		if (data != NULL) this->data = data;
		if (addr == 0) addr = this->address;
		if (absolute == true) 
			WriteProcessMemory(
				gProc.handle,
				(LPVOID)(addr),
				this->data,
				this->size,
				NULL);
		else
			WriteProcessMemory(
				gProc.handle,
				(LPVOID)(gProc.baddr + addr),
				this->data,
				this->size,
				NULL);
	}

	// Read the value currently stored in the game's memory, to the program.
	int
	read_memory(bool absolute) {
		if (absolute == true) 
			ReadProcessMemory(
				gProc.handle,
				(LPVOID)(this->address),
				this->data, 
				this->size, 
				NULL);
		else
			ReadProcessMemory(
				gProc.handle,
				(LPVOID)(gProc.baddr + this->address),
				this->data,
				this->size,
				NULL);

		return decode_data();
	}

	int
	decode_data() {
		if ((this->size == 1) || (this->size == 2) || (this->size == 4)) {
			memcpy(&this->int_data, this->data, this->size);
			return this->int_data;
		} else
			return -1;
	}

	// Lê os primeiros 4 bytes do que tá armazenado e converte para um número
	int
	btoi() {
		int a = 0;
		for (int i = 0; i < 3; i++) a |= this->data[i] << (8*i);
		return a;
	}
};
