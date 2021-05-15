// sub_5C4A14 
 
int __fastcall sub_5C4A14(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  _DWORD *v5; // r2
  int v7; // lr
  int v8; // r4
  int *v9; // r3
  unsigned int i; // r1
  unsigned int v11; // r0
  int v12; // r4
  int *v13; // r1
  int v14; // r0
  int v15; // r3
  int v16; // r10
  unsigned int v17; // r4
  int *v18; // r3
  unsigned int j; // r1
  unsigned int v20; // r0
  int v21; // r6
  _DWORD *v22; // r7
  int v23; // r9
  unsigned int k; // r1
  unsigned int v25; // r3
  int v26; // r0
  unsigned int *v27; // r3
  int v28; // r1
  unsigned int v29; // r8
  int v30; // r4
  int v31; // r2
  int v32; // r9
  int v33; // r0
  unsigned int v34; // r6
  unsigned int v35; // r3
  unsigned int v36; // r6
  unsigned int v37; // r7
  unsigned int v38; // r1
  unsigned int v39; // r3
  unsigned int v40; // r2
  int v41; // r0
  unsigned int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  int v45; // r6
  int v46; // r0
  unsigned int v47; // r2
  unsigned int v48; // r3
  int v49; // r7
  unsigned int v50; // r0
  _DWORD *v51; // r1
  int v52; // r3
  unsigned int v53; // r2
  unsigned int v54; // r3
  unsigned int v55; // r0
  _DWORD *v56; // r1
  unsigned int v57; // r2
  unsigned int v58; // r3
  unsigned int v59; // r0
  unsigned int v60; // r3
  unsigned int v61; // r2
  unsigned int v62; // r2
  unsigned int *v63; // r1
  unsigned int v64; // r0
  _DWORD *v65; // r1
  int v66; // r3
  int v68[2]; // [sp+0h] [bp-60h] BYREF
  int v69; // [sp+8h] [bp-58h]
  int v70; // [sp+Ch] [bp-54h] BYREF
  int v71; // [sp+10h] [bp-50h]
  unsigned int v72; // [sp+14h] [bp-4Ch]
  int v73; // [sp+18h] [bp-48h]
  int v74; // [sp+1Ch] [bp-44h]
  int v75; // [sp+20h] [bp-40h] BYREF
  unsigned int v76; // [sp+24h] [bp-3Ch] BYREF
  int v77; // [sp+28h] [bp-38h]
  unsigned int v78; // [sp+2Ch] [bp-34h]
  int v79; // [sp+30h] [bp-30h]
  int v80; // [sp+34h] [bp-2Ch]
  int v81; // [sp+38h] [bp-28h]
  int v82; // [sp+3Ch] [bp-24h]

  v5 = (_DWORD *)a1[2];
  v7 = 0;
  v77 = a2;
  v69 = 0;
  v70 = 0;
  v73 = 0;
  if ( v5 && *a1 > 3 )
  {
    v9 = v5;
    for ( i = 0; i < 3; ++i )
    {
      v11 = (unsigned int)(v9 + 1);
      v12 = *v9;
      if ( v9 + 1 < v9 )
        goto LABEL_14;
      v9 = (int *)(v12 + v11);
      if ( v12 + v11 < v11 )
        goto LABEL_14;
    }
    v13 = v9 + 1;
    v14 = *v9;
    if ( v9 + 1 < v9 )
    {
LABEL_14:
      v8 = -1073741675;
      goto LABEL_15;
    }
    v8 = 0;
    if ( !v14 )
      v13 = 0;
    if ( v14 == 8 )
    {
      v16 = v13[1];
      v15 = *v13;
      goto LABEL_16;
    }
    return -1073741789;
  }
  v8 = -1073741811;
LABEL_15:
  v15 = v79;
  v16 = v80;
LABEL_16:
  v71 = v15;
  if ( v8 >= 0 )
  {
    if ( !v5 )
      return -1073741811;
    v17 = *a1;
    if ( *a1 <= 4 )
      return -1073741811;
    v18 = v5;
    for ( j = 0; j < 4; ++j )
    {
      v20 = (unsigned int)(v18 + 1);
      v21 = *v18;
      if ( v18 + 1 < v18 )
        return -1073741675;
      v18 = (int *)(v21 + v20);
      if ( v21 + v20 < v20 )
        return -1073741675;
    }
    v22 = v18 + 1;
    v23 = *v18;
    if ( v18 + 1 < v18 )
      return -1073741675;
    if ( !v23 )
      v22 = 0;
    if ( v17 > 5 )
    {
      for ( k = 0; k < 5; ++k )
      {
        v25 = (unsigned int)(v5 + 1);
        v26 = *v5;
        if ( v5 + 1 < v5 )
          goto LABEL_38;
        v5 = (_DWORD *)(v26 + v25);
        if ( v26 + v25 < v25 )
          goto LABEL_38;
      }
      v27 = v5 + 1;
      v28 = *v5;
      if ( v5 + 1 < v5 )
      {
LABEL_38:
        v8 = -1073741675;
        goto LABEL_39;
      }
      v8 = 0;
      if ( !v28 )
        v27 = 0;
      if ( v28 == 4 )
      {
        v29 = *v27;
        goto LABEL_40;
      }
      return -1073741789;
    }
    v8 = -1073741811;
LABEL_39:
    v29 = v72;
LABEL_40:
    if ( v8 >= 0 )
    {
      if ( v29 )
      {
        v30 = 0;
        v7 = ExAllocatePoolWithTag(1, v29);
        v69 = v7;
        if ( !v7 )
          return -1073741801;
        v73 = v70;
      }
      else
      {
        v30 = 1;
      }
      if ( off_920488 )
      {
        if ( v30 )
          v31 = 0;
        else
          v31 = v7;
        v32 = off_920488(v22, v23, v31, v29, &v70);
        v73 = v70;
      }
      else
      {
        v32 = -1073741637;
      }
      v33 = RtlUIntAdd(4u, 4, &v76);
      v8 = v33;
      if ( v33 < 0 )
        v34 = v78;
      else
        v34 = v76;
      if ( v33 >= 0 )
      {
        v8 = RtlUIntAdd(4u, 8, &v76);
        if ( v8 >= 0 )
        {
          v35 = v76 + v34;
          if ( v76 + v34 < v34 )
            goto LABEL_93;
          v36 = v29 + 4;
          if ( v29 >= 0xFFFFFFFC )
          {
            v8 = -1073741675;
          }
          else
          {
            v37 = v36 + v35;
            if ( v36 + v35 < v35 )
              goto LABEL_93;
            v8 = RtlUIntAdd(4u, 4, &v76);
            if ( v8 >= 0 )
            {
              v38 = v76 + v37;
              if ( v76 + v37 < v37 )
                goto LABEL_93;
              v8 = 0;
              goto LABEL_65;
            }
          }
        }
      }
      v38 = v76;
LABEL_65:
      if ( v8 < 0 )
        goto LABEL_94;
      if ( v38 < 0xFFFFFFF8 )
      {
        v39 = (v38 + 15) & 0xFFFFFFF8;
        if ( v39 >= v38 + 8 )
        {
          v40 = v39 + 8;
          if ( v39 + 8 < v39 )
            goto LABEL_78;
          v8 = 0;
        }
        else
        {
          v8 = -1073741675;
          v40 = v77;
        }
        if ( v8 < 0 )
          goto LABEL_94;
        v41 = *(_DWORD *)(v77 + 8);
        v42 = v40 + 4;
        if ( v40 < 0xFFFFFFFC )
        {
          v43 = v40 + 8;
          if ( v42 + 4 >= v42 )
          {
            v44 = v43 + v41;
            if ( v43 + v41 >= v43 && v44 + 4 >= v44 && v44 + 4 + *(_DWORD *)(v77 + 16) >= v44 + 4 )
            {
              v8 = 0;
              goto LABEL_79;
            }
          }
        }
LABEL_78:
        v8 = -1073741675;
LABEL_79:
        if ( v8 >= 0 )
        {
          if ( !a4 )
          {
            v8 = -1073741811;
            goto LABEL_94;
          }
          v8 = 0;
          a4[1] = v38;
          if ( v38 )
          {
            v46 = ExAllocatePoolWithTag(1, v38);
            v45 = v70;
            if ( v46 )
            {
              a4[2] = v46;
              *a4 = 0;
            }
            else
            {
              v8 = -1073741801;
            }
          }
          else
          {
            v8 = -1073741762;
            v45 = v73;
          }
          if ( v8 < 0 )
            goto LABEL_94;
          v74 = v32 | 0x10000000;
          if ( v68 == (int *)-28 )
          {
            v8 = -1073741811;
          }
          else
          {
            v47 = a4[2];
            if ( !v47 )
            {
              v48 = a4[1];
              if ( v48 + 8 < v48 )
              {
LABEL_92:
                a4[1] = -1;
                goto LABEL_93;
              }
              a4[1] = v48 + 8;
              ++*a4;
              goto LABEL_108;
            }
            v50 = 0;
            v51 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v51 < 0xFFFFFFFC )
              {
                if ( (_DWORD *)((char *)v51 + *v51 + 4) < v51 )
                  goto LABEL_93;
                ++v50;
                v51 = (_DWORD *)((char *)v51 + *v51 + 4);
                if ( v50 >= *a4 )
                  goto LABEL_101;
              }
              v8 = -1073741675;
            }
            else
            {
LABEL_101:
              if ( v51 + 1 < v51 )
                goto LABEL_93;
              v8 = 0;
              if ( (unsigned int)(v51 + 2) > v47 + a4[1] )
                goto LABEL_103;
              v52 = v74;
              *v51 = 4;
              v51[1] = v52;
              v45 = v70;
              ++*a4;
            }
          }
          if ( v8 < 0 )
            goto LABEL_94;
LABEL_108:
          v81 = v71;
          v82 = v16;
          if ( v68 == (int *)-56 )
          {
            v8 = -1073741811;
            goto LABEL_121;
          }
          v53 = a4[2];
          if ( !v53 )
          {
            v54 = a4[1];
            if ( v54 + 12 >= v54 )
            {
              a4[1] = v54 + 12;
              ++*a4;
              goto LABEL_122;
            }
            goto LABEL_92;
          }
          v55 = 0;
          v56 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v56 < 0xFFFFFFFC )
            {
              if ( (_DWORD *)((char *)v56 + *v56 + 4) < v56 )
                goto LABEL_93;
              ++v55;
              v56 = (_DWORD *)((char *)v56 + *v56 + 4);
              if ( v55 >= *a4 )
                goto LABEL_116;
            }
            v8 = -1073741675;
LABEL_121:
            if ( v8 < 0 )
              goto LABEL_94;
LABEL_122:
            v49 = v69;
            if ( v69 )
            {
              if ( !v29 )
                goto LABEL_124;
            }
            else if ( v29 )
            {
LABEL_124:
              v8 = -1073741811;
              goto LABEL_125;
            }
            v59 = a4[2];
            if ( v59 )
            {
              v62 = 0;
              v63 = (unsigned int *)a4[2];
              if ( !*a4 )
              {
LABEL_142:
                if ( v63 + 1 < v63 )
                  goto LABEL_136;
                v8 = 0;
                if ( (unsigned int)v63 + v29 + 4 > a4[1] + v59 )
                  goto LABEL_144;
                *v63 = v29;
                if ( v49 )
                  memmove((int)(v63 + 1), v49, v29);
                v45 = v70;
                ++*a4;
                goto LABEL_125;
              }
              while ( *v63 < 0xFFFFFFFC )
              {
                if ( (unsigned int *)((char *)v63 + *v63 + 4) < v63 )
                  goto LABEL_136;
                ++v62;
                v63 = (unsigned int *)((char *)v63 + *v63 + 4);
                if ( v62 >= *a4 )
                  goto LABEL_142;
              }
            }
            else if ( v29 < 0xFFFFFFFC )
            {
              v60 = a4[1];
              v61 = v29 + 4 + v60;
              if ( v61 < v60 )
              {
LABEL_135:
                a4[1] = -1;
                goto LABEL_136;
              }
              a4[1] = v61;
              ++*a4;
              goto LABEL_126;
            }
            v8 = -1073741675;
LABEL_125:
            if ( v8 < 0 )
              goto LABEL_95;
LABEL_126:
            v75 = v45;
            if ( !&v75 )
            {
              v8 = -1073741811;
LABEL_95:
              if ( v49 )
                ExFreePoolWithTag(v49);
              return v8;
            }
            v57 = a4[2];
            if ( !v57 )
            {
              v58 = a4[1];
              if ( v58 + 8 >= v58 )
              {
                a4[1] = v58 + 8;
                ++*a4;
                v8 = 0;
                goto LABEL_95;
              }
              goto LABEL_135;
            }
            v64 = 0;
            v65 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v65 < 0xFFFFFFFC && (_DWORD *)((char *)v65 + *v65 + 4) >= v65 )
              {
                ++v64;
                v65 = (_DWORD *)((char *)v65 + *v65 + 4);
                if ( v64 >= *a4 )
                  goto LABEL_152;
              }
              goto LABEL_136;
            }
LABEL_152:
            if ( v65 + 1 < v65 )
            {
LABEL_136:
              v8 = -1073741675;
              goto LABEL_95;
            }
            v8 = 0;
            if ( (unsigned int)(v65 + 2) <= v57 + a4[1] )
            {
              v66 = v75;
              *v65 = 4;
              v65[1] = v66;
              ++*a4;
              goto LABEL_95;
            }
LABEL_144:
            v8 = -1073741789;
            goto LABEL_95;
          }
LABEL_116:
          if ( v56 + 1 < v56 )
            goto LABEL_93;
          v8 = 0;
          if ( (unsigned int)(v56 + 3) <= v53 + a4[1] )
          {
            *v56 = 8;
            v56[1] = v81;
            v56[2] = v82;
            v45 = v70;
            ++*a4;
            goto LABEL_121;
          }
LABEL_103:
          v8 = -1073741789;
        }
LABEL_94:
        v49 = v69;
        goto LABEL_95;
      }
LABEL_93:
      v8 = -1073741675;
      goto LABEL_94;
    }
  }
  return v8;
}
