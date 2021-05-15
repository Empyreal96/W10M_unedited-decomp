// sub_8B0478 
 
int __fastcall sub_8B0478(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  int result; // r0
  int *v6; // r3
  unsigned int v7; // r5
  int *v8; // r2
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r6
  int v12; // r6
  int v13; // r1
  unsigned int j; // r2
  unsigned int v15; // r1
  int v16; // r0
  int *v17; // r2
  int v18; // r1
  int v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r0
  _DWORD *v23; // r1
  int v24; // r3
  int v25; // r1
  unsigned int v26; // r0
  _DWORD *v27; // r1
  int v28; // r3
  int v29; // [sp+0h] [bp-18h] BYREF
  int v30; // [sp+4h] [bp-14h]
  unsigned int *v31; // [sp+8h] [bp-10h] BYREF

  v29 = a2;
  v30 = a3;
  v31 = a4;
  if ( !a1 )
    return -1073741811;
  if ( !a4 )
    return -1073741811;
  v6 = (int *)a1[2];
  if ( !v6 )
    return -1073741811;
  v7 = *a1;
  if ( *a1 <= 3 )
    return -1073741811;
  v8 = (int *)a1[2];
  for ( i = 0; i < 3; ++i )
  {
    v10 = (unsigned int)(v8 + 1);
    v11 = *v8;
    if ( v8 + 1 < v8 )
      return -1073741675;
    v8 = (int *)(v11 + v10);
    if ( v11 + v10 < v10 )
      return -1073741675;
  }
  v12 = (int)(v8 + 1);
  v13 = *v8;
  if ( v8 + 1 < v8 )
    return -1073741675;
  if ( !v13 )
    v12 = 0;
  if ( v13 != 32 )
    return -1073741811;
  if ( v7 > 4 )
  {
    for ( j = 0; j < 4; ++j )
    {
      v15 = (unsigned int)(v6 + 1);
      v16 = *v6;
      if ( v6 + 1 < v6 )
        goto LABEL_26;
      v6 = (int *)(v16 + v15);
      if ( v16 + v15 < v15 )
        goto LABEL_26;
    }
    v17 = v6 + 1;
    v18 = *v6;
    if ( v6 + 1 < v6 )
    {
LABEL_26:
      result = -1073741675;
      goto LABEL_27;
    }
    result = 0;
    if ( !v18 )
      v17 = 0;
    if ( v18 == 4 )
    {
      v19 = *v17;
      goto LABEL_28;
    }
    return -1073741789;
  }
  result = -1073741811;
LABEL_27:
  v19 = v29;
LABEL_28:
  if ( result >= 0 )
  {
    result = sub_5BD6AC(v12, v19);
    if ( result >= 0 )
    {
      v30 = 0;
      if ( &v29 == (int *)-4 )
      {
        result = -1073741811;
      }
      else
      {
        v20 = a4[2];
        if ( !v20 )
        {
          v21 = a4[1];
          if ( v21 + 8 >= v21 )
          {
            a4[1] = v21 + 8;
            ++*a4;
            goto LABEL_47;
          }
          a4[1] = -1;
          return -1073741675;
        }
        v22 = 0;
        v23 = (_DWORD *)a4[2];
        if ( *a4 )
        {
          while ( *v23 < 0xFFFFFFFC )
          {
            if ( (_DWORD *)((char *)v23 + *v23 + 4) < v23 )
              return -1073741675;
            ++v22;
            v23 = (_DWORD *)((char *)v23 + *v23 + 4);
            if ( v22 >= *a4 )
              goto LABEL_41;
          }
          result = -1073741675;
        }
        else
        {
LABEL_41:
          if ( v23 + 1 < v23 )
            return -1073741675;
          result = 0;
          if ( (unsigned int)(v23 + 2) > v20 + a4[1] )
            return -1073741789;
          v24 = v30;
          *v23 = 4;
          v23[1] = v24;
          ++*a4;
        }
      }
      if ( result >= 0 )
      {
LABEL_47:
        v25 = a4[1];
        if ( !v25 )
          return -1073741762;
        v26 = ExAllocatePoolWithTag(1, v25, 542329939);
        v27 = (_DWORD *)v26;
        if ( !v26 )
          return -1073741801;
        a4[2] = v26;
        *a4 = 0;
        v31 = 0;
        if ( &v31 )
        {
          if ( v26 + 4 >= v26 )
          {
            result = 0;
            if ( v27 + 2 <= (_DWORD *)((char *)v27 + a4[1]) )
            {
              v28 = (int)v31;
              *v27 = 4;
              v27[1] = v28;
              ++*a4;
              return result;
            }
            return -1073741789;
          }
          return -1073741675;
        }
        return -1073741811;
      }
    }
  }
  return result;
}
