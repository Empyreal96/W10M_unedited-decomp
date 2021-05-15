// sub_8B0158 
 
int __fastcall sub_8B0158(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  unsigned int *v7; // r2
  _DWORD *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  __int64 *v12; // r1
  int v13; // r0
  unsigned int j; // r3
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r6
  unsigned int v18; // r7
  unsigned int *v19; // r2
  unsigned int v20; // r9
  int v21; // r0
  int v22; // r10
  unsigned int k; // r1
  unsigned int v24; // r3
  unsigned int v25; // r0
  int v26; // r6
  unsigned int v27; // r7
  int v28; // r7
  unsigned int v29; // r7
  int v30; // r0
  int v31; // r0
  unsigned int v32; // r6
  int v33; // r1
  _DWORD *v34; // r0
  unsigned int v35; // r2
  unsigned int v36; // r3
  unsigned int v38; // r0
  unsigned int v39; // r1
  __int64 v40; // [sp+0h] [bp-68h] BYREF
  unsigned int v41; // [sp+8h] [bp-60h]
  int v42; // [sp+Ch] [bp-5Ch]
  unsigned int v43; // [sp+10h] [bp-58h]
  int v44; // [sp+14h] [bp-54h]
  int v45; // [sp+18h] [bp-50h]
  int v46[7]; // [sp+1Ch] [bp-4Ch] BYREF
  __int64 v47; // [sp+38h] [bp-30h]
  __int64 v48; // [sp+40h] [bp-28h] BYREF

  if ( !a1 || !a2 || !a4 )
    return -1073741811;
  v7 = (unsigned int *)a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = (_DWORD *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_18;
      v8 = (_DWORD *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_18;
    }
    v12 = (__int64 *)(v8 + 1);
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_18:
      v6 = -1073741675;
      v40 = v47;
      goto LABEL_19;
    }
    v6 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 == 8 )
    {
      v40 = *v12;
      goto LABEL_19;
    }
    return -1073741789;
  }
  v6 = -1073741811;
  v40 = v47;
LABEL_19:
  if ( v6 >= 0 )
  {
    if ( v7 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v15 = (unsigned int)(v7 + 1);
        v16 = *v7;
        if ( v7 + 1 < v7 )
          goto LABEL_37;
        v7 = (unsigned int *)(v16 + v15);
        if ( v16 + v15 < v15 )
          goto LABEL_37;
      }
      v17 = (int)(v7 + 1);
      v18 = *v7;
      if ( v7 + 1 < v7 )
      {
LABEL_37:
        v6 = -1073741675;
        goto LABEL_38;
      }
      v6 = 0;
      if ( v18
        && (v18 & 1) == 0
        && !*(_WORD *)(v17 + 2 * (v18 >> 1) - 2)
        && StringCbLengthW(v17, v18, v46) >= 0
        && v46[0] + 2 == v18 )
      {
        v20 = (unsigned int)v46[0] >> 1;
        goto LABEL_39;
      }
      return -1073741762;
    }
    v6 = -1073741811;
LABEL_38:
    v20 = v41;
    v17 = v42;
LABEL_39:
    if ( v6 >= 0 )
    {
      if ( !(2 * (v20 + 1)) )
        return -1073741762;
      v21 = ExAllocatePoolWithTag(1, 2 * (v20 + 1), 542329939);
      v22 = v21;
      if ( !v21 )
        return -1073741801;
      memmove(v21, v17, 2 * (v20 + 1));
      v19 = (unsigned int *)a1[2];
      if ( v19 && *a1 > 5u )
      {
        for ( k = 0; k < 5; ++k )
        {
          v24 = (unsigned int)(v19 + 1);
          v25 = *v19;
          if ( v19 + 1 < v19 )
            goto LABEL_60;
          v19 = (unsigned int *)(v25 + v24);
          if ( v25 + v24 < v24 )
            goto LABEL_60;
        }
        v26 = (int)(v19 + 1);
        v27 = *v19;
        if ( v19 + 1 < v19 )
        {
LABEL_60:
          v6 = -1073741675;
          goto LABEL_61;
        }
        v6 = 0;
        if ( v27
          && (v27 & 1) == 0
          && !*(_WORD *)(v26 + 2 * (v27 >> 1) - 2)
          && StringCbLengthW(v26, v27, v46) >= 0
          && v46[0] + 2 == v27 )
        {
          v29 = (unsigned int)v46[0] >> 1;
          goto LABEL_62;
        }
        return -1073741762;
      }
      v6 = -1073741811;
LABEL_61:
      v29 = v43;
      v26 = v44;
LABEL_62:
      if ( v6 >= 0 )
      {
        if ( !(2 * (v29 + 1)) )
          return -1073741762;
        v30 = ExAllocatePoolWithTag(1, 2 * (v29 + 1), 542329939);
        if ( !v30 )
          return -1073741801;
        memmove(v30, v26, 2 * (v29 + 1));
        v28 = ExUpdateOsPfnInRegistry(2 * (v20 + 1), v22, 2 * (v29 + 1));
        if ( v28 >= 0 )
        {
          v28 = off_9204B4 ? off_9204B4(v22) : -1073741637;
          if ( v28 == -1073741198 )
            v28 = 0;
        }
        v31 = RtlUIntAdd(4u, 4, v46);
        v6 = v31;
        v32 = v31 < 0 ? v46[5] : v46[0];
        if ( v31 >= 0 )
        {
          v6 = RtlUIntAdd(4u, 8, v46);
          if ( v6 >= 0 )
          {
            v33 = v46[0] + v32;
            if ( v46[0] + v32 < v32 )
              return -1073741675;
            a4[1] = v33;
            if ( !v33 )
              return -1073741762;
            v34 = (_DWORD *)ExAllocatePoolWithTag(1, v33, 542329939);
            if ( !v34 )
              return -1073741801;
            a4[2] = (unsigned int)v34;
            *a4 = 0;
            v45 = v28 | 0x10000000;
            if ( &v40 == (__int64 *)-24 )
            {
              v6 = -1073741811;
            }
            else
            {
              if ( v34 + 1 < v34 )
                return -1073741675;
              v6 = 0;
              if ( v34 + 2 > (_DWORD *)((char *)v34 + a4[1]) )
                return -1073741789;
              *v34 = 4;
              v34[1] = v45;
              ++*a4;
            }
            if ( v6 < 0 )
              return v6;
            v48 = v40;
            if ( &v48 )
            {
              v35 = a4[2];
              if ( v35 )
              {
                v38 = 0;
                v39 = a4[2];
                if ( *a4 )
                {
                  while ( *(_DWORD *)v39 < 0xFFFFFFFC && *(_DWORD *)v39 + 4 + v39 >= v39 )
                  {
                    ++v38;
                    v39 += *(_DWORD *)v39 + 4;
                    if ( v38 >= *a4 )
                      goto LABEL_97;
                  }
                }
                else
                {
LABEL_97:
                  if ( v39 + 4 >= v39 )
                  {
                    v6 = 0;
                    if ( v39 + 12 <= v35 + a4[1] )
                    {
                      *(_DWORD *)v39 = 8;
                      *(_QWORD *)(v39 + 4) = v48;
                      ++*a4;
                      return v6;
                    }
                    return -1073741789;
                  }
                }
              }
              else
              {
                v36 = a4[1];
                if ( v36 + 12 >= v36 )
                {
                  a4[1] = v36 + 12;
                  ++*a4;
                  return 0;
                }
                a4[1] = -1;
              }
              return -1073741675;
            }
            return -1073741811;
          }
        }
      }
    }
  }
  return v6;
}
