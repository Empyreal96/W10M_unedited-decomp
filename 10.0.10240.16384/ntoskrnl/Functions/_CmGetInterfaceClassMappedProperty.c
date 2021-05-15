// _CmGetInterfaceClassMappedProperty 
 
int __fastcall CmGetInterfaceClassMappedProperty(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int v9; // r6
  int (**v10)[5]; // r7
  int v11; // r4
  unsigned int v12; // r1
  int (*v13)[5]; // t1

  v9 = -1073741802;
  *a9 = 0;
  if ( a4 )
    return v9;
  v10 = &off_8C9508;
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
    if ( ++v11 )
      return sub_7C8900();
  }
  v9 = CmGetInterfaceClassMappedPropertyFromRegValue(a1, a2, a3, a5, a6, a7, a8, a9);
  if ( v9 != -1073741802 )
    return v9;
  return sub_7C8900();
}
