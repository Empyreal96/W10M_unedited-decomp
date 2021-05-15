// WmipGetSMBiosTableData 
 
int __fastcall WmipGetSMBiosTableData(int a1, int *a2, _DWORD *a3)
{
  int v5; // r2
  int result; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4

  if ( !a2 )
    return -1073741811;
  if ( a3 )
    *a3 = WmipSMBiosVersionInfo;
  v5 = WmipSMBiosTableLength;
  if ( *a2 >= (unsigned int)WmipSMBiosTableLength )
  {
    if ( WmipSMBiosTablePhysicalAddress )
    {
      v7 = MmMapIoSpaceEx(
             WmipSMBiosTablePhysicalAddress,
             SHIDWORD(WmipSMBiosTablePhysicalAddress),
             WmipSMBiosTableLength,
             4);
      v8 = v7;
      if ( v7 )
      {
        v9 = WmipSMBiosTableLength;
        memmove(a1, v7, WmipSMBiosTableLength);
        MmUnmapIoSpace(v8, v9);
        result = 0;
      }
      else
      {
        result = -1073741670;
      }
      v5 = WmipSMBiosTableLength;
    }
    else
    {
      result = -1073741808;
    }
  }
  else
  {
    result = -1073741789;
  }
  *a2 = v5;
  return result;
}
