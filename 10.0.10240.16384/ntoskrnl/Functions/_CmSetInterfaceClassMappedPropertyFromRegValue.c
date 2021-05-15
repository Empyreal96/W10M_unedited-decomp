// _CmSetInterfaceClassMappedPropertyFromRegValue 
 
int __fastcall CmSetInterfaceClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4, int (*a5)[5], int a6, int a7)
{
  unsigned int v8; // r10
  int v9; // r4
  int v11; // r2
  int (**v12)[5]; // r9
  int v13; // r7
  int (**v14)[5]; // r5
  unsigned int v15; // r1
  int (*v16)[5]; // t1
  int *v17; // r5
  int v18; // r0
  int v19; // r5
  int v21; // [sp+4h] [bp-3Ch]
  int v22; // [sp+10h] [bp-30h] BYREF
  int v23; // [sp+14h] [bp-2Ch] BYREF
  int *v24; // [sp+18h] [bp-28h]
  int v25; // [sp+1Ch] [bp-24h]
  unsigned __int16 *v26; // [sp+20h] [bp-20h]

  v8 = *(_DWORD *)(a4 + 16);
  v9 = 0;
  v26 = a2;
  v23 = 0;
  v24 = a1;
  v22 = 0;
  if ( v8 < 2 )
    return -1073741264;
  v11 = *(_DWORD *)(a4 + 16);
  v12 = &off_8C9508;
  v13 = 0;
  v25 = v11;
  do
  {
    v14 = v12;
    v16 = *v12;
    v12 += 2;
    v15 = (unsigned int)v16;
    if ( v11 == (*v16)[4] )
    {
      if ( !memcmp(a4, v15, 16) )
        break;
      v11 = v25;
    }
    ++v13;
    v14 = 0;
  }
  while ( !v13 );
  if ( !v14 )
    return -1073741264;
  if ( a5 != v14[1] )
    return -1073741811;
  if ( v8 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterfaceClass_DefaultInterface, 16) )
  {
    v17 = v24;
    if ( !a3 )
    {
      v9 = CmOpenInterfaceClassRegKey(v24, v26, 0, (int)&v23, 1, 0, (int)&v23, 0);
      if ( v9 < 0 )
      {
LABEL_21:
        if ( v23 )
          ZwClose();
        return v9;
      }
      a3 = v23;
    }
    v18 = PnpOpenPropertiesKey(v17, a3, 0, 2, 1u, v21, &v22);
    v9 = v18;
    if ( v18 >= 0 )
    {
      v19 = PnpCtxRegSetValue(v18, v22, (int)L"Default", 1, a6, a7);
      ZwClose();
      if ( v19 == -1073741444 )
      {
        v9 = -1073741772;
      }
      else if ( v19 < 0 )
      {
        v9 = v19;
      }
    }
    goto LABEL_21;
  }
  return v9;
}
