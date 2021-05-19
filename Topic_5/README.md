# Topic 5 - Abstract base classes - Files operations
## General info
This project was based on [Topic 3](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_3), but this time writing and reading data to and from files without using separate class for each file type.

* [BinaryFile.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/BinaryFile.h) - header file for thebinary files handling class.
* [CsvFile.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/CsvFile.h) - header file for the CSV files handling class.
* [FileFactory.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/FileFactory.h) - header file for FileFactory class determining the file type.
* [Point.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/Point.h) - header file for  with structure "point" implementation.
* [IFile.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/IFile.h) - header file for pure virtual methods 
* [Errors.h](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/Errors.h) - header file with enumerated errors
* [BinaryFile.cpp](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/BinaryFile.cpp) - ccpp file containing implementation of the binary files handling class and its methods.
* [CsvFile.cpp](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/CsvFile.cpp) - cpp file containing implementation of the CSV files handling class and its methods.
* [FileFactory.cpp](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/FileFactory.cpp) - cpp file containing implementation of the FileFactory class determining the file type.
* [Source.cpp](https://github.com/SSketcher/Objective_Programming---College/blob/main/Topic_5/Source.cpp) - cpp file writing or reading poits to or from the files, testing the implementation.

## Technologies
* C++

Libraries:
* iostream
* string
* vector
* fstream
* cstdint
* sstream

## Sources and helpful materials
[C++ reference](https://en.cppreference.com/w/)
