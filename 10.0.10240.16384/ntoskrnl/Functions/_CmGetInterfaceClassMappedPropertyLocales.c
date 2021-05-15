// _CmGetInterfaceClassMappedPropertyLocales 
 
int __fastcall CmGetInterfaceClassMappedPropertyLocales(int a1, int a2, int a3, unsigned int a4, _WORD *a5, int a6, _DWORD *a7)
{
  int v7; // r4
  int (**v8)[5]; // r6
  int v10; // r5
  unsigned int v11; // r1
  int (*v12)[5]; // t1
  int v13; // r8
  int (**v14)[5]; // r6
  int v15; // r5
  unsigned int v16; // r1
  int (*v17)[5]; // t1

  v7 = -1073741802;
  v8 = &off_8C9508;
  *a7 = 0;
  v10 = 0;
  while ( 1 )
  {
    v12 = *v8;
    v8 += 2;
    v11 = (unsigned int)v12;
    if ( v12 )
    {
      if ( *(_DWORD *)(a4 + 16) == *(_DWORD *)(v11 + 16) && !memcmp(a4, v11, 16) )
        break;
    }
    if ( ++v10 )
    {
      v13 = *(_DWORD *)(a4 + 16);
      v14 = &off_8C9408;
      v15 = 0;
      while ( 1 )
      {
        v17 = *v14;
        v14 += 2;
        v16 = (unsigned int)v17;
        if ( v13 == (*v17)[4] && !memcmp(a4, v16, 16) )
          break;
        if ( ++v15 )
          return v7;
      }
      break;
    }
  }
  *a7 = 1;
  if ( !a6 )
    return -1073741789;
  v7 = 0;
  *a5 = 0;
  return v7;
}
