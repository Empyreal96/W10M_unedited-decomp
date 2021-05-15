// BiGetPartitionVhdFilePathFromUnicodeString 
 
int __fastcall BiGetPartitionVhdFilePathFromUnicodeString(int a1)
{
  int *v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int v6[23]; // [sp+24h] [bp-5Ch] BYREF

  v6[3] = 24;
  v6[4] = 0;
  v6[5] = a1;
  v6[6] = 576;
  v6[7] = 0;
  v6[8] = 0;
  v1 = 0;
  if ( ZwOpenFile() >= 0 )
  {
    v6[9] = 24;
    v6[10] = 0;
    v6[12] = 512;
    v6[11] = 0;
    v6[13] = 0;
    v6[14] = 0;
    if ( ZwCreateEvent() >= 0 )
    {
      v2 = 1;
      v3 = 520;
      while ( 1 )
      {
        v1 = (int *)ExAllocatePoolWithTag(1, v3, 1262764866);
        if ( !v1 )
          break;
        v4 = ZwDeviceIoControlFile();
        if ( v4 == 259 )
          return sub_813450();
        if ( v4 != -1073741789 )
          goto LABEL_8;
        if ( v2 != 1 )
          goto LABEL_9;
        v3 = *v1;
        ExFreePoolWithTag((unsigned int)v1);
        v2 = 2;
      }
      v4 = -1073741801;
LABEL_8:
      if ( v4 < 0 )
      {
LABEL_9:
        if ( v1 )
        {
          ExFreePoolWithTag((unsigned int)v1);
          v1 = 0;
        }
        return (int)v1;
      }
      if ( BiTranslateSymbolicLinkFile(v1, v6) >= 0 )
      {
        ExFreePoolWithTag((unsigned int)v1);
        v1 = (int *)v6[0];
      }
    }
  }
  return (int)v1;
}
