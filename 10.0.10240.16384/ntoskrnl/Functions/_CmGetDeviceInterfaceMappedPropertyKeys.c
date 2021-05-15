// _CmGetDeviceInterfaceMappedPropertyKeys 
 
int __fastcall CmGetDeviceInterfaceMappedPropertyKeys(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int (**v7)[6]; // r8
  int result; // r0
  int v9; // r7
  int (*v10)[6]; // r6
  int (*v11)[6]; // t1
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
  int v28; // [sp+10h] [bp-38h]
  unsigned __int16 *v29; // [sp+14h] [bp-34h]
  unsigned int v32; // [sp+20h] [bp-28h] BYREF
  _DWORD v33[9]; // [sp+24h] [bp-24h] BYREF

  v29 = a2;
  v28 = a4;
  v7 = &off_8C94F0;
  result = 0;
  *a7 = 0;
  v9 = 0;
  while ( 1 )
  {
    v11 = *v7;
    v7 += 2;
    v10 = v11;
    v12 = 0;
    if ( v11 )
      break;
LABEL_18:
    if ( (unsigned int)++v9 >= 3 )
      goto LABEL_19;
  }
  if ( !a4 )
  {
    result = CmGetDeviceInterfaceMappedPropertyFromRegValue(a1, a2, a3, (unsigned int)v10, v33, 0, 0, &v32);
    if ( result == -1073741789 || !result )
    {
      v12 = 1;
    }
    else if ( result == -1073741811 || result == -1073741766 || result == -1073741767 )
    {
      goto LABEL_9;
    }
    result = 0;
    if ( !v12 )
    {
LABEL_17:
      a4 = v28;
      a2 = v29;
      goto LABEL_18;
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
    goto LABEL_17;
  }
  result = -1073741675;
  *a7 = -1;
LABEL_9:
  *a7 = 0;
LABEL_19:
  if ( result < 0 )
    return result;
  v18 = &off_8C93E8;
  v19 = 0;
  while ( 2 )
  {
    v21 = *v18;
    v18 += 2;
    v20 = v21;
    v22 = 0;
    if ( !v28 )
    {
      result = CmGetDeviceInterfaceMappedPropertyFromComposite((int)a1, v29, a3, (unsigned int)v20, v33, 0, 0, &v32);
      if ( result == -1073741789 || !result )
      {
        v22 = 1;
      }
      else if ( result == -1073741811 || result == -1073741766 || result == -1073741767 )
      {
        goto LABEL_39;
      }
      result = 0;
      if ( !v22 )
      {
LABEL_36:
        if ( (unsigned int)++v19 >= 4 )
          goto LABEL_40;
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
    goto LABEL_36;
  }
  result = -1073741675;
  *a7 = -1;
LABEL_39:
  *a7 = 0;
LABEL_40:
  if ( result >= 0 )
  {
    result = -1073741789;
    if ( *a7 <= a6 )
      result = 0;
  }
  return result;
}
