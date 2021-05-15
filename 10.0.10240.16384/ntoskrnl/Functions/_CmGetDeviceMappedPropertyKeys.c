// _CmGetDeviceMappedPropertyKeys 
 
int __fastcall CmGetDeviceMappedPropertyKeys(int a1, int a2, unsigned int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int (**v7)[5]; // r8
  int result; // r0
  int v9; // r6
  int (*v10)[5]; // r7
  int (*v11)[5]; // t1
  int v12; // r4
  _DWORD *v13; // r4
  int v14; // r1
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r2
  int (**v18)[5]; // r8
  int v19; // r6
  int (*v20)[5]; // r7
  int (*v21)[5]; // t1
  int v22; // r4
  _DWORD *v23; // r4
  int v24; // r1
  int v25; // r2
  int v26; // r3
  unsigned int v27; // r2
  int (**v28)[5]; // r7
  int v29; // r6
  int (*v30)[5]; // r8
  int (*v31)[5]; // t1
  int v32; // r4
  _DWORD *v33; // r4
  int v34; // r1
  int v35; // r2
  int v36; // r3
  unsigned int v37; // r2
  int v38; // [sp+10h] [bp-38h]
  unsigned __int16 *v39; // [sp+14h] [bp-34h]
  int v42; // [sp+20h] [bp-28h] BYREF
  int v43[9]; // [sp+24h] [bp-24h] BYREF

  v39 = (unsigned __int16 *)a2;
  v38 = a4;
  v7 = &CmDeviceRegPropMap;
  result = 0;
  *a7 = 0;
  v9 = 0;
  while ( 1 )
  {
    v11 = *v7;
    v7 += 4;
    v10 = v11;
    v12 = 0;
    if ( v11 )
      break;
LABEL_16:
    if ( (unsigned int)++v9 >= 0x21 )
      goto LABEL_17;
  }
  if ( !a4 )
  {
    result = CmGetDeviceMappedPropertyFromRegProp(a1, a2, a3, (unsigned int)v10, v43, 0, 0, &v42);
    if ( result == -1073741789 || !result )
    {
      v12 = 1;
    }
    else if ( result == -1073741632 )
    {
LABEL_7:
      *a7 = 0;
      return result;
    }
    result = 0;
    if ( !v12 )
    {
LABEL_15:
      a4 = v38;
      a2 = (int)v39;
      goto LABEL_16;
    }
  }
  if ( a5 && *a7 < a6 )
  {
    v13 = (_DWORD *)(a5 + 20 * *a7);
    v14 = (*v10)[1];
    v15 = (*v10)[2];
    v16 = (*v10)[3];
    *v13 = (*v10)[0];
    v13[1] = v14;
    v13[2] = v15;
    v13[3] = v16;
    v13[4] = (*v10)[4];
  }
  v17 = *a7 + 1;
  if ( v17 >= *a7 )
  {
    *a7 = v17;
    result = 0;
    goto LABEL_15;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_17:
  if ( result < 0 )
    return result;
  v18 = &off_8C94D0;
  v19 = 0;
  while ( 2 )
  {
    v21 = *v18;
    v18 += 4;
    v20 = v21;
    v22 = 0;
    if ( !v21 )
      goto LABEL_33;
    if ( !v38 )
    {
      result = CmGetDeviceMappedPropertyFromInstanceKeyRegValue(a1, (int)v39, a3, (unsigned int)v20, v43, 0, 0, &v42);
      if ( result == -1073741789 || !result )
      {
        v22 = 1;
      }
      else if ( result == -1073741632 )
      {
        goto LABEL_7;
      }
      result = 0;
      if ( !v22 )
      {
LABEL_33:
        if ( (unsigned int)++v19 >= 2 )
          goto LABEL_36;
        continue;
      }
    }
    break;
  }
  if ( a5 && *a7 < a6 )
  {
    v23 = (_DWORD *)(a5 + 20 * *a7);
    v24 = (*v20)[1];
    v25 = (*v20)[2];
    v26 = (*v20)[3];
    *v23 = (*v20)[0];
    v23[1] = v24;
    v23[2] = v25;
    v23[3] = v26;
    v23[4] = (*v20)[4];
  }
  v27 = *a7 + 1;
  if ( v27 >= *a7 )
  {
    *a7 = v27;
    result = 0;
    goto LABEL_33;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_36:
  if ( result < 0 )
    return result;
  v28 = &off_8C9318;
  v29 = 0;
  while ( 2 )
  {
    v31 = *v28;
    v28 += 2;
    v30 = v31;
    v32 = 0;
    if ( !v38 )
    {
      result = CmGetDeviceMappedPropertyFromComposite(a1, v39, a3, (unsigned int)v30, v43, 0, 0, (unsigned int *)&v42);
      if ( result == -1073741789 || !result )
      {
        v32 = 1;
      }
      else if ( result == -1073741632 )
      {
        goto LABEL_7;
      }
      result = 0;
      if ( !v32 )
      {
LABEL_50:
        if ( (unsigned int)++v29 >= 0x18 )
          goto LABEL_53;
        continue;
      }
    }
    break;
  }
  if ( a5 && *a7 < a6 )
  {
    v33 = (_DWORD *)(a5 + 20 * *a7);
    v34 = (*v30)[1];
    v35 = (*v30)[2];
    v36 = (*v30)[3];
    *v33 = (*v30)[0];
    v33[1] = v34;
    v33[2] = v35;
    v33[3] = v36;
    v33[4] = (*v30)[4];
  }
  v37 = *a7 + 1;
  if ( v37 >= *a7 )
  {
    *a7 = v37;
    result = 0;
    goto LABEL_50;
  }
  *a7 = -1;
  result = -1073741675;
  *a7 = 0;
LABEL_53:
  if ( result >= 0 )
  {
    result = -1073741789;
    if ( *a7 <= a6 )
      result = 0;
  }
  return result;
}
