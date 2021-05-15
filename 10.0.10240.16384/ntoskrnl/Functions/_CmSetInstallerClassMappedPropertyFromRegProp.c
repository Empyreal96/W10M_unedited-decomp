// _CmSetInstallerClassMappedPropertyFromRegProp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmSetInstallerClassMappedPropertyFromRegProp(int a1, int a2, int a3, unsigned int a4, int a5, _BYTE *a6, int a7)
{
  int v7; // r9
  int (**v8)[5]; // r7
  unsigned int i; // r6
  int (**v12)[5]; // r5
  unsigned int v13; // r1
  int (*v14)[5]; // t1
  int result; // r0
  int v16; // r1 OVERLAPPED
  int v17; // r2 OVERLAPPED
  bool v18; // zf
  int v19; // r0
  int v20; // r3
  int v21; // r1
  int v22; // r3
  int *v23; // r3
  int v24; // r2
  int v25; // [sp+10h] [bp-28h] BYREF
  int v26; // [sp+14h] [bp-24h]
  int v27; // [sp+18h] [bp-20h]

  v7 = *(_DWORD *)(a4 + 16);
  v8 = &CmClassRegPropMap;
  v26 = a2;
  v27 = a1;
  for ( i = 0; i < 9; ++i )
  {
    v12 = v8;
    v14 = *v8;
    v8 += 4;
    v13 = (unsigned int)v14;
    if ( v7 == (*v14)[4] && !memcmp(a4, v13, 16) )
      break;
    v12 = 0;
  }
  if ( !v12 )
    return -1073741264;
  *(_QWORD *)&v16 = *(_QWORD *)(v12 + 1);
  if ( a5 != v16 )
  {
    if ( a5 == 25 )
    {
      v18 = v16 == 18;
    }
    else
    {
      if ( !a5 )
        goto LABEL_14;
      v18 = a5 == 1;
    }
    if ( !v18 )
      return -1073741811;
  }
LABEL_14:
  v19 = (int)v12[3];
  if ( v17 == 25 )
    return -1073741637;
  if ( v17 == 27 )
  {
    if ( a6 )
    {
      if ( !a7 )
        return -1073741811;
      if ( (char)*a6 == -1 )
      {
        v22 = 1;
      }
      else
      {
        if ( *a6 )
          return -1073741811;
        v22 = 0;
      }
      v25 = v22;
      v23 = &v25;
      v24 = 4;
    }
    else
    {
      v23 = 0;
      v24 = 0;
    }
    result = CmSetInstallerClassRegProp(v27, v26, a3, 27, v19, (int)v23, v24);
  }
  else
  {
    v20 = (int)a6;
    if ( a6 )
    {
      v21 = a7;
    }
    else
    {
      v20 = 0;
      v21 = 0;
    }
    result = CmSetInstallerClassRegProp(v27, v26, a3, v17, v19, v20, v21);
  }
  return result;
}
