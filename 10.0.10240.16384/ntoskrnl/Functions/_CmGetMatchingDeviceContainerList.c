// _CmGetMatchingDeviceContainerList 
 
int __fastcall CmGetMatchingDeviceContainerList(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int (__fastcall *v11)(_DWORD *, _DWORD, int, int, int, int *); // r5
  int v13; // r4
  int v14[3]; // [sp+14h] [bp-5Ch] BYREF
  int v15; // [sp+20h] [bp-50h] BYREF
  _DWORD v16[10]; // [sp+24h] [bp-4Ch] BYREF

  v15 = 0;
  memset(v16, 0, sizeof(v16));
  v11 = (int (__fastcall *)(_DWORD *, _DWORD, int, int, int, int *))a1[40];
  v16[4] = a5;
  v16[5] = a6;
  v16[6] = a7;
  v16[1] = a2;
  v16[2] = a3;
  v16[3] = a4;
  if ( v11 )
  {
    if ( v11(a1, 0, 5, 4, 1, &v15) != -1073741822 )
      return sub_811B08();
    a2 = v16[1];
    a3 = v16[2];
  }
  v14[0] = 0;
  v13 = PnpCtxGetCachedContextBaseKey(a1, 9, v14);
  if ( v13 >= 0 )
  {
    v14[1] = a2;
    v14[2] = a3;
    v13 = PnpGetGenericObjectList(a1, v14[0]);
  }
  return v13;
}
