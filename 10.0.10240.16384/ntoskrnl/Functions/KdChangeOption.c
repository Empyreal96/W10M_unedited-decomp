// KdChangeOption 
 
int __fastcall KdChangeOption(int a1, int a2, char *a3, int a4, int a5, _DWORD *a6)
{
  int result; // r0

  if ( KdPitchDebugger )
    return -1073740972;
  if ( a1 )
  {
    result = -1073741821;
  }
  else
  {
    if ( a2 != 1 || a4 || a5 )
      return -1073741811;
    if ( (KdBlockEnable & 0x80) != 0 )
      return -1073741790;
    result = 0;
    KdBlockEnable = *a3;
  }
  if ( a6 )
    *a6 = 0;
  return result;
}
