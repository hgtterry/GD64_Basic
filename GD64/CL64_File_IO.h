/*
Copyright (c) GameDirector 2019 To 2024 HGT Software W.T.Flanigan H.C.Flanigan

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#pragma once
class CL64_File_IO
{
public:
	CL64_File_IO();
	~CL64_File_IO();

	bool Open_File_Model(const char* Extension, const char* Title, const char* StartDirectory);
	bool Open_Resource_File(char* Extension, char* Title, char* StartDirectory);

	std::string Get_Model_Path_File_Name();

	void Open_HTML(char* HelpTitle);

	char Model_FileName[MAX_PATH];
	char Model_Path_FileName[MAX_PATH];

	char OgreCFG_FileName[MAX_PATH];
	char OgreCFG_Path_FileName[MAX_PATH];

	OPENFILENAME ofn;
};

