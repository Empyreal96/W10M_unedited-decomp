// SiGetSystemPartition 
 
int __fastcall SiGetSystemPartition(int a1, unsigned int *a2, int a3, int a4)
{
  int v6; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a4;
  if ( SiIsWinPEBoot() || (v6 = SiGetFirmwareBootDeviceName(1, a2), v6 < 0) )
  {
    if ( a1 != 2 )
      return sub_81576C();
    v6 = SiGetEfiSystemDevice(1);
    if ( v6 >= 0 )
    {
      v6 = SiTranslateSymbolicLink(*a2, v8);
      if ( v6 < 0 )
      {
        v6 = 0;
      }
      else
      {
        ExFreePoolWithTag(*a2);
        *a2 = v8[0];
      }
    }
  }
  return v6;
}
