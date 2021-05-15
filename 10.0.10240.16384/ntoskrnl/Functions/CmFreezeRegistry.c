// CmFreezeRegistry 
 
int __fastcall CmFreezeRegistry(int a1)
{
  int v1; // r5
  int v2; // r9
  int v3; // r3
  unsigned int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1
  int v7; // r10
  _DWORD *v8; // r7
  _DWORD *v9; // r3
  _DWORD *v10; // r5
  _DWORD *v11; // r6
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r4
  _DWORD *v16; // r3
  _DWORD *v17; // r5
  _DWORD *v18; // r6
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r4
  _DWORD *v23; // r3
  _DWORD *v24; // r5
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  _DWORD *v29; // r3
  _DWORD *v30; // r3
  _DWORD *v31; // r3
  int v32; // r3
  unsigned int v33; // r5
  unsigned int v34; // r6
  int v35; // r0
  int v36; // r4
  unsigned __int64 v37; // r2
  unsigned int *v38; // r4
  unsigned int v39; // r1
  unsigned int v40; // r2
  unsigned __int8 *v41; // r0
  int v42; // r4
  unsigned int v43; // r1
  __int16 v44; // r3
  unsigned int v45; // r4
  unsigned int v46; // r1
  unsigned int v47; // r1
  __int16 v48; // r3
  unsigned __int8 *v50; // r0
  unsigned int v51; // r4
  unsigned int v52; // r1
  unsigned int v53; // r1
  int v54; // r3
  int v55; // [sp+10h] [bp-28h]

  v1 = a1;
  v2 = 0;
  CmpLockRegistryExclusive();
  v3 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v3 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v4 = CmpShutdownRundown & 0xFFFFFFFE;
  v5 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v6 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v6 == v4 && __strex(v5, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v6 == v4 )
  {
    v7 = 1;
    v55 = 1;
  }
  else
  {
    v7 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    v55 = v7;
    if ( !v7 )
    {
      v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v44 = *(_WORD *)(v43 + 0x134) + 1;
      *(_WORD *)(v43 + 308) = v44;
      if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
        KiCheckForKernelApcDelivery(0);
      goto LABEL_38;
    }
  }
  if ( CmpFreezeThawState )
  {
LABEL_38:
    CmpUnlockRegistry();
    v2 = -1073741431;
    goto LABEL_39;
  }
  v8 = (_DWORD *)CmpGetNextActiveHive(0);
  if ( v8 )
  {
    do
    {
      if ( (v8[23] & 3) == 0 )
      {
        v9 = (_DWORD *)v8[8];
        v10 = v9 + 28;
        v11 = v9 + 1014;
        v12 = v9[28];
        v13 = v9[29];
        v14 = v9[30];
        v15 = v10[3];
        *v11 = v12;
        v11[1] = v13;
        v11[2] = v14;
        v11[3] = v15;
        v16 = (_DWORD *)v8[8];
        v17 = v16 + 37;
        v18 = v16 + 1010;
        v19 = v16[37];
        v20 = v16[38];
        v21 = v16[39];
        v22 = v17[3];
        *v18 = v19;
        v18[1] = v20;
        v18[2] = v21;
        v18[3] = v22;
        v23 = (_DWORD *)v8[8];
        v24 = v23 + 1018;
        v25 = v23[32];
        v26 = v23[33];
        v27 = v23[34];
        v28 = v23[35];
        *v24 = v25;
        v24[1] = v26;
        v24[2] = v27;
        v24[3] = v28;
        v29 = (_DWORD *)v8[8];
        v29[28] = 0;
        v29[29] = 0;
        v29[30] = 0;
        v29[31] = 0;
        v30 = (_DWORD *)v8[8];
        v30[37] = 0;
        v30[38] = 0;
        v30[39] = 0;
        v30[40] = 0;
        v31 = (_DWORD *)v8[8];
        v31[32] = 0;
        v31[33] = 0;
        v31[34] = 0;
        v31[35] = 0;
        *(_DWORD *)(v8[8] + 164) = 0;
        v32 = v8[807];
        if ( ((v32 & 0x200) != 0 || (v32 & 0x100) == 0) && !v8[11] )
        {
          v33 = v8[467];
          v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v35 = KeAbPreAcquire(v33, 0, 0);
          v36 = v35;
          do
          {
            LODWORD(v37) = __ldrex((unsigned __int8 *)v33);
            HIDWORD(v37) = __strex(v37 & 0xFE, (unsigned __int8 *)v33);
          }
          while ( HIDWORD(v37) );
          __dmb(0xBu);
          if ( (v37 & 1) == 0 )
            ExpAcquireFastMutexContended(v33, v35);
          if ( v36 )
          {
            HIDWORD(v37) = *(unsigned __int8 *)(v36 + 14) | 1;
            *(_BYTE *)(v36 + 14) = BYTE4(v37);
          }
          *(_DWORD *)(v33 + 4) = v34;
          HvMarkBaseBlockDirty((int)v8, v37);
          v38 = (unsigned int *)v8[467];
          v38[1] = 0;
          __dmb(0xBu);
          do
            v39 = __ldrex(v38);
          while ( !v39 && __strex(1u, v38) );
          if ( v39 )
            ExpReleaseFastMutexContended(v38, v39);
          KeAbPostRelease((unsigned int)v38);
        }
      }
      v8 = (_DWORD *)CmpGetNextActiveHive((int)v8);
    }
    while ( v8 );
    v7 = v55;
    v1 = a1;
    v2 = 0;
  }
  CmpFreezeThawState = 1;
  if ( !v1 )
    v1 = CmFreezeThawTimeoutInSeconds;
  KiSetTimerEx(
    (int)CmpFreezeThawTimer,
    (unsigned int)&CmpFreezeThawDpc,
    -10000000i64 * v1,
    0,
    0,
    (int)&CmpFreezeThawDpc);
  CmpDisableLazyFlush(2);
  CmpUnlockRegistry();
  v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v40 + 308);
  v41 = (unsigned __int8 *)CmpGetNextActiveHive(0);
  v42 = (int)v41;
  if ( v41 )
  {
    while ( 1 )
    {
      if ( (*(_DWORD *)(v42 + 92) & 3) == 0 )
      {
        v2 = CmpFlushHive(v42, 13);
        if ( v2 < 0 )
          break;
      }
      v41 = (unsigned __int8 *)CmpGetNextActiveHive(v42);
      v42 = (int)v41;
      if ( !v41 )
        goto LABEL_56;
    }
    v50 = (unsigned __int8 *)(v42 + 1832);
    __pld((void *)(v42 + 1832));
    v51 = *(_DWORD *)(v42 + 1832) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v52 = __ldrex((unsigned int *)v50);
    while ( v52 == v51 && __strex(v51 - 2, (unsigned int *)v50) );
    if ( v52 != v51 )
      v50 = ExfReleaseRundownProtection(v50);
    v41 = (unsigned __int8 *)CmThawRegistry(v50);
    v2 = -1073741491;
  }
LABEL_56:
  v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v54 = (__int16)(*(_WORD *)(v53 + 0x134) + 1);
  *(_WORD *)(v53 + 308) = v54;
  if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
    v41 = (unsigned __int8 *)KiCheckForKernelApcDelivery((int)v41);
LABEL_39:
  if ( v7 )
  {
    __pld(&CmpShutdownRundown);
    v45 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v46 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v46 == v45 && __strex(v45 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v46 != v45 )
      v41 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v48 = *(_WORD *)(v47 + 0x134) + 1;
    *(_WORD *)(v47 + 308) = v48;
    if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
      KiCheckForKernelApcDelivery((int)v41);
  }
  return v2;
}
