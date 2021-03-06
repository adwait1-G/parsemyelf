//---------------------------------------------------------------------//
//
// Tool: parsemyelf
//
// C++ HeaderFile: pme.h
//
// Info: This headerfile has function declarations defined in various sourcefiles. 
//
// Note: parsemyelf is a simple ELF Parser written in C++ to understand ELF binaries better. 
//
// Author: Adwaith V Gautham
//
// License: NONE
//
// Use the tool the way you want to, enjoy the learning and improve :)
//
//---------------------------------------------------------------------//

#ifndef _PME_H

#define _PME_H 1



#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
#include<elf.h>
#include<capstone/capstone.h>

namespace pme{

	// Simple Error routine
	void PmeErrExit(const char* errmsg);

	void PmeLogo();
	
	//  Given the File Pointer, this routine returns the pointer to .shstrtab section.
	char* PmeGetShStrTabPtr(unsigned char* PmeFilePtr);

}


// _PME_H
#endif
