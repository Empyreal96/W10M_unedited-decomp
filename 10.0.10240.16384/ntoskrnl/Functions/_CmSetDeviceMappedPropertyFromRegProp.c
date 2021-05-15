// _CmSetDeviceMappedPropertyFromRegProp 
 
int __fastcall CmSetDeviceMappedPropertyFromRegProp(int a1, int a2, int a3, unsigned int a4, int a5, _BYTE *a6, unsigned int a7)
{
  int v7; // r10
  int v8; // r5
  int (**v9)[5]; // r8
  unsigned int i; // r7
  int (**v12)[5]; // r6
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  __int64 v15; // kr00_8
  int result; // r0
  int v17; // r6
  int v18; // r3
  char *v19; // r3
  int v20; // r3
  int *v21; // r3
  int v22; // r2
  int v26; // [sp+1Ch] [bp-74h] BYREF
  char v27[112]; // [sp+20h] [bp-70h] BYREF

  v7 = *(_DWORD *)(a4 + 16);
  v8 = (int)a6;
  v9 = &CmDeviceRegPropMap;
  for ( i = 0; i < 0x21; ++i )
  {
    v12 = v9;
    v14 = *v9;
    v9 += 4;
    v13 = (unsigned int)v14;
    if ( v7 == (*v14)[4] && !memcmp(a4, v13, 16) )
      break;
    v12 = 0;
  }
  if ( !v12 )
    return -1073741264;
  v15 = *(_QWORD *)(v12 + 1);
  if ( a5 != (_DWORD)v15 )
    return sub_7EFBAC();
  v17 = (int)v12[3];
  switch ( HIDWORD(v15) )
  {
    case 9:
      goto LABEL_17;
    case 0x19:
      return -1073741637;
    case 0x1B:
      if ( a6 )
      {
        if ( !a7 )
          return -1073741811;
        if ( (char)*a6 == -1 )
        {
          v20 = 1;
        }
        else
        {
          if ( *a6 )
            return -1073741811;
          v20 = 0;
        }
        v26 = v20;
        v21 = &v26;
        v22 = 4;
      }
      else
      {
        v21 = 0;
        v22 = 0;
      }
      return CmSetDeviceRegProp(a1, a2, a3, 27, v17, (int)v21, v22, 0);
    case 0x25:
LABEL_17:
      if ( !a6 )
      {
        v19 = 0;
        return CmSetDeviceRegProp(a1, a2, a3, SHIDWORD(v15), v17, (int)v19, v15, 0);
      }
      if ( a7 >= 0x10 )
      {
        result = PnpStringFromGuid((int)a6, (int)v27);
        if ( result < 0 )
          return result;
        v19 = v27;
        return CmSetDeviceRegProp(a1, a2, a3, SHIDWORD(v15), v17, (int)v19, v15, 0);
      }
      return -1073741811;
  }
  if ( a6 )
  {
    v18 = a7;
  }
  else
  {
    v8 = 0;
    v18 = 0;
  }
  return CmSetDeviceRegProp(a1, a2, a3, SHIDWORD(v15), v17, v8, v18, 0);
}
