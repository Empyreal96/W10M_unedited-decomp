// SiGetSystemDisk 
 
int __fastcall SiGetSystemDisk(int a1, unsigned __int16 **a2, int a3, int a4)
{
  int v6; // r4
  unsigned __int16 *v8; // [sp+0h] [bp-10h] BYREF

  v8 = (unsigned __int16 *)a4;
  if ( SiIsWinPEBoot(a1) || (v6 = SiGetFirmwareBootDeviceName(0, a2), v6 < 0) )
  {
    v6 = SiGetDefaultSystemDisk(a1, a2);
    if ( v6 >= 0 )
    {
      v6 = SiTranslateSymbolicLink(*a2, &v8);
      if ( v6 < 0 )
      {
        v6 = 0;
      }
      else
      {
        ExFreePoolWithTag((unsigned int)*a2);
        *a2 = v8;
      }
    }
  }
  return v6;
}
