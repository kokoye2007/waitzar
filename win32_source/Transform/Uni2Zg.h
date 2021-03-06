/*
 * Copyright 2009 by Seth N. Hetu
 *
 * Please refer to the end of the file for licensing information
 */

#ifndef _TRANSFORM_UNI2ZG
#define _TRANSFORM_UNI2ZG

#include "Transform/Transformation.h"
#include "NGram/wz_utilities.h"
#include "NGram/Logger.h"

/**
 * Placeholder class: to be used for Uni2Zg Conversion method
 */
class Uni2Zg : public Transformation
{
public:
	Uni2Zg() {
		Logger::resetLogFile('Z');
	}

	//Convert
	void convertInPlace(std::wstring& src) const {
		//Save time
		if (src.empty())
			return;

		//Use our code, from the utilities package.
		Logger::writeLogLine('Z', std::wstring(L"Unicode: {") + src + L"}");
		src = waitzar::sortMyanmarString(src);
		src = waitzar::renderAsZawgyi(src);
		Logger::writeLogLine('Z', std::wstring(L"Zawgyi1: {") + src + L"}");
		Logger::writeLogLine('Z');
		//src = waitzar::removeZWS(src, L"-"); //Remove hyphens
	}
};


#endif //_TRANSFORM_UNI2ZG

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

