// _CmGetInterfaceClassMappedPropertyKeys 
 
int __fastcall CmGetInterfaceClassMappedPropertyKeys(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, unsigned int a6, unsigned int *a7)
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
  int v18; // r4
  _DWORD *v19; // r4
  unsigned int v20; // r2
  int v21; // [sp+10h] [bp-38h]
  int v22; // [sp+14h] [bp-34h]
  int v25; // [sp+20h] [bp-28h] BYREF
  _DWORD v26[9]; // [sp+24h] [bp-24h] BYREF

  v22 = (int)a2;
  v21 = a4;
  v7 = &off_8C9508;
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
LABEL_16:
    if ( ++v9 )
      goto LABEL_17;
  }
  if ( !a4 )
  {
    result = CmGetInterfaceClassMappedPropertyFromRegValue(a1, a2, a3, (unsigned int)v10, v26, 0, 0, &v25);
    if ( result == -1073741789 || !result )
    {
      v12 = 1;
    }
    else if ( result == -1073741772 )
    {
      goto LABEL_7;
    }
    result = 0;
    if ( !v12 )
    {
LABEL_15:
      a4 = v21;
      a2 = (unsigned __int16 *)v22;
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
  if ( result >= 0 )
  {
    v18 = 0;
    if ( v21 )
      goto LABEL_27;
    result = CmGetInterfaceClassMappedPropertyFromComposite(
               (int)a1,
               v22,
               a3,
               (unsigned int)DEVPKEY_NAME,
               v26,
               0,
               0,
               &v25);
    if ( result == -1073741789 || !result )
    {
      v18 = 1;
    }
    else if ( result == -1073741772 )
    {
LABEL_7:
      *a7 = 0;
      return result;
    }
    result = 0;
    if ( v18 )
    {
LABEL_27:
      if ( a5 && *a7 < a6 )
      {
        v19 = (_DWORD *)(a5 + 20 * *a7);
        *v19 = -1222250192;
        v19[1] = 270157807;
        v19[2] = 1610805669;
        v19[3] = -1393844596;
        v19[4] = 10;
      }
      v20 = *a7 + 1;
      if ( v20 < *a7 )
      {
        *a7 = -1;
        result = -1073741675;
        *a7 = 0;
      }
      else
      {
        *a7 = v20;
        result = 0;
      }
    }
    if ( result >= 0 )
    {
      result = -1073741789;
      if ( *a7 <= a6 )
        result = 0;
    }
  }
  return result;
}
