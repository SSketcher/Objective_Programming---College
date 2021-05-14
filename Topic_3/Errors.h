#pragma once

enum FileError {
	Success,						//Returns 0
	OperationNotPermitted,			//Returns 1
	FileClosed,						//Returns 2
	Error							//Returns 3
};