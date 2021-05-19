#pragma once

enum FileError {
	Success,						//zwraca numer 0
	OperationNotPermitted,			//zwraca numer 1
	FileClosed,						//zwraca numer 2
	Error							//zwraca numer 3
};