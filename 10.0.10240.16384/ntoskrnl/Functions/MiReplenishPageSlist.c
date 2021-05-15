// MiReplenishPageSlist 
 
int __fastcall MiReplenishPageSlist(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // lr
  unsigned int v5; // r6
  _DWORD *v7; // r2
  int v8; // r10
  unsigned int v10; // r3
  int v11; // r0
  int v12; // r9
  int v13; // r5
  int *v14; // r10
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r6
  int v21; // r1
  unsigned int v22; // r5
  unsigned int v23; // r2
  unsigned int *v24; // r1
  unsigned int v25; // r4
  unsigned int v26; // r1
  int v27; // r3
  __int16 i; // r5
  _DWORD *v29; // r0
  unsigned int v30; // r0
  int v31; // r2
  int v32; // r2
  unsigned int v33; // r0
  int v34; // r4
  int v35; // r2
  unsigned int v36; // r0
  unsigned int *v37; // r3
  unsigned int v38; // r2
  int v39; // r2
  unsigned int v40; // r0
  unsigned int v41; // r0
  unsigned int v42; // r1
  unsigned int *v43; // [sp+0h] [bp-40h]
  _DWORD *v44; // [sp+4h] [bp-3Ch]
  unsigned int *v45; // [sp+Ch] [bp-34h]
  _DWORD *v46; // [sp+10h] [bp-30h]
  _DWORD *v48; // [sp+18h] [bp-28h]
  unsigned int v50; // [sp+20h] [bp-20h]

  v4 = a3;
  v46 = a1;
  v5 = a4;
  v7 = (_DWORD *)(a1[6] + 104 * (a3 >> byte_6337F5));
  v44 = v7;
  if ( a2 )
  {
    v8 = a1[257];
    v45 = a1 + 320;
    v26 = 0;
    v27 = 0;
    for ( i = 1024; ; i |= 2u )
    {
      v29 = &v7[v27];
      v26 += v29[14];
      if ( (i & 0x400) != 0 )
      {
        v7 = v44;
        v26 += (v29[10] + v29[12]) << 10;
      }
      if ( (i & 2) != 0 )
        break;
      v27 = 1;
    }
    if ( v26 < v5 + 64 )
      return 0;
  }
  else
  {
    v8 = a1[256];
    v45 = a1 + 288;
    if ( v7[14] + ((v7[10] + v7[12]) << 10) < a4 + 64 || byte_634378 == 1 )
      return 0;
  }
  v10 = *(_DWORD *)(v8 + 20 * v4);
  v48 = (_DWORD *)(v8 + 20 * v4);
  if ( v5 > v10 )
  {
    v5 = *(_DWORD *)(v8 + 20 * v4);
    if ( !v10 )
      return 0;
  }
  if ( a1[928] - v5 < 0x400 )
    return 0;
  v11 = *(_DWORD *)(v8 + 20 * v4 + 8);
  v12 = 0;
  v13 = MmPfnDatabase + 24 * v11;
  v14 = 0;
  v50 = v13;
  do
  {
    v15 = (unsigned __int8 *)(v13 + 15);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
    __dmb(0xBu);
    if ( v16 >> 7 )
      break;
    v14 = (int *)v13;
    if ( dword_634380 == 1 )
    {
      LOBYTE(v30) = 1;
      v31 = ((v13 - MmPfnDatabase) / 24) & 0x1F;
      v43 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * ((unsigned int)((v13 - MmPfnDatabase) / 24) >> 5));
      if ( (unsigned int)(v31 + 1) > 0x20 )
      {
        if ( v31 )
        {
          v34 = 32 - v31;
          __dmb(0xBu);
          v35 = ((1 << (32 - v31)) - 1) << v31;
          do
            v36 = __ldrex(v43);
          while ( __strex(v36 | v35, v43) );
          __dmb(0xBu);
          v30 = 1 - v34;
          v37 = ++v43;
          if ( (unsigned int)(1 - v34) >= 0x20 )
          {
            v38 = v30 >> 5;
            do
            {
              v30 -= 32;
              --v38;
              *v37++ = -1;
            }
            while ( v38 );
            v43 = v37;
          }
          if ( !v30 )
            goto LABEL_12;
        }
        __dmb(0xBu);
        v39 = (1 << v30) - 1;
        do
          v40 = __ldrex(v43);
        while ( __strex(v40 | v39, v43) );
      }
      else
      {
        __dmb(0xBu);
        v32 = 1 << v31;
        do
          v33 = __ldrex(v43);
        while ( __strex(v33 | v32, v43) );
      }
      __dmb(0xBu);
    }
LABEL_12:
    v17 = *(_DWORD *)(v13 + 12) & 0xFFF00000;
    *(_BYTE *)(v13 + 18) = *(_BYTE *)(v13 + 18) & 0xF8 | 5;
    *(_DWORD *)(v13 + 12) = v17;
    __dmb(0xBu);
    v18 = (unsigned int *)(v13 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    v11 = *(_DWORD *)v13;
    if ( *(_DWORD *)v13 == 0xFFFFF )
      v13 = 0;
    else
      v13 = MmPfnDatabase + 24 * v11;
    *v14 = v13;
    ++v12;
  }
  while ( --v5 );
  if ( !v12 )
    return 0;
  v48[2] = v11;
  if ( v11 == 0xFFFFF )
  {
    v48[3] = 0xFFFFF;
  }
  else
  {
    v20 = (unsigned int *)(v13 + 12);
    v21 = *(_DWORD *)(v13 + 12);
    do
      v22 = __ldrex(v20);
    while ( v22 == v21 && __strex(v21 | 0xFFFFF, v20) );
    if ( v21 != v22 )
    {
      do
      {
        v41 = v22;
        do
          v42 = __ldrex(v20);
        while ( v42 == v22 && __strex(v22 | 0xFFFFF, v20) );
        v22 = v42;
      }
      while ( v41 != v42 );
    }
  }
  InterlockedPushListSList((unsigned __int64 *)(v46[a2 + 258] + 8 * a3), v50, v14, v12);
  *v48 -= v12;
  do
    v23 = __ldrex(v45);
  while ( __strex(v23 - v12, v45) );
  MiDecreaseAvailablePages(v46, v12);
  v24 = &v44[a2 + 14];
  do
    v25 = __ldrex(v24);
  while ( __strex(v25 - v12, v24) );
  return v12;
}
