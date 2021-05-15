// _CmDeviceClassesSubkeyCallback 
 
int __fastcall CmDeviceClassesSubkeyCallback(int *a1, int a2, unsigned __int16 *a3, int a4)
{
  unsigned int v5; // r9
  char *v6; // r6
  unsigned int v8; // r10
  int v10; // r9
  unsigned int v11; // r1
  int *v12; // r4
  int v13; // r1
  _BYTE *v14; // r0
  int v15; // r9
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r9
  unsigned int v19; // r4
  int (__fastcall *v20)(int, char *, int, _DWORD, int, int *); // r7
  unsigned int v21; // r1
  int v22; // [sp+0h] [bp-50h]
  int *v23; // [sp+4h] [bp-4Ch]
  char v24[4]; // [sp+8h] [bp-48h] BYREF
  int *v25; // [sp+Ch] [bp-44h]
  int v26; // [sp+10h] [bp-40h] BYREF
  int v27; // [sp+18h] [bp-38h]
  int *v28; // [sp+20h] [bp-30h] BYREF
  int v29[10]; // [sp+28h] [bp-28h] BYREF

  v5 = *(_DWORD *)a4;
  v6 = 0;
  v27 = a2;
  v25 = a1;
  v26 = 0;
  v8 = 0;
  v28 = 0;
  if ( v5 == 1 )
  {
    if ( wcslen(a3) != 38 || *a3 != 123 )
      return 0;
  }
  else
  {
    if ( v5 - 2 > 1 )
      goto LABEL_6;
    if ( !wcslen(a3) || *a3 != 35 )
      return 0;
  }
  a1 = v25;
  a2 = v27;
LABEL_6:
  if ( v5 < 3 || v5 == 3 && *(_BYTE *)(a4 + 1420) )
  {
    v23 = &v26;
    v22 = 131097;
    a1 = (int *)PnpCtxRegOpenKey(a1, a2, (int)a3, 8);
    if ( a1 == (int *)-1073741444 || (int)a1 < 0 )
      goto LABEL_31;
  }
  if ( *(_DWORD *)a4 < 3u )
  {
    if ( *(_DWORD *)a4 == 2 && *(_WORD *)(a4 + 1012) )
      return sub_811C40();
    goto LABEL_13;
  }
  if ( *(_DWORD *)a4 != 3 || (a1 = (int *)wcslen(a3), (unsigned int)a1 <= 1) || *a3 != 35 )
  {
LABEL_13:
    v10 = 0;
    goto LABEL_14;
  }
  v10 = 1;
LABEL_14:
  if ( *(_DWORD *)a4 < 2u )
    goto LABEL_24;
  a1 = (int *)ExAllocatePoolWithTag(1, 1008, 1380994640);
  v6 = (char *)a1;
  if ( a1 )
  {
    v11 = 504;
    if ( *(_WORD *)(a4 + 4) )
    {
      a1 = (int *)RtlStringCchCopyExW(a1, 504, a4 + 4, &v28, v29, 2304);
      if ( (int)a1 < 0 )
        goto LABEL_29;
      v12 = v28;
      v13 = v29[0];
      *(_WORD *)v28 = 0;
      v11 = v13 - 1;
    }
    else
    {
      v12 = a1;
    }
    if ( *(_DWORD *)a4 == 2 || v10 == 1 )
    {
      a1 = (int *)RtlStringCchCopyW(v12, v11, (int)a3);
      if ( (int)a1 < 0 )
        goto LABEL_29;
      if ( v10 == 1 )
        *(_WORD *)v12 = 92;
    }
LABEL_24:
    if ( *(_DWORD *)a4 >= 3u )
    {
      strcpy(v6, "\\\\?\\");
      if ( CmValidateDeviceInterfaceName((int)a1, (unsigned __int16 *)v6) >= 0
        && RtlInitUnicodeStringEx((int)v29, (unsigned __int16 *)v6) >= 0 )
      {
        v18 = (int)v25;
        v19 = HIWORD(v29[0]) >> 1;
        if ( !*(_BYTE *)(a4 + 1420)
          || CmIsDeviceInterfaceEnabled((int)v25, (unsigned __int16 *)v6, v17, (int)v24) >= 0 && v24[0] )
        {
          v20 = *(int (__fastcall **)(int, char *, int, _DWORD, int, int *))(a4 + 1424);
          if ( !v20 || v20(v18, v6, 3, *(_DWORD *)(a4 + 1428), v22, v23) )
          {
            v21 = *(_DWORD *)(a4 + 1436);
            *(_DWORD *)(a4 + 1440) += v19;
            if ( v21 > v19 )
            {
              RtlStringCchCopyExW(*(_WORD **)(a4 + 1432), v21, v6);
              *(_DWORD *)(a4 + 1432) += 2 * v19;
              v16 = *(_DWORD *)(a4 + 1436) - v19;
LABEL_27:
              *(_DWORD *)(a4 + 1436) = v16;
              if ( v8 )
                ExFreePoolWithTag(v8);
              goto LABEL_29;
            }
          }
        }
      }
    }
    else
    {
      v14 = (_BYTE *)ExAllocatePoolWithTag(1, 1444, 1380994640);
      v8 = (unsigned int)v14;
      if ( v14 )
      {
        memset(v14, 0, 1444);
        *(_DWORD *)v8 = *(_DWORD *)a4 + 1;
        RtlStringCchCopyExW((_WORD *)(v8 + 4), 504, v6, 0, 0, 2304);
        RtlStringCchCopyExW((_WORD *)(v8 + 1012), 200, a4 + 1012, 0, 0, 2304);
        v15 = (int)v25;
        *(_DWORD *)(v8 + 1412) = *(_DWORD *)(a4 + 1412);
        *(_DWORD *)(v8 + 1416) = *(_DWORD *)(a4 + 1416);
        *(_BYTE *)(v8 + 1420) = *(_BYTE *)(a4 + 1420);
        *(_DWORD *)(v8 + 1424) = *(_DWORD *)(a4 + 1424);
        *(_DWORD *)(v8 + 1428) = *(_DWORD *)(a4 + 1428);
        *(_DWORD *)(v8 + 1432) = *(_DWORD *)(a4 + 1432);
        *(_DWORD *)(v8 + 1436) = *(_DWORD *)(a4 + 1436);
        *(_DWORD *)(v8 + 1440) = *(_DWORD *)(a4 + 1440);
        PnpCtxRegEnumKeyWithCallback(v15, v26, CmDeviceClassesSubkeyCallback, v8);
        *(_DWORD *)(a4 + 1412) = *(_DWORD *)(v8 + 1412);
        *(_DWORD *)(a4 + 1416) = *(_DWORD *)(v8 + 1416);
        *(_DWORD *)(a4 + 1440) = *(_DWORD *)(v8 + 1440);
        *(_DWORD *)(a4 + 1432) = *(_DWORD *)(v8 + 1432);
        v16 = *(_DWORD *)(v8 + 1436);
        goto LABEL_27;
      }
    }
LABEL_29:
    if ( v6 )
      ExFreePoolWithTag((unsigned int)v6);
  }
LABEL_31:
  if ( v26 )
    ZwClose();
  return 0;
}
