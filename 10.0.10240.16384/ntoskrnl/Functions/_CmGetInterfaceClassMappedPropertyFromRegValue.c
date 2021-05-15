// _CmGetInterfaceClassMappedPropertyFromRegValue 
 
int __fastcall CmGetInterfaceClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4, _DWORD *a5, int a6, int *a7, _DWORD *a8)
{
  unsigned int v11; // r7
  int v12; // r2
  int (**v13)[5]; // r4
  int v14; // r5
  int (**v15)[5]; // r8
  unsigned int v16; // r1
  int (*v17)[5]; // t1
  int v18; // r4
  int v19; // r2
  int *v20; // r5
  int v21; // r0
  int v22; // r5
  int v23; // [sp+4h] [bp-44h]
  int v24; // [sp+10h] [bp-38h] BYREF
  int v25; // [sp+14h] [bp-34h] BYREF
  int *v26; // [sp+18h] [bp-30h]
  int v27; // [sp+1Ch] [bp-2Ch]
  int v28; // [sp+20h] [bp-28h]
  unsigned __int16 *v29; // [sp+24h] [bp-24h]

  v24 = 0;
  v25 = 0;
  *a5 = 0;
  v29 = a2;
  v26 = a1;
  *a8 = 0;
  v27 = a6;
  if ( !a6 )
    return sub_7C894C();
  if ( !a7 )
    v27 = 0;
  v11 = *(_DWORD *)(a4 + 16);
  if ( v11 >= 2 )
  {
    v12 = *(_DWORD *)(a4 + 16);
    v13 = &off_8C9508;
    v28 = v12;
    v14 = 0;
    do
    {
      v15 = v13;
      v17 = *v13;
      v13 += 2;
      v16 = (unsigned int)v17;
      if ( v12 == (*v17)[4] )
      {
        if ( !memcmp(a4, v16, 16) )
          break;
        v12 = v28;
      }
      ++v14;
      v15 = 0;
    }
    while ( !v14 );
    v18 = 0;
    if ( v15 )
    {
      if ( v11 != 2 || memcmp(a4, (unsigned int)DEVPKEY_DeviceInterfaceClass_DefaultInterface, 16) )
        return v18;
      v20 = v26;
      if ( !a3 )
      {
        v18 = CmOpenInterfaceClassRegKey(v26, v29, v19, 1, 1, 0, (int)&v25, 0);
        if ( v18 < 0 )
          goto LABEL_15;
        a3 = v25;
      }
      v21 = PnpOpenPropertiesKey(v20, a3, 0, 1, 0, v23, &v24);
      v18 = v21;
      if ( v21 == -1073741772 )
      {
LABEL_14:
        v18 = -1073741275;
        goto LABEL_15;
      }
      if ( v21 >= 0 )
      {
        v26 = a7;
        v22 = PnpCtxRegQueryValue(v21, v24);
        ZwClose();
        if ( v22 != -1073741772 && v22 != -1073741444 )
        {
          if ( !v22 || v22 == -1073741789 )
          {
            *a8 = v26;
            *a5 = 18;
            if ( v22 || !a7 )
              v18 = -1073741789;
          }
          else
          {
            v18 = v22;
          }
          goto LABEL_15;
        }
        goto LABEL_14;
      }
LABEL_15:
      if ( v25 )
        ZwClose();
      return v18;
    }
  }
  return -1073741264;
}
