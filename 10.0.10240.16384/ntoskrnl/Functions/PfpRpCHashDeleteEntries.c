// PfpRpCHashDeleteEntries 
 
int __fastcall PfpRpCHashDeleteEntries(int a1, int a2, unsigned int *a3, unsigned int a4, int *a5)
{
  unsigned int *v5; // r6
  unsigned __int8 *v6; // r8
  int v7; // r10
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r7
  unsigned int v11; // r5
  unsigned int v12; // r7
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r9
  char v19; // r2
  char v20; // r5
  unsigned int v21; // r3
  unsigned int v22; // r4
  int *v23; // r7
  int *v24; // r3
  unsigned int v25; // r2
  int v26; // r8
  int v27; // r1
  unsigned int v28; // r2
  int *v29; // r0
  int v30; // t1
  int *v31; // r0
  int v32; // r3
  int v33; // r2
  int v34; // r8
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v37; // r1
  __int16 v38; // r3
  unsigned int v39; // r2
  unsigned int v40; // r3
  int v41; // r4
  unsigned int v42; // r1
  __int16 v43; // r3
  unsigned int v44; // r1
  int v45; // r0
  unsigned int v46; // r1
  __int16 v47; // r3
  _BYTE *v49; // [sp+8h] [bp-48h]
  int v50; // [sp+Ch] [bp-44h]
  unsigned __int8 *v53; // [sp+18h] [bp-38h]
  unsigned int v55; // [sp+20h] [bp-30h]
  int v56; // [sp+24h] [bp-2Ch]
  int v57; // [sp+28h] [bp-28h]

  v5 = a3;
  v6 = (unsigned __int8 *)(a1 + 76);
  v53 = (unsigned __int8 *)(a1 + 76);
  v7 = a2;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(a1 + 76, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v6);
  while ( __strex(v11 | 1, v6) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v6, v9, (unsigned int)v6);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = *(_DWORD *)(v7 + 8) << *(_QWORD *)(v7 + 4);
  if ( !v12 )
    goto LABEL_68;
  v49 = (_BYTE *)ExAllocatePoolWithTag(1, v12, 1212376656);
  if ( v49 )
  {
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v14 + 308);
    v15 = KeAbPreAcquire((unsigned int)v5, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex(v5);
    while ( !v17 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v17 )
      ExfAcquirePushLockSharedEx(v5, v15, (unsigned int)v5);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    v55 = *(_DWORD *)v7;
    v56 = *(_DWORD *)(v7 + 4);
    v57 = *(_DWORD *)(v7 + 8);
    v18 = 1 << v56;
    v19 = -1;
    v20 = -1;
    v21 = 1 << v56;
    if ( 1 << v56 )
    {
      do
      {
        v21 >>= 1;
        ++v20;
      }
      while ( v21 );
    }
    if ( ((v18 - 1) & v18) != 0 )
      ++v20;
    v22 = v12 >> v20;
    if ( (((v12 >> v20) - 1) & (v12 >> v20)) != 0 )
    {
      while ( v22 )
      {
        v22 >>= 1;
        ++v19;
      }
      v22 = 1 << v19;
    }
    v50 = 0;
    memset(v49, 0, v22 << v20);
    v23 = (int *)v55;
    if ( v55 < (v57 << v56) + v55 )
    {
      v24 = a5;
      v25 = (v57 << v56) + v55;
      v26 = 0;
      do
      {
        v27 = *v23;
        if ( *v23 )
        {
          if ( !v24 )
            goto LABEL_35;
          v28 = 0;
          if ( !a4 )
            goto LABEL_35;
          v29 = v24;
          do
          {
            v30 = *v29++;
            if ( v30 == v27 )
              break;
            ++v28;
          }
          while ( v28 < a4 );
          if ( v28 >= a4 )
          {
LABEL_35:
            if ( v22 )
            {
              v31 = (int *)&v49[((HIBYTE(*v23)
                                + 37
                                * (37 * (37 * ((unsigned __int8)*v23 + 11623883) + (unsigned __int8)BYTE1(*v23))
                                 + (unsigned __int8)BYTE2(*v23))) & (v22 - 1)) << v20];
              v32 = *v31;
              v33 = 0;
              if ( *v31 )
              {
                v34 = (HIBYTE(*v23)
                     + 37
                     * (37 * (37 * ((unsigned __int8)*v23 + 11623883) + (unsigned __int8)BYTE1(*v23))
                      + (unsigned __int8)BYTE2(*v23))) & (v22 - 1);
                do
                {
                  if ( v32 == v27 )
                    break;
                  if ( !v33 )
                  {
                    v33 = -1640531535 * v27;
                    if ( ((-1640531535 * v27) & 1) == 0 )
                      ++v33;
                  }
                  v34 = (v33 + v34) & (v22 - 1);
                  v31 = (int *)&v49[v34 << v20];
                  v32 = *v31;
                }
                while ( *v31 );
                v26 = v50;
              }
            }
            else
            {
              v31 = 0;
            }
            memmove((int)v31, (int)v23, v18);
            v50 = ++v26;
          }
          v25 = (v57 << v56) + v55;
          v24 = a5;
        }
        v23 = (int *)((char *)v23 + v18);
      }
      while ( (unsigned int)v23 < v25 );
      v5 = a3;
      v6 = v53;
      v7 = a2;
    }
    *(_DWORD *)v7 = v49;
    *(_DWORD *)(v7 + 12) = v50;
    __dmb(0xBu);
    do
      v35 = __ldrex(v5);
    while ( v35 == 17 && __strex(0, v5) );
    if ( v35 != 17 )
      ExfReleasePushLockShared(v5);
    v36 = KeAbPostRelease((unsigned int)v5);
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v38 = *(_WORD *)(v37 + 0x134) + 1;
    *(_WORD *)(v37 + 308) = v38;
    if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
      v36 = KiCheckForKernelApcDelivery(v36);
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v39 + 308);
    __dmb(0xFu);
    v40 = *v5;
    __dmb(0xBu);
    if ( (v40 & 1) != 0 )
    {
      v41 = KeAbPreAcquire((unsigned int)v5, 0, 0);
      ExfAcquirePushLockExclusiveEx(v5, v41, (unsigned int)v5);
      if ( v41 )
        *(_BYTE *)(v41 + 14) |= 1u;
      v36 = (int)ExfReleasePushLockExclusive(v5);
      if ( v41 )
        v36 = KeAbPostRelease((unsigned int)v5);
    }
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v43 = *(_WORD *)(v42 + 0x134) + 1;
    *(_WORD *)(v42 + 308) = v43;
    if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
      KiCheckForKernelApcDelivery(v36);
    ExFreePoolWithTag(v55);
LABEL_68:
    v13 = 0;
    goto LABEL_69;
  }
  v13 = -1073741670;
LABEL_69:
  __dmb(0xBu);
  do
    v44 = __ldrex((unsigned int *)v6);
  while ( __strex(v44 - 1, (unsigned int *)v6) );
  if ( (v44 & 2) != 0 && (v44 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  v45 = KeAbPostRelease((unsigned int)v6);
  v46 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v47 = *(_WORD *)(v46 + 0x134) + 1;
  *(_WORD *)(v46 + 308) = v47;
  if ( !v47 && *(_DWORD *)(v46 + 100) != v46 + 100 && !*(_WORD *)(v46 + 310) )
    KiCheckForKernelApcDelivery(v45);
  return v13;
}
