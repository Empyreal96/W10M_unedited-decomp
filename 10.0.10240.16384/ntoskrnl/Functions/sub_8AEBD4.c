// sub_8AEBD4 
 
int __fastcall sub_8AEBD4(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int result; // r0
  int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r6
  int *v12; // r1
  int v13; // r6
  int v14; // r8
  int v15; // r9
  unsigned int j; // r3
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r0
  int v20; // r3
  unsigned int v21; // r5
  unsigned int v22; // r6
  int v23; // r1
  unsigned int v24; // r0
  _DWORD *v25; // r1
  int v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r0
  _DWORD *v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int v33; // r0
  _DWORD *v34; // r1
  int v35; // r3
  int v36; // [sp+0h] [bp-40h] BYREF
  int v37; // [sp+4h] [bp-3Ch] BYREF
  int v38[6]; // [sp+8h] [bp-38h] BYREF
  int v39; // [sp+20h] [bp-20h]
  int v40; // [sp+24h] [bp-1Ch]

  if ( !a1 || !a4 )
    return -1073741811;
  v7 = (int *)a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = (int *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_17;
      v8 = (int *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_17;
    }
    v12 = v8 + 1;
    v13 = *v8;
    if ( v8 + 1 >= v8 )
    {
      result = 0;
      if ( !v13 )
        v12 = 0;
      if ( v13 != 8 )
        return -1073741789;
      v14 = v12[1];
      v15 = *v12;
      goto LABEL_19;
    }
LABEL_17:
    result = -1073741675;
  }
  else
  {
    result = -1073741811;
  }
  v15 = v38[4];
  v14 = v38[5];
LABEL_19:
  if ( result >= 0 )
  {
    if ( !v7 || *a1 <= 4u )
      return -1073741811;
    for ( j = 0; j < 4; ++j )
    {
      v17 = (unsigned int)(v7 + 1);
      v18 = *v7;
      if ( v7 + 1 < v7 )
        return -1073741675;
      v7 = (int *)(v18 + v17);
      if ( v18 + v17 < v17 )
        return -1073741675;
    }
    v19 = (int)(v7 + 1);
    v20 = *v7;
    if ( v7 + 1 < v7 )
      return -1073741675;
    if ( !v20 )
      v19 = 0;
    if ( v20 != 32 )
      return -1073741811;
    result = sub_447E24(v19);
    if ( result >= 0 )
    {
      result = RtlUIntAdd(4u, 4, v38);
      v21 = result < 0 ? v38[2] : v38[0];
      if ( result >= 0 )
      {
        result = RtlUIntAdd(4u, 8, v38);
        if ( result >= 0 )
        {
          v22 = v38[0] + v21;
          if ( v38[0] + v21 < v21 )
            return -1073741675;
          result = RtlUIntAdd(4u, 4, v38);
          if ( result < 0 )
            return result;
          v23 = v38[0] + v22;
          if ( v38[0] + v22 < v22 )
            return -1073741675;
          a4[1] = v23;
          if ( !v23 )
            return -1073741762;
          v24 = ExAllocatePoolWithTag(1, v23, 542329939);
          v25 = (_DWORD *)v24;
          if ( !v24 )
            return -1073741801;
          a4[2] = v24;
          *a4 = 0;
          v36 = 0;
          if ( &v36 )
          {
            if ( v24 + 4 < v24 )
              return -1073741675;
            result = 0;
            if ( v25 + 2 > (_DWORD *)((char *)v25 + a4[1]) )
              return -1073741789;
            v26 = v36;
            *v25 = 4;
            v25[1] = v26;
            ++*a4;
          }
          else
          {
            result = -1073741811;
          }
          if ( result < 0 )
            return result;
          v39 = v15;
          v40 = v14;
          if ( &v36 == (int *)-32 )
          {
            result = -1073741811;
          }
          else
          {
            v27 = a4[2];
            if ( !v27 )
            {
              v28 = a4[1];
              if ( v28 + 12 < v28 )
              {
LABEL_53:
                a4[1] = -1;
                return -1073741675;
              }
              a4[1] = v28 + 12;
              ++*a4;
LABEL_66:
              v37 = v38[1];
              if ( &v37 )
              {
                v31 = a4[2];
                if ( !v31 )
                {
                  v32 = a4[1];
                  if ( v32 + 8 >= v32 )
                  {
                    a4[1] = v32 + 8;
                    ++*a4;
                    return 0;
                  }
                  goto LABEL_53;
                }
                v33 = 0;
                v34 = (_DWORD *)a4[2];
                if ( *a4 )
                {
                  while ( *v34 < 0xFFFFFFFC && (_DWORD *)((char *)v34 + *v34 + 4) >= v34 )
                  {
                    ++v33;
                    v34 = (_DWORD *)((char *)v34 + *v34 + 4);
                    if ( v33 >= *a4 )
                      goto LABEL_74;
                  }
                  return -1073741675;
                }
LABEL_74:
                if ( v34 + 1 >= v34 )
                {
                  result = 0;
                  if ( (unsigned int)(v34 + 2) <= v31 + a4[1] )
                  {
                    v35 = v37;
                    *v34 = 4;
                    v34[1] = v35;
                    ++*a4;
                    return result;
                  }
                  return -1073741789;
                }
                return -1073741675;
              }
              return -1073741811;
            }
            v29 = 0;
            v30 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v30 < 0xFFFFFFFC )
              {
                if ( (_DWORD *)((char *)v30 + *v30 + 4) < v30 )
                  return -1073741675;
                ++v29;
                v30 = (_DWORD *)((char *)v30 + *v30 + 4);
                if ( v29 >= *a4 )
                  goto LABEL_60;
              }
              result = -1073741675;
            }
            else
            {
LABEL_60:
              if ( v30 + 1 < v30 )
                return -1073741675;
              result = 0;
              if ( (unsigned int)(v30 + 3) > v27 + a4[1] )
                return -1073741789;
              *v30 = 8;
              v30[1] = v39;
              v30[2] = v40;
              ++*a4;
            }
          }
          if ( result >= 0 )
            goto LABEL_66;
        }
      }
    }
  }
  return result;
}
