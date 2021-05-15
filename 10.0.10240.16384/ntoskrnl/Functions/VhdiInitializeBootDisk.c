// VhdiInitializeBootDisk 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VhdiInitializeBootDisk(int a1, int a2, unsigned __int16 *a3)
{
  int *v3; // r9 OVERLAPPED
  int v4; // r10 OVERLAPPED
  _DWORD *v5; // r4
  int v6; // r3
  int v7; // r4
  int v8; // r5
  int v9; // r7
  int v10; // r8
  unsigned int v11; // r0
  int v12; // r6
  int i; // r1
  int v14; // r2
  bool v15; // zf
  int v17; // [sp+1Ch] [bp-D4h] BYREF
  _DWORD *v18; // [sp+20h] [bp-D0h]
  unsigned int v19; // [sp+24h] [bp-CCh]
  int v20; // [sp+28h] [bp-C8h]
  int v21; // [sp+2Ch] [bp-C4h]
  char *v22; // [sp+30h] [bp-C0h]
  int v23; // [sp+34h] [bp-BCh]
  int v24; // [sp+38h] [bp-B8h]
  int v25; // [sp+3Ch] [bp-B4h]
  char v26[8]; // [sp+48h] [bp-A8h] BYREF
  unsigned __int16 v27[80]; // [sp+50h] [bp-A0h] BYREF

  v17 = 0;
  if ( !a1 )
    return -1073741811;
  if ( !a2 )
    return -1073741811;
  if ( !a3 )
    return -1073741811;
  *(_QWORD *)&v3 = *(_QWORD *)a2;
  v5 = *(_DWORD **)(a2 + 12);
  v15 = *(_DWORD *)a2 == 0;
  v18 = v5;
  if ( v15 )
    return -1073741811;
  if ( !v4 )
    return -1073741811;
  v6 = *(_DWORD *)(a2 + 8);
  if ( !v6 || !v5 )
    return -1073741811;
  if ( !RtlCreateUnicodeStringFromAsciiz(a3, *(_DWORD *)(a1 + 104), (int)a3, v6) )
    return -1073741823;
  v8 = 0;
  v9 = 0;
  v19 = *IoGetConfigurationInformation();
  v10 = 0;
  if ( !v19 )
    goto LABEL_38;
  while ( 1 )
  {
    v7 = RtlStringCbPrintfW(v27, 0x80u, (int)L"\\Device\\Harddisk%d\\Partition0", v9);
    if ( v7 < 0 )
      goto LABEL_34;
    v7 = RtlInitUnicodeStringEx((int)v26, v27);
    if ( v7 < 0 )
      goto LABEL_34;
    v20 = 24;
    v21 = 0;
    v23 = 576;
    v22 = v26;
    v24 = 0;
    v25 = 0;
    v7 = ZwOpenFile();
    if ( v7 < 0 )
      goto LABEL_34;
    v11 = VhdiQueryVolumeVhdFilePath(0);
    if ( !v11 )
      break;
    ExFreePoolWithTag(v11);
LABEL_34:
    if ( ++v9 >= v19 )
      goto LABEL_37;
  }
  if ( v8 )
    ExFreePoolWithTag(v8);
  v12 = 4096;
  for ( i = 4096; ; i = v12 )
  {
    v8 = ExAllocatePoolWithTag(512, i, 1113876566);
    if ( !v8 )
      break;
    v7 = ZwDeviceIoControlFile();
    if ( v7 != -1073741789 )
      goto LABEL_23;
    ExFreePoolWithTag(v8);
    v12 *= 2;
  }
  v7 = -1073741801;
LABEL_23:
  if ( v7 < 0 )
    goto LABEL_34;
  v14 = *v3;
  if ( *(_DWORD *)v8 == *v3 )
  {
    if ( v14 )
    {
      if ( v14 != 1 )
        goto LABEL_33;
      v15 = RtlCompareMemory((unsigned __int8 *)(v8 + 8), v4, 16) == 16;
    }
    else
    {
      v15 = RtlCompareMemory((unsigned __int8 *)(v8 + 8), v4, 4) == 4;
    }
    if ( v15 )
    {
      v7 = VhdiGetPartitionNumber((int *)v8, (int)v3, &v17);
      if ( v7 >= 0 )
        v10 = 1;
    }
  }
LABEL_33:
  if ( !v10 )
    goto LABEL_34;
  v7 = VhdiGetVolumeNumber(0, v9, v17, v18);
LABEL_37:
  if ( !v10 )
LABEL_38:
    v7 = -1073741810;
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
