// _CmGetInstallerClassMappedPropertyFromCoInstallers 
 
int __fastcall CmGetInstallerClassMappedPropertyFromCoInstallers(_DWORD *a1, unsigned __int16 *a2, int a3, _DWORD *a4, int a5, int a6, _DWORD *a7)
{
  int v8; // r4
  int v11; // r0
  int v12; // [sp+8h] [bp-28h] BYREF
  unsigned int v13; // [sp+Ch] [bp-24h] BYREF
  int v14[8]; // [sp+10h] [bp-20h] BYREF

  *a4 = 0;
  v8 = 0;
  *a7 = 0;
  v12 = 0;
  if ( a5 )
    return sub_7E57D4();
  v11 = PnpCtxGetCachedContextBaseKey(a1, 11, &v12);
  if ( v11 < 0 )
    return v11;
  v13 = 0;
  v11 = PnpCtxRegQueryValue(v11, v12, a2, v14, 0, &v13);
  if ( v11 != -1073741772 && v11 != -1073741444 )
  {
    if ( !v11 || v11 == -1073741789 )
    {
      if ( v14[0] == 7 )
      {
        *a7 = v13;
        *a4 = 8210;
        v8 = -1073741789;
      }
      else if ( RtlInitUnicodeStringEx((int)v14, a2) >= 0 )
      {
        ZwDeleteValueKey();
      }
      return v8;
    }
    return v11;
  }
  return -1073741275;
}
