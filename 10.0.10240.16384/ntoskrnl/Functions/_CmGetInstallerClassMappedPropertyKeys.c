// _CmGetInstallerClassMappedPropertyKeys 
 
int __fastcall CmGetInstallerClassMappedPropertyKeys(int *a1, int a2, unsigned int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int (**v7)[5]; // r8
  unsigned int v8; // r2
  int result; // r0
  int v10; // r5
  int (*v11)[5]; // r7
  int (*v12)[5]; // t1
  int v13; // r4
  _DWORD *v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  int (**v19)[5]; // r9
  int v20; // r5
  int (**v21)[5]; // r8
  int (*v22)[5]; // r7
  int (*v23)[5]; // t1
  int v24; // r4
  _DWORD *v25; // r4
  int v26; // r1
  int v27; // r2
  int v28; // r3
  unsigned int v29; // r2
  int v30; // r5
  int (*v31)[5]; // r7
  int (*v32)[5]; // t1
  int v33; // r4
  unsigned int v34; // r2
  _DWORD *v35; // r4
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int v39; // r0
  _DWORD *v40; // r5
  unsigned int v41; // r2
  unsigned __int16 *v42; // [sp+10h] [bp-38h]
  int v43; // [sp+14h] [bp-34h]
  int v46; // [sp+20h] [bp-28h] BYREF
  int (*v47[9])[5]; // [sp+24h] [bp-24h] BYREF

  v42 = (unsigned __int16 *)a2;
  v43 = a4;
  v7 = &CmClassRegPropMap;
  *a7 = 0;
  v8 = a6;
  result = 0;
  v10 = 0;
  while ( 1 )
  {
    v12 = *v7;
    v7 += 4;
    v11 = v12;
    v13 = 0;
    if ( v12 )
      break;
LABEL_16:
    if ( (unsigned int)++v10 >= 9 )
      goto LABEL_17;
  }
  if ( !a4 )
  {
    result = CmGetInstallerClassMappedPropertyFromRegProp((int)a1, a2, a3, (int)v11, (unsigned int *)v47, 0, 0, &v46);
    if ( result == -1073741789 || !result )
    {
      v13 = 1;
    }
    else if ( result == -1073741772 )
    {
LABEL_7:
      *a7 = 0;
      return result;
    }
    v8 = a6;
    result = 0;
    if ( !v13 )
    {
LABEL_15:
      a2 = (int)v42;
      a4 = v43;
      goto LABEL_16;
    }
  }
  if ( a5 && *a7 < v8 )
  {
    v14 = (_DWORD *)(a5 + 20 * *a7);
    v15 = (*v11)[1];
    v16 = (*v11)[2];
    v17 = (*v11)[3];
    *v14 = (*v11)[0];
    v14[1] = v15;
    v14[2] = v16;
    v14[3] = v17;
    v14[4] = (*v11)[4];
  }
  v18 = *a7 + 1;
  if ( v18 >= *a7 )
  {
    *a7 = v18;
    v8 = a6;
    result = 0;
    goto LABEL_15;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_17:
  if ( result < 0 )
    return result;
  v19 = &off_8C93D8;
  v20 = 0;
  v21 = &off_8C9410;
  while ( 2 )
  {
    v23 = *v21;
    v21 += 4;
    v22 = v23;
    v24 = 0;
    if ( !v23 )
      goto LABEL_33;
    if ( !v43 )
    {
      result = CmGetInstallerClassMappedPropertyFromRegValue(a1, v42, a3, (unsigned int)v22, v47, 0, 0, &v46);
      if ( result == -1073741789 || !result )
      {
        v24 = 1;
      }
      else if ( result == -1073741772 )
      {
        goto LABEL_7;
      }
      result = 0;
      if ( !v24 )
      {
LABEL_33:
        if ( (unsigned int)++v20 >= 0xC )
          goto LABEL_36;
        continue;
      }
    }
    break;
  }
  if ( a5 && *a7 < a6 )
  {
    v25 = (_DWORD *)(a5 + 20 * *a7);
    v26 = (*v22)[1];
    v27 = (*v22)[2];
    v28 = (*v22)[3];
    *v25 = (*v22)[0];
    v25[1] = v26;
    v25[2] = v27;
    v25[3] = v28;
    v25[4] = (*v22)[4];
  }
  v29 = *a7 + 1;
  if ( v29 >= *a7 )
  {
    *a7 = v29;
    result = 0;
    goto LABEL_33;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_36:
  if ( result < 0 )
    return result;
  v30 = 0;
  while ( 2 )
  {
    v32 = *v19;
    v19 += 2;
    v31 = v32;
    v33 = 0;
    if ( !v43 )
    {
      result = CmGetInstallerClassMappedPropertyFromComposite(
                 (int)a1,
                 (int)v42,
                 a3,
                 (unsigned int)v31,
                 v47,
                 0,
                 0,
                 (unsigned int *)&v46);
      if ( result == -1073741789 || !result )
      {
        v33 = 1;
      }
      else if ( result == -1073741772 )
      {
        goto LABEL_7;
      }
      result = 0;
      if ( !v33 )
      {
LABEL_50:
        if ( (unsigned int)++v30 >= 2 )
          goto LABEL_53;
        continue;
      }
    }
    break;
  }
  if ( a5 && *a7 < a6 )
  {
    v35 = (_DWORD *)(a5 + 20 * *a7);
    v36 = (*v31)[1];
    v37 = (*v31)[2];
    v38 = (*v31)[3];
    *v35 = (*v31)[0];
    v35[1] = v36;
    v35[2] = v37;
    v35[3] = v38;
    v35[4] = (*v31)[4];
  }
  v34 = *a7 + 1;
  if ( v34 >= *a7 )
  {
    *a7 = v34;
    result = 0;
    goto LABEL_50;
  }
  result = -1073741675;
  *a7 = -1;
  *a7 = 0;
LABEL_53:
  if ( result >= 0 )
  {
    if ( v43
      || (v39 = CmGetInstallerClassMappedPropertyFromCoInstallers(a1, v42, v34, v47, 0, 0, &v46), v39 == -1073741789)
      || !v39 )
    {
      if ( a5 && *a7 < a6 )
      {
        v40 = (_DWORD *)(a5 + 20 * *a7);
        *v40 = 1899828995;
        v40[1] = 1240834786;
        v40[2] = 1196823698;
        v40[3] = 1557852974;
        v40[4] = 2;
      }
      v41 = *a7 + 1;
      if ( v41 >= *a7 )
      {
        *a7 = v41;
        goto LABEL_62;
      }
      result = -1073741675;
      *a7 = 0;
    }
    else
    {
LABEL_62:
      if ( *a7 <= a6 )
        result = 0;
      else
        result = -1073741789;
    }
  }
  return result;
}
