// _CmSetInstallerClassMappedPropertyFromRegValue 
 
int __fastcall CmSetInstallerClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, int a3, unsigned int a4, int (*a5)[5], _BYTE *a6, unsigned int a7)
{
  int v7; // r0
  int v8; // r4
  int v9; // r5
  int v10; // r6
  int (**v12)[5]; // r3
  unsigned int i; // r9
  int (**v15)[5]; // r8
  unsigned int v16; // r1
  int (*v17)[5]; // t1
  int (*v18)[5]; // r2
  bool v19; // zf
  unsigned __int64 v20; // kr00_8
  int v21; // r8
  int v22; // r0
  int v23; // r0
  int v24; // r3
  int v26; // [sp+4h] [bp-44h]
  int v27; // [sp+10h] [bp-38h] BYREF
  int v28; // [sp+14h] [bp-34h] BYREF
  int v29; // [sp+18h] [bp-30h]
  int *v30; // [sp+1Ch] [bp-2Ch]
  int (**v31)[5]; // [sp+20h] [bp-28h]
  unsigned __int16 *v32; // [sp+24h] [bp-24h]

  v30 = a1;
  v7 = *(_DWORD *)(a4 + 16);
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v12 = &off_8C9410;
  v28 = 0;
  v29 = v7;
  v32 = a2;
  v27 = 0;
  for ( i = 0; i < 0xC; ++i )
  {
    v15 = v12;
    v17 = *v12;
    v12 += 4;
    v16 = (unsigned int)v17;
    v31 = v12;
    if ( v7 == (*v17)[4] )
    {
      if ( !memcmp(a4, v16, 16) )
        break;
      v12 = v31;
      v7 = v29;
    }
    v15 = 0;
  }
  if ( !v15 )
    return -1073741802;
  v18 = v15[1];
  if ( a5 != v18 )
  {
    if ( a5 == (int (*)[5])25 )
    {
      v19 = v18 == (int (*)[5])18;
    }
    else
    {
      if ( !a5 )
        goto LABEL_15;
      v19 = a5 == (int (*)[5])1;
    }
    if ( !v19 )
      return -1073741811;
  }
LABEL_15:
  if ( !a3 )
  {
    v8 = CmOpenInstallerClassRegKey(v30, v32, 32, 0, 3, 0, (int)&v28, 0);
    if ( v8 < 0 )
    {
LABEL_54:
      v10 = v27;
      v9 = v28;
      goto LABEL_55;
    }
    v10 = v27;
    v9 = v28;
  }
  v20 = *((_QWORD *)v15 + 1);
  v21 = *(_DWORD *)(a4 + 16);
  v29 = HIDWORD(v20);
  v32 = (unsigned __int16 *)v20;
  if ( v21 == 7 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoInstallClass, 16)
    || v21 == 8 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoDisplayClass, 16)
    || v21 == 9 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_SilentInstall, 16)
    || v21 == 10 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoUseClass, 16) )
  {
    if ( a7 && ((char)*a6 == -1 || !*a6) )
    {
      if ( !a3 )
        a3 = v9;
      v22 = a3;
      goto LABEL_33;
    }
  }
  else if ( v21 == 2 && !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_DHPRebalanceOptOut, 16) )
  {
    if ( a7 )
    {
      if ( (char)*a6 == -1 )
      {
        v24 = 1;
      }
      else
      {
        if ( *a6 )
          goto LABEL_27;
        v24 = 0;
      }
      v31 = (int (**)[5])v24;
      if ( !a3 )
        a3 = v9;
      v8 = PnpOpenPropertiesKey(v30, a3, 0, 2, 1u, v26, &v27);
      if ( v8 < 0 )
        goto LABEL_54;
      v22 = v27;
LABEL_33:
      v23 = RegRtlSetValue(v22, (unsigned __int16 *)v20);
      if ( v23 == -1073741444 )
      {
        v8 = -1073741772;
        goto LABEL_54;
      }
LABEL_52:
      if ( v23 < 0 )
        v8 = v23;
      goto LABEL_54;
    }
  }
  else if ( v21 != 3 || memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_ClassName, 16) || a7 <= 0x40 )
  {
    if ( !a3 )
      a3 = v9;
    v23 = RegRtlSetValue(a3, v32);
    goto LABEL_52;
  }
LABEL_27:
  v8 = -1073741811;
LABEL_55:
  if ( v10 )
  {
    ZwClose();
    v9 = v28;
  }
  if ( v9 )
    ZwClose();
  return v8;
}
