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
class CL64_Preferences
{
public:

	CL64_Preferences(void);
	~CL64_Preferences(void);

	void Clean_Up(void);

	void Start_Preferences_Dlg();
	void Read_Preferences();
	bool Write_Preferences();

	bool Start_FullScreen;
	bool Start_Full_3DWin;

private:

	static LRESULT CALLBACK Preferences_Dlg_Proc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	FILE* WriteData;
};

