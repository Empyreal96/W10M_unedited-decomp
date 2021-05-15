// BiGetVolumeDiskExtentsInformation 
 
int __fastcall BiGetVolumeDiskExtentsInformation(int a1, _DWORD *a2)
{
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r7
  _DWORD *v6; // r5

  v3 = ZwCreateEvent();
  if ( v3 >= 0 )
  {
    v4 = 32;
    v5 = 0;
    while ( 1 )
    {
      v6 = (_DWORD *)ExAllocatePoolWithTag(1, v4, 1262764866);
      if ( !v6 )
        break;
      v3 = ZwDeviceIoControlFile();
      if ( v3 == 259 )
      {
        v3 = ZwWaitForSingleObject();
        if ( v3 >= 0 )
          v3 = 0;
      }
      ZwResetEvent();
      if ( v3 == -1073741789 || v3 == -2147483643 )
      {
        v4 += 24 * *v6;
        ExFreePoolWithTag((unsigned int)v6);
        ++v5;
        v6 = 0;
        if ( v5 < 2 )
          continue;
      }
      goto LABEL_12;
    }
    v3 = -1073741670;
LABEL_12:
    if ( v3 < 0 )
    {
      if ( v6 )
        ExFreePoolWithTag((unsigned int)v6);
    }
    else
    {
      *a2 = v6;
    }
  }
  return v3;
}
