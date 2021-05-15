// ExpCopyProcessInfo 
 
int __fastcall ExpCopyProcessInfo(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int *v6; // r0
  unsigned int v7; // lr
  unsigned int v8; // r6
  _DWORD *v9; // r10
  unsigned int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int i; // r5
  unsigned int v14; // r3
  unsigned int *v15; // r6
  int v16; // r4
  unsigned int v17; // r2
  unsigned int j; // r4
  unsigned int *v19; // r5
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v23; // r3
  unsigned int *v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r1
  unsigned int v27; // r3
  unsigned int v28; // r0
  unsigned int v29; // r1
  int v30; // r3
  int v31; // r2
  int v32; // r2
  int v33; // r1
  int v34; // r2
  int v35; // r3
  unsigned int *v36; // r5
  int v37; // r0
  int v38; // r4
  unsigned int v39; // r2
  unsigned int v40; // r10
  unsigned int v41; // r6
  int v42; // r0
  int v43; // r2
  int v44; // r0
  int v45; // r2
  int v46; // r0
  int v47; // r2
  int v48; // r0
  _DWORD *v49; // r5
  unsigned __int64 *v50; // r3
  __int64 v51; // r0
  unsigned __int64 v52; // kr10_8
  unsigned int *v53; // r4
  unsigned int v54; // r2
  int v55; // r0
  __int16 v56; // r3
  int v57; // r0
  int v58; // r1
  int v59; // r0
  int v60; // r1
  int v61; // r0
  int v62; // r1
  int v63; // r0
  int v64; // r1
  int v65; // r0
  int v66; // r1
  unsigned int v68; // [sp+0h] [bp-48h]
  int v69; // [sp+4h] [bp-44h]
  int v70; // [sp+4h] [bp-44h]
  int v71; // [sp+8h] [bp-40h]
  int v72; // [sp+8h] [bp-40h]
  unsigned int v73; // [sp+8h] [bp-40h]
  unsigned int v75; // [sp+18h] [bp-30h]

  v6 = (unsigned int *)(a2 + 172);
  __pld((void *)(a2 + 172));
  v7 = *(_DWORD *)(a2 + 172) & 0xFFFFFFFE;
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 + 2, v6) );
  __dmb(0xBu);
  if ( v8 != v7 )
  {
    if ( !ExfAcquireRundownProtection(v6) )
    {
LABEL_13:
      v27 = 0;
      goto LABEL_43;
    }
    v6 = (unsigned int *)(a2 + 172);
  }
  v9 = *(_DWORD **)(a2 + 336);
  if ( !v9 )
  {
    __pld(v6);
    v10 = *v6 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v6);
    while ( v11 == v10 && __strex(v10 - 2, v6) );
    if ( v11 != v10 )
      ExfReleaseRundownProtection((unsigned __int8 *)v6);
    goto LABEL_13;
  }
  v68 = 0;
  v71 = 0;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  for ( i = 0; ; ++i )
  {
    v14 = dword_92038C;
    if ( i >= dword_92038C )
      break;
    v15 = &v9[13 * i];
    v16 = KeAbPreAcquire((unsigned int)(v15 + 10), 0, 0);
    v6 = v15 + 10;
    do
      v17 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v17 | 1, (unsigned __int8 *)v6) );
    __dmb(0xBu);
    if ( (v17 & 1) != 0 )
      v6 = (unsigned int *)ExfAcquirePushLockExclusiveEx(v6, v16, (unsigned int)(v15 + 10));
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    v68 += v15[13];
    v71 += v15[14];
  }
  for ( j = 0; j < v14; ++j )
  {
    v19 = &v9[13 * j + 10];
    __dmb(0xBu);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 - 1, v19) );
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock(v19);
    v6 = (unsigned int *)KeAbPostRelease((unsigned int)v19);
    v14 = dword_92038C;
  }
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery((int)v6);
  v23 = 511 * (*v9 >> 2);
  if ( v68 > v23 >> 9 )
    v68 = v23 >> 9;
  v24 = (unsigned int *)(a2 + 172);
  __pld((void *)(a2 + 172));
  v25 = *(_DWORD *)(a2 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v26 = __ldrex(v24);
  while ( v26 == v25 && __strex(v25 - 2, v24) );
  if ( v26 != v25 )
    ExfReleaseRundownProtection((unsigned __int8 *)v24);
  v27 = v68;
LABEL_43:
  a1[19] = v27;
  a1[8] = *(_DWORD *)(a2 + 200);
  a1[9] = *(_DWORD *)(a2 + 204);
  a1[16] = *(char *)(a2 + 104);
  a1[17] = *(_DWORD *)(a2 + 176);
  a1[18] = *(_DWORD *)(a2 + 312);
  a1[5] = *(_DWORD *)(a2 + 712);
  a1[22] = *(_DWORD *)(a2 + 224);
  a1[23] = *(_DWORD *)(a2 + 228);
  a1[24] = *(_DWORD *)(a2 + 592);
  a1[4] = *(_DWORD *)(a2 + 580);
  a1[25] = *(_DWORD *)(a2 + 576) << 12;
  v28 = *(_DWORD *)(a2 + 544) << 12;
  v29 = *(_DWORD *)(a2 + 548) << 12;
  a1[26] = v28;
  if ( v29 >= v28 )
    v29 = v28;
  a1[2] = v29;
  a1[3] = 0;
  v30 = *(_DWORD *)(a2 + 212);
  __dmb(0xBu);
  v69 = v30;
  v31 = *(_DWORD *)(a2 + 220);
  __dmb(0xBu);
  a1[28] = v69;
  a1[27] = v31;
  v32 = *(_DWORD *)(a2 + 208);
  __dmb(0xBu);
  v70 = v32;
  v33 = *(_DWORD *)(a2 + 216);
  __dmb(0xBu);
  a1[30] = v70;
  a1[29] = v33;
  v34 = *(_DWORD *)(a2 + 484);
  __dmb(0xBu);
  v72 = v34 << 12;
  a1[31] = v34 << 12;
  v35 = *(_DWORD *)(a2 + 488);
  __dmb(0xBu);
  a1[32] = v35 << 12;
  a1[33] = v72;
  v75 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v75 + 0x134);
  v36 = (unsigned int *)(a2 + 720);
  v37 = KeAbPreAcquire(a2 + 720, 0, 0);
  v38 = v37;
  do
    v39 = __ldrex(v36);
  while ( !v39 && __strex(0x11u, v36) );
  __dmb(0xBu);
  if ( v39 )
    ExfAcquirePushLockSharedEx((_DWORD *)(a2 + 720), v37, a2 + 720);
  if ( v38 )
    *(_BYTE *)(v38 + 14) |= 1u;
  v40 = *(_DWORD *)(a2 + 152);
  v41 = *(_DWORD *)(a2 + 156);
  *(_QWORD *)(a4 + 16) = *(_QWORD *)(a2 + 128);
  v42 = *(_DWORD *)(a2 + 140);
  *(_DWORD *)(a4 + 24) = *(_DWORD *)(a2 + 136);
  *(_DWORD *)(a4 + 28) = v42;
  v43 = *(_DWORD *)(a2 + 436);
  *(_DWORD *)(a4 + 32) = *(_DWORD *)(a2 + 432);
  *(_DWORD *)(a4 + 36) = v43;
  v44 = *(_DWORD *)(a2 + 444);
  *(_DWORD *)(a4 + 40) = *(_DWORD *)(a2 + 440);
  *(_DWORD *)(a4 + 44) = v44;
  v45 = *(_DWORD *)(a2 + 452);
  *(_DWORD *)(a4 + 48) = *(_DWORD *)(a2 + 448);
  *(_DWORD *)(a4 + 52) = v45;
  v46 = *(_DWORD *)(a2 + 460);
  *(_DWORD *)(a4 + 56) = *(_DWORD *)(a2 + 456);
  *(_DWORD *)(a4 + 60) = v46;
  v47 = *(_DWORD *)(a2 + 468);
  *(_DWORD *)(a4 + 64) = *(_DWORD *)(a2 + 464);
  *(_DWORD *)(a4 + 68) = v47;
  v48 = *(_DWORD *)(a2 + 476);
  *(_DWORD *)(a4 + 72) = *(_DWORD *)(a2 + 472);
  *(_DWORD *)(a4 + 76) = v48;
  v49 = *(_DWORD **)(a2 + 396);
  while ( v49 != (_DWORD *)(a2 + 396) )
  {
    v40 += *(v49 - 132);
    v73 = v41 + *(v49 - 121);
    while ( 1 )
    {
      v50 = (unsigned __int64 *)(v49 - 221);
      LODWORD(v51) = *(v49 - 220);
      HIDWORD(v51) = *(v49 - 221);
      do
        v52 = __ldrexd(v50);
      while ( __PAIR64__(v52, HIDWORD(v52)) == v51 && __strexd(__PAIR64__(v51, HIDWORD(v51)), v50) );
      if ( v51 == __PAIR64__(v52, HIDWORD(v52)) )
        break;
      __dmb(0xAu);
      __yield();
    }
    *(_QWORD *)(a4 + 16) += __PAIR64__(v51, HIDWORD(v51));
    *(_QWORD *)(a4 + 24) += (unsigned int)*(v49 - 201);
    v49 = (_DWORD *)*v49;
    v41 = v73;
  }
  v53 = (unsigned int *)(a2 + 720);
  __dmb(0xBu);
  do
    v54 = __ldrex(v53);
  while ( v54 == 17 && __strex(0, v53) );
  if ( v54 != 17 )
    ExfReleasePushLockShared((_DWORD *)(a2 + 720));
  v55 = KeAbPostRelease(a2 + 720);
  v56 = *(_WORD *)(v75 + 308) + 1;
  *(_WORD *)(v75 + 308) = v56;
  if ( !v56 && *(_DWORD *)(v75 + 100) != v75 + 100 && !*(_WORD *)(v75 + 310) )
    KiCheckForKernelApcDelivery(v55);
  v57 = KeMaximumIncrement;
  *(_QWORD *)a4 = v40 * (unsigned __int64)(unsigned int)KeMaximumIncrement;
  *(_QWORD *)(a4 + 8) = v41 * (unsigned __int64)(unsigned int)v57;
  v58 = *(_DWORD *)(a4 + 20);
  a1[6] = *(_DWORD *)(a4 + 16);
  a1[7] = v58;
  v59 = *(_DWORD *)(a4 + 12);
  a1[10] = *(_DWORD *)(a4 + 8);
  a1[11] = v59;
  v60 = *(_DWORD *)(a4 + 4);
  a1[12] = *(_DWORD *)a4;
  a1[13] = v60;
  v61 = *(_DWORD *)(a4 + 36);
  a1[34] = *(_DWORD *)(a4 + 32);
  a1[35] = v61;
  v62 = *(_DWORD *)(a4 + 44);
  a1[36] = *(_DWORD *)(a4 + 40);
  a1[37] = v62;
  v63 = *(_DWORD *)(a4 + 52);
  a1[38] = *(_DWORD *)(a4 + 48);
  a1[39] = v63;
  v64 = *(_DWORD *)(a4 + 60);
  a1[40] = *(_DWORD *)(a4 + 56);
  a1[41] = v64;
  v65 = *(_DWORD *)(a4 + 68);
  a1[42] = *(_DWORD *)(a4 + 64);
  a1[43] = v65;
  v66 = *(_DWORD *)(a4 + 76);
  a1[44] = *(_DWORD *)(a4 + 72);
  a1[45] = v66;
  if ( a3 )
    a1[21] = *(_DWORD *)(a2 + 176);
  return 0;
}
