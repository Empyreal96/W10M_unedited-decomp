// _CmSetInstallerClassMappedProperty 
 
int __fastcall CmSetInstallerClassMappedProperty(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v10; // r4
  int (**v11)[5]; // r10
  int v12; // r8
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  int v15; // r2
  int v16; // r8
  int (**v17)[5]; // r10
  unsigned int v18; // r1
  int (*v19)[5]; // t1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r8
  int v24; // r0
  int v25; // r7
  int (**v26)[5]; // r8
  int v27; // r6
  unsigned int v28; // r1
  int (*v29)[5]; // t1
  int v32; // [sp+14h] [bp-24h]

  v10 = -1073741802;
  if ( a4 )
    return v10;
  v11 = &CmClassRegPropMap;
  v12 = 0;
  while ( 1 )
  {
    v14 = *v11;
    v11 += 4;
    v13 = (unsigned int)v14;
    if ( v14 )
    {
      if ( *(_DWORD *)(a5 + 16) == *(_DWORD *)(v13 + 16) && !memcmp(a5, v13, 16) )
        break;
    }
    if ( (unsigned int)++v12 >= 9 )
      goto LABEL_9;
  }
  v10 = CmSetInstallerClassMappedPropertyFromRegProp(a1, a2, a3, a5, a6, a7, a8);
  if ( v10 != -1073741802 )
    return v10;
LABEL_9:
  v15 = *(_DWORD *)(a5 + 16);
  v16 = 0;
  v32 = v15;
  v17 = &off_8C9410;
  while ( 1 )
  {
    v19 = *v17;
    v17 += 4;
    v18 = (unsigned int)v19;
    if ( v15 == (*v19)[4] )
      break;
LABEL_13:
    if ( (unsigned int)++v16 >= 0xC )
      goto LABEL_14;
  }
  if ( memcmp(a5, v18, 16) )
  {
    v15 = v32;
    goto LABEL_13;
  }
  if ( !a6 || a6 == 1 )
  {
    v23 = a3;
    v24 = CmDeleteInstallerClassMappedPropertyFromRegValue((int *)a1, a2, a3, a5);
  }
  else
  {
    v23 = a3;
    v24 = CmSetInstallerClassMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8);
  }
  v10 = v24;
  if ( v24 >= 0 && *(_DWORD *)(a1 + 156) )
    PnpInstallerClassRaisePropertyChangeEventWorker(
      a1,
      (int)a2,
      v23,
      0,
      a5,
      *(int (__fastcall **)(int, int, int, int, int))(a1 + 156));
  if ( v10 != -1073741802 )
    return v10;
LABEL_14:
  if ( *(_DWORD *)(a5 + 16) != 2 || memcmp(a5, (unsigned int)DEVPKEY_DeviceClass_ClassCoInstallers, 16) )
    goto LABEL_33;
  v22 = !a6 || a6 == 1 ? CmDeleteInstallerClassMappedPropertyFromCoInstallers((_DWORD *)a1, a2, v20, v21) : CmSetInstallerClassMappedPropertyFromCoInstallers(a1, a2);
  v10 = v22;
  if ( v22 >= 0 && *(_DWORD *)(a1 + 156) )
    PnpInstallerClassRaisePropertyChangeEventWorker(
      a1,
      (int)a2,
      a3,
      0,
      a5,
      *(int (__fastcall **)(int, int, int, int, int))(a1 + 156));
  if ( v10 == -1073741802 )
  {
LABEL_33:
    v25 = *(_DWORD *)(a5 + 16);
    v26 = &off_8C93D8;
    v27 = 0;
    while ( 1 )
    {
      v29 = *v26;
      v26 += 2;
      v28 = (unsigned int)v29;
      if ( v25 == (*v29)[4] && !memcmp(a5, v28, 16) )
        break;
      if ( (unsigned int)++v27 >= 2 )
        return v10;
    }
    v10 = -1073741790;
  }
  return v10;
}
