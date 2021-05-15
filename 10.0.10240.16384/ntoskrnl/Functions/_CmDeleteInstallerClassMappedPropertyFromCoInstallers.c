// _CmDeleteInstallerClassMappedPropertyFromCoInstallers 
 
int __fastcall CmDeleteInstallerClassMappedPropertyFromCoInstallers(_DWORD *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v8[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v9[4]; // [sp+8h] [bp-10h] BYREF

  v8[1] = (int)a2;
  v9[0] = a3;
  v9[1] = a4;
  v8[0] = 0;
  v5 = 0;
  v6 = PnpCtxGetCachedContextBaseKey(a1, 11, v8);
  if ( v6 < 0 )
    return v6;
  v6 = RtlInitUnicodeStringEx((int)v9, a2);
  if ( v6 >= 0 )
    v6 = ZwDeleteValueKey();
  if ( v6 != -1073741772 && v6 != -1073741444 && v6 < 0 )
    return v6;
  return v5;
}
