// ExpGetPartitionTableInfo 
 
int __fastcall ExpGetPartitionTableInfo(unsigned __int16 *a1, int *a2)
{
  int v3; // r4
  int v4; // r6
  int v5; // r5
  char v7[8]; // [sp+20h] [bp-48h] BYREF
  int v8; // [sp+30h] [bp-38h]
  int v9; // [sp+34h] [bp-34h]
  char *v10; // [sp+38h] [bp-30h]
  int v11; // [sp+3Ch] [bp-2Ch]
  int v12; // [sp+40h] [bp-28h]
  int v13; // [sp+44h] [bp-24h]

  RtlInitUnicodeString((unsigned int)v7, a1);
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v7;
  v12 = 0;
  v13 = 0;
  v3 = ZwOpenFile();
  if ( v3 >= 0 )
  {
    v4 = 2352;
    v5 = ExAllocatePoolWithTag(512, 2352, 1920364101);
    if ( !v5 )
      return sub_8152F4();
    while ( 1 )
    {
      v3 = ZwDeviceIoControlFile();
      if ( v3 >= 0 )
        break;
      ExFreePoolWithTag(v5);
      if ( v3 != -1073741789 )
        goto LABEL_9;
      v4 *= 2;
      v5 = ExAllocatePoolWithTag(512, v4, 1920364101);
      if ( !v5 )
        return sub_8152F4();
    }
    *a2 = v5;
LABEL_9:
    ZwClose();
  }
  return v3;
}
