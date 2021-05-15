// sub_5C528C 
 
int __fastcall sub_5C528C(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int *v5; // r2
  int v7; // r4
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r9
  int v15; // r10
  unsigned int j; // r3
  unsigned int v17; // r1
  int v18; // r0
  int *v19; // r3
  int v20; // r1
  int v21; // r3
  int v22; // r0
  int v23; // r8
  int v24; // r0
  unsigned int v25; // r6
  unsigned int v26; // r3
  unsigned int v27; // r6
  unsigned int v28; // r7
  unsigned int v29; // r3
  unsigned int v30; // r2
  int v31; // r1
  unsigned int v32; // r3
  unsigned int v33; // r2
  unsigned int v34; // r3
  int v35; // r0
  unsigned int v36; // r2
  unsigned int v37; // r3
  int v38; // r7
  unsigned int v40; // r0
  _DWORD *v41; // r1
  int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  unsigned int v45; // r0
  _DWORD *v46; // r1
  unsigned int v47; // r2
  unsigned int v48; // r3
  unsigned int v49; // r0
  _DWORD *v50; // r1
  unsigned int v51; // r2
  unsigned int v52; // r3
  unsigned int v53; // r0
  _DWORD *v54; // r1
  int v55; // r3
  int v56[2]; // [sp+0h] [bp-50h] BYREF
  int v57; // [sp+8h] [bp-48h]
  int v58; // [sp+Ch] [bp-44h]
  unsigned int v59; // [sp+10h] [bp-40h] BYREF
  int v60; // [sp+14h] [bp-3Ch]
  unsigned int v61; // [sp+18h] [bp-38h]
  int v62; // [sp+20h] [bp-30h]
  int v63; // [sp+24h] [bp-2Ch]
  int v64; // [sp+28h] [bp-28h]
  int v65; // [sp+2Ch] [bp-24h]

  v5 = (int *)a1[2];
  v60 = a2;
  if ( v5 && *a1 > 3u )
  {
    v8 = v5;
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_14;
      v8 = (int *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_14;
    }
    v12 = v8 + 1;
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_14:
      v7 = -1073741675;
      goto LABEL_15;
    }
    v7 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 == 8 )
    {
      v14 = v12[1];
      v15 = *v12;
      goto LABEL_16;
    }
    return -1073741789;
  }
  v7 = -1073741811;
LABEL_15:
  v15 = v62;
  v14 = v63;
LABEL_16:
  if ( v7 >= 0 )
  {
    if ( v5 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v17 = (unsigned int)(v5 + 1);
        v18 = *v5;
        if ( v5 + 1 < v5 )
          goto LABEL_29;
        v5 = (int *)(v18 + v17);
        if ( v18 + v17 < v17 )
          goto LABEL_29;
      }
      v19 = v5 + 1;
      v20 = *v5;
      if ( v5 + 1 < v5 )
      {
LABEL_29:
        v7 = -1073741675;
        goto LABEL_30;
      }
      v7 = 0;
      if ( !v20 )
        v19 = 0;
      if ( v20 == 4 )
      {
        v21 = *v19;
        goto LABEL_31;
      }
      return -1073741789;
    }
    v7 = -1073741811;
LABEL_30:
    v21 = v56[1];
LABEL_31:
    if ( v7 >= 0 )
    {
      if ( v21 != 4104 )
        return -1073741762;
      v22 = ExAllocatePoolWithTag(1, 4104);
      v56[0] = v22;
      if ( !v22 )
        return -1073741801;
      if ( off_92045C )
        v23 = off_92045C(v22);
      else
        v23 = -1073741637;
      v7 = v23;
      if ( v23 < 0 )
        goto LABEL_80;
      v24 = RtlUIntAdd(4u, 4, &v59);
      v7 = v24;
      if ( v24 < 0 )
        v25 = v61;
      else
        v25 = v59;
      if ( v24 < 0 )
        goto LABEL_50;
      v7 = RtlUIntAdd(4u, 8, &v59);
      if ( v7 < 0 )
        goto LABEL_50;
      v26 = v59 + v25;
      if ( v59 + v25 < v25 )
        goto LABEL_79;
      v27 = v26 + 4108;
      if ( v26 + 4108 < v26 )
        goto LABEL_79;
      v7 = RtlUIntAdd(4u, 4, &v59);
      if ( v7 < 0 )
      {
LABEL_50:
        v28 = v60;
      }
      else
      {
        v28 = v59 + v27;
        if ( v59 + v27 < v27 )
          goto LABEL_79;
        v7 = 0;
      }
      if ( v7 < 0 )
        goto LABEL_80;
      if ( v28 >= 0xFFFFFFF8 )
        goto LABEL_79;
      v29 = (v28 + 15) & 0xFFFFFFF8;
      if ( v29 >= v28 + 8 )
      {
        v30 = v29 + 8;
        if ( v29 + 8 < v29 )
          goto LABEL_64;
        v7 = 0;
      }
      else
      {
        v7 = -1073741675;
        v30 = v60;
      }
      if ( v7 < 0 )
        goto LABEL_80;
      v31 = *(_DWORD *)(v60 + 8);
      v32 = v30 + 4;
      if ( v30 < 0xFFFFFFFC )
      {
        v33 = v30 + 8;
        if ( v32 + 4 >= v32 )
        {
          v34 = v33 + v31;
          if ( v33 + v31 >= v33 && v34 + 4 >= v34 && v34 + 4 + *(_DWORD *)(v60 + 16) >= v34 + 4 )
          {
            v7 = 0;
            goto LABEL_65;
          }
        }
      }
LABEL_64:
      v7 = -1073741675;
LABEL_65:
      if ( v7 >= 0 )
      {
        if ( !a4 )
        {
          v7 = -1073741811;
          goto LABEL_80;
        }
        v7 = 0;
        a4[1] = v28;
        if ( v28 )
        {
          v35 = ExAllocatePoolWithTag(1, v28);
          if ( v35 )
          {
            a4[2] = v35;
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
        }
        if ( v7 < 0 )
          goto LABEL_80;
        v57 = v23 | 0x10000000;
        if ( v56 == (int *)-8 )
        {
          v7 = -1073741811;
        }
        else
        {
          v36 = a4[2];
          if ( !v36 )
          {
            v37 = a4[1];
            if ( v37 + 8 < v37 )
              goto LABEL_78;
            a4[1] = v37 + 8;
            ++*a4;
            goto LABEL_94;
          }
          v40 = 0;
          v41 = (_DWORD *)a4[2];
          if ( *a4 )
          {
            while ( *v41 < 0xFFFFFFFC )
            {
              if ( (_DWORD *)((char *)v41 + *v41 + 4) < v41 )
                goto LABEL_79;
              ++v40;
              v41 = (_DWORD *)((char *)v41 + *v41 + 4);
              if ( v40 >= *a4 )
                goto LABEL_87;
            }
            v7 = -1073741675;
          }
          else
          {
LABEL_87:
            if ( v41 + 1 < v41 )
              goto LABEL_79;
            v7 = 0;
            if ( (unsigned int)(v41 + 2) > v36 + a4[1] )
              goto LABEL_89;
            v42 = v57;
            *v41 = 4;
            v41[1] = v42;
            ++*a4;
          }
        }
        if ( v7 < 0 )
          goto LABEL_80;
LABEL_94:
        v64 = v15;
        v65 = v14;
        if ( v56 == (int *)-40 )
        {
          v7 = -1073741811;
          goto LABEL_107;
        }
        v43 = a4[2];
        if ( !v43 )
        {
          v44 = a4[1];
          if ( v44 + 12 >= v44 )
          {
            a4[1] = v44 + 12;
            ++*a4;
LABEL_108:
            v47 = a4[2];
            if ( !v47 )
            {
              v48 = a4[1];
              v38 = v56[0];
              if ( v48 + 4108 < v48 )
              {
LABEL_111:
                a4[1] = -1;
                goto LABEL_112;
              }
              a4[1] = v48 + 4108;
              ++*a4;
              goto LABEL_123;
            }
            v49 = 0;
            v50 = (_DWORD *)a4[2];
            if ( *a4 )
            {
              while ( *v50 < 0xFFFFFFFC )
              {
                if ( (_DWORD *)((char *)v50 + *v50 + 4) < v50 )
                  goto LABEL_79;
                ++v49;
                v50 = (_DWORD *)((char *)v50 + *v50 + 4);
                if ( v49 >= *a4 )
                  goto LABEL_117;
              }
              v7 = -1073741675;
              v38 = v56[0];
LABEL_122:
              if ( v7 < 0 )
                goto LABEL_81;
LABEL_123:
              v58 = 4104;
              if ( v56 == (int *)-12 )
              {
                v7 = -1073741811;
                goto LABEL_81;
              }
              v51 = a4[2];
              if ( !v51 )
              {
                v52 = a4[1];
                if ( v52 + 8 >= v52 )
                {
                  a4[1] = v52 + 8;
                  ++*a4;
                  v7 = 0;
                  goto LABEL_81;
                }
                goto LABEL_111;
              }
              v53 = 0;
              v54 = (_DWORD *)a4[2];
              if ( *a4 )
              {
                while ( *v54 < 0xFFFFFFFC && (_DWORD *)((char *)v54 + *v54 + 4) >= v54 )
                {
                  ++v53;
                  v54 = (_DWORD *)((char *)v54 + *v54 + 4);
                  if ( v53 >= *a4 )
                    goto LABEL_131;
                }
                goto LABEL_112;
              }
LABEL_131:
              if ( v54 + 1 < v54 )
              {
LABEL_112:
                v7 = -1073741675;
                goto LABEL_81;
              }
              v7 = 0;
              if ( (unsigned int)(v54 + 2) <= v51 + a4[1] )
              {
                v55 = v58;
                *v54 = 4;
                v54[1] = v55;
                ++*a4;
                goto LABEL_81;
              }
LABEL_119:
              v7 = -1073741789;
              goto LABEL_81;
            }
LABEL_117:
            if ( v50 + 1 >= v50 )
            {
              v38 = v56[0];
              v7 = 0;
              if ( (unsigned int)(v50 + 1027) > v47 + a4[1] )
                goto LABEL_119;
              *v50 = 4104;
              memmove((int)(v50 + 1), v38, 0x1008u);
              ++*a4;
              goto LABEL_122;
            }
LABEL_79:
            v7 = -1073741675;
            goto LABEL_80;
          }
LABEL_78:
          a4[1] = -1;
          goto LABEL_79;
        }
        v45 = 0;
        v46 = (_DWORD *)a4[2];
        if ( *a4 )
        {
          while ( *v46 < 0xFFFFFFFC )
          {
            if ( (_DWORD *)((char *)v46 + *v46 + 4) < v46 )
              goto LABEL_79;
            ++v45;
            v46 = (_DWORD *)((char *)v46 + *v46 + 4);
            if ( v45 >= *a4 )
              goto LABEL_102;
          }
          v7 = -1073741675;
LABEL_107:
          if ( v7 < 0 )
            goto LABEL_80;
          goto LABEL_108;
        }
LABEL_102:
        if ( v46 + 1 < v46 )
          goto LABEL_79;
        v7 = 0;
        if ( (unsigned int)(v46 + 3) <= v43 + a4[1] )
        {
          *v46 = 8;
          v46[1] = v64;
          v46[2] = v65;
          ++*a4;
          goto LABEL_107;
        }
LABEL_89:
        v7 = -1073741789;
      }
LABEL_80:
      v38 = v56[0];
LABEL_81:
      ExFreePoolWithTag(v38);
      return v7;
    }
  }
  return v7;
}
