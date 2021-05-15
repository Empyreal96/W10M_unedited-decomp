// _CmGetInstallerClassMappedPropertyLocales 
 
int __fastcall CmGetInstallerClassMappedPropertyLocales(int a1, int a2, int a3, unsigned int a4, _WORD *a5, int a6, _DWORD *a7)
{
  int v7; // r6
  int (**v8)[5]; // r7
  int v10; // r5
  unsigned int v11; // r1
  int (*v12)[5]; // t1
  int (**v13)[5]; // r7
  int v14; // r5
  int (**v15)[5]; // r8
  unsigned int v16; // r1
  int (*v17)[5]; // t1
  int v18; // r8
  int v19; // r5
  unsigned int v20; // r1
  int (*v21)[5]; // t1

  v7 = -1073741802;
  v8 = &CmClassRegPropMap;
  *a7 = 0;
  v10 = 0;
  while ( 1 )
  {
    v12 = *v8;
    v8 += 4;
    v11 = (unsigned int)v12;
    if ( v12 )
    {
      if ( *(_DWORD *)(a4 + 16) == *(_DWORD *)(v11 + 16) && !memcmp(a4, v11, 16) )
        break;
    }
    if ( (unsigned int)++v10 >= 9 )
    {
      v13 = &off_8C93D8;
      v14 = 0;
      v15 = &off_8C9410;
      while ( 1 )
      {
        v17 = *v15;
        v15 += 4;
        v16 = (unsigned int)v17;
        if ( v17 )
        {
          if ( *(_DWORD *)(a4 + 16) == *(_DWORD *)(v16 + 16) && !memcmp(a4, v16, 16) )
            goto LABEL_17;
        }
        if ( (unsigned int)++v14 >= 0xC )
        {
          v18 = *(_DWORD *)(a4 + 16);
          v19 = 0;
          while ( 1 )
          {
            v21 = *v13;
            v13 += 2;
            v20 = (unsigned int)v21;
            if ( v18 == (*v21)[4] && !memcmp(a4, v20, 16) )
              goto LABEL_17;
            if ( (unsigned int)++v19 >= 2 )
            {
              if ( *(_DWORD *)(a4 + 16) != 2 || memcmp(a4, (unsigned int)DEVPKEY_DeviceClass_ClassCoInstallers, 16) )
                return v7;
              goto LABEL_17;
            }
          }
        }
      }
    }
  }
LABEL_17:
  *a7 = 1;
  if ( !a6 )
    return -1073741789;
  v7 = 0;
  *a5 = 0;
  return v7;
}
