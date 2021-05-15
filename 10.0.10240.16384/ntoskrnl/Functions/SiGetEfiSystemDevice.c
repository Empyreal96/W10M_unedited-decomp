// SiGetEfiSystemDevice 
 
int __fastcall SiGetEfiSystemDevice(int a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // r8
  unsigned int v4; // r7
  int v5; // r4
  _WORD *v6; // r9
  _WORD *v7; // r5
  int v9; // r4
  int v10; // r8
  int v11; // r0
  _WORD *v12; // r4
  int v13; // t1
  int v14; // r0
  _DWORD *v15; // r8
  unsigned int v16; // r10
  const __int16 *v17; // r2
  int v18; // r3
  _DWORD *v19; // [sp+10h] [bp-68h] BYREF
  unsigned int v20; // [sp+14h] [bp-64h]
  int v21; // [sp+18h] [bp-60h]
  int v22; // [sp+1Ch] [bp-5Ch]
  int v23; // [sp+20h] [bp-58h]
  _DWORD *v24; // [sp+24h] [bp-54h]
  int v25[4]; // [sp+28h] [bp-50h] BYREF
  char v26[8]; // [sp+38h] [bp-40h] BYREF
  int v27; // [sp+40h] [bp-38h]
  int v28; // [sp+44h] [bp-34h]
  char *v29; // [sp+48h] [bp-30h]
  int v30; // [sp+4Ch] [bp-2Ch]
  int v31; // [sp+50h] [bp-28h]
  int v32; // [sp+54h] [bp-24h]

  v3 = a3;
  v24 = a3;
  v25[2] = a1;
  v4 = 0;
  v5 = 0;
  v21 = 0;
  v22 = 0;
  v6 = 0;
  v19 = 0;
  v20 = 0;
  v23 = 0;
  v25[0] = 0;
  v7 = (_WORD *)ExAllocatePoolWithTag(1, 106, 1263556947);
  if ( !v7 )
    return sub_815828();
  if ( SiDisambiguateSystemDevice((int)v25) >= 0 )
    goto LABEL_41;
  RtlInitUnicodeString((unsigned int)v26, L"\\Device");
  v27 = 24;
  v28 = 0;
  v30 = 576;
  v29 = v26;
  v31 = 0;
  v32 = 0;
  v9 = ZwOpenDirectoryObject();
  if ( v9 < 0 )
    goto LABEL_15;
  v10 = 4096;
  v6 = (_WORD *)ExAllocatePoolWithTag(1, 4096, 1263556947);
  if ( !v6 )
  {
LABEL_8:
    v9 = -1073741801;
    goto LABEL_15;
  }
  while ( 1 )
  {
    v25[1] = 0;
    v11 = ZwQueryDirectoryObject();
    v9 = v11;
    if ( v11 != 261 )
      break;
    ExFreePoolWithTag((unsigned int)v6);
    v10 += 4096;
    v6 = (_WORD *)ExAllocatePoolWithTag(1, v10, 1263556947);
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v11 < 0 && v11 != -2147483622 )
  {
LABEL_39:
    if ( v9 < 0 )
      goto LABEL_15;
    v5 = v23;
    v3 = v24;
LABEL_41:
    if ( v5 )
    {
      v17 = L"\\Device\\%s\\Partition%lu";
      v18 = v5;
    }
    else
    {
      v17 = L"\\Device\\Harddisk%lu\\Partition%lu";
      v18 = v25[0];
    }
    v9 = RtlStringCbPrintfW(v7, 0x6Au, (int)v17, v18);
    if ( v9 >= 0 )
    {
      *v3 = v7;
      goto LABEL_16;
    }
LABEL_15:
    ExFreePoolWithTag((unsigned int)v7);
    goto LABEL_16;
  }
  v12 = v6;
  if ( !*v6 )
  {
LABEL_14:
    v9 = -1073740718;
    goto LABEL_15;
  }
  while ( 1 )
  {
    if ( SiIsValidDiskDevice(*((_DWORD *)v12 + 1), *((_DWORD *)v12 + 3)) )
    {
      RtlStringCbPrintfW(v7, 0x6Au, (int)L"\\Device\\%s\\Partition%lu", *((_DWORD *)v12 + 1));
      if ( v4 )
      {
        ExFreePoolWithTag(v4);
        v19 = 0;
      }
      v14 = SiGetDriveLayoutInformation(v7, &v19);
      v4 = (unsigned int)v19;
      if ( v14 >= 0 && *v19 == 1 )
      {
        v15 = v19 + 12;
        v16 = 0;
        v20 = v19[1];
        if ( v20 )
          break;
      }
    }
LABEL_12:
    v13 = (unsigned __int16)v12[8];
    v12 += 8;
    if ( !v13 )
    {
      if ( v21 )
      {
        v9 = 0;
        goto LABEL_39;
      }
      goto LABEL_14;
    }
  }
  while ( memcmp((unsigned int)(v15 + 8), (unsigned int)PARTITION_SYSTEM_GUID, 16) )
  {
LABEL_29:
    ++v16;
    v15 += 36;
    if ( v16 >= v20 )
      goto LABEL_12;
  }
  if ( !v21 )
  {
    v21 = 1;
    v23 = *((_DWORD *)v12 + 1);
    goto LABEL_29;
  }
  v9 = SiGetEspFromFirmware(v7);
  if ( v9 < 0 )
  {
    v9 = -1073740719;
    goto LABEL_15;
  }
  *v24 = v7;
LABEL_16:
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  if ( v22 )
    ZwClose();
  return v9;
}
