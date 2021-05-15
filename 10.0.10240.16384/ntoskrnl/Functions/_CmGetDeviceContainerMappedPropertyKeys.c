// _CmGetDeviceContainerMappedPropertyKeys 
 
int __fastcall CmGetDeviceContainerMappedPropertyKeys(int a1, int a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int result; // r0
  int (**v8)[5]; // r8
  int v9; // r6
  int (*v10)[5]; // r7
  int (*v11)[5]; // t1
  _DWORD *v12; // r4
  int v13; // r1
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r2

  result = 0;
  v8 = &off_40B4B8;
  *a7 = 0;
  v9 = 0;
  while ( 1 )
  {
    v11 = *v8;
    v8 += 2;
    v10 = v11;
    if ( v11 )
      break;
LABEL_8:
    if ( (unsigned int)++v9 >= 4 )
      goto LABEL_11;
  }
  if ( a5 && *a7 < a6 )
  {
    v12 = (_DWORD *)(a5 + 20 * *a7);
    v13 = (*v10)[1];
    v14 = (*v10)[2];
    v15 = (*v10)[3];
    *v12 = (*v10)[0];
    v12[1] = v13;
    v12[2] = v14;
    v12[3] = v15;
    v12[4] = (*v10)[4];
  }
  v16 = *a7 + 1;
  if ( v16 >= *a7 )
  {
    *a7 = v16;
    result = 0;
    goto LABEL_8;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_11:
  if ( result >= 0 )
  {
    if ( *a7 <= a6 )
      result = 0;
    else
      result = -1073741789;
  }
  return result;
}
