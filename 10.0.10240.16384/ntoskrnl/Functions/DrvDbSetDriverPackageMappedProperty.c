// DrvDbSetDriverPackageMappedProperty 
 
int __fastcall DrvDbSetDriverPackageMappedProperty(int **a1, int a2, int a3, unsigned int a4, int (*a5)[4], _DWORD *a6, unsigned int a7)
{
  int v8; // r4
  int v9; // r6
  int v11; // r4
  int v12; // r10
  int v13; // r4
  int (**v14)[4]; // r9
  unsigned int v15; // r0
  int (*v16)[4]; // t1
  int v17; // r0
  int (**v19)[4]; // r8
  int (*v20)[4]; // r2
  bool v21; // zf
  int v22; // r0
  _BYTE *v23; // r6
  int v24; // r1
  int v25; // r0
  __int64 v26; // kr00_8
  _BYTE *v27; // r0
  int v28; // r0
  int v29; // r2
  int v30; // r1
  int *v31; // r0
  int v32; // r1
  int v33; // r4
  int v34; // r2
  int v35; // r2
  int v36; // r2
  int v37; // r6
  int v38; // r1
  int v39; // r2
  int v40; // r1
  int v41; // [sp+10h] [bp-38h] BYREF
  int **v42; // [sp+14h] [bp-34h]
  int v43; // [sp+18h] [bp-30h] BYREF
  unsigned int v44; // [sp+1Ch] [bp-2Ch] BYREF
  int v45; // [sp+20h] [bp-28h] BYREF
  int *v46; // [sp+24h] [bp-24h]

  v8 = *(_DWORD *)(a4 + 16);
  v9 = 0;
  v42 = a1;
  v43 = a2;
  v41 = 0;
  v46 = 0;
  if ( v8 == 18 && !memcmp(a4, (unsigned int)DEVPKEY_DriverPackage_Configurable, 16) )
    return -1073741790;
  v12 = *(_DWORD *)(a4 + 16);
  v13 = 0;
  v14 = &off_402398;
  while ( 1 )
  {
    v16 = *v14;
    v14 += 6;
    v15 = (unsigned int)v16;
    if ( (*v16)[4] == v12 )
    {
      v17 = memcmp(v15, a4, 16);
      if ( !v17 )
        break;
    }
    if ( (unsigned int)++v13 >= 0x1A )
      return -1073741802;
  }
  v19 = &off_402398 + 6 * v13;
  if ( !v19 )
    return -1073741802;
  if ( a5 != v19[1] && a5 )
    return -1073741811;
  if ( a3 )
  {
LABEL_17:
    v20 = v19[5];
    if ( v20 )
    {
      if ( a5 )
        v21 = a7 == (_DWORD)v20;
      else
        v21 = a7 == 0;
      if ( !v21 )
      {
        v11 = -1073741823;
        goto LABEL_108;
      }
      v44 = 48;
      v22 = ExAllocatePoolWithTag(1, 48, 1111770192);
      v23 = (_BYTE *)v22;
      if ( !v22 )
        goto LABEL_24;
      if ( a3 )
        v24 = a3;
      else
        v24 = v41;
      v25 = PnpCtxRegQueryValue(v22, v24, L"Version", &v43, v22, &v44);
      v11 = v25;
      if ( v25 == -1073741772 )
      {
        memset(v23, 0, 48);
        goto LABEL_35;
      }
      if ( v25 == -1073741789 )
      {
        v11 = -1073741595;
      }
      else if ( v25 >= 0 )
      {
        if ( v43 == 3 && v44 == 48 )
        {
LABEL_35:
          v26 = *((_QWORD *)v19 + 2);
          if ( a5 )
            v27 = (_BYTE *)memmove((int)&v23[v26], (int)a6, HIDWORD(v26));
          else
            v27 = memset(&v23[v26], 0, SHIDWORD(v26));
          if ( !a3 )
            a3 = v41;
          v28 = PnpCtxRegSetValue((int)v27, a3, (int)L"Version", 3, (int)v23, 48);
LABEL_102:
          v11 = v28;
          goto LABEL_103;
        }
        v11 = -1073741823;
      }
LABEL_103:
      if ( v23 )
        ExFreePoolWithTag((unsigned int)v23);
      if ( v46 )
        ExFreePoolWithTag((unsigned int)v46);
      goto LABEL_107;
    }
    if ( *(_DWORD *)(a4 + 16) == 7 )
    {
      v17 = memcmp(a4, (unsigned int)DEVPKEY_DriverPackage_SignerName, 16);
      if ( !v17 && a5 == (int (*)[4])18 && a7 > 2 && a6 && !*((_WORD *)a6 + (a7 >> 1) - 1) )
      {
        v17 = wcsicmp((int)a6, L"Microsoft Windows");
        if ( !v17 )
        {
          if ( a3 )
            v29 = a3;
          else
            v29 = v41;
          v17 = DrvDbGetDriverPackageSignerScore(v42, v43, v29, &v45);
          if ( v17 >= 0 && v45 == 218103811 )
          {
            if ( !a3 )
              a3 = v41;
            v11 = DrvDbSetRegValueMappedProperty(v17, a3);
            if ( v11 != -1073741275 )
              goto LABEL_107;
LABEL_57:
            v11 = 0;
            goto LABEL_107;
          }
          goto LABEL_81;
        }
        v9 = v41;
      }
    }
    if ( *(_DWORD *)(a4 + 16) != 8 )
      goto LABEL_99;
    v17 = memcmp(a4, (unsigned int)DEVPKEY_DriverPackage_SignerScore, 16);
    if ( v17 )
      goto LABEL_99;
    if ( a5 == (int (*)[4])7 )
    {
      if ( a7 != 4 || !a6 )
        goto LABEL_99;
      if ( *a6 == 218103811 )
      {
        if ( a3 )
          v9 = a3;
        v17 = DrvDbGetDriverPackageSignerName(0, v30, v9, 0, 0, &v44);
        if ( v17 == -1073741789 && v44 == 18 )
        {
          v31 = (int *)ExAllocatePoolWithTag(1, 36, 1111770192);
          v33 = (int)v31;
          v46 = v31;
          if ( !v31 )
          {
LABEL_24:
            v11 = -1073741801;
            goto LABEL_107;
          }
          if ( a3 )
            v34 = a3;
          else
            v34 = v41;
          v17 = DrvDbGetDriverPackageSignerName((int)v31, v32, v34, v31, 18, &v44);
          if ( v17 >= 0 )
          {
            if ( v44 )
            {
              if ( !*(_WORD *)(v33 + 2 * v44 - 2) )
              {
                v17 = wcsicmp(v33, L"Microsoft Windows");
                if ( !v17 )
                {
                  if ( a3 )
                    v35 = a3;
                  else
                    v35 = v41;
                  v17 = DrvDbSetDriverPackageMappedProperty(v42, v43, v35, DEVPKEY_DriverPackage_SignerName);
                }
              }
            }
          }
        }
LABEL_81:
        v9 = v41;
LABEL_99:
        if ( !a3 )
          a3 = v9;
        v28 = DrvDbSetRegValueMappedProperty(v17, a3);
        v23 = 0;
        goto LABEL_102;
      }
    }
    else if ( a5 )
    {
      goto LABEL_99;
    }
    if ( a3 )
      v9 = a3;
    v36 = v9;
    v37 = v43;
    v17 = DrvDbGetDriverPackageSignerScore(v42, v43, v36, &v45);
    if ( v17 >= 0 && v45 == 218103811 )
    {
      v39 = a3 ? a3 : v41;
      v17 = DrvDbGetDriverPackageSignerName(v17, v38, v39, 0, 0, &v44);
      if ( v17 == -1073741275 )
      {
        if ( a3 )
          v40 = a3;
        else
          v40 = v41;
        v11 = DrvDbSetRegValueMappedProperty(-1073741275, v40);
        if ( v11 < 0 )
          goto LABEL_107;
        if ( !a3 )
          a3 = v41;
        DrvDbSetDriverPackageMappedProperty(v42, v37, a3, DEVPKEY_DriverPackage_SignerName);
        goto LABEL_57;
      }
    }
    goto LABEL_81;
  }
  v17 = DrvDbOpenObjectRegKey(v42, 0, 2, v43, 3, 0, (int)&v41, 0);
  v11 = v17;
  if ( v17 >= 0 )
  {
    v9 = v41;
    goto LABEL_17;
  }
LABEL_107:
  v9 = v41;
LABEL_108:
  if ( v9 )
    ZwClose();
  return v11;
}
