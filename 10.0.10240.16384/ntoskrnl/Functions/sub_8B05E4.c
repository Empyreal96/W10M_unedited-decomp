// sub_8B05E4 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall sub_8B05E4(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  _DWORD *v6; // r5
  int result; // r0
  _DWORD *v8; // r3
  unsigned int i; // r2
  unsigned int v10; // r1
  int v11; // r0
  _QWORD *v12; // r2
  int v13; // r1
  int v14; // r1 OVERLAPPED
  int v15; // r2 OVERLAPPED
  int *v16; // r3
  unsigned int j; // r2
  unsigned int v18; // r1
  int v19; // r0
  int *v20; // r2
  int v21; // r1
  int v22; // r7
  unsigned int v23; // r6
  unsigned int *v24; // r3
  unsigned int k; // r2
  unsigned int v26; // r1
  unsigned int v27; // r0
  _DWORD *v28; // lr
  unsigned int v29; // r8
  int *v30; // r3
  unsigned int l; // r2
  unsigned int v32; // r1
  int v33; // r0
  int *v34; // r2
  int v35; // r1
  int v36; // r1
  unsigned int m; // r3
  unsigned int v38; // r2
  unsigned int v39; // r0
  int *v40; // r3
  unsigned int v41; // r2
  int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  unsigned int v45; // r0
  _DWORD *v46; // r1
  int v47; // r3
  int v48; // r1
  unsigned int v49; // r0
  _DWORD *v50; // r1
  int *v51; // r5
  int v52; // r3
  unsigned int v53; // r2
  unsigned int v54; // r3
  unsigned int v55; // r0
  _DWORD *v56; // r1
  int v57; // r3
  int v58; // r1
  unsigned int v59; // r0
  unsigned int v60; // r2
  unsigned int v61; // r3
  unsigned int v62; // r0
  _DWORD *v63; // r1
  int v64; // r3
  int v65; // r1
  unsigned int v66; // r0
  int v67[5]; // [sp+0h] [bp-50h] BYREF
  int v68; // [sp+14h] [bp-3Ch]
  int v69; // [sp+18h] [bp-38h] BYREF
  int v70; // [sp+1Ch] [bp-34h]
  int v71; // [sp+20h] [bp-30h] BYREF
  int v72; // [sp+24h] [bp-2Ch]
  int v73; // [sp+28h] [bp-28h]
  int v74; // [sp+30h] [bp-20h]
  int v75; // [sp+34h] [bp-1Ch]

  if ( !a1 || !a4 )
    return -1073741811;
  v6 = (_DWORD *)a1[2];
  if ( !v6 || *a1 <= 3 )
  {
    result = -1073741811;
LABEL_16:
    v14 = v74;
    v15 = v75;
    goto LABEL_17;
  }
  v8 = (_DWORD *)a1[2];
  for ( i = 0; i < 3; ++i )
  {
    v10 = (unsigned int)(v8 + 1);
    v11 = *v8;
    if ( v8 + 1 < v8 )
      goto LABEL_15;
    v8 = (_DWORD *)(v11 + v10);
    if ( v11 + v10 < v10 )
      goto LABEL_15;
  }
  v12 = v8 + 1;
  v13 = *v8;
  if ( v8 + 1 < v8 )
  {
LABEL_15:
    result = -1073741675;
    goto LABEL_16;
  }
  result = 0;
  if ( !v13 )
    v12 = 0;
  if ( v13 != 8 )
    return -1073741789;
  *(_QWORD *)&v14 = *v12;
LABEL_17:
  if ( result < 0 )
    return result;
  if ( v14 | v15 && qword_920418 )
  {
    if ( __PAIR64__(v15, v14) == qword_920418 )
    {
      if ( v6 && *a1 > 4 )
      {
        v16 = (int *)a1[2];
        for ( j = 0; j < 4; ++j )
        {
          v18 = (unsigned int)(v16 + 1);
          v19 = *v16;
          if ( v16 + 1 < v16 )
            goto LABEL_33;
          v16 = (int *)(v19 + v18);
          if ( v19 + v18 < v18 )
            goto LABEL_33;
        }
        v20 = v16 + 1;
        v21 = *v16;
        if ( v16 + 1 >= v16 )
        {
          result = 0;
          if ( !v21 )
            v20 = 0;
          if ( v21 == 4 )
          {
            v22 = *v20;
LABEL_35:
            if ( result < 0 )
              return result;
            if ( v6 )
            {
              v23 = *a1;
              if ( v23 > 5 )
              {
                v24 = v6;
                for ( k = 0; k < 5; ++k )
                {
                  v26 = (unsigned int)(v24 + 1);
                  v27 = *v24;
                  if ( v24 + 1 < v24 )
                    return -1073741675;
                  v24 = (unsigned int *)(v27 + v26);
                  if ( v27 + v26 < v26 )
                    return -1073741675;
                }
                v28 = v24 + 1;
                v29 = *v24;
                if ( v24 + 1 < v24 )
                  return -1073741675;
                if ( !v29 )
                  v28 = 0;
                if ( v23 > 6 )
                {
                  v30 = v6;
                  for ( l = 0; l < 6; ++l )
                  {
                    v32 = (unsigned int)(v30 + 1);
                    v33 = *v30;
                    if ( v30 + 1 < v30 )
                      goto LABEL_56;
                    v30 = (int *)(v33 + v32);
                    if ( v33 + v32 < v32 )
                      goto LABEL_56;
                  }
                  v34 = v30 + 1;
                  v35 = *v30;
                  if ( v30 + 1 < v30 )
                  {
LABEL_56:
                    result = -1073741675;
                    goto LABEL_57;
                  }
                  result = 0;
                  if ( !v35 )
                    v34 = 0;
                  if ( v35 == 4 )
                  {
                    v36 = *v34;
                    goto LABEL_58;
                  }
                  return -1073741789;
                }
                result = -1073741811;
LABEL_57:
                v36 = v67[3];
LABEL_58:
                if ( result < 0 )
                  return result;
                if ( v23 > 7 )
                {
                  for ( m = 0; m < 7; ++m )
                  {
                    v38 = (unsigned int)(v6 + 1);
                    v39 = *v6;
                    if ( v6 + 1 < v6 )
                      goto LABEL_70;
                    v6 = (_DWORD *)(v39 + v38);
                    if ( v39 + v38 < v38 )
                      goto LABEL_70;
                  }
                  v40 = v6 + 1;
                  v41 = *v6;
                  if ( v6 + 1 < v6 )
                  {
LABEL_70:
                    result = -1073741675;
                    goto LABEL_71;
                  }
                  result = 0;
                  if ( !v41 )
                    v40 = 0;
                  if ( v41 == 4 )
                  {
                    v42 = *v40;
                    goto LABEL_72;
                  }
                  return -1073741789;
                }
                result = -1073741811;
LABEL_71:
                v42 = v67[4];
LABEL_72:
                if ( result < 0 )
                  return result;
                result = sub_89FFCC(v22, v29, v28, v36 != 0, v42 != 0);
                if ( result < 0 )
                  return result;
                v68 = 0;
                if ( v67 == (int *)-20 )
                {
                  result = -1073741811;
                }
                else
                {
                  v43 = a4[2];
                  if ( !v43 )
                  {
                    v44 = a4[1];
                    if ( v44 + 8 < v44 )
                      goto LABEL_118;
                    a4[1] = v44 + 8;
                    ++*a4;
                    goto LABEL_88;
                  }
                  v45 = 0;
                  v46 = (_DWORD *)a4[2];
                  if ( *a4 )
                  {
                    while ( *v46 < 0xFFFFFFFC )
                    {
                      if ( (_DWORD *)((char *)v46 + *v46 + 4) < v46 )
                        return -1073741675;
                      ++v45;
                      v46 = (_DWORD *)((char *)v46 + *v46 + 4);
                      if ( v45 >= *a4 )
                        goto LABEL_82;
                    }
                    result = -1073741675;
                  }
                  else
                  {
LABEL_82:
                    if ( v46 + 1 < v46 )
                      return -1073741675;
                    result = 0;
                    if ( (unsigned int)(v46 + 2) > v43 + a4[1] )
                      return -1073741789;
                    v47 = v68;
                    *v46 = 4;
                    v46[1] = v47;
                    ++*a4;
                  }
                }
                if ( result < 0 )
                  return result;
LABEL_88:
                v48 = a4[1];
                if ( !v48 )
                  return -1073741762;
                v49 = ExAllocatePoolWithTag(1, v48, 542329939);
                v50 = (_DWORD *)v49;
                if ( !v49 )
                  return -1073741801;
                a4[2] = v49;
                *a4 = 0;
                v69 = 0;
                if ( !&v69 )
                  return -1073741811;
                v51 = (int *)(v49 + 4);
                if ( v49 + 4 >= v49 )
                {
                  result = 0;
                  if ( v50 + 2 > (_DWORD *)((char *)v50 + a4[1]) )
                    return -1073741789;
                  v52 = v69;
                  goto LABEL_139;
                }
                return -1073741675;
              }
            }
            return -1073741811;
          }
          return -1073741789;
        }
LABEL_33:
        result = -1073741675;
      }
      else
      {
        result = -1073741811;
      }
      v22 = v67[2];
      goto LABEL_35;
    }
    v70 = -2147467259;
    if ( v67 == (int *)-28 )
    {
      result = -1073741811;
    }
    else
    {
      v53 = a4[2];
      if ( !v53 )
      {
        v54 = a4[1];
        if ( v54 + 8 >= v54 )
        {
          a4[1] = v54 + 8;
          ++*a4;
          goto LABEL_108;
        }
LABEL_118:
        a4[1] = -1;
        return -1073741675;
      }
      v55 = 0;
      v56 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v56 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v56 + *v56 + 4) < v56 )
            return -1073741675;
          ++v55;
          v56 = (_DWORD *)((char *)v56 + *v56 + 4);
          if ( v55 >= *a4 )
            goto LABEL_102;
        }
        result = -1073741675;
      }
      else
      {
LABEL_102:
        if ( v56 + 1 < v56 )
          return -1073741675;
        result = 0;
        if ( (unsigned int)(v56 + 2) > v53 + a4[1] )
          return -1073741789;
        v57 = v70;
        *v56 = 4;
        v56[1] = v57;
        ++*a4;
      }
    }
    if ( result < 0 )
      return result;
LABEL_108:
    v58 = a4[1];
    if ( v58 )
    {
      v59 = ExAllocatePoolWithTag(1, v58, 542329939);
      v50 = (_DWORD *)v59;
      if ( v59 )
      {
        a4[2] = v59;
        *a4 = 0;
        v71 = -2147467259;
        if ( &v71 )
        {
          v51 = (int *)(v59 + 4);
          if ( v59 + 4 >= v59 )
          {
            result = 0;
            if ( v50 + 2 > (_DWORD *)((char *)v50 + a4[1]) )
              return -1073741789;
            v52 = -2147467259;
LABEL_139:
            *v50 = 4;
            *v51 = v52;
            ++*a4;
            return result;
          }
          return -1073741675;
        }
        return -1073741811;
      }
      return -1073741801;
    }
    return -1073741762;
  }
  v72 = -2147467259;
  if ( v67 == (int *)-36 )
  {
    result = -1073741811;
LABEL_129:
    if ( result < 0 )
      return result;
    goto LABEL_130;
  }
  v60 = a4[2];
  if ( v60 )
  {
    v62 = 0;
    v63 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v63 < 0xFFFFFFFC )
      {
        if ( (_DWORD *)((char *)v63 + *v63 + 4) < v63 )
          return -1073741675;
        ++v62;
        v63 = (_DWORD *)((char *)v63 + *v63 + 4);
        if ( v62 >= *a4 )
          goto LABEL_124;
      }
      result = -1073741675;
    }
    else
    {
LABEL_124:
      if ( v63 + 1 < v63 )
        return -1073741675;
      result = 0;
      if ( (unsigned int)(v63 + 2) > v60 + a4[1] )
        return -1073741789;
      v64 = v72;
      *v63 = 4;
      v63[1] = v64;
      ++*a4;
    }
    goto LABEL_129;
  }
  v61 = a4[1];
  if ( v61 + 8 < v61 )
    goto LABEL_118;
  a4[1] = v61 + 8;
  ++*a4;
LABEL_130:
  v65 = a4[1];
  if ( !v65 )
    return -1073741762;
  v66 = ExAllocatePoolWithTag(1, v65, 542329939);
  v50 = (_DWORD *)v66;
  if ( !v66 )
    return -1073741801;
  a4[2] = v66;
  *a4 = 0;
  v73 = -2147467259;
  if ( v67 != (int *)-40 )
  {
    v51 = (int *)(v66 + 4);
    if ( v66 + 4 >= v66 )
    {
      result = 0;
      if ( v50 + 2 > (_DWORD *)((char *)v50 + a4[1]) )
        return -1073741789;
      v52 = v73;
      goto LABEL_139;
    }
    return -1073741675;
  }
  return -1073741811;
}
