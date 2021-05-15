// _CmGetDeviceContainerMappedPropertyLocales 
 
int __fastcall CmGetDeviceContainerMappedPropertyLocales(int a1, int a2, int a3, unsigned int a4, _WORD *a5, int a6, _DWORD *a7)
{
  int v7; // r4
  int (**v8)[5]; // r7
  int v9; // r8
  int v11; // r5
  unsigned int v12; // r1
  int (*v13)[5]; // t1

  v7 = -1073741802;
  v8 = &off_40B4B8;
  *a7 = 0;
  v9 = *(_DWORD *)(a4 + 16);
  v11 = 0;
  while ( 1 )
  {
    v13 = *v8;
    v8 += 2;
    v12 = (unsigned int)v13;
    if ( v9 == (*v13)[4] && !memcmp(a4, v12, 16) )
      break;
    if ( (unsigned int)++v11 >= 4 )
      return v7;
  }
  *a7 = 1;
  if ( !a6 )
    return -1073741789;
  v7 = 0;
  *a5 = 0;
  return v7;
}
