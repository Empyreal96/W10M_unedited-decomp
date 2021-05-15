// BiGetNtPartitionPath 
 
int __fastcall BiGetNtPartitionPath(int a1, unsigned __int16 **a2)
{
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r8
  unsigned __int16 *v5; // r5
  _DWORD *v7; // r7
  int v8; // r4
  unsigned int v9; // r10
  int v10; // r9
  int v11; // r9
  unsigned int v12; // r10
  int v13; // r3
  int v14; // r7
  int v15; // r1
  int v16; // r2
  bool v17; // zf
  int v18; // r1
  int v19; // r2
  unsigned __int16 *v20; // r0
  __int64 v21; // kr00_8
  unsigned __int16 *v22; // r0
  unsigned int v23; // [sp+8h] [bp-B0h]
  _DWORD *v24; // [sp+Ch] [bp-ACh] BYREF
  int v25; // [sp+10h] [bp-A8h]
  unsigned int v26; // [sp+14h] [bp-A4h] BYREF
  int v27; // [sp+18h] [bp-A0h]
  int v28; // [sp+1Ch] [bp-9Ch]
  unsigned __int16 *v29; // [sp+20h] [bp-98h] BYREF
  _DWORD *v30; // [sp+24h] [bp-94h] BYREF
  unsigned __int16 **v31; // [sp+2Ch] [bp-8Ch]
  int v32; // [sp+30h] [bp-88h]
  int v33; // [sp+34h] [bp-84h]
  char *v34; // [sp+38h] [bp-80h]
  int v35; // [sp+3Ch] [bp-7Ch]
  int v36; // [sp+40h] [bp-78h]
  int v37; // [sp+44h] [bp-74h]
  char v38[8]; // [sp+48h] [bp-70h] BYREF
  unsigned int v39; // [sp+58h] [bp-60h]
  char v40[4]; // [sp+70h] [bp-48h] BYREF
  char v41[68]; // [sp+74h] [bp-44h] BYREF

  v29 = 0;
  v25 = 0;
  v31 = a2;
  v2 = 0;
  v3 = BiVerifyBootPartition(a1, &v24, &v30);
  v4 = v25;
  if ( v3 < 0 )
    goto LABEL_36;
  v3 = ZwQuerySystemInformation();
  if ( v3 < 0 )
    goto LABEL_36;
  v5 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 106, 1262764866);
  if ( !v5 )
    return sub_81417C();
  v7 = v24;
  v25 = 0;
  if ( v4 && !v24 && !v30 )
    v25 = 1;
  v8 = 0;
  v9 = 0;
  v23 = 0;
  if ( !v39 )
    goto LABEL_64;
  v10 = v27;
  while ( BiGetDriveLayoutBlock(v9, &v26, v40) < 0 )
  {
LABEL_62:
    v23 = ++v9;
    if ( v9 >= v39 )
      goto LABEL_32;
  }
  if ( !v4 && memcmp(v10 + 4, (unsigned int)v41, 20) )
  {
    ExFreePoolWithTag(v26);
    goto LABEL_62;
  }
  v11 = *(_DWORD *)(v10 + 4);
  if ( v30 )
  {
    if ( v11 == 1 )
    {
      swprintf_s((int)v5, 53, (int)L"\\Device\\Harddisk%lu\\Partition%lu", v9, *v30, 0);
      RtlInitUnicodeString((unsigned int)v38, v5);
      v32 = 24;
      v33 = 0;
      v35 = 576;
      v34 = v38;
      v36 = 0;
      v37 = 0;
      if ( ZwOpenFile() >= 0 )
      {
        ZwClose();
        v8 = 1;
      }
      goto LABEL_31;
    }
LABEL_13:
    if ( v11 )
      goto LABEL_31;
  }
  else if ( v11 != 1 )
  {
    goto LABEL_13;
  }
  v12 = 0;
  if ( !v11 )
  {
    if ( v30 )
    {
      v12 = (unsigned int)v30;
    }
    else if ( v7 )
    {
      v12 = (unsigned int)v7;
    }
  }
  v13 = *(_DWORD *)(v26 + 4);
  v28 = 0;
  if ( !v13 )
    goto LABEL_30;
  v14 = v26 + 48;
  while ( 2 )
  {
    if ( !*(_DWORD *)(v14 + 24) )
      goto LABEL_26;
    swprintf_s((int)v5, 53, (int)L"\\Device\\Harddisk%lu\\Partition%lu", v23, *(_DWORD *)(v14 + 24));
    if ( !v25 || (v20 = (unsigned __int16 *)BiGetPartitionVhdFilePath(v5, v15, v16, v25), (v2 = (unsigned int)v20) == 0) )
    {
LABEL_22:
      if ( v11 == 1 )
      {
        if ( v24 )
        {
          v21 = *(_QWORD *)(v14 + 8);
          if ( *v24 == (_DWORD)v21 )
          {
            v17 = v24[1] == HIDWORD(v21);
LABEL_25:
            if ( v17 )
              goto LABEL_28;
            goto LABEL_26;
          }
        }
      }
      else if ( v12 )
      {
        v17 = memcmp(v12, v14 + 48, 16) == 0;
        goto LABEL_25;
      }
LABEL_26:
      v14 += 144;
      if ( (unsigned int)++v28 >= *(_DWORD *)(v26 + 4) )
        goto LABEL_29;
      continue;
    }
    break;
  }
  if ( wcsicmp(v4, v20) )
  {
    ExFreePoolWithTag(v2);
    v2 = 0;
    goto LABEL_22;
  }
LABEL_28:
  v8 = 1;
LABEL_29:
  v7 = v24;
LABEL_30:
  v9 = v23;
LABEL_31:
  ExFreePoolWithTag(v26);
  if ( v4 )
  {
    if ( v8 && !v25 )
    {
      v22 = (unsigned __int16 *)BiGetPartitionVhdFilePath(v5, v18, v19, 0);
      v2 = (unsigned int)v22;
      if ( v22 )
      {
        if ( !wcsicmp(v4, v22) )
          goto LABEL_32;
        ExFreePoolWithTag(v2);
        v2 = 0;
      }
      v8 = 0;
    }
    v10 = v27;
    goto LABEL_62;
  }
LABEL_32:
  if ( !v8 )
  {
LABEL_64:
    v3 = -1073741811;
    ExFreePoolWithTag((unsigned int)v5);
    goto LABEL_36;
  }
  if ( BiTranslateSymbolicLink(v5, &v29) >= 0 )
  {
    ExFreePoolWithTag((unsigned int)v5);
    v5 = v29;
  }
  v3 = 0;
  *v31 = v5;
LABEL_36:
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v3;
}
