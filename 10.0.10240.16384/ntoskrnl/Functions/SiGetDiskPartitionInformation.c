// SiGetDiskPartitionInformation 
 
int __fastcall SiGetDiskPartitionInformation(unsigned __int16 *a1)
{
  int v1; // r4
  int result; // r0
  char v3[8]; // [sp+28h] [bp-48h] BYREF
  int v4; // [sp+30h] [bp-40h]
  int v5; // [sp+34h] [bp-3Ch]
  char *v6; // [sp+38h] [bp-38h]
  int v7; // [sp+3Ch] [bp-34h]
  int v8; // [sp+40h] [bp-30h]
  int v9; // [sp+44h] [bp-2Ch]
  int v10; // [sp+48h] [bp-28h]
  int v11; // [sp+4Ch] [bp-24h]
  int v12; // [sp+50h] [bp-20h]
  int v13; // [sp+54h] [bp-1Ch]
  int v14; // [sp+58h] [bp-18h]
  int v15; // [sp+5Ch] [bp-14h]

  RtlInitUnicodeString((unsigned int)v3, a1);
  v4 = 24;
  v5 = 0;
  v7 = 576;
  v6 = v3;
  v8 = 0;
  v9 = 0;
  v1 = ZwOpenFile();
  if ( v1 < 0 )
    goto LABEL_5;
  v10 = 24;
  v11 = 0;
  v13 = 512;
  v12 = 0;
  v14 = 0;
  v15 = 0;
  v1 = ZwCreateEvent();
  if ( v1 < 0 )
    goto LABEL_5;
  ZwResetEvent();
  v1 = ZwDeviceIoControlFile();
  if ( v1 == 259 )
    result = sub_815910();
  else
LABEL_5:
    result = v1;
  return result;
}
