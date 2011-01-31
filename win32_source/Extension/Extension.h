/*
 * Copyright 2011 by Seth N. Hetu
 *
 * Please refer to the end of the file for licensing information
 */

#ifndef _WZ_SETTINGS_EXTENSION
#define _WZ_SETTINGS_EXTENSION


#include <string>


//This class is meant to be sub-classed by various DLL wrappers.
//  Sub-classes will need to add functionality; the DLLs themselves
//  are too varied for me to declare a generalized virtual method.


class Extension {
public:
	//Struct-like properties
	std::wstring id;
	std::wstring libraryFilePath;
	std::wstring libraryFileChecksum;
	bool enabled;
	bool requireChecksum;


	//Basic constructor
	Extension(std::wstring id=L"") {
		this->id = id;
	}


	//Initializing is predictable
	virtual void InitDLL(/*std::string (*MD5Function)(const std::string&)*/) {}


	//Allow map comparison
	bool operator<(const Extension& other) const {
		return id < other.id;
	}

	//Allow logical equals and not equals
	bool operator==(const Extension &other) const {
		return id == other.id;
	}
	bool operator!=(const Extension &other) const {
		return id != other.id;
	}

	//Allow eq/neq on strings, too
	bool operator==(const std::wstring& other) const {
		return id == other;
	}
	bool operator!=(const std::wstring& other) const {
		return id != other;
	}
};




#endif //_WZ_SETTINGS_LANGUAGE

/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
