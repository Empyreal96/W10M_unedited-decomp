// _CmGetInterfaceClassMappedPropertyFromComposite 
 
int __fastcall CmGetInterfaceClassMappedPropertyFromComposite(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7, _DWORD *a8)
{
  int v8; // r5
  int v9; // r8
  int v11; // r4
  unsigned int v13; // r3
  int v14; // r0
  int v16; // [sp+20h] [bp-28h] BYREF
  int v17; // [sp+24h] [bp-24h]
  int v18; // [sp+28h] [bp-20h]

  v17 = a2;
  v18 = a1;
  v9 = a6;
  v11 = 0;
  *a5 = 0;
  if ( !a6 )
    v8 = 0;
  v16 = 0;
  *a8 = 0;
  if ( a6 )
  {
    v8 = a7;
    if ( !a7 )
      v9 = 0;
  }
  v13 = *(_DWORD *)(a4 + 16);
  if ( v13 < 2 )
    return -1073741264;
  if ( v13 == 10 && !memcmp(a4, (unsigned int)DEVPKEY_NAME, 16) )
  {
    v14 = PnpGetObjectProperty(
            v18,
            v17,
            4,
            a3,
            0,
            (int)DEVPKEY_DeviceInterfaceClass_Name,
            (int)a5,
            v9,
            v8,
            (int)&v16,
            0);
    v11 = v14;
    if ( !v14 || v14 == -1073741789 )
      *a8 = v16;
  }
  return v11;
}
