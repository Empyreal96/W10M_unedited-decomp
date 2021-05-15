// PpDevCfgTraceDeviceStart 
 
_DWORD *__fastcall PpDevCfgTraceDeviceStart(_DWORD *result)
{
  int v1; // r2
  BOOL v2; // r3

  v1 = result[43];
  if ( v1 >= 770 )
  {
    if ( v1 <= 775 )
    {
      v2 = (result[67] & 0x6000) != 0;
      goto LABEL_4;
    }
    if ( v1 == 776 )
      goto LABEL_7;
  }
  v2 = 1;
LABEL_4:
  if ( v2 )
  {
LABEL_7:
    result[114] &= 0xFFFFFFFE;
    result = (_DWORD *)PiDevCfgLogDeviceStarted();
  }
  return result;
}
