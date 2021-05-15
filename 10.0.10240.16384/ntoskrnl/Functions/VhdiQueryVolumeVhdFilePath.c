// VhdiQueryVolumeVhdFilePath 
 
int __fastcall VhdiQueryVolumeVhdFilePath(int a1)
{
  int v1; // r6
  int v2; // r4
  int v3; // r0

  if ( !a1 )
    goto LABEL_9;
  v1 = 520;
  v2 = ExAllocatePoolWithTag(512, 520, 1113876566);
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = ZwDeviceIoControlFile();
      if ( v3 != -1073741789 )
        break;
      ExFreePoolWithTag(v2);
      v1 *= 2;
      v2 = ExAllocatePoolWithTag(512, v1, 1113876566);
      if ( !v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = -1073741801;
  }
  if ( v3 < 0 && v2 )
  {
    ExFreePoolWithTag(v2);
LABEL_9:
    v2 = 0;
  }
  return v2;
}
