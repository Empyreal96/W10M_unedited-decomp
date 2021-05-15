// _CmGetDeviceMappedProperty 
 
int __fastcall CmGetDeviceMappedProperty(int a1, int a2, unsigned int a3, int a4, unsigned int a5, _DWORD *a6, _DWORD *a7, unsigned int a8, int *a9)
{
  unsigned int v9; // r0
  int (**v10)[5]; // r5
  int v11; // r4
  int v12; // r6
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  unsigned int v15; // r7
  _DWORD *v16; // r8
  _DWORD *v17; // r9
  int v18; // r6
  int (**v19)[5]; // r5
  int v20; // r4
  unsigned int v21; // r1
  int (*v22)[5]; // t1
  int (**v23)[5]; // r5
  int v24; // r4
  int v25; // r6
  unsigned int v26; // r1
  int (*v27)[5]; // t1
  int v29; // [sp+10h] [bp-30h]

  v29 = -1073741802;
  *a9 = 0;
  if ( a4 )
    return v29;
  v9 = a5;
  v10 = &CmDeviceRegPropMap;
  v11 = 0;
  v12 = *(_DWORD *)(a5 + 16);
  while ( 1 )
  {
    v14 = *v10;
    v10 += 4;
    v13 = (unsigned int)v14;
    if ( v12 == (*v14)[4] )
      break;
LABEL_4:
    if ( (unsigned int)++v11 >= 0x21 )
    {
      v15 = a8;
      v16 = a7;
      v17 = a6;
      goto LABEL_6;
    }
  }
  if ( memcmp(v9, v13, 16) )
  {
    v9 = a5;
    goto LABEL_4;
  }
  v16 = a7;
  v17 = a6;
  v15 = a8;
  v29 = CmGetDeviceMappedPropertyFromRegProp(a1, a2, a3, a5, a6, a7, a8, a9);
  if ( v29 != -1073741802 )
    return v29;
  v9 = a5;
LABEL_6:
  v18 = *(_DWORD *)(v9 + 16);
  v19 = &off_8C94D0;
  v20 = 0;
  while ( 2 )
  {
    v22 = *v19;
    v19 += 4;
    v21 = (unsigned int)v22;
    if ( v18 != (*v22)[4] )
    {
LABEL_8:
      if ( (unsigned int)++v20 >= 2 )
        goto LABEL_9;
      continue;
    }
    break;
  }
  if ( memcmp(v9, v21, 16) )
  {
    v9 = a5;
    goto LABEL_8;
  }
  v29 = CmGetDeviceMappedPropertyFromInstanceKeyRegValue(a1, a2, a3, a5, v17, v16, v15, a9);
  if ( v29 != -1073741802 )
    return v29;
LABEL_9:
  v23 = &off_8C9318;
  v24 = 0;
  v25 = *(_DWORD *)(a5 + 16);
  while ( 1 )
  {
    v27 = *v23;
    v23 += 2;
    v26 = (unsigned int)v27;
    if ( v25 == (*v27)[4] && !memcmp(a5, v26, 16) )
      break;
    if ( (unsigned int)++v24 >= 0x18 )
      return v29;
  }
  return CmGetDeviceMappedPropertyFromComposite(a1, a2, a3, a5, v17, v16, v15, a9);
}
