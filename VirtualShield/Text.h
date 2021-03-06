/*
    Copyright(c) Microsoft Open Technologies, Inc. All rights reserved.

    The MIT License(MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions :

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef Text_h
#define Text_h

#include "Sensor.h"

const PROGMEM char Y[] = "Y";
const PROGMEM char CLEAR[] = "CLEAR";
const PROGMEM char RGBAKEY[] = "ARGB";
const PROGMEM char PID[] = "Pid";

class Text : public Sensor
{
public:
    Text(const VirtualShield &shield);

	int clear(ARGB argb = 0);
	int clearLine(UINT line);
	int clearId(UINT id);

	int print(String text, ARGB argb = 0);
	int printAt(UINT line, String text, Attr extraAttributes[] = 0, int extraAttributeCount = 0);
	int printAt(UINT line, EPtr text, Attr extraAttributes[] = 0, int extraAttributeCount = 0);
	int printAt(UINT line, double value, ARGB argb = 0);

	void onJsonReceived(JsonObject& root, ShieldEvent* shieldEvent) override;
};

#endif