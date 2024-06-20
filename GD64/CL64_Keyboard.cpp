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

#include "pch.h"
#include "CL64_App.h"
#include "CL64_Keyboard.h"

CL64_Keyboard::CL64_Keyboard(void)
{
	Real Rate = 0;
	OldPos = Ogre::Vector3::ZERO;
}

CL64_Keyboard::~CL64_Keyboard(void)
{
}

// *************************************************************************
// *					Keyboard_Mode_First Terry						   *
// *************************************************************************
void CL64_Keyboard::Keyboard_Mode_First(float deltaTime)
{
	//if (Block_Keyboard == 0)
	{
		//	------------------------------------------------ Move Forward
		if (GetAsyncKeyState(87) < 0) // W Key
		{

			if (App->CL_Scene->Player_Added == 1)
			{
				//App->Flash_Window();
				App->CL_Player->mMoveDirection = (btVector3(0, 0, -1));
				//App->CL_Player->Check_Collisions_New();
				App->CL_Scene->B_Player[0]->IsMOving = 1;
			}

		}
		else
		{
			if (App->CL_Scene->Player_Added == 1 && App->CL_Scene->B_Player[0]->IsMOving == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(0, 0, 0));
				App->CL_Scene->B_Player[0]->IsMOving = 0;
			}
		}

		//	------------------------------------------------ Move Back
		if (GetAsyncKeyState(83) < 0) // S Key	
		{

			if (App->CL_Scene->Player_Added == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(0, 0, 1));
				App->CL_Scene->B_Player[0]->IsMOving_Back = 1;
			}

		}
		else
		{
			if (App->CL_Scene->Player_Added == 1 && App->CL_Scene->B_Player[0]->IsMOving_Back == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(0, 0, 0));
				App->CL_Scene->B_Player[0]->IsMOving_Back = 0;
			}
		}

		//	------------------------------------------------ Move Right
		if (GetAsyncKeyState(65) < 0)
		{

			if (App->CL_Scene->Player_Added == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(1, 0, 0));// walkDirection
				App->CL_Scene->B_Player[0]->IsMOving_Right = 1;
			}
		}
		else
		{
			if (App->CL_Scene->Player_Added == 1 && App->CL_Scene->B_Player[0]->IsMOving_Right == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(0, 0, 0));// walkDirection
				App->CL_Scene->B_Player[0]->IsMOving_Right = 0;
			}
		}

		//	------------------------------------------------ Move Left
		if (GetAsyncKeyState(68) < 0)
		{

			if (App->CL_Scene->Player_Added == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(-1, 0, 0));// walkDirection
				//App->CL_Player->Check_Collisions_New();
				App->CL_Scene->B_Player[0]->IsMOving_Left = 1;
			}

		}
		else
		{
			if (App->CL_Scene->Player_Added == 1 && App->CL_Scene->B_Player[0]->IsMOving_Left == 1)
			{
				App->CL_Player->mMoveDirection = (btVector3(0, 0, 0));// walkDirection
				App->CL_Scene->B_Player[0]->IsMOving_Left = 0;
			}
		}

		//------------------------------------------------ Escape 
		if (GetAsyncKeyState(VK_ESCAPE) < 0) // Back to Editor mode;
		{
			/*if (Block_Keyboard == 0)
			{
				Block_Keyboard = 1;
				if (App->BR_True3D_Mode_Active == 1)
				{
					App->CLSB_BR_Render->Go_BR_3D_Mode();
				}
				else
				{
					if (App->CLSB_Scene_Data->FullScreenMode_Flag == 1)
					{
						App->CLSB_Ogre_Setup->ExitFullScreen();
					}
				}
			}*/

			//Block_Keyboard = 0;
		}
	}
}

// *************************************************************************
// *		Keyboard_Mode_Model:- Terry and Hazel Flanigan 2024			   *
// *************************************************************************
void CL64_Keyboard::Keyboard_Mode_Model(float deltaTime)
{
	//	Pan Up
	if (GetAsyncKeyState(69) < 0) // E key 
	{
		Rate = (App->CL_Ogre->OgreListener->mMoveSensitivity / 1000) * 2;
		OldPos = App->CL_Ogre->OgreListener->mCamNode->getPosition();

		OldPos.y += Rate;
		App->CL_Ogre->OgreListener->mCamNode->setPosition(OldPos);
	}

	// Pan Down
	if (GetAsyncKeyState(81) < 0)  // Q Key
	{
		Rate = (App->CL_Ogre->OgreListener->mMoveSensitivity / 1000) * 2;

		OldPos = App->CL_Ogre->OgreListener->mCamNode->getPosition();

		OldPos.y -= Rate;
		App->CL_Ogre->OgreListener->mCamNode->setPosition(OldPos);
	}

	// Forward
	if (App->CL_Ogre->OgreListener->Wheel < 0) // Mouse Wheel Forward
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = -App->CL_Ogre->OgreListener->mMoveScale * 25;
	}
	if (GetAsyncKeyState(87) < 0) // W Key
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = -App->CL_Ogre->OgreListener->mMoveScale;
	}

	// Back
	if (App->CL_Ogre->OgreListener->Wheel > 0) // Mouse Wheel Back
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = App->CL_Ogre->OgreListener->mMoveScale * 25;
	}
	if (GetAsyncKeyState(83) < 0) // S Key	
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = App->CL_Ogre->OgreListener->mMoveScale;
	}

	// Pan Left
	if (GetAsyncKeyState(65) < 0) // A Key
	{
		App->CL_Ogre->OgreListener->mTranslateVector.x = App->CL_Ogre->OgreListener->mMoveScale;
	}

	// Pan Right
	if (GetAsyncKeyState(68) < 0)  // D Key
	{
		App->CL_Ogre->OgreListener->mTranslateVector.x = -App->CL_Ogre->OgreListener->mMoveScale;
	}

	//------------------------------------------------ Escape 
	if (GetAsyncKeyState(VK_ESCAPE) < 0) // Back to Editor mode;
	{
		
	}
}

// *************************************************************************
// *		Keyboard_Mode_Free:- Terry and Hazel Flanigan 2024			   *
// *************************************************************************
void CL64_Keyboard::Keyboard_Mode_Free(float deltaTime)
{
	// Forward
	if (App->CL_Ogre->OgreListener->Wheel < 0) // Mouse Wheel Forward
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = -App->CL_Ogre->OgreListener->mMoveScale * 30;
	}
	if (GetAsyncKeyState(87) < 0) // W Key
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			App->CL_Ogre->OgreListener->mTranslateVector.z = -App->CL_Ogre->OgreListener->mMoveScale;
		}
	}

	// Back
	if (App->CL_Ogre->OgreListener->Wheel > 0) // Mouse Wheel Back
	{
		App->CL_Ogre->OgreListener->mTranslateVector.z = App->CL_Ogre->OgreListener->mMoveScale * 30;
	}
	if (GetAsyncKeyState(83) < 0) // S Key	
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			App->CL_Ogre->OgreListener->mTranslateVector.z = App->CL_Ogre->OgreListener->mMoveScale;
		}

	}

	// Pan Down
	if (GetAsyncKeyState(81) < 0) // Q Key	
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			Rate = (App->CL_Ogre->OgreListener->mMoveSensitivity / 1000) * 2; //FlyRate;

			OldPos = App->CL_Ogre->OgreListener->mCamNode->getPosition();

			OldPos.y -= Rate;

			App->CL_Ogre->OgreListener->mCamNode->setPosition(OldPos);
		}
	}

	//	Pan Up
	if (GetAsyncKeyState(69) < 0) // E Key
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			Rate = (App->CL_Ogre->OgreListener->mMoveSensitivity / 1000) * 2; //FlyRate;

			OldPos = App->CL_Ogre->OgreListener->mCamNode->getPosition();

			OldPos.y += Rate;

			App->CL_Ogre->OgreListener->mCamNode->setPosition(OldPos);
		}
	}

	// Pan Left
	if (GetAsyncKeyState(65) < 0) // A Key
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			App->CL_Ogre->OgreListener->mTranslateVector.x = -App->CL_Ogre->OgreListener->mMoveScale;
		}
	}

	// Pan Right
	if (GetAsyncKeyState(68) < 0) // D Key
	{
		if (App->CL_Ogre->OgreListener->CameraMode == Enums::Cam_Mode_Free)
		{
			App->CL_Ogre->OgreListener->mTranslateVector.x = App->CL_Ogre->OgreListener->mMoveScale;
		}
	}

	//------------------------------------------------ Escape 
	if (GetAsyncKeyState(VK_ESCAPE) < 0) // Back to Editor mode;
	{
		
	}
}
