// _CmDeleteInterfaceClassMappedPropertyFromRegValue 
 
int __fastcall CmDeleteInterfaceClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  unsigned int v5; // r10
  int v6; // r4
  int v8; // r2
  int (**v9)[5]; // r9
  int v10; // r6
  int (**v11)[5]; // r8
  unsigned int v12; // r1
  int (*v13)[5]; // t1
  int v14; // r2
  int *v15; // r6
  int v16; // r0
  int v17; // r5
  int v19; // [sp+4h] [bp-44h]
  int v20; // [sp+10h] [bp-38h] BYREF
  int v21; // [sp+14h] [bp-34h] BYREF
  int *v22; // [sp+18h] [bp-30h]
  int v23; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 *v24; // [sp+20h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a4 + 16);
  v6 = 0;
  v24 = a2;
  v21 = 0;
  v22 = a1;
  v20 = 0;
  if ( v5 < 2 )
    return -1073741264;
  v8 = *(_DWORD *)(a4 + 16);
  v9 = &off_8C9508;
  v10 = 0;
  v23 = v8;
  do
  {
    v11 = v9;
    v13 = *v9;
    v9 += 2;
    v12 = (unsigned int)v13;
    if ( v8 == (*v13)[4] )
    {
      if ( !memcmp(a4, v12, 16) )
        break;
      v8 = v23;
    }
    ++v10;
    v11 = 0;
  }
  while ( !v10 );
  if ( !v11 )
    return -1073741264;
  if ( v5 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceInterfaceClass_DefaultInterface, 16) )
  {
    v15 = v22;
    if ( !a3 )
    {
      v6 = CmOpenInterfaceClassRegKey(v22, v24, v14, 1, 1, 0, (int)&v21, 0);
      if ( v6 < 0 )
      {
LABEL_23:
        if ( v21 )
          ZwClose();
        return v6;
      }
      a3 = v21;
    }
    v16 = PnpOpenPropertiesKey(v15, a3, 0, 2, 0, v19, &v20);
    v6 = v16;
    if ( v16 == -1073741772 )
    {
      v6 = -1073741275;
    }
    else if ( v16 >= 0 )
    {
      v17 = RtlInitUnicodeStringEx((int)&v24, L"Default");
      if ( v17 >= 0 )
        v17 = ZwDeleteValueKey();
      ZwClose();
      if ( v17 != -1073741772 && v17 != -1073741444 && v17 < 0 )
        v6 = v17;
    }
    goto LABEL_23;
  }
  return v6;
}
