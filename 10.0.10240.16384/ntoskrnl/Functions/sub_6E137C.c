// sub_6E137C 
 
int __fastcall sub_6E137C(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int *v7; // r2
  _DWORD *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  __int64 *v12; // r1
  int v13; // r0
  int v14; // r4
  int *v15; // r3
  unsigned int j; // r1
  unsigned int v17; // r0
  int v18; // r4
  int *v19; // r1
  int v20; // r0
  int v21; // r9
  int *v22; // r3
  unsigned int k; // r1
  unsigned int v24; // r0
  int v25; // r6
  _DWORD *v26; // r10
  int v27; // r1
  unsigned int m; // r1
  unsigned int v29; // r3
  int v30; // r0
  int v31; // r4
  unsigned int v32; // r6
  int v33; // r7
  unsigned int v34; // r3
  unsigned int v35; // r3
  unsigned int v36; // r6
  unsigned int v37; // r0
  int *v38; // r2
  unsigned int l; // r1
  unsigned int v40; // r3
  int v41; // r0
  int *v42; // r3
  int v43; // r1
  int v44; // r6
  int v45; // r0
  int *v46; // r2
  unsigned int n; // r1
  unsigned int v48; // r3
  int v49; // r0
  int *v50; // r3
  int v51; // r1
  unsigned int v52; // r7
  unsigned int v53; // r8
  int v54; // r0
  int v55; // r0
  unsigned int v56; // r8
  unsigned int v57; // r9
  unsigned int v58; // r8
  int v59; // r1
  _DWORD *v60; // r0
  int v61; // r3
  unsigned int v62; // r2
  unsigned int v63; // r3
  unsigned int v64; // r0
  unsigned int v65; // r1
  unsigned int v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r2
  unsigned int v69; // r0
  _DWORD *v70; // r1
  int v71; // r3
  int v72; // lr
  unsigned int v73; // r2
  unsigned int v74; // r0
  unsigned int *v75; // r1
  int v76; // [sp+0h] [bp-70h] BYREF
  int v77; // [sp+10h] [bp-60h]
  __int64 v78; // [sp+14h] [bp-5Ch]
  int v79; // [sp+1Ch] [bp-54h]
  unsigned int v80; // [sp+20h] [bp-50h]
  unsigned int v81; // [sp+24h] [bp-4Ch]
  int v82; // [sp+28h] [bp-48h]
  unsigned int v83; // [sp+2Ch] [bp-44h] BYREF
  int v84; // [sp+30h] [bp-40h]
  int v85; // [sp+34h] [bp-3Ch]
  int v86; // [sp+38h] [bp-38h]
  unsigned int v87; // [sp+3Ch] [bp-34h]
  __int64 v88; // [sp+40h] [bp-30h]
  __int64 v89; // [sp+48h] [bp-28h]

  v84 = 0;
  if ( !a1 || !a4 )
    return sub_7DAEE0();
  v7 = (int *)a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = (_DWORD *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_76;
      v8 = (_DWORD *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_76;
    }
    v12 = (__int64 *)(v8 + 1);
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_76:
      v14 = -1073741675;
      v78 = v88;
      goto LABEL_15;
    }
    v14 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 == 8 )
    {
      v78 = *v12;
      goto LABEL_15;
    }
    return -1073741789;
  }
  v14 = -1073741811;
  v78 = v88;
LABEL_15:
  if ( v14 < 0 )
    return v14;
  if ( v7 && *a1 > 4u )
  {
    v15 = v7;
    for ( j = 0; j < 4; ++j )
    {
      v17 = (unsigned int)(v15 + 1);
      v18 = *v15;
      if ( v15 + 1 < v15 )
        goto LABEL_78;
      v15 = (int *)(v18 + v17);
      if ( v18 + v17 < v17 )
        goto LABEL_78;
    }
    v19 = v15 + 1;
    v20 = *v15;
    if ( v15 + 1 < v15 )
    {
LABEL_78:
      v14 = -1073741675;
      goto LABEL_79;
    }
    v14 = 0;
    if ( !v20 )
      v19 = 0;
    if ( v20 == 4 )
    {
      v21 = *v19;
      goto LABEL_27;
    }
    return -1073741789;
  }
  v14 = -1073741811;
LABEL_79:
  v21 = v79;
LABEL_27:
  if ( v14 < 0 )
    return v14;
  if ( !v7 || *a1 <= 5u )
    return sub_7DAEE0();
  v22 = v7;
  for ( k = 0; k < 5; ++k )
  {
    v24 = (unsigned int)(v22 + 1);
    v25 = *v22;
    if ( v22 + 1 < v22 )
      return -1073741675;
    v22 = (int *)(v25 + v24);
    if ( v25 + v24 < v24 )
      return -1073741675;
  }
  v26 = v22 + 1;
  v27 = *v22;
  if ( v22 + 1 < v22 )
    return -1073741675;
  if ( !v27 )
    v26 = 0;
  if ( v27 != 32 )
    return sub_7DAEE0();
  if ( *a1 <= 6u )
  {
    v33 = -1073741811;
LABEL_93:
    v34 = v81;
    v31 = v82;
LABEL_50:
    if ( v33 >= 0 )
    {
      v35 = v34 + 1;
      v36 = 2 * v35;
      if ( 2 * v35 )
      {
        v37 = ExAllocatePoolWithTag(1, 2 * v35, 542329939);
        v80 = v37;
        if ( v37 )
        {
          memmove(v37, v31, v36);
          v38 = (int *)a1[2];
          if ( v38 && *a1 > 7u )
          {
            for ( l = 0; l < 7; ++l )
            {
              v40 = (unsigned int)(v38 + 1);
              v41 = *v38;
              if ( v38 + 1 < v38 )
                goto LABEL_72;
              v38 = (int *)(v41 + v40);
              if ( v41 + v40 < v40 )
                goto LABEL_72;
            }
            v42 = v38 + 1;
            v43 = *v38;
            if ( v38 + 1 < v38 )
            {
LABEL_72:
              v14 = -1073741675;
              goto LABEL_94;
            }
            v14 = 0;
            if ( !v43 )
              v42 = 0;
            if ( v43 == 4 )
            {
              v44 = *v42;
              goto LABEL_64;
            }
            v14 = -1073741789;
            goto LABEL_67;
          }
          v14 = -1073741811;
LABEL_94:
          v44 = v77;
LABEL_64:
          if ( v14 < 0 )
          {
LABEL_67:
            if ( v80 )
              ExFreePoolWithTag(v80);
            return v14;
          }
LABEL_65:
          v45 = sub_6E331C(v21, v26, v80, 0, 0, 0, &v83);
          v14 = v45;
          if ( v45 >= 0 )
            goto LABEL_73;
          if ( v45 != -1073741789 )
            goto LABEL_67;
          v52 = v83;
          if ( !v83 )
          {
LABEL_73:
            v14 = -1073741823;
            goto LABEL_67;
          }
          v53 = v83;
          if ( !v44 )
          {
            v54 = ExAllocatePoolWithTag(1, v83, 542329939);
            v84 = v54;
            if ( !v54 )
            {
              v14 = -1073741801;
              goto LABEL_67;
            }
            v14 = sub_6E331C(v21, v26, v80, 0, v52, v54, &v83);
            if ( v14 < 0 )
            {
LABEL_134:
              if ( v84 )
                ExFreePoolWithTag(v84);
              goto LABEL_67;
            }
            v52 = v83;
            if ( v53 < v83 )
            {
LABEL_106:
              v14 = -1073741762;
              goto LABEL_134;
            }
          }
          v55 = RtlUIntAdd(4u, 4, &v83);
          v14 = v55;
          if ( v55 < 0 )
            v56 = v87;
          else
            v56 = v83;
          if ( v55 < 0 )
            goto LABEL_134;
          v14 = RtlUIntAdd(4u, 8, &v83);
          if ( v14 < 0 )
            goto LABEL_134;
          v57 = v83 + v56;
          if ( v83 + v56 < v56 )
            goto LABEL_133;
          if ( v44 )
          {
            v14 = RtlUIntAdd(4u, 4, &v83);
            if ( v14 < 0 )
              goto LABEL_134;
            v58 = v83;
          }
          else
          {
            v58 = v52 + 4;
            if ( v52 >= 0xFFFFFFFC )
              goto LABEL_133;
          }
          v59 = v58 + v57;
          if ( v58 + v57 < v57 )
            goto LABEL_133;
          a4[1] = v59;
          if ( !v59 )
            goto LABEL_106;
          v60 = (_DWORD *)ExAllocatePoolWithTag(1, v59, 542329939);
          if ( !v60 )
          {
            v14 = -1073741801;
            goto LABEL_134;
          }
          a4[2] = (unsigned int)v60;
          *a4 = 0;
          v85 = 0;
          if ( &v76 == (int *)-52 )
          {
            v14 = -1073741811;
          }
          else
          {
            if ( v60 + 1 < v60 )
              goto LABEL_133;
            v14 = 0;
            if ( v60 + 2 > (_DWORD *)((char *)v60 + a4[1]) )
              goto LABEL_125;
            v61 = v85;
            *v60 = 4;
            v60[1] = v61;
            ++*a4;
          }
          if ( v14 < 0 )
            goto LABEL_134;
          v89 = v78;
          if ( &v76 == (int *)-72 )
          {
            v14 = -1073741811;
          }
          else
          {
            v62 = a4[2];
            if ( !v62 )
            {
              v63 = a4[1];
              if ( v63 + 12 < v63 )
              {
LABEL_132:
                a4[1] = -1;
                goto LABEL_133;
              }
              a4[1] = v63 + 12;
              ++*a4;
LABEL_146:
              if ( v44 )
              {
                v86 = v52;
                if ( &v76 != (int *)-56 )
                {
                  v66 = a4[2];
                  if ( !v66 )
                  {
                    v67 = a4[1];
                    v68 = v67 + 8;
LABEL_150:
                    if ( v68 >= v67 )
                    {
                      a4[1] = v68;
                      ++*a4;
                      v14 = 0;
                      goto LABEL_134;
                    }
                    goto LABEL_132;
                  }
                  v69 = 0;
                  v70 = (_DWORD *)a4[2];
                  if ( *a4 )
                  {
                    while ( *v70 < 0xFFFFFFFC && (_DWORD *)((char *)v70 + *v70 + 4) >= v70 )
                    {
                      ++v69;
                      v70 = (_DWORD *)((char *)v70 + *v70 + 4);
                      if ( v69 >= *a4 )
                        goto LABEL_156;
                    }
                    goto LABEL_133;
                  }
LABEL_156:
                  if ( v70 + 1 >= v70 )
                  {
                    v14 = 0;
                    if ( (unsigned int)(v70 + 2) <= v66 + a4[1] )
                    {
                      v71 = v86;
                      *v70 = 4;
                      v70[1] = v71;
LABEL_159:
                      ++*a4;
                      goto LABEL_134;
                    }
                    goto LABEL_125;
                  }
                  goto LABEL_133;
                }
                goto LABEL_162;
              }
              v72 = v84;
              if ( v84 )
              {
                if ( !v52 )
                  goto LABEL_162;
              }
              else if ( v52 )
              {
LABEL_162:
                v14 = -1073741811;
                goto LABEL_134;
              }
              v73 = a4[2];
              if ( !v73 )
              {
                if ( v52 >= 0xFFFFFFFC )
                  goto LABEL_133;
                v67 = a4[1];
                v68 = v52 + 4 + v67;
                goto LABEL_150;
              }
              v74 = 0;
              v75 = (unsigned int *)a4[2];
              if ( *a4 )
              {
                while ( *v75 < 0xFFFFFFFC && (unsigned int *)((char *)v75 + *v75 + 4) >= v75 )
                {
                  ++v74;
                  v75 = (unsigned int *)((char *)v75 + *v75 + 4);
                  if ( v74 >= *a4 )
                    goto LABEL_171;
                }
                goto LABEL_133;
              }
LABEL_171:
              if ( v75 + 1 >= v75 )
              {
                v14 = 0;
                if ( (unsigned int)v75 + v52 + 4 <= v73 + a4[1] )
                {
                  *v75 = v52;
                  if ( v72 )
                    memmove((int)(v75 + 1), v72, v52);
                  goto LABEL_159;
                }
LABEL_125:
                v14 = -1073741789;
                goto LABEL_134;
              }
LABEL_133:
              v14 = -1073741675;
              goto LABEL_134;
            }
            v64 = 0;
            v65 = a4[2];
            if ( *a4 )
            {
              while ( *(_DWORD *)v65 < 0xFFFFFFFC )
              {
                if ( *(_DWORD *)v65 + 4 + v65 < v65 )
                  goto LABEL_133;
                ++v64;
                v65 += *(_DWORD *)v65 + 4;
                if ( v64 >= *a4 )
                  goto LABEL_140;
              }
              v14 = -1073741675;
            }
            else
            {
LABEL_140:
              if ( v65 + 4 < v65 )
                goto LABEL_133;
              v14 = 0;
              if ( v65 + 12 > v62 + a4[1] )
                goto LABEL_125;
              *(_DWORD *)v65 = 8;
              *(_QWORD *)(v65 + 4) = v89;
              ++*a4;
            }
          }
          if ( v14 < 0 )
            goto LABEL_134;
          goto LABEL_146;
        }
      }
    }
  }
  else
  {
    for ( m = 0; m < 6; ++m )
    {
      v29 = (unsigned int)(v7 + 1);
      v30 = *v7;
      if ( v7 + 1 < v7 )
        goto LABEL_92;
      v7 = (int *)(v30 + v29);
      if ( v30 + v29 < v29 )
        goto LABEL_92;
    }
    v31 = (int)(v7 + 1);
    v32 = *v7;
    if ( v7 + 1 < v7 )
    {
LABEL_92:
      v33 = -1073741675;
      goto LABEL_93;
    }
    v33 = 0;
    if ( v32
      && (v32 & 1) == 0
      && !*(_WORD *)(v31 + 2 * (v32 >> 1) - 2)
      && StringCbLengthW(v31, v32, &v83) >= 0
      && v83 + 2 == v32 )
    {
      v34 = v83 >> 1;
      goto LABEL_50;
    }
  }
  v46 = (int *)a1[2];
  v80 = 0;
  if ( !v46 || *a1 <= 6u )
  {
    v14 = -1073741811;
LABEL_97:
    v44 = v77;
LABEL_98:
    if ( v14 < 0 )
      return v14;
    goto LABEL_65;
  }
  for ( n = 0; n < 6; ++n )
  {
    v48 = (unsigned int)(v46 + 1);
    v49 = *v46;
    if ( v46 + 1 < v46 )
      goto LABEL_96;
    v46 = (int *)(v49 + v48);
    if ( v49 + v48 < v48 )
      goto LABEL_96;
  }
  v50 = v46 + 1;
  v51 = *v46;
  if ( v46 + 1 < v46 )
  {
LABEL_96:
    v14 = -1073741675;
    goto LABEL_97;
  }
  v14 = 0;
  if ( !v51 )
    v50 = 0;
  if ( v51 == 4 )
  {
    v44 = *v50;
    goto LABEL_98;
  }
  return -1073741789;
}
