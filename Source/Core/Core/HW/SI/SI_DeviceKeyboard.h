// Copyright 2015 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Core/HW/SI/SI_Device.h"

class PointerWrap;
struct KeyboardStatus;

namespace SerialInterface
{
class CSIDevice_Keyboard : public ISIDevice
{
public:
  // Constructor
  CSIDevice_Keyboard(SIDevices device, int device_number);

  // Run the SI Buffer
  int RunBuffer(u8* buffer, int request_length) override;

  // Return true on new data
  bool GetData(u32& hi, u32& low) override;

  KeyboardStatus GetKeyboardStatus() const;
  void MapKeys(const KeyboardStatus& key_status, u8* key);

  // Send a command directly
  void SendCommand(u32 command, u8 poll) override;

  // Savestate support
  void DoState(PointerWrap& p) override;

protected:
  // PADAnalogMode
  u8 m_mode = 0;

  // Internal counter synchonizing GC and keyboard
  u8 m_counter = 0;
};
}  // namespace SerialInterface
