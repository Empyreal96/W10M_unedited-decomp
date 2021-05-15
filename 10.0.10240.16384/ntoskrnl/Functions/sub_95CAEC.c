// sub_95CAEC 
 
int sub_95CAEC()
{
  int v0; // r9
  int v1; // r0
  __int64 v2; // r0
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  unsigned int v7; // r0
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r1
  int v23; // r6
  int v24; // r4
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  _BYTE *v29; // r4
  int v30; // r6
  char v31; // r0
  int v32; // r1
  unsigned int v33; // r2
  int v34; // r0
  int v35; // r4
  unsigned int v36; // r1
  unsigned int v37; // r0
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int v41; // r2
  int v42; // r0
  int v43; // r4
  unsigned int v44; // r1
  unsigned int v45; // r0
  int v46; // r0
  unsigned int v47; // r1
  int v48; // r3
  __int64 v49; // [sp+0h] [bp-68h] BYREF
  _DWORD v50[10]; // [sp+8h] [bp-60h] BYREF
  char v51; // [sp+30h] [bp-38h]
  _DWORD v52[12]; // [sp+38h] [bp-30h] BYREF

  dword_920444 = (int)ExIsAppLicensed;
  v0 = (unsigned __int8)byte_920AF2;
  dword_920448 = (int)ExIsAppLicensedProduct;
  dword_920450 = (int)sub_447E24;
  dword_920454 = (int)ExQueryFastCacheDevLicense;
  dword_92044C = (int)ExIsWindowsToGo;
  dword_920458 = (int)sub_8AA39C;
  KiInitializeMutant((int)&unk_619700, 0, 0);
  byte_619720 = 0;
  byte_619721 = 0;
  byte_619722 = 4;
  dword_619724 = 0;
  dword_61972C = (int)&dword_619728;
  dword_619728 = (int)&dword_619728;
  KeQueryTickCount((int *)&v49);
  v1 = KeQueryTimeIncrement();
  LODWORD(v2) = _rt_sdiv64(10000i64, v49 * (unsigned int)v1);
  qword_9203F0 = v2;
  ClipSpInitialize_0();
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&dword_922C40);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_922C40) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_96C700(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v50[0] = 0;
  v50[1] = 0;
  v50[4] = 0;
  v50[5] = 0;
  v50[2] = 0;
  v50[6] = 0;
  v50[7] = 0;
  v50[8] = 10800;
  v50[9] = 0;
  v51 = 1;
  if ( InitSafeBootMode || InitIsWinPEMode )
    v51 = 0;
  sub_6E34A4((int)v50, -1, 1);
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&dword_922C40);
  while ( __strex(v7 - 1, (unsigned int *)&dword_922C40) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_922C40);
  v8 = KeAbPostRelease((unsigned int)&dword_922C40);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  if ( sub_7A2B64(&v49) >= 0 )
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v14 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_922C40, v12, (unsigned int)&dword_922C40);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    dword_920358 = v49;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&dword_922C40);
    while ( __strex(v15 - 1, (unsigned int *)&dword_922C40) );
    if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_922C40);
    v16 = KeAbPostRelease((unsigned int)&dword_922C40);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  if ( off_920350 )
  {
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v19 + 308);
    v20 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v21 = v20;
    do
      v22 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v22 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v22 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_922C40, v20, (unsigned int)&dword_922C40);
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    v23 = sub_7BBFAC();
    if ( v23 == -1073741762 )
    {
      v24 = 1;
      byte_920AF2 = 1;
    }
    else
    {
      v24 = (unsigned __int8)byte_920AF2;
    }
    __dmb(0xBu);
    do
      v25 = __ldrex((unsigned int *)&dword_922C40);
    while ( __strex(v25 - 1, (unsigned int *)&dword_922C40) );
    if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_922C40);
    v26 = KeAbPostRelease((unsigned int)&dword_922C40);
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = *(_WORD *)(v27 + 0x134) + 1;
    *(_WORD *)(v27 + 308) = v28;
    if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
      KiCheckForKernelApcDelivery(v26);
    if ( !v0 && v24 )
      sub_7663CC((int)KernelLicensingCacheCorrupt);
    if ( v23 >= 0 && !v24 )
      sub_79FADC(dword_98216C, off_920350);
    v29 = v52;
    v30 = 16;
    do
    {
      v31 = ReadTimeStampCounter();
      HIDWORD(v49) = v32;
      *v29++ = v31;
      --v30;
    }
    while ( v30 );
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v33 + 308);
    v34 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v35 = v34;
    do
      v36 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v36 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v36 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_922C40, v34, (unsigned int)&dword_922C40);
    if ( v35 )
      *(_BYTE *)(v35 + 14) |= 1u;
    dword_922C28 = v52[0];
    dword_922C2C = v52[1];
    dword_922C30 = v52[2];
    dword_922C34 = v52[3];
    __dmb(0xBu);
    do
      v37 = __ldrex((unsigned int *)&dword_922C40);
    while ( __strex(v37 - 1, (unsigned int *)&dword_922C40) );
    if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_922C40);
    v38 = KeAbPostRelease((unsigned int)&dword_922C40);
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v40 = *(_WORD *)(v39 + 0x134) + 1;
    *(_WORD *)(v39 + 308) = v40;
    if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
      KiCheckForKernelApcDelivery(v38);
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v41 + 308);
    v42 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
    v43 = v42;
    do
      v44 = __ldrex((unsigned __int8 *)&dword_922C40);
    while ( __strex(v44 | 1, (unsigned __int8 *)&dword_922C40) );
    __dmb(0xBu);
    if ( (v44 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_922C40, v42, (unsigned int)&dword_922C40);
    if ( v43 )
      *(_BYTE *)(v43 + 14) |= 1u;
    off_920350 = 0;
    if ( !dword_922C44 && dword_922C3C )
    {
      memset(byte_922C48, 0, 8 * dword_922C3C);
      dword_922C3C = 0;
    }
    __dmb(0xBu);
    do
      v45 = __ldrex((unsigned int *)&dword_922C40);
    while ( __strex(v45 - 1, (unsigned int *)&dword_922C40) );
    if ( (v45 & 2) != 0 && (v45 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_922C40);
    v46 = KeAbPostRelease((unsigned int)&dword_922C40);
    v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v48 = (__int16)(*(_WORD *)(v47 + 0x134) + 1);
    *(_WORD *)(v47 + 308) = v48;
    if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
      KiCheckForKernelApcDelivery(v46);
  }
  return sub_95CCA0();
}
