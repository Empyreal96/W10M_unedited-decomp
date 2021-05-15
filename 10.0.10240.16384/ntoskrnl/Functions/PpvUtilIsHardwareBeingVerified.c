// PpvUtilIsHardwareBeingVerified 
 
BOOL __fastcall PpvUtilIsHardwareBeingVerified(int a1)
{
  int v1; // r3
  int v2; // r3
  BOOL result; // r0

  result = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    if ( v1 )
    {
      v2 = *(_DWORD *)(v1 + 268);
      if ( (v2 & 0x20000) == 0 && (v2 & 0x8000) != 0 )
        result = 1;
    }
  }
  return result;
}
