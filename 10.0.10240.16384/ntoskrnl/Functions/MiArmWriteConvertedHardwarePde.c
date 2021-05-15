// MiArmWriteConvertedHardwarePde 
 
int __fastcall MiArmWriteConvertedHardwarePde(int a1, _DWORD *a2, __int16 a3)
{
  int result; // r0

  if ( (a3 & 2) != 0 )
  {
    if ( (a3 & 0x400) != 0 )
      result = MiArmWriteLargePageHardwarePde();
    else
      result = MiArmWriteSimpleHardwarePde();
  }
  else
  {
    *a2 = 0;
    a2[1] = 0;
    a2[2] = 0;
    a2[3] = 0;
  }
  return result;
}
