// PfCheckDeprioritizeFile 
 
int __fastcall PfCheckDeprioritizeFile(int a1, int a2, int a3)
{
  int v4; // r9
  unsigned int v5; // r4
  int v6; // r8
  unsigned int v7; // r5
  int v8; // r0
  char *v9; // r0
  int v10; // r1
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r1
  int v15; // r8
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r2
  int v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r1
  int v24; // r1
  int v25; // r4
  int *v26; // r3
  int i; // r2
  unsigned int v28; // r1
  int v29; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  int v34[2]; // [sp+8h] [bp-38h] BYREF
  int v35[12]; // [sp+10h] [bp-30h] BYREF

  v34[0] = a1;
  v4 = 0;
  if ( !a2 )
    return v4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&dword_6372FC, 0, 1);
  do
    v7 = __ldrex(&dword_6372FC);
  while ( !v7 && __strex(0x11u, &dword_6372FC) );
  __dmb(0xBu);
  if ( !v7 || (v8 = ExfTryAcquirePushLockShared(&dword_6372FC)) != 0 )
  {
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v13 = dword_6372EC;
    if ( a2 != *(_DWORD *)(dword_6372EC + 4) )
    {
      v14 = -1 << (dword_6372E4 & 0x1F);
      if ( !((unsigned int)dword_6372E4 >> 5) )
        goto LABEL_42;
      v13 = dword_6372E8
          + 4
          * ((37
            * (37
             * (37 * ((unsigned __int8)(v14 & a2) + 11623883) + (unsigned __int8)((unsigned __int16)(v14 & a2) >> 8))
             + (unsigned __int8)((v14 & (unsigned int)a2) >> 16))
            + ((v14 & (unsigned int)a2) >> 24)) & (((unsigned int)dword_6372E4 >> 5) - 1));
      while ( 1 )
      {
        v13 = *(_DWORD *)v13;
        if ( (v13 & 1) != 0 )
          break;
        if ( (v14 & a2) == (*(_DWORD *)(v13 + 4) & v14) )
          goto LABEL_23;
      }
      v13 = 0;
LABEL_23:
      if ( !v13 )
      {
LABEL_42:
        __dmb(0xBu);
        do
          v23 = __ldrex(&dword_6372FC);
        while ( v23 == 17 && __strex(0, &dword_6372FC) );
        if ( v23 != 17 )
          ExfReleasePushLockShared(&dword_6372FC);
        v8 = KeAbPostRelease((unsigned int)&dword_6372FC);
        goto LABEL_10;
      }
      dword_6372EC = v13;
    }
    v15 = *(_DWORD *)(v13 + 8);
    __dmb(0xBu);
    do
      v16 = __ldrex(&dword_6372FC);
    while ( v16 == 17 && __strex(0, &dword_6372FC) );
    if ( v16 != 17 )
      ExfReleasePushLockShared(&dword_6372FC);
    v17 = KeAbPostRelease((unsigned int)&dword_6372FC);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
    if ( dword_637310 == v15 )
      goto LABEL_70;
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v20 + 308);
    v21 = KeAbPreAcquire((unsigned int)algn_637314, 0, 1);
    do
      v22 = __ldrex((unsigned int *)algn_637314);
    while ( !v22 && __strex(0x11u, (unsigned int *)algn_637314) );
    __dmb(0xBu);
    if ( v22 )
    {
      v8 = ExfTryAcquirePushLockShared((unsigned int *)algn_637314);
      if ( !v8 )
      {
        if ( !v21 )
          goto LABEL_10;
        v9 = algn_637314;
        v10 = v21;
        goto LABEL_9;
      }
    }
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    if ( !dword_637308 )
      goto LABEL_59;
    v24 = 0;
    v25 = (dword_637308 - 1) & (37 * (37 * (37 * ((unsigned __int8)v15 + 11623883) + BYTE1(v15)) + BYTE2(v15))
                              + HIBYTE(v15));
    v26 = (int *)((v25 << unk_637304) + dword_637300);
    for ( i = *v26; *v26; i = *v26 )
    {
      if ( i == v15 )
        break;
      if ( !v24 )
      {
        v24 = -1640531535 * v15;
        if ( ((-1640531535 * v15) & 1) == 0 )
          ++v24;
      }
      v25 = (v24 + v25) & (dword_637308 - 1);
      v26 = (int *)((v25 << unk_637304) + dword_637300);
    }
    if ( *v26 )
    {
      dword_637310 = v15;
    }
    else
    {
LABEL_59:
      v4 = 1;
      KeQueryTickCount(&dword_637338);
    }
    __dmb(0xBu);
    do
      v28 = __ldrex((unsigned int *)algn_637314);
    while ( v28 == 17 && __strex(0, (unsigned int *)algn_637314) );
    if ( v28 != 17 )
      ExfReleasePushLockShared(algn_637314);
    v29 = KeAbPostRelease((unsigned int)algn_637314);
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v31 = *(_WORD *)(v30 + 0x134) + 1;
    *(_WORD *)(v30 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
      KiCheckForKernelApcDelivery(v29);
    if ( !v4 )
LABEL_70:
      a3 = 0;
    v35[0] = a2;
    v35[1] = dword_643B68;
    v35[2] = v34[0];
    v35[3] = a3;
    KeQueryTickCount(v34);
    PfLogEvent(
      30,
      ((__int64)((((unsigned int)v34[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
               + (((unsigned int)v34[1] * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
    + dword_63728C,
      (int)v35,
      0x10u);
    return v4;
  }
  if ( v6 )
  {
    v9 = (char *)&dword_6372FC;
    v10 = v6;
LABEL_9:
    v8 = KeAbPostReleaseEx((int)v9, v10);
  }
LABEL_10:
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v4;
}
