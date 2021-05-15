// _CmMapPropertyKeyToRegProp 
 
int (*__fastcall CmMapPropertyKeyToRegProp(int a1, unsigned int a2))[5]
{
  int v2; // r9
  int (**v3)[5]; // r7
  int (*v4)[5]; // r5
  unsigned int i; // r6
  int (**v7)[5]; // r4
  unsigned int v8; // r1
  int (*v9)[5]; // t1

  v2 = *(_DWORD *)(a2 + 16);
  v3 = &CmDeviceRegPropMap;
  v4 = 0;
  for ( i = 0; i < 0x21; ++i )
  {
    v7 = v3;
    v9 = *v3;
    v3 += 4;
    v8 = (unsigned int)v9;
    if ( v2 == (*v9)[4] && !memcmp(a2, v8, 16) )
      break;
    v7 = 0;
  }
  if ( v7 )
    v4 = v7[2];
  return v4;
}
