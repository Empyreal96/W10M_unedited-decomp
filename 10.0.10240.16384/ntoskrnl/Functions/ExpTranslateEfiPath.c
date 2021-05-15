// ExpTranslateEfiPath 
 
int __fastcall ExpTranslateEfiPath(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r7
  unsigned int v7; // r5
  int v8; // r9
  unsigned int v9; // r0
  int v10; // r10
  unsigned int v11; // r4
  char *v12; // r0
  char *v13; // r6
  int v15; // r4
  unsigned int v16; // r6
  int v17; // r0
  int v18; // r10
  char *v19; // r4
  int v20; // r6
  unsigned int v21; // r0
  int v22; // r1
  int v23; // r1
  int v24; // r0
  unsigned int v25; // r6
  int v26; // r4
  unsigned int v27; // r1
  unsigned int v28; // r3
  char *v29; // r3
  unsigned int v30; // r1
  int v31; // [sp+10h] [bp-70h] BYREF
  unsigned int v32; // [sp+14h] [bp-6Ch] BYREF
  int v33[2]; // [sp+18h] [bp-68h] BYREF
  unsigned int v34; // [sp+20h] [bp-60h] BYREF
  char *v35; // [sp+24h] [bp-5Ch]
  int v36; // [sp+28h] [bp-58h]
  int v37; // [sp+2Ch] [bp-54h]
  unsigned __int64 v38; // [sp+30h] [bp-50h] BYREF
  int v39; // [sp+38h] [bp-48h] BYREF
  char v40[4]; // [sp+40h] [bp-40h] BYREF
  unsigned int v41; // [sp+44h] [bp-3Ch]
  char v42[20]; // [sp+48h] [bp-38h] BYREF
  int v43; // [sp+5Ch] [bp-24h]

  v36 = a3;
  v37 = a4;
  v33[0] = 0;
  v5 = ExpParseEfiPath(a1 + 12, v33, &v32, &v31);
  if ( v5 < 0 )
    return v5;
  RtlInitUnicodeString((unsigned int)v40, 0);
  v6 = 0;
  v7 = v33[0];
  v39 = 0;
  v8 = 0;
  if ( (unsigned __int8)v31 != 1 || a2 == 2 )
    goto LABEL_14;
  v5 = RtlStringFromGUIDEx(v33[0] + 24, (int)&v34, 1);
  if ( v5 < 0 )
    goto LABEL_21;
  v9 = wcslen(L"\\??\\Volume");
  v10 = (unsigned __int16)v34;
  v11 = (unsigned __int16)v34 + 2 * (v9 + 1);
  v12 = (char *)ExAllocatePoolWithTag(512, v11, 1920364101);
  v13 = v12;
  if ( !v12 )
    return sub_815304();
  wcscpy_s(v12, v11 >> 1, (char *)L"\\??\\Volume");
  wcsncat_s(v13, v11 >> 1, v35, v10);
  ExFreePoolWithTag((unsigned int)v35);
  v15 = ExpTranslateSymbolicLink(v13, v40);
  ExFreePoolWithTag((unsigned int)v13);
  if ( v15 < 0 )
  {
LABEL_14:
    v33[0] = *(_DWORD *)(v7 + 4);
    v5 = ExpFindDiskSignature(v7 + 24, v33, &v39, &v34, &v38, v31);
    if ( v5 < 0 )
      goto LABEL_21;
    v18 = v33[0];
    if ( *(_DWORD *)(v7 + 4) == v33[0] )
    {
      v19 = v35;
      v6 = v39;
      if ( *(_DWORD *)(v7 + 8) == v34 && *(char **)(v7 + 12) == v35 && *(_QWORD *)(v7 + 16) == v38 )
        goto LABEL_33;
      if ( ExpGetDriveGeometry(v39, (int)v42) >= 0 )
      {
        v20 = v43;
      }
      else
      {
        v20 = 1;
        v43 = 1;
      }
      if ( !v20 )
        __brkdiv0();
      if ( *(_DWORD *)(v7 + 8) == _rt_udiv64((unsigned int)v20, __PAIR64__((unsigned int)v19, v34))
        && *(_DWORD *)(v7 + 12) == v22
        && *(_DWORD *)(v7 + 16) == _rt_udiv64((unsigned int)v20, v38)
        && *(_DWORD *)(v7 + 20) == v23 )
      {
        v8 = 1;
LABEL_33:
        v24 = ExAllocatePoolWithTag(512, 94, 1920364101);
        v25 = v24;
        if ( !v24 )
          JUMPOUT(0x81530C);
        swprintf_s(v24, 47, (int)L"\\Device\\Harddisk%lu\\Partition%lu", v6, v18);
        v5 = ExpTranslateSymbolicLink(v25, v40);
        ExFreePoolWithTag(v25);
        if ( v5 >= 0 )
          goto LABEL_8;
LABEL_21:
        v21 = v32;
        if ( !v32 )
          goto LABEL_12;
LABEL_24:
        ExFreePoolWithTag(v21);
        goto LABEL_12;
      }
    }
    if ( v32 )
      ExFreePoolWithTag(v32);
    v5 = -1073741811;
    goto LABEL_12;
  }
LABEL_8:
  v16 = v32;
  if ( a2 == 3 )
  {
    v17 = ExpCreateOutputNT(v36, v37, v40, v32);
LABEL_10:
    v5 = v17;
    goto LABEL_11;
  }
  if ( a2 != 2 )
  {
    v17 = ExpCreateOutputARC(v36, v37, v40, v32);
    goto LABEL_10;
  }
  v26 = 1;
  if ( v8 != 1 )
  {
LABEL_40:
    v27 = *(_DWORD *)(v7 + 12);
    v33[0] = *(_DWORD *)(v7 + 4);
    v28 = *(_DWORD *)(v7 + 8);
    v34 = v28 * v26;
    v29 = (char *)((__PAIR64__(v27, v28) * (unsigned int)v26) >> 32);
    v30 = *(_DWORD *)(v7 + 20);
    v35 = v29;
    v38 = __PAIR64__(v30, *(_DWORD *)(v7 + 16)) * (unsigned int)v26;
    v17 = ExpCreateOutputSIGNATURE(v36, v37, v7 + 24, v33, &v34, &v38, v16, (unsigned __int8)v31, v31, v32);
    goto LABEL_10;
  }
  v5 = ExpGetDriveGeometry(v6, (int)v42);
  if ( v5 >= 0 )
  {
    v26 = v43;
    goto LABEL_40;
  }
LABEL_11:
  ExFreePoolWithTag(v41);
  if ( v16 )
  {
    v21 = v16;
    goto LABEL_24;
  }
LABEL_12:
  ExFreePoolWithTag(v7);
  return v5;
}
