// _CmGetDeviceInterfaceMappedProperty 
 
int __fastcall CmGetDeviceInterfaceMappedProperty(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int v9; // r6
  int (**v10)[6]; // r7
  int v11; // r4
  unsigned int v12; // r1
  int (*v13)[6]; // t1
  int v14; // r8
  int (**v15)[5]; // r7
  int v16; // r4
  unsigned int v17; // r1
  int (*v18)[5]; // t1

  v9 = -1073741802;
  *a9 = 0;
  if ( !a4 )
  {
    v10 = &off_8C94F0;
    v11 = 0;
    while ( 1 )
    {
      v13 = *v10;
      v10 += 2;
      v12 = (unsigned int)v13;
      if ( v13 )
      {
        if ( *(_DWORD *)(a5 + 16) == *(_DWORD *)(v12 + 16) && !memcmp(a5, v12, 16) )
          break;
      }
      if ( (unsigned int)++v11 >= 3 )
        goto LABEL_6;
    }
    v9 = CmGetDeviceInterfaceMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8, a9);
    if ( v9 != -1073741802 )
      return v9;
LABEL_6:
    v14 = *(_DWORD *)(a5 + 16);
    v15 = &off_8C93E8;
    v16 = 0;
    while ( 1 )
    {
      v18 = *v15;
      v15 += 2;
      v17 = (unsigned int)v18;
      if ( v14 == (*v18)[4] && !memcmp(a5, v17, 16) )
        break;
      if ( (unsigned int)++v16 >= 4 )
        return v9;
    }
    v9 = CmGetDeviceInterfaceMappedPropertyFromComposite(a1, a2, a3, a5, a6, a7, a8, a9);
  }
  return v9;
}
