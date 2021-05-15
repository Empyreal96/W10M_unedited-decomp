// sub_8AE324 
 
int __fastcall sub_8AE324(_DWORD *a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  unsigned int *v7; // r2
  int *v8; // r3
  unsigned int i; // r1
  unsigned int v10; // r0
  int v11; // r4
  int *v12; // r1
  int v13; // r0
  int v14; // r8
  int v15; // r9
  unsigned int j; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  int v19; // r6
  unsigned int v20; // r7
  int v21; // r0
  int v22; // r6
  unsigned int v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r7
  int v26; // r0
  unsigned __int16 *v27; // r4
  unsigned int v28; // r10
  int v29; // r7
  bool v30; // zf
  int v31; // r1
  _DWORD *v32; // r0
  int v33; // r3
  unsigned int v34; // r2
  unsigned int v35; // r3
  unsigned int v36; // r0
  _DWORD *v37; // r1
  unsigned int v38; // r2
  unsigned int v39; // r3
  unsigned int v40; // r0
  _DWORD *v41; // r1
  int v42; // r3
  _DWORD v44[2]; // [sp+0h] [bp-50h] BYREF
  int v45; // [sp+8h] [bp-48h]
  int v46; // [sp+Ch] [bp-44h]
  int v47[2]; // [sp+10h] [bp-40h] BYREF
  int v48[4]; // [sp+18h] [bp-38h] BYREF
  int v49; // [sp+28h] [bp-28h]
  int v50; // [sp+2Ch] [bp-24h]

  if ( !a1 || !a4 )
    return -1073741811;
  v7 = (unsigned int *)a1[2];
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
    if ( v8 + 1 < v8 )
    {
LABEL_17:
      v6 = -1073741675;
      goto LABEL_18;
    }
    v6 = 0;
    if ( !v13 )
      v12 = 0;
    if ( v13 != 8 )
      return -1073741789;
    v14 = v12[1];
    v15 = *v12;
  }
  else
  {
    v6 = -1073741811;
LABEL_18:
    v15 = v48[2];
    v14 = v48[3];
  }
  if ( v6 >= 0 )
  {
    if ( v7 && *a1 > 4u )
    {
      for ( j = 0; j < 4; ++j )
      {
        v17 = (unsigned int)(v7 + 1);
        v18 = *v7;
        if ( v7 + 1 < v7 )
          goto LABEL_38;
        v7 = (unsigned int *)(v18 + v17);
        if ( v18 + v17 < v17 )
          goto LABEL_38;
      }
      v19 = (int)(v7 + 1);
      v20 = *v7;
      if ( v7 + 1 < v7 )
      {
LABEL_38:
        v6 = -1073741675;
        goto LABEL_39;
      }
      v6 = 0;
      if ( v20
        && (v20 & 1) == 0
        && !*(_WORD *)(v19 + 2 * (v20 >> 1) - 2)
        && StringCbLengthW(v19, v20, v47) >= 0
        && v47[0] + 2 == v20 )
      {
        v23 = (unsigned int)v47[0] >> 1;
        goto LABEL_40;
      }
      return -1073741762;
    }
    v6 = -1073741811;
LABEL_39:
    v23 = v44[0];
    v19 = v44[1];
LABEL_40:
    if ( v6 >= 0 )
    {
      v24 = v23 + 1;
      v25 = 2 * v24;
      if ( !(2 * v24) )
        return -1073741762;
      v26 = ExAllocatePoolWithTag(1, 2 * v24, 542329939);
      v27 = (unsigned __int16 *)v26;
      if ( !v26 )
        return -1073741801;
      memmove(v26, v19, v25);
      v28 = (unsigned int)v27;
      RtlInitUnicodeString((unsigned int)v47, v27);
      v6 = ExQueryFastCacheAppOrigin((unsigned __int16 *)v47, v48);
      if ( v6 < 0 )
        goto LABEL_89;
      v21 = RtlUIntAdd(4u, 4, v47);
      v6 = v21;
      v22 = v21 < 0 ? v48[1] : v47[0];
      if ( v21 < 0 )
        goto LABEL_89;
      v6 = RtlUIntAdd(4u, 8, v47);
      if ( v6 < 0 )
        goto LABEL_89;
      v29 = v22 + v47[0];
      v6 = RtlUIntAdd(4u, 4, v47);
      if ( v6 < 0 )
        goto LABEL_89;
      v31 = v47[0] + v29;
      v30 = v47[0] + v29 == 0;
      a4[1] = v47[0] + v29;
      if ( v30 )
      {
        v6 = -1073741762;
        goto LABEL_89;
      }
      v32 = (_DWORD *)ExAllocatePoolWithTag(1, v31, 542329939);
      if ( !v32 )
      {
        v6 = -1073741801;
        goto LABEL_89;
      }
      a4[2] = (unsigned int)v32;
      *a4 = 0;
      v45 = 0;
      if ( v44 == (_DWORD *)-8 )
      {
        v6 = -1073741811;
      }
      else
      {
        if ( v32 + 1 < v32 )
          goto LABEL_79;
        v6 = 0;
        if ( v32 + 2 > (_DWORD *)((char *)v32 + a4[1]) )
          goto LABEL_86;
        v33 = v45;
        *v32 = 4;
        v32[1] = v33;
        ++*a4;
      }
      if ( v6 < 0 )
        goto LABEL_89;
      v49 = v15;
      v50 = v14;
      if ( v44 == (_DWORD *)-40 )
      {
        v6 = -1073741811;
        goto LABEL_73;
      }
      v34 = a4[2];
      if ( !v34 )
      {
        v35 = a4[1];
        if ( v35 + 12 < v35 )
        {
LABEL_78:
          a4[1] = -1;
          goto LABEL_79;
        }
        a4[1] = v35 + 12;
        ++*a4;
        goto LABEL_74;
      }
      v36 = 0;
      v37 = (_DWORD *)a4[2];
      if ( *a4 )
      {
        while ( *v37 < 0xFFFFFFFC )
        {
          if ( (_DWORD *)((char *)v37 + *v37 + 4) < v37 )
            goto LABEL_79;
          ++v36;
          v37 = (_DWORD *)((char *)v37 + *v37 + 4);
          if ( v36 >= *a4 )
            goto LABEL_68;
        }
        v6 = -1073741675;
LABEL_73:
        if ( v6 < 0 )
          goto LABEL_89;
LABEL_74:
        v46 = v48[0];
        if ( v44 == (_DWORD *)-12 )
        {
          v6 = -1073741811;
          goto LABEL_89;
        }
        v38 = a4[2];
        if ( !v38 )
        {
          v39 = a4[1];
          if ( v39 + 8 >= v39 )
          {
            a4[1] = v39 + 8;
            ++*a4;
            v6 = 0;
            goto LABEL_89;
          }
          goto LABEL_78;
        }
        v40 = 0;
        v41 = (_DWORD *)a4[2];
        if ( *a4 )
        {
          while ( *v41 < 0xFFFFFFFC && (_DWORD *)((char *)v41 + *v41 + 4) >= v41 )
          {
            ++v40;
            v41 = (_DWORD *)((char *)v41 + *v41 + 4);
            if ( v40 >= *a4 )
              goto LABEL_84;
          }
          goto LABEL_79;
        }
LABEL_84:
        if ( v41 + 1 >= v41 )
        {
          v6 = 0;
          if ( (unsigned int)(v41 + 2) > v38 + a4[1] )
            goto LABEL_86;
          v42 = v46;
          *v41 = 4;
          v41[1] = v42;
          ++*a4;
LABEL_89:
          if ( v28 )
            ExFreePoolWithTag(v28);
          return v6;
        }
LABEL_79:
        v6 = -1073741675;
        goto LABEL_89;
      }
LABEL_68:
      if ( v37 + 1 < v37 )
        goto LABEL_79;
      v6 = 0;
      if ( (unsigned int)(v37 + 3) <= v34 + a4[1] )
      {
        *v37 = 8;
        v37[1] = v49;
        v37[2] = v50;
        ++*a4;
        goto LABEL_73;
      }
LABEL_86:
      v6 = -1073741789;
      goto LABEL_89;
    }
  }
  return v6;
}
