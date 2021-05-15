// _CmGetMatchingDeviceListForSubkey 
 
int __fastcall CmGetMatchingDeviceListForSubkey(int *a1, int a2, int a3, int a4, int a5, _WORD *a6, unsigned int a7, unsigned int *a8)
{
  int v10; // r4
  int v12; // r0
  _BYTE *v13; // r0
  unsigned int v14; // r5
  int v15; // r0
  int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r3
  int v19; // [sp+Ch] [bp-2Ch] BYREF
  int v20; // [sp+10h] [bp-28h]
  int v21; // [sp+14h] [bp-24h]
  int *v22; // [sp+18h] [bp-20h]

  v20 = a3;
  v21 = a4;
  *a8 = 0;
  v22 = a1;
  v19 = 0;
  if ( a7 )
    *a6 = 0;
  v10 = PnpCtxGetCachedContextBaseKey(a1, 5, &v19);
  if ( v10 >= 0 )
  {
    if ( a2 )
      return sub_811AD4(a2);
    v12 = PnpCtxRegOpenKey(a1, v19, 0, 0);
    v10 = v12;
    if ( v12 == -1073741444 )
    {
      v10 = -1073741595;
    }
    else if ( v12 >= 0 )
    {
      v13 = (_BYTE *)ExAllocatePoolWithTag(1, 428, 1380994640);
      v14 = (unsigned int)v13;
      if ( v13 )
      {
        memset(v13, 0, 428);
        *(_DWORD *)v14 = 1;
        RtlStringCchCopyExW((_WORD *)(v14 + 4), 200, 0, 0, 0, 2304);
        v15 = (int)v22;
        *(_BYTE *)(v14 + 404) = v20;
        v16 = v21;
        *(_DWORD *)(v14 + 416) = a6;
        *(_DWORD *)(v14 + 420) = a7;
        *(_DWORD *)(v14 + 424) = 0;
        *(_DWORD *)(v14 + 408) = v16;
        *(_DWORD *)(v14 + 412) = a5;
        v10 = PnpCtxRegEnumKeyWithCallback(v15, 0, CmEnumSubkeyCallback, v14);
        if ( v10 >= 0 )
        {
          v17 = *(_DWORD *)(v14 + 424);
          *a8 = v17;
          if ( v17 )
          {
            v18 = v17 + 1;
            *a8 = v18;
            if ( a6 && a7 >= v18 )
              a6[v18 - 1] = 0;
            else
              v10 = -1073741789;
          }
        }
        ExFreePoolWithTag(v14);
      }
      else
      {
        v10 = -1073741801;
      }
    }
  }
  return v10;
}
