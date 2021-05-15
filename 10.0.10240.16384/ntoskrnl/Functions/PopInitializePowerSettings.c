// PopInitializePowerSettings 
 
void PopInitializePowerSettings()
{
  _DWORD *v0; // r3
  int v1; // r2

  v0 = &PopSessionSpecificLists;
  v1 = 2;
  do
  {
    *v0 = v0;
    v0[1] = v0;
    v0 += 2;
    --v1;
  }
  while ( v1 );
  PopSettingLock = 1;
  dword_61F324 = 0;
  unk_61F328 = 0;
  byte_61F32C = 1;
  byte_61F32D = 0;
  byte_61F32E = 4;
  dword_61F330 = 0;
  dword_61F338 = (int)&dword_61F334;
  dword_61F334 = (int)&dword_61F334;
  PopRegisteredPowerSettingCallbacks = (int)&PopRegisteredPowerSettingCallbacks;
  dword_61E6DC = (int)&PopRegisteredPowerSettingCallbacks;
  PopPowerSettings = (int)&PopPowerSettings;
  *(_DWORD *)algn_61E6D4 = &PopPowerSettings;
}
