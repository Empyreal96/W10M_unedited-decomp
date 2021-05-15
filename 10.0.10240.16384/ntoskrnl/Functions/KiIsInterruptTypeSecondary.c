// KiIsInterruptTypeSecondary 
 
int __fastcall KiIsInterruptTypeSecondary(_DWORD *a1)
{
  int result; // r0

  if ( KiSecondaryInterruptServicesEnabled && *a1 == 1 )
    result = off_617A68(a1[2], a1[14]);
  else
    result = 0;
  return result;
}
