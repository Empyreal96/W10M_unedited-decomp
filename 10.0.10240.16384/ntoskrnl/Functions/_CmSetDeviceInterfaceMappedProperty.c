// _CmSetDeviceInterfaceMappedProperty 
 
int __fastcall CmSetDeviceInterfaceMappedProperty(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v10; // r5
  int (**v11)[6]; // r8
  int v12; // r7
  unsigned int v13; // r1
  int (*v14)[6]; // t1
  int v15; // r8
  int (**v16)[5]; // r7
  int v17; // r4
  unsigned int v18; // r1
  int (*v19)[5]; // t1

  v10 = -1073741802;
  if ( !a4 )
  {
    v11 = &off_8C94F0;
    v12 = 0;
    while ( 1 )
    {
      v14 = *v11;
      v11 += 2;
      v13 = (unsigned int)v14;
      if ( v14 )
      {
        if ( *(_DWORD *)(a5 + 16) == *(_DWORD *)(v13 + 16) && !memcmp(a5, v13, 16) )
          break;
      }
      if ( (unsigned int)++v12 >= 3 )
        goto LABEL_6;
    }
    if ( !a6 || a6 == 1 )
      return sub_7EA6F0();
    v10 = CmSetDeviceInterfaceMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8);
    if ( v10 >= 0 )
      PnpObjectRaisePropertyChangeEvent(a1, a2, 3, a3, 0, a5);
    if ( v10 == -1073741802 )
    {
LABEL_6:
      v15 = *(_DWORD *)(a5 + 16);
      v16 = &off_8C93E8;
      v17 = 0;
      while ( 1 )
      {
        v19 = *v16;
        v16 += 2;
        v18 = (unsigned int)v19;
        if ( v15 == (*v19)[4] && !memcmp(a5, v18, 16) )
          break;
        if ( (unsigned int)++v17 >= 4 )
          return v10;
      }
      return -1073741790;
    }
  }
  return v10;
}
