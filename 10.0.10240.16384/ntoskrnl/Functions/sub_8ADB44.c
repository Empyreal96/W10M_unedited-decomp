// sub_8ADB44 
 
int __fastcall sub_8ADB44(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  _DWORD *v5; // r2
  int v7; // r4
  _DWORD *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  __int64 *v12; // r1
  int v13; // r0
  unsigned int v14; // r4
  int *v15; // r3
  unsigned int j; // r1
  unsigned int v17; // r0
  int v18; // r6
  int v19; // lr
  _DWORD *v20; // r9
  int *v21; // r3
  unsigned int k; // r1
  unsigned int v23; // r0
  int v24; // r6
  _DWORD *v25; // r7
  int v26; // r10
  unsigned int l; // r1
  unsigned int v28; // r3
  int v29; // r0
  unsigned int *v30; // r3
  int v31; // r1
  unsigned int v32; // r8
  int v33; // r4
  int v34; // r2
  int v35; // r3
  int v36; // r9
  int v37; // r0
  unsigned int v38; // r6
  unsigned int v39; // r3
  unsigned int v40; // r6
  unsigned int v41; // r7
  unsigned int v42; // r1
  unsigned int v43; // r3
  unsigned int v44; // r2
  int v45; // r0
  unsigned int v46; // r3
  unsigned int v47; // r2
  unsigned int v48; // r3
  int v49; // r6
  int v50; // r0
  unsigned int v51; // r2
  unsigned int v52; // r3
  int v53; // r7
  unsigned int v54; // r0
  _DWORD *v55; // r1
  int v56; // r3
  unsigned int v57; // r2
  unsigned int v58; // r3
  unsigned int v59; // r0
  unsigned int v60; // r1
  unsigned int v61; // r2
  unsigned int v62; // r3
  unsigned int v63; // r0
  unsigned int v64; // r3
  unsigned int v65; // r2
  unsigned int v66; // r2
  unsigned int *v67; // r1
  unsigned int v68; // r0
  _DWORD *v69; // r1
  int v70; // r3
  int v72; // [sp+0h] [bp-70h] BYREF
  int v73; // [sp+10h] [bp-60h]
  int v74; // [sp+14h] [bp-5Ch] BYREF
  __int64 v75; // [sp+18h] [bp-58h]
  unsigned int v76; // [sp+20h] [bp-50h]
  int v77; // [sp+24h] [bp-4Ch]
  int v78; // [sp+28h] [bp-48h]
  int v79; // [sp+2Ch] [bp-44h] BYREF
  int v80; // [sp+30h] [bp-40h] BYREF
  int v81; // [sp+34h] [bp-3Ch]
  unsigned int v82; // [sp+38h] [bp-38h]
  __int64 v83; // [sp+40h] [bp-30h]
  __int64 v84; // [sp+48h] [bp-28h]

  v5 = (_DWORD *)a1[2];
  v81 = a2;
  v73 = 0;
  v74 = 0;
  v77 = 0;
  if ( v5 && *a1 > 3 )
  {
    v8 = v5;
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_14;
      v8 = (_DWORD *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_14;
    }
    v12 = (__int64 *)(v8 + 1);
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_14:
      v7 = -1073741675;
      v75 = v83;
    }
    else
    {
      v7 = 0;
      if ( !v13 )
        v12 = 0;
      if ( v13 != 8 )
        return -1073741789;
      v75 = *v12;
    }
  }
  else
  {
    v7 = -1073741811;
    v75 = v83;
  }
  if ( v7 < 0 )
    return v7;
  if ( !v5 )
    return -1073741811;
  v14 = *a1;
  if ( *a1 <= 4 )
    return -1073741811;
  v15 = v5;
  for ( j = 0; j < 4; ++j )
  {
    v17 = (unsigned int)(v15 + 1);
    v18 = *v15;
    if ( v15 + 1 < v15 )
      return -1073741675;
    v15 = (int *)(v18 + v17);
    if ( v18 + v17 < v17 )
      return -1073741675;
  }
  v19 = *v15;
  v20 = v15 + 1;
  v80 = *v15;
  if ( v15 + 1 < v15 )
    return -1073741675;
  if ( !v19 )
    v20 = 0;
  if ( v14 <= 5 )
    return -1073741811;
  v21 = v5;
  for ( k = 0; k < 5; ++k )
  {
    v23 = (unsigned int)(v21 + 1);
    v24 = *v21;
    if ( v21 + 1 < v21 )
      return -1073741675;
    v21 = (int *)(v24 + v23);
    if ( v24 + v23 < v23 )
      return -1073741675;
  }
  v25 = v21 + 1;
  v26 = *v21;
  if ( v21 + 1 < v21 )
    return -1073741675;
  if ( !v26 )
    v25 = 0;
  if ( v14 > 6 )
  {
    for ( l = 0; l < 6; ++l )
    {
      v28 = (unsigned int)(v5 + 1);
      v29 = *v5;
      if ( v5 + 1 < v5 )
        goto LABEL_45;
      v5 = (_DWORD *)(v29 + v28);
      if ( v29 + v28 < v28 )
        goto LABEL_45;
    }
    v30 = v5 + 1;
    v31 = *v5;
    if ( v5 + 1 < v5 )
    {
LABEL_45:
      v7 = -1073741675;
      goto LABEL_46;
    }
    v7 = 0;
    if ( !v31 )
      v30 = 0;
    if ( v31 == 4 )
    {
      v32 = *v30;
      goto LABEL_47;
    }
    return -1073741789;
  }
  v7 = -1073741811;
LABEL_46:
  v32 = v76;
LABEL_47:
  if ( v7 >= 0 )
  {
    if ( v32 )
    {
      v33 = 0;
      v34 = ExAllocatePoolWithTag(1, v32, 542329939);
      v73 = v34;
      if ( !v34 )
        return -1073741801;
      v19 = v80;
      v77 = v74;
    }
    else
    {
      v33 = 1;
      v34 = 0;
    }
    if ( off_9204A0 )
    {
      if ( v33 )
        v35 = 0;
      else
        v35 = v34;
      v36 = off_9204A0(v20, v19, v25, v26, v35, v32, &v74);
      v77 = v74;
    }
    else
    {
      v36 = -1073741637;
    }
    v37 = RtlUIntAdd(4u, 4, &v80);
    v7 = v37;
    if ( v37 < 0 )
      v38 = v82;
    else
      v38 = v80;
    if ( v37 >= 0 )
    {
      v7 = RtlUIntAdd(4u, 8, &v80);
      if ( v7 >= 0 )
      {
        v39 = v80 + v38;
        if ( v80 + v38 < v38 )
          goto LABEL_100;
        v40 = v32 + 4;
        if ( v32 >= 0xFFFFFFFC )
        {
          v7 = -1073741675;
        }
        else
        {
          v41 = v40 + v39;
          if ( v40 + v39 < v39 )
            goto LABEL_100;
          v7 = RtlUIntAdd(4u, 4, &v80);
          if ( v7 >= 0 )
          {
            v42 = v80 + v41;
            if ( v80 + v41 < v41 )
              goto LABEL_100;
            v7 = 0;
            goto LABEL_72;
          }
        }
      }
    }
    v42 = v80;
LABEL_72:
    if ( v7 < 0 )
      goto LABEL_101;
    if ( v42 < 0xFFFFFFF8 )
    {
      v43 = (v42 + 15) & 0xFFFFFFF8;
      if ( v43 >= v42 + 8 )
      {
        v44 = v43 + 8;
        if ( v43 + 8 < v43 )
          goto LABEL_85;
        v7 = 0;
      }
      else
      {
        v7 = -1073741675;
        v44 = v81;
      }
      if ( v7 < 0 )
        goto LABEL_101;
      v45 = *(_DWORD *)(v81 + 8);
      v46 = v44 + 4;
      if ( v44 < 0xFFFFFFFC )
      {
        v47 = v44 + 8;
        if ( v46 + 4 >= v46 )
        {
          v48 = v47 + v45;
          if ( v47 + v45 >= v47 && v48 + 4 >= v48 && v48 + 4 + *(_DWORD *)(v81 + 16) >= v48 + 4 )
          {
            v7 = 0;
            goto LABEL_86;
          }
        }
      }
LABEL_85:
      v7 = -1073741675;
LABEL_86:
      if ( v7 >= 0 )
      {
        if ( !a4 )
        {
          v7 = -1073741811;
          goto LABEL_101;
        }
        v7 = 0;
        a4[1] = v42;
        if ( v42 )
        {
          v50 = ExAllocatePoolWithTag(1, v42, 542329939);
          v49 = v74;
          if ( v50 )
          {
            a4[2] = v50;
            *a4 = 0;
          }
          else
          {
            v7 = -1073741801;
          }
        }
        else
        {
          v7 = -1073741762;
          v49 = v77;
        }
        if ( v7 < 0 )
          goto LABEL_101;
        v78 = v36 | 0x10000000;
        if ( &v72 == (int *)-40 )
        {
          v7 = -1073741811;
        }
        else
        {
          v51 = a4[2];
          if ( !v51 )
          {
            v52 = a4[1];
            if ( v52 + 8 < v52 )
            {
LABEL_99:
              a4[1] = -1;
              goto LABEL_100;
            }
            a4[1] = v52 + 8;
            ++*a4;
            goto LABEL_115;
          }
          v54 = 0;
          v55 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v55 < 0xFFFFFFFC )
            {
              if ( (_DWORD *)((char *)v55 + *v55 + 4) < v55 )
                goto LABEL_100;
              ++v54;
              v55 = (_DWORD *)((char *)v55 + *v55 + 4);
              if ( v54 >= *a4 )
                goto LABEL_108;
            }
            v7 = -1073741675;
          }
          else
          {
LABEL_108:
            if ( v55 + 1 < v55 )
              goto LABEL_100;
            v7 = 0;
            if ( (unsigned int)(v55 + 2) > v51 + a4[1] )
              goto LABEL_110;
            v56 = v78;
            *v55 = 4;
            v55[1] = v56;
            v49 = v74;
            ++*a4;
          }
        }
        if ( v7 < 0 )
          goto LABEL_101;
LABEL_115:
        v84 = v75;
        if ( &v72 == (int *)-72 )
        {
          v7 = -1073741811;
          goto LABEL_128;
        }
        v57 = a4[2];
        if ( !v57 )
        {
          v58 = a4[1];
          if ( v58 + 12 >= v58 )
          {
            a4[1] = v58 + 12;
            ++*a4;
            goto LABEL_129;
          }
          goto LABEL_99;
        }
        v59 = 0;
        v60 = a4[2];
        if ( *a4 )
        {
          while ( *(_DWORD *)v60 < 0xFFFFFFFC )
          {
            if ( *(_DWORD *)v60 + 4 + v60 < v60 )
              goto LABEL_100;
            ++v59;
            v60 += *(_DWORD *)v60 + 4;
            if ( v59 >= *a4 )
              goto LABEL_123;
          }
          v7 = -1073741675;
LABEL_128:
          if ( v7 < 0 )
            goto LABEL_101;
LABEL_129:
          v53 = v73;
          if ( v73 )
          {
            if ( !v32 )
              goto LABEL_131;
          }
          else if ( v32 )
          {
LABEL_131:
            v7 = -1073741811;
            goto LABEL_132;
          }
          v63 = a4[2];
          if ( v63 )
          {
            v66 = 0;
            v67 = (unsigned int *)a4[2];
            if ( !*a4 )
            {
LABEL_149:
              if ( v67 + 1 < v67 )
                goto LABEL_143;
              v7 = 0;
              if ( (unsigned int)v67 + v32 + 4 > a4[1] + v63 )
                goto LABEL_151;
              *v67 = v32;
              if ( v53 )
                memmove((int)(v67 + 1), v53, v32);
              v49 = v74;
              ++*a4;
              goto LABEL_132;
            }
            while ( *v67 < 0xFFFFFFFC )
            {
              if ( (unsigned int *)((char *)v67 + *v67 + 4) < v67 )
                goto LABEL_143;
              ++v66;
              v67 = (unsigned int *)((char *)v67 + *v67 + 4);
              if ( v66 >= *a4 )
                goto LABEL_149;
            }
          }
          else if ( v32 < 0xFFFFFFFC )
          {
            v64 = a4[1];
            v65 = v32 + 4 + v64;
            if ( v65 < v64 )
            {
LABEL_142:
              a4[1] = -1;
              goto LABEL_143;
            }
            a4[1] = v65;
            ++*a4;
            goto LABEL_133;
          }
          v7 = -1073741675;
LABEL_132:
          if ( v7 < 0 )
            goto LABEL_102;
LABEL_133:
          v79 = v49;
          if ( !&v79 )
          {
            v7 = -1073741811;
LABEL_102:
            if ( v53 )
              ExFreePoolWithTag(v53);
            return v7;
          }
          v61 = a4[2];
          if ( !v61 )
          {
            v62 = a4[1];
            if ( v62 + 8 >= v62 )
            {
              a4[1] = v62 + 8;
              ++*a4;
              v7 = 0;
              goto LABEL_102;
            }
            goto LABEL_142;
          }
          v68 = 0;
          v69 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v69 < 0xFFFFFFFC && (_DWORD *)((char *)v69 + *v69 + 4) >= v69 )
            {
              ++v68;
              v69 = (_DWORD *)((char *)v69 + *v69 + 4);
              if ( v68 >= *a4 )
                goto LABEL_159;
            }
            goto LABEL_143;
          }
LABEL_159:
          if ( v69 + 1 < v69 )
          {
LABEL_143:
            v7 = -1073741675;
            goto LABEL_102;
          }
          v7 = 0;
          if ( (unsigned int)(v69 + 2) <= v61 + a4[1] )
          {
            v70 = v79;
            *v69 = 4;
            v69[1] = v70;
            ++*a4;
            goto LABEL_102;
          }
LABEL_151:
          v7 = -1073741789;
          goto LABEL_102;
        }
LABEL_123:
        if ( v60 + 4 < v60 )
          goto LABEL_100;
        v7 = 0;
        if ( v60 + 12 <= v57 + a4[1] )
        {
          *(_DWORD *)v60 = 8;
          *(_QWORD *)(v60 + 4) = v84;
          v49 = v74;
          ++*a4;
          goto LABEL_128;
        }
LABEL_110:
        v7 = -1073741789;
      }
LABEL_101:
      v53 = v73;
      goto LABEL_102;
    }
LABEL_100:
    v7 = -1073741675;
    goto LABEL_101;
  }
  return v7;
}
