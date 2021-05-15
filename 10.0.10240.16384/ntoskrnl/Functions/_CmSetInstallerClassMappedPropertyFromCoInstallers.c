// _CmSetInstallerClassMappedPropertyFromCoInstallers 
 
int __fastcall CmSetInstallerClassMappedPropertyFromCoInstallers(_DWORD *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r0
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v4 = 0;
  if ( a4 == 8210 )
  {
    v6 = PnpCtxGetCachedContextBaseKey(a1, 11, v8);
    if ( v6 >= 0 )
    {
      v6 = RegRtlSetValue(v8[0], a2);
      if ( v6 == -1073741444 )
        return -1073741595;
      if ( v6 >= 0 )
        return v4;
    }
    return v6;
  }
  return -1073741811;
}
