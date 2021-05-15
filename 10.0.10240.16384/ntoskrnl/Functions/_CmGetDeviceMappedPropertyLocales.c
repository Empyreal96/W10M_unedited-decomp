// _CmGetDeviceMappedPropertyLocales 
 
int __fastcall CmGetDeviceMappedPropertyLocales(int a1, int a2, int a3, unsigned int a4, _WORD *a5, int a6, _DWORD *a7)
{
  int v7; // r5
  int (**v8)[5]; // r6
  int v10; // r4
  unsigned int v11; // r1
  int (*v12)[5]; // t1
  int (**v13)[5]; // r6
  int v14; // r4
  unsigned int v15; // r1
  int (*v16)[5]; // t1
  int v17; // r8
  int (**v18)[5]; // r6
  int v19; // r4
  unsigned int v20; // r1
  int (*v21)[5]; // t1

  v7 = -1073741802;
  v8 = &CmDeviceRegPropMap;
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
    if ( (unsigned int)++v10 >= 0x21 )
    {
      v13 = &off_8C94D0;
      v14 = 0;
      while ( 1 )
      {
        v16 = *v13;
        v13 += 4;
        v15 = (unsigned int)v16;
        if ( v16 )
        {
          if ( *(_DWORD *)(a4 + 16) == *(_DWORD *)(v15 + 16) && !memcmp(a4, v15, 16) )
            goto LABEL_16;
        }
        if ( (unsigned int)++v14 >= 2 )
        {
          v17 = *(_DWORD *)(a4 + 16);
          v18 = &off_8C9318;
          v19 = 0;
          while ( 1 )
          {
            v21 = *v18;
            v18 += 2;
            v20 = (unsigned int)v21;
            if ( v17 == (*v21)[4] && !memcmp(a4, v20, 16) )
              break;
            if ( (unsigned int)++v19 >= 0x18 )
              return v7;
          }
          goto LABEL_16;
        }
      }
    }
  }
LABEL_16:
  *a7 = 1;
  if ( !a6 )
    return -1073741789;
  v7 = 0;
  *a5 = 0;
  return v7;
}
