// PpmInfoRegisterCallbacks 
 
int PpmInfoRegisterCallbacks()
{
  int result; // r0
  unsigned int i; // r4
  _DWORD v2[3]; // [sp+8h] [bp-30h] BYREF
  int v3; // [sp+14h] [bp-24h]
  _DWORD v4[3]; // [sp+18h] [bp-20h] BYREF
  int v5; // [sp+24h] [bp-14h]

  v2[0] = 0;
  v2[1] = 0;
  v2[2] = 0;
  v3 = 0x10000;
  result = 0;
  v4[0] = 0;
  v4[1] = 0;
  v4[2] = 0;
  v5 = 0x20000;
  for ( i = 0; i < KeNumberProcessors_0; ++i )
  {
    HIBYTE(v3) = i;
    HIBYTE(v5) = i;
    PoRegisterPowerSettingCallback(0, v2, (int)PpmPerfProcCapFloorSettingCallback, 0, 0);
    result = PoRegisterPowerSettingCallback(0, v4, (int)PpmPerfProcCapFloorSettingCallback, 0, 0);
  }
  return result;
}
