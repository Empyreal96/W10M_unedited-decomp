// _CmSetInterfaceClassMappedProperty 
 
int __fastcall CmSetInterfaceClassMappedProperty(int *a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v10; // r5
  int (**v11)[5]; // r8
  int v12; // r7
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  int v15; // r4
  int v16; // r0
  int v17; // r8
  int (**v18)[5]; // r7
  int v19; // r4
  unsigned int v20; // r1
  int (*v21)[5]; // t1

  v10 = -1073741802;
  if ( !a4 )
  {
    v11 = &off_8C9508;
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
      if ( ++v12 )
        goto LABEL_15;
    }
    if ( !a6 || a6 == 1 )
    {
      v15 = (int)a1;
      v16 = CmDeleteInterfaceClassMappedPropertyFromRegValue(a1, a2, a3, a5);
    }
    else
    {
      v15 = (int)a1;
      v16 = CmSetInterfaceClassMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8);
    }
    v10 = v16;
    if ( v16 >= 0 )
      PnpObjectRaisePropertyChangeEvent(v15, (int)a2, 4, a3, 0, a5);
    if ( v10 != -1073741802 )
      return v10;
LABEL_15:
    v17 = *(_DWORD *)(a5 + 16);
    v18 = &off_8C9408;
    v19 = 0;
    while ( 1 )
    {
      v21 = *v18;
      v18 += 2;
      v20 = (unsigned int)v21;
      if ( v17 == (*v21)[4] && !memcmp(a5, v20, 16) )
        break;
      if ( ++v19 )
        return v10;
    }
    v10 = -1073741790;
  }
  return v10;
}
