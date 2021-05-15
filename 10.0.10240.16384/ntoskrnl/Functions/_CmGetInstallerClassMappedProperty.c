// _CmGetInstallerClassMappedProperty 
 
int __fastcall CmGetInstallerClassMappedProperty(int a1, int a2, int a3, int a4, unsigned int a5, _DWORD *a6, char *a7, unsigned int a8, unsigned int *a9)
{
  int v9; // r5
  int (**v10)[5]; // r7
  unsigned int i; // r6
  unsigned int v12; // r1
  int (*v13)[5]; // t1
  int (**v14)[5]; // r10
  int v15; // r8
  int v16; // r6
  int (**v17)[5]; // r7
  unsigned int v18; // r1
  int (*v19)[5]; // t1
  unsigned int *v20; // r8
  int v21; // r7
  int v22; // r6
  unsigned int v23; // r1
  int (*v24)[5]; // t1

  v9 = -1073741802;
  *a9 = 0;
  if ( !a4 )
  {
    v10 = &CmClassRegPropMap;
    for ( i = 0; i < 9; ++i )
    {
      v13 = *v10;
      v10 += 4;
      v12 = (unsigned int)v13;
      if ( v13 && *(_DWORD *)(a5 + 16) == *(_DWORD *)(v12 + 16) && !memcmp(a5, v12, 16) )
        return sub_7E557C();
    }
    v14 = &off_8C93D8;
    v15 = *(_DWORD *)(a5 + 16);
    v16 = 0;
    v17 = &off_8C9410;
    while ( 1 )
    {
      v19 = *v17;
      v17 += 4;
      v18 = (unsigned int)v19;
      if ( v15 == (*v19)[4] && !memcmp(a5, v18, 16) )
        break;
      if ( (unsigned int)++v16 >= 0xC )
      {
        v20 = a9;
        goto LABEL_10;
      }
    }
    v20 = a9;
    v9 = CmGetInstallerClassMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8, a9);
    if ( v9 != -1073741802 )
      return v9;
LABEL_10:
    if ( *(_DWORD *)(a5 + 16) != 2
      || memcmp(a5, (unsigned int)DEVPKEY_DeviceClass_ClassCoInstallers, 16)
      || (v9 = CmGetInstallerClassMappedPropertyFromCoInstallers(a1, a2), v9 == -1073741802) )
    {
      v21 = *(_DWORD *)(a5 + 16);
      v22 = 0;
      while ( 1 )
      {
        v24 = *v14;
        v14 += 2;
        v23 = (unsigned int)v24;
        if ( v21 == (*v24)[4] && !memcmp(a5, v23, 16) )
          break;
        if ( (unsigned int)++v22 >= 2 )
          return v9;
      }
      v9 = CmGetInstallerClassMappedPropertyFromComposite(a1, a2, a3, a5, a6, a7, a8, v20);
    }
  }
  return v9;
}
