// _CmDeleteInstallerClassMappedPropertyFromRegValue 
 
int __fastcall CmDeleteInstallerClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  int v5; // r5
  int v6; // r6
  unsigned int v7; // r8
  int v8; // r3
  int (**v9)[5]; // r9
  int (**v11)[5]; // r7
  unsigned int v12; // r1
  int (*v13)[5]; // t1
  int *v14; // r9
  unsigned __int16 *v15; // r8
  int v16; // r0
  int v17; // r0
  int v19; // [sp+4h] [bp-44h]
  int v20; // [sp+10h] [bp-38h] BYREF
  int v21; // [sp+14h] [bp-34h] BYREF
  int *v22; // [sp+18h] [bp-30h]
  int v23; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 *v24[10]; // [sp+20h] [bp-28h] BYREF

  v5 = 0;
  v6 = 0;
  v20 = 0;
  v21 = 0;
  v7 = 0;
  v8 = *(_DWORD *)(a4 + 16);
  v9 = &off_8C9410;
  v23 = v8;
  v24[0] = a2;
  v22 = a1;
  do
  {
    v11 = v9;
    v13 = *v9;
    v9 += 4;
    v12 = (unsigned int)v13;
    if ( v8 == (*v13)[4] )
    {
      if ( !memcmp(a4, v12, 16) )
        break;
      v8 = v23;
    }
    ++v7;
    v11 = 0;
  }
  while ( v7 < 0xC );
  if ( !v11 )
    return -1073741802;
  v14 = v22;
  if ( a3 )
  {
LABEL_11:
    v15 = (unsigned __int16 *)v11[2];
    if ( *(_DWORD *)(a4 + 16) == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_DHPRebalanceOptOut, 16) )
    {
      if ( !a3 )
        a3 = v6;
      v16 = PnpOpenPropertiesKey(v14, a3, 0, 2, 0, v19, &v20);
      v5 = v16;
      if ( v16 == -1073741772 )
      {
        v5 = 0;
        goto LABEL_26;
      }
      if ( v16 < 0 )
        goto LABEL_26;
    }
    v17 = RtlInitUnicodeStringEx((int)v24, v15);
    if ( v17 >= 0 )
      v17 = ZwDeleteValueKey();
    if ( v17 != -1073741772 )
    {
      if ( v17 == -1073741444 )
        goto LABEL_26;
      if ( v17 < 0 )
      {
        v5 = v17;
        goto LABEL_26;
      }
    }
    if ( RtlInitUnicodeStringEx((int)v24, (unsigned __int16 *)&dword_8CE900) >= 0 )
      ZwDeleteValueKey();
    goto LABEL_26;
  }
  v5 = CmOpenInstallerClassRegKey(v22, v24[0], 32, 0, 2, 0, (int)&v21, 0);
  if ( v5 >= 0 )
  {
    v6 = v21;
    goto LABEL_11;
  }
LABEL_26:
  if ( v20 )
    ZwClose();
  if ( v21 )
    ZwClose();
  return v5;
}
