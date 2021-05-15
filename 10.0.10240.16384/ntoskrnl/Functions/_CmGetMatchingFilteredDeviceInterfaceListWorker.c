// _CmGetMatchingFilteredDeviceInterfaceListWorker 
 
int __fastcall CmGetMatchingFilteredDeviceInterfaceListWorker(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, _WORD *a7, unsigned int a8, unsigned int *a9, __int16 a10)
{
  unsigned int v10; // r5
  int v14; // r4
  int v15; // r8
  int v16; // r0
  _BYTE *v17; // r0
  unsigned int v18; // r0
  unsigned int v19; // r3
  unsigned int v20; // r3
  int v21; // [sp+Ch] [bp-34h] BYREF
  int v22; // [sp+10h] [bp-30h]
  int v23; // [sp+14h] [bp-2Ch]
  __int16 v24; // [sp+18h] [bp-28h] BYREF
  int v25; // [sp+1Ah] [bp-26h]
  __int16 v26; // [sp+1Eh] [bp-22h]

  v23 = a3;
  v21 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v22 = 0;
  v10 = 0;
  *a9 = 0;
  if ( a8 )
    *a7 = 0;
  if ( (a4 & 0xFFFFFFFE) != 0 || a10 )
    return sub_811B54();
  if ( (a4 & 1) != 0 )
    v22 = 1;
  v14 = PnpCtxGetCachedContextBaseKey(a1, 8, &v21);
  if ( v14 < 0 )
    goto LABEL_21;
  if ( !a2 )
  {
    a2 = 0;
    v15 = 0;
    goto LABEL_11;
  }
  if ( !PnpIsValidGuidString(a2) )
    return sub_811B54();
  v15 = 1;
LABEL_11:
  v16 = PnpCtxRegOpenKey(a1, v21, (int)a2, 0);
  v14 = v16;
  if ( v16 == -1073741444 )
  {
    v14 = -1073741595;
  }
  else if ( v16 >= 0 )
  {
    v17 = (_BYTE *)ExAllocatePoolWithTag(1, 1444, 1380994640);
    v10 = (unsigned int)v17;
    if ( v17 )
    {
      memset(v17, 0, 1444);
      *(_DWORD *)v10 = v15 + 1;
      RtlStringCchCopyExW((_WORD *)(v10 + 1012), 200, v23, 0, 0, 2304);
      *(_BYTE *)(v10 + 1420) = v22;
      *(_DWORD *)(v10 + 1412) = 0;
      *(_DWORD *)(v10 + 1416) = 0;
      *(_DWORD *)(v10 + 1424) = a5;
      *(_DWORD *)(v10 + 1432) = a7;
      *(_DWORD *)(v10 + 1436) = a8;
      *(_DWORD *)(v10 + 1428) = a6;
      *(_DWORD *)(v10 + 1440) = 0;
      v14 = PnpCtxRegEnumKeyWithCallback(a1, 0, CmDeviceClassesSubkeyCallback, v10);
      v18 = *(_DWORD *)(v10 + 1412);
      if ( v18 )
        ExFreePoolWithTag(v18);
      if ( v14 >= 0 )
      {
        v19 = *(_DWORD *)(v10 + 1440);
        *a9 = v19;
        if ( v19 )
        {
          v20 = v19 + 1;
          *a9 = v20;
          if ( a7 && a8 >= v20 )
            a7[v20 - 1] = 0;
          else
            v14 = -1073741789;
        }
      }
    }
    else
    {
      v14 = -1073741801;
    }
  }
LABEL_21:
  RtlFreeAnsiString(&v24);
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v14;
}
