#include <iostream>
#include "Interface.h"

int main()
{
	Interface program;
	while (program.end_app == false) {
		program.getCommand();
	}
	
}
