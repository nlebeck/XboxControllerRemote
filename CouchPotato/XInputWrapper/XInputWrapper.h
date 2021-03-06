// XInputWrapper.h

#pragma once

#include <WinUser.h>
#include <Xinput.h>

using namespace System;

namespace XInputWrapper {

	public value class XInputConstants
	{
	public:
		static const short GAMEPAD_LEFT_THUMB_DEADZONE = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
		static const short GAMEPAD_RIGHT_THUMB_DEADZONE = XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
		static const short GAMEPAD_TRIGGER_THRESHOLD = XINPUT_GAMEPAD_TRIGGER_THRESHOLD;

		static const unsigned short GAMEPAD_DPAD_UP = 0x0001;
		static const unsigned short GAMEPAD_DPAD_DOWN = 0x0002;
		static const unsigned short GAMEPAD_DPAD_LEFT = 0x0004;
		static const unsigned short GAMEPAD_DPAD_RIGHT = 0x0008;
		static const unsigned short GAMEPAD_START = 0x0010;
		static const unsigned short GAMEPAD_BACK = 0x0020;
		static const unsigned short GAMEPAD_LEFT_THUMB = 0x0040;
		static const unsigned short GAMEPAD_RIGHT_THUMB = 0x0080;
		static const unsigned short GAMEPAD_LEFT_SHOULDER = 0x0100;
		static const unsigned short GAMEPAD_RIGHT_SHOULDER = 0x0200;
		static const unsigned short GAMEPAD_A = 0x1000;
		static const unsigned short GAMEPAD_B = 0x2000;
		static const unsigned short GAMEPAD_X = 0x4000;
		static const unsigned short GAMEPAD_Y = 0x8000;

		static const unsigned int RET_ERROR_SUCCESS = ERROR_SUCCESS;
		static const unsigned int RET_ERROR_DEVICE_NOT_CONNECTED = ERROR_DEVICE_NOT_CONNECTED;
	};

	public value class XInputGamepad
	{
	public:
		WORD wButtons;
		BYTE bLeftTrigger;
		BYTE bRightTrigger;
		SHORT sThumbLX;
		SHORT sThumbLY;
		SHORT sThumbRX;
		SHORT sThumbRY;
	};

	public value class XInputState
	{
	public:
		DWORD dwPacketNumber;
		XInputGamepad Gamepad;

		static DWORD XInputGetStateWrapper(DWORD dwUserIndex, XInputState% state);
	};

	public value class MouseEventWrapper
	{
	public:
		static const DWORD FLAG_MOUSEEVENTF_LEFTDOWN = MOUSEEVENTF_LEFTDOWN;
		static const DWORD FLAG_MOUSEEVENTF_LEFTUP = MOUSEEVENTF_LEFTUP;
		static const DWORD FLAG_MOUSEEVENTF_RIGHTDOWN = MOUSEEVENTF_RIGHTDOWN;
		static const DWORD FLAG_MOUSEEVENTF_RIGHTUP = MOUSEEVENTF_RIGHTUP;
		static const DWORD FLAG_MOUSEEVENTF_WHEEL = MOUSEEVENTF_WHEEL;
		static const DWORD FLAG_MOUSEEVENTF_MOVE = MOUSEEVENTF_MOVE;

		static const DWORD VALUE_WHEEL_DELTA = WHEEL_DELTA;

		static void MouseEvent(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo);
	};
}
