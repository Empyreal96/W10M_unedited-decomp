// _CmGetInstallerClassMappedPropertyFromRegValue 
 
int __fastcall CmGetInstallerClassMappedPropertyFromRegValue(int *a1, unsigned __int16 *a2, unsigned int a3, unsigned int a4, int (**a5)[5], unsigned __int16 *a6, unsigned int a7, _DWORD *a8)
{
  int v10; // r2
  unsigned int v11; // r4
  int (**v12)[5]; // r9
  int v13; // r5
  unsigned int v14; // r7
  int (**v15)[5]; // r8
  unsigned int v16; // r1
  int (*v17)[5]; // t1
  unsigned int v18; // r9
  int v20; // r7
  int v21; // r2
  int v22; // r0
  int v23; // r0
  unsigned __int16 *v24; // r2
  char v25; // r3
  int v26; // r7
  int *v27; // r2
  int (**v28)[5]; // r1
  int (*v29)[5]; // r3
  unsigned __int16 *v30; // r7
  int v31; // r0
  int v32; // [sp+4h] [bp-74h]
  unsigned int v33; // [sp+10h] [bp-68h] BYREF
  bool v34; // [sp+14h] [bp-64h] BYREF
  unsigned int v35; // [sp+18h] [bp-60h] BYREF
  unsigned __int16 *v36; // [sp+1Ch] [bp-5Ch]
  int (**v37)[5]; // [sp+20h] [bp-58h]
  _DWORD *v38; // [sp+24h] [bp-54h]
  unsigned int v39; // [sp+28h] [bp-50h] BYREF
  int *v40; // [sp+2Ch] [bp-4Ch]
  int v41; // [sp+30h] [bp-48h] BYREF
  unsigned __int16 *v42; // [sp+34h] [bp-44h] BYREF
  int v43; // [sp+38h] [bp-40h]
  unsigned __int16 v44[28]; // [sp+40h] [bp-38h] BYREF

  v10 = *(_DWORD *)(a4 + 16);
  v37 = a5;
  v11 = 0;
  v12 = &off_8C9410;
  v36 = a6;
  v13 = 0;
  v42 = a2;
  v43 = v10;
  v40 = a1;
  v38 = a8;
  v41 = 0;
  v39 = 0;
  v35 = 0;
  v34 = 0;
  v33 = 0;
  v14 = 0;
  while ( 1 )
  {
    v15 = v12;
    v17 = *v12;
    v12 += 4;
    v16 = (unsigned int)v17;
    if ( v10 == (*v17)[4] )
      break;
LABEL_3:
    ++v14;
    v15 = 0;
    if ( v14 >= 0xC )
      goto LABEL_6;
  }
  if ( memcmp(a4, v16, 16) )
  {
    v10 = v43;
    goto LABEL_3;
  }
LABEL_6:
  if ( !v15 )
    return -1073741802;
  *v37 = 0;
  *v38 = 0;
  if ( v36 )
  {
    v18 = a7;
    if ( !a7 )
      return sub_7E55A4();
  }
  else
  {
    v18 = 0;
  }
  if ( !a3 )
  {
    v13 = CmOpenInstallerClassRegKey(v40, v42, 32, 0, 1, 0, (int)&v33, 0);
    if ( v13 >= 0 )
    {
      v11 = v33;
      goto LABEL_11;
    }
    goto LABEL_20;
  }
LABEL_11:
  v20 = *(_DWORD *)(a4 + 16);
  if ( v20 == 7 && (v23 = memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoInstallClass, 16)) == 0
    || v20 == 8 && (v23 = memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoDisplayClass, 16)) == 0
    || v20 == 9 && (v23 = memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_SilentInstall, 16)) == 0
    || v20 == 10 && (v23 = memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_NoUseClass, 16)) == 0 )
  {
    v24 = (unsigned __int16 *)v15[2];
    v35 = 22;
    if ( !a3 )
      a3 = v11;
    v22 = PnpCtxRegQueryValue(v23, a3, v24, &v39, (int)v44, &v35);
    if ( v22 != -1073741772 && v22 != -1073741444 )
    {
      if ( v22 >= 0 )
      {
        *v38 = 1;
        *v37 = v15[1];
        if ( v18 )
        {
          v44[10] = 0;
          if ( wcsicmp((int)L"0", v44) )
            goto LABEL_45;
LABEL_49:
          v25 = 0;
          goto LABEL_46;
        }
LABEL_48:
        v13 = -1073741789;
        goto LABEL_20;
      }
LABEL_47:
      v13 = v22;
      goto LABEL_20;
    }
LABEL_19:
    v13 = -1073741275;
    goto LABEL_20;
  }
  if ( v20 != 2 )
  {
LABEL_16:
    v21 = (int)v15[2];
    v35 = v18;
    if ( !a3 )
      a3 = v11;
    v22 = PnpCtxRegQueryValueIndirect((int)v40, a3, v21, &v39, v36, &v35, &v34);
    if ( v22 == -1073741772 || v22 == -1073741444 )
      goto LABEL_19;
    if ( v22 && v22 != -1073741789 )
      goto LABEL_47;
LABEL_66:
    *v38 = v35;
    v28 = v37;
    v29 = v15[1];
    *v37 = v29;
    if ( v22 || !v18 )
      v13 = -1073741789;
    if ( v29 == (int (*)[5])18 && v34 )
      *v28 = (int (*)[5])25;
    goto LABEL_20;
  }
  if ( !memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_Name, 16) )
  {
    v13 = -1073741275;
    v26 = 0;
    while ( 1 )
    {
      if ( v26 )
      {
        v27 = &dword_8CE900;
      }
      else
      {
        v27 = (int *)v15[2];
        if ( !v27 )
          goto LABEL_21;
      }
      v35 = v18;
      if ( a3 )
        v11 = a3;
      v22 = PnpCtxRegQueryValueIndirect((int)v40, v11, (int)v27, &v39, v36, &v35, &v34);
      if ( v22 != -1073741772 && v22 != -1073741444 )
        break;
      ++v26;
      v11 = v33;
      if ( v26 >= 2 )
        goto LABEL_21;
    }
    if ( !v22 || v22 == -1073741789 )
      v13 = 0;
    else
      v13 = v22;
    if ( v13 < 0 )
      goto LABEL_20;
    goto LABEL_66;
  }
  if ( memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_DHPRebalanceOptOut, 16) )
    goto LABEL_16;
  v30 = (unsigned __int16 *)v15[2];
  v35 = 4;
  if ( !a3 )
    a3 = v11;
  v31 = PnpOpenPropertiesKey(v40, a3, 0, 1, 0, v32, &v41);
  v13 = v31;
  if ( v31 == -1073741772 )
    goto LABEL_19;
  if ( v31 < 0 )
    goto LABEL_20;
  v22 = PnpCtxRegQueryValue(v31, v41, v30, &v39, (int)&v42, &v35);
  if ( v22 == -1073741772 || v22 == -1073741444 )
    goto LABEL_19;
  if ( v22 < 0 )
    goto LABEL_47;
  *v38 = 1;
  *v37 = v15[1];
  if ( !v18 )
    goto LABEL_48;
  if ( !v42 )
    goto LABEL_49;
LABEL_45:
  v25 = -1;
LABEL_46:
  *(_BYTE *)v36 = v25;
LABEL_20:
  v11 = v33;
LABEL_21:
  if ( v41 )
  {
    ZwClose();
    v11 = v33;
  }
  if ( v11 )
    ZwClose();
  return v13;
}
