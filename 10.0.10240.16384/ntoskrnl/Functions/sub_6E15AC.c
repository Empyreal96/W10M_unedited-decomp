// sub_6E15AC 
 
int __fastcall sub_6E15AC(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r4
  int v15; // r9
  int v16; // r10
  unsigned int j; // r3
  unsigned int v18; // r1
  unsigned int v19; // r0
  int v20; // r6
  unsigned int v21; // r7
  unsigned int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // r7
  int v25; // r0
  unsigned int v26; // r4
  int v27; // r8
  int v28; // r0
  int v29; // r6
  unsigned int v30; // r7
  bool v31; // zf
  int v32; // r1
  _DWORD *v33; // r0
  int v34; // r3
  unsigned int v35; // r2
  unsigned int v36; // r0
  _DWORD *v37; // r1
  unsigned int v38; // r2
  unsigned int v39; // r0
  _DWORD *v40; // r1
  int v41; // r3
  unsigned int v42; // r3
  unsigned int v43; // r3
  _DWORD v44[2]; // [sp+0h] [bp-50h] BYREF
  int v45; // [sp+8h] [bp-48h] BYREF
  int v46; // [sp+Ch] [bp-44h]
  unsigned int v47; // [sp+10h] [bp-40h]
  unsigned int v48; // [sp+14h] [bp-3Ch] BYREF
  int v49[4]; // [sp+18h] [bp-38h] BYREF
  int v50; // [sp+28h] [bp-28h] BYREF
  int v51; // [sp+2Ch] [bp-24h]

  v47 = 0;
  if ( !a1 || !a4 )
    return sub_7DB21C();
  v7 = (unsigned int *)a1[2];
  if ( v7 && *a1 > 3u )
  {
    v8 = (int *)a1[2];
    for ( i = 0; i < 3; ++i )
    {
      v10 = (unsigned int)(v8 + 1);
      v11 = *v8;
      if ( v8 + 1 < v8 )
        goto LABEL_76;
      v8 = (int *)(v11 + v10);
      if ( v11 + v10 < v10 )
        goto LABEL_76;
    }
    v12 = v8 + 1;
    v13 = *v8;
    if ( v8 + 1 < v8 )
    {
LABEL_76:
      v14 = -1073741675;
      goto LABEL_77;
    }
    v14 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 == 8 )
    {
      v15 = v12[1];
      v16 = *v12;
      goto LABEL_15;
    }
    return -1073741789;
  }
  v14 = -1073741811;
LABEL_77:
  v16 = v49[2];
  v15 = v49[3];
LABEL_15:
  if ( v14 >= 0 )
  {
    if ( v7 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v18 = (unsigned int)(v7 + 1);
        v19 = *v7;
        if ( v7 + 1 < v7 )
          goto LABEL_80;
        v7 = (unsigned int *)(v19 + v18);
        if ( v19 + v18 < v18 )
          goto LABEL_80;
      }
      v20 = (int)(v7 + 1);
      v21 = *v7;
      if ( v7 + 1 < v7 )
      {
LABEL_80:
        v14 = -1073741675;
        goto LABEL_81;
      }
      v14 = 0;
      if ( v21
        && (v21 & 1) == 0
        && !*(_WORD *)(v20 + 2 * (v21 >> 1) - 2)
        && StringCbLengthW(v20, v21, &v48) >= 0
        && v48 + 2 == v21 )
      {
        v22 = v48 >> 1;
        goto LABEL_29;
      }
      return -1073741762;
    }
    v14 = -1073741811;
LABEL_81:
    v22 = v44[0];
    v20 = v44[1];
LABEL_29:
    if ( v14 < 0 )
      return v14;
    v23 = v22 + 1;
    v24 = 2 * v23;
    if ( !(2 * v23) )
      return -1073741762;
    v25 = ExAllocatePoolWithTag(1, 2 * v23, 542329939);
    v26 = v25;
    if ( !v25 )
      return -1073741801;
    memmove(v25, v20, v24);
    v47 = v26;
    if ( off_9204C4 )
      v27 = off_9204C4(v26, v49);
    else
      v27 = -1073700223;
    v28 = RtlUIntAdd(4u, 4, &v48);
    v14 = v28;
    if ( v28 < 0 )
      v29 = v49[1];
    else
      v29 = v48;
    if ( v28 < 0
      || (v14 = RtlUIntAdd(4u, 8, &v48), v14 < 0)
      || (v30 = v29 + v48, v14 = RtlUIntAdd(4u, 4, &v48), v14 < 0) )
    {
LABEL_65:
      if ( v47 )
        ExFreePoolWithTag(v47);
      return v14;
    }
    v32 = v48 + v30;
    v31 = v48 + v30 == 0;
    a4[1] = v48 + v30;
    if ( v31 )
    {
      v14 = -1073741762;
      goto LABEL_65;
    }
    v33 = (_DWORD *)ExAllocatePoolWithTag(1, v32, 542329939);
    if ( !v33 )
    {
      v14 = -1073741801;
      goto LABEL_65;
    }
    a4[2] = (unsigned int)v33;
    *a4 = 0;
    v45 = v27 | 0x10000000;
    if ( &v45 )
    {
      if ( v33 + 1 < v33 )
        goto LABEL_71;
      v14 = 0;
      if ( v33 + 2 > (_DWORD *)((char *)v33 + a4[1]) )
        goto LABEL_72;
      v34 = v45;
      *v33 = 4;
      v33[1] = v34;
      ++*a4;
    }
    else
    {
      v14 = -1073741811;
    }
    if ( v14 < 0 )
      goto LABEL_65;
    v50 = v16;
    v51 = v15;
    if ( !&v50 )
    {
      v14 = -1073741811;
      goto LABEL_55;
    }
    v35 = a4[2];
    if ( !v35 )
    {
      v42 = a4[1];
      if ( v42 + 12 < v42 )
        goto LABEL_91;
      a4[1] = v42 + 12;
      ++*a4;
LABEL_56:
      v46 = v49[0];
      if ( v44 == (_DWORD *)-12 )
      {
        v14 = -1073741811;
        goto LABEL_65;
      }
      v38 = a4[2];
      if ( v38 )
      {
        v39 = 0;
        v40 = (_DWORD *)a4[2];
        if ( *a4 )
        {
          while ( *v40 < 0xFFFFFFFC && (_DWORD *)((char *)v40 + *v40 + 4) >= v40 )
          {
            ++v39;
            v40 = (_DWORD *)((char *)v40 + *v40 + 4);
            if ( v39 >= *a4 )
              goto LABEL_62;
          }
          goto LABEL_71;
        }
LABEL_62:
        if ( v40 + 1 >= v40 )
        {
          v14 = 0;
          if ( (unsigned int)(v40 + 2) <= v38 + a4[1] )
          {
            v41 = v46;
            *v40 = 4;
            v40[1] = v41;
            ++*a4;
            goto LABEL_65;
          }
          goto LABEL_72;
        }
LABEL_71:
        v14 = -1073741675;
        goto LABEL_65;
      }
      v43 = a4[1];
      if ( v43 + 8 >= v43 )
      {
        a4[1] = v43 + 8;
        ++*a4;
        v14 = 0;
        goto LABEL_65;
      }
LABEL_91:
      a4[1] = -1;
      goto LABEL_71;
    }
    v36 = 0;
    v37 = (_DWORD *)a4[2];
    if ( *a4 )
    {
      while ( *v37 < 0xFFFFFFFC )
      {
        if ( (_DWORD *)((char *)v37 + *v37 + 4) < v37 )
          goto LABEL_71;
        ++v36;
        v37 = (_DWORD *)((char *)v37 + *v37 + 4);
        if ( v36 >= *a4 )
          goto LABEL_52;
      }
      v14 = -1073741675;
LABEL_55:
      if ( v14 < 0 )
        goto LABEL_65;
      goto LABEL_56;
    }
LABEL_52:
    if ( v37 + 1 < v37 )
      goto LABEL_71;
    v14 = 0;
    if ( (unsigned int)(v37 + 3) <= v35 + a4[1] )
    {
      *v37 = 8;
      v37[1] = v50;
      v37[2] = v51;
      ++*a4;
      goto LABEL_55;
    }
LABEL_72:
    v14 = -1073741789;
    goto LABEL_65;
  }
  return v14;
}
