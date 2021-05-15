// PfpRpCHashGrow 
 
int __fastcall PfpRpCHashGrow(int a1, int a2, unsigned __int8 *a3, int *a4)
{
  unsigned __int8 *v4; // r7
  unsigned __int8 *v5; // r8
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r5
  __int64 v11; // r2
  unsigned int v12; // r2
  int v13; // r3
  unsigned int v14; // r6
  _BYTE *v15; // lr
  int v16; // r5
  unsigned int v17; // r10
  char v18; // r2
  int v19; // r5
  unsigned int v20; // r3
  unsigned int v21; // r4
  _DWORD *v22; // r6
  unsigned int v23; // r3
  int *v24; // r9
  int v25; // r6
  int v26; // r1
  int *v27; // r0
  int v28; // r8
  int v29; // r3
  int v30; // r2
  unsigned int v31; // r2
  int v32; // r0
  int v33; // r4
  unsigned int v34; // r2
  int v35; // r3
  unsigned int v36; // r2
  int v37; // r0
  int v38; // r4
  unsigned int v39; // r2
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  unsigned int v45; // [sp+Ch] [bp-54h]
  unsigned __int8 *v47; // [sp+14h] [bp-4Ch]
  _DWORD *v48; // [sp+18h] [bp-48h]
  _DWORD *v50; // [sp+20h] [bp-40h]
  int v51; // [sp+24h] [bp-3Ch]
  int v52; // [sp+28h] [bp-38h]
  unsigned int v53; // [sp+38h] [bp-28h]
  int v54; // [sp+3Ch] [bp-24h]

  v4 = a3;
  v5 = (unsigned __int8 *)(a1 + 76);
  v47 = (unsigned __int8 *)(a1 + 76);
  v48 = (_DWORD *)a2;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire(a1 + 76, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v5);
  while ( __strex(v10 | 1, v5) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v5, v8, (unsigned int)v5);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_QWORD *)(a2 + 8);
  if ( 2 * HIDWORD(v11) < (unsigned int)v11 )
  {
    v16 = 0;
    v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v36 + 308);
    v37 = KeAbPreAcquire((unsigned int)v4, 0, 0);
    v38 = v37;
    do
      v39 = __ldrex(v4);
    while ( __strex(v39 | 1, v4) );
    __dmb(0xBu);
    if ( (v39 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v37, (unsigned int)v4);
    if ( v38 )
      *(_BYTE *)(v38 + 14) |= 1u;
  }
  else
  {
    v12 = 2 * v11;
    v13 = *(_DWORD *)(a2 + 4);
    if ( v12 < 8 )
      v12 = 8;
    v14 = v12 << v13;
    v15 = (_BYTE *)ExAllocatePoolWithTag(1, v12 << v13, 1212376656);
    if ( v15 )
    {
      v50 = *(_DWORD **)a2;
      v51 = *(_DWORD *)(a2 + 4);
      v52 = *(_DWORD *)(a2 + 8);
      v17 = 1 << v51;
      v18 = -1;
      v19 = -1;
      v20 = 1 << v51;
      if ( 1 << v51 )
      {
        do
        {
          v20 >>= 1;
          ++v19;
        }
        while ( v20 );
      }
      if ( ((v17 - 1) & v17) != 0 )
        ++v19;
      v21 = v14 >> v19;
      if ( (((v14 >> v19) - 1) & (v14 >> v19)) != 0 )
      {
        while ( v21 )
        {
          v21 >>= 1;
          ++v18;
        }
        v21 = 1 << v18;
      }
      v53 = v21;
      v54 = 0;
      memset(v15, 0, v21 << v19);
      v22 = v50;
      v23 = (unsigned int)v50 + (v52 << v51);
      v45 = v23;
      v24 = v50;
      if ( (unsigned int)v50 < v23 )
      {
        v25 = 0;
        do
        {
          v26 = *v24;
          if ( *v24 )
          {
            if ( v21 )
            {
              v28 = (v21 - 1) & (HIBYTE(*v24)
                               + 37
                               * (37 * (37 * ((unsigned __int8)*v24 + 11623883) + (unsigned __int8)BYTE1(*v24))
                                + (unsigned __int8)BYTE2(*v24)));
              v27 = (int *)&v15[v28 << v19];
              v29 = *v27;
              v30 = 0;
              if ( *v27 )
              {
                do
                {
                  if ( v29 == v26 )
                    break;
                  if ( !v30 )
                  {
                    v30 = -1640531535 * v26;
                    if ( ((-1640531535 * v26) & 1) == 0 )
                      ++v30;
                  }
                  v28 = (v30 + v28) & (v21 - 1);
                  v27 = (int *)&v15[v28 << v19];
                  v29 = *v27;
                }
                while ( *v27 );
                v17 = 1 << v51;
              }
            }
            else
            {
              v27 = 0;
            }
            memmove((int)v27, (int)v24, v17);
            v23 = v45;
            ++v25;
          }
          v24 = (int *)((char *)v24 + v17);
        }
        while ( (unsigned int)v24 < v23 );
        v4 = a3;
        v5 = v47;
        v54 = v25;
        v22 = v50;
      }
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v31 + 308);
      v32 = KeAbPreAcquire((unsigned int)v4, 0, 0);
      v33 = v32;
      do
        v34 = __ldrex(v4);
      while ( __strex(v34 | 1, v4) );
      __dmb(0xBu);
      if ( (v34 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v4, v32, (unsigned int)v4);
      if ( v33 )
        *(_BYTE *)(v33 + 14) |= 1u;
      *v48 = v15;
      v48[1] = v19;
      v48[2] = v53;
      v48[3] = v54;
      if ( v22 )
      {
        v35 = *a4;
        *a4 = (int)v22;
        *v22 = v35;
      }
      v16 = 0;
    }
    else
    {
      v16 = -1073741670;
    }
  }
  __dmb(0xBu);
  do
    v40 = __ldrex((unsigned int *)v5);
  while ( __strex(v40 - 1, (unsigned int *)v5) );
  if ( (v40 & 2) != 0 && (v40 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v5);
  v41 = KeAbPostRelease((unsigned int)v5);
  v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v43 = *(_WORD *)(v42 + 0x134) + 1;
  *(_WORD *)(v42 + 308) = v43;
  if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
    KiCheckForKernelApcDelivery(v41);
  return v16;
}
