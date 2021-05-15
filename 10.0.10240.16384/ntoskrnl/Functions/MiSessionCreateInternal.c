// MiSessionCreateInternal 
 
int __fastcall MiSessionCreateInternal(int *a1)
{
  unsigned int v2; // r9
  unsigned int v3; // r4
  _BYTE *v4; // r0
  unsigned int v5; // r10
  unsigned int v7; // r5
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r0
  int v12; // r0
  int v13; // r3
  int v14; // r8
  int v15; // r0
  int v16; // r7
  int v17; // r3
  unsigned int v18; // r1
  __int16 v19; // r0
  __int16 v20; // r4
  unsigned int v21; // r9
  int v22; // r1
  unsigned int v23; // r3
  int v24; // r1
  int v25; // r2
  int v26; // r2
  int v27; // r0
  unsigned int v28; // r2
  int v29; // r3
  unsigned int v30; // r8
  unsigned int *v31; // r0
  int v32; // r7
  unsigned int v33; // r0
  int v34; // r0
  __int16 v35; // r3
  unsigned int *v36; // r0
  unsigned int v37; // r1
  int v38; // r3
  int v39; // r7
  unsigned int v40; // r1
  unsigned int v41; // r0
  int v42; // r0
  __int16 v43; // r3
  int *v44; // [sp+8h] [bp-48h]
  int v45; // [sp+Ch] [bp-44h]
  int v46[2]; // [sp+10h] [bp-40h] BYREF
  unsigned int v47; // [sp+18h] [bp-38h]
  unsigned int v48; // [sp+1Ch] [bp-34h]
  int v49[12]; // [sp+20h] [bp-30h] BYREF

  v44 = a1;
  v2 = 0;
  v47 = MmSessionSpace;
  v46[0] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v3 = (((unsigned int)(-4194304 - dword_63389C) >> 22) + 7) >> 3;
  v48 = v3;
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, v3 + 2048, 1950903629);
  v5 = (unsigned int)v4;
  if ( !v4 )
    return -1073741670;
  memset(v4, 0, v3 + 2048);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 310);
  v8 = KeAbPreAcquire((unsigned int)&dword_633780, 0, 0);
  do
    v9 = __ldrex((unsigned __int8 *)&dword_633780);
  while ( __strex(v9 | 1, (unsigned __int8 *)&dword_633780) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_80F3C0(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = RtlFindClearBitsAndSet((unsigned int *)dword_634D30, 1u, 0);
  *a1 = v10;
  if ( v10 == -1 )
  {
    v30 = *(_DWORD *)dword_634D30 + 64;
    if ( v30 > 0x7FFFF )
      v30 = 0x7FFFF;
    v31 = (unsigned int *)ExAllocatePoolWithTag(1, 4 * (((v30 & 0x1F) != 0) + (v30 >> 5) + 2), 538996045);
    v32 = (int)v31;
    if ( !v31 )
    {
      __dmb(0xBu);
      do
        v33 = __ldrex((unsigned int *)&dword_633780);
      while ( __strex(v33 - 1, (unsigned int *)&dword_633780) );
      if ( (v33 & 2) != 0 && (v33 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&dword_633780);
      v34 = KeAbPostRelease((unsigned int)&dword_633780);
      v35 = *(_WORD *)(v7 + 310) + 1;
      *(_WORD *)(v7 + 310) = v35;
      if ( !v35 && *(_DWORD *)(v7 + 100) != v7 + 100 )
        KiCheckForKernelApcDelivery(v34);
      ExFreePoolWithTag(v5);
      return -1073741801;
    }
    v31[1] = (unsigned int)(v31 + 2);
    *v31 = v30;
    RtlClearAllBits((int)v31);
    memmove(
      *(_DWORD *)(v32 + 4),
      *(_DWORD *)(dword_634D30 + 4),
      4 * (((*(_DWORD *)dword_634D30 & 0x1F) != 0) + (*(_DWORD *)dword_634D30 >> 5)));
    ExFreePoolWithTag(dword_634D30);
    dword_634D30 = v32;
    *v44 = RtlFindClearBitsAndSet((unsigned int *)v32, 1u, 0);
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&dword_633780);
  while ( __strex(v11 - 1, (unsigned int *)&dword_633780) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_633780);
  v12 = KeAbPostRelease((unsigned int)&dword_633780);
  v13 = (__int16)(*(_WORD *)(v7 + 310) + 1);
  *(_WORD *)(v7 + 310) = v13;
  if ( !v13 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v12);
  v14 = 6;
  if ( !MiChargeCommit((int)MiSystemPartition, 6u, 0) )
  {
    v14 = 0;
LABEL_47:
    ExFreePoolWithTag(v5);
    if ( v14 )
      MiReturnCommit((int)MiSystemPartition, v14);
    if ( v2 )
      MiReleasePtes(&dword_634D58, v2, 3u);
    --*(_WORD *)(v7 + 310);
    v39 = KeAbPreAcquire((unsigned int)&dword_633780, 0, 0);
    do
      v40 = __ldrex((unsigned __int8 *)&dword_633780);
    while ( __strex(v40 | 1, (unsigned __int8 *)&dword_633780) );
    __dmb(0xBu);
    if ( (v40 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_633780, v39, (unsigned int)&dword_633780);
    if ( v39 )
      *(_BYTE *)(v39 + 14) |= 1u;
    *(_BYTE *)(((unsigned int)*v44 >> 3) + *(_DWORD *)(dword_634D30 + 4)) &= ~(1 << (*v44 & 7));
    __dmb(0xBu);
    do
      v41 = __ldrex((unsigned int *)&dword_633780);
    while ( __strex(v41 - 1, (unsigned int *)&dword_633780) );
    if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_633780);
    v42 = KeAbPostRelease((unsigned int)&dword_633780);
    v43 = *(_WORD *)(v7 + 310) + 1;
    *(_WORD *)(v7 + 310) = v43;
    if ( !v43 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v42);
    return -1073741801;
  }
  v15 = MiReservePtes(&dword_634D58, 3u);
  v2 = v15;
  if ( !v15 )
    goto LABEL_47;
  v16 = v15 << 10;
  v17 = *v44 ? 1024 : 20;
  v45 = v17;
  v49[0] = v17 + 6;
  if ( !MiChargeResident(MiSystemPartition, v17 + 6, 0) )
    goto LABEL_47;
  do
    v18 = __ldrex(&dword_634A2C[13]);
  while ( __strex(v18 + v49[0], &dword_634A2C[13]) );
  v19 = MiMapNewSession(v16);
  *(_DWORD *)v16 = 1;
  *(_DWORD *)(v16 + 4) = 0;
  v20 = v19;
  *(_DWORD *)(v16 + 8) = *v44;
  *(_DWORD *)(v16 + 72) = PsDefaultSystemLocaleId;
  *(_DWORD *)(v16 + 8416) = KeQueryInterruptTimePrecise((unsigned int *)v49);
  v21 = v47;
  *(_DWORD *)(v16 + 8420) = v22;
  v23 = *(_DWORD *)(((v21 >> 20) & 0xFFC) - 1070596096);
  *(_WORD *)(v16 + 3344) = v20;
  *(_DWORD *)(v16 + 24) = v23 >> 12;
  *(_DWORD *)(v16 + 3296) = v45;
  *(_DWORD *)(v16 + 28) = 6;
  *(_DWORD *)(v16 + 32) = 6;
  v24 = *(_DWORD *)MiGetTopPteAddress(v21);
  v25 = MmSessionSpace;
  *(_DWORD *)(v16 + 0x2000) = v5;
  *(_DWORD *)(v5 + 4 * ((unsigned int)(v25 - dword_63389C) >> 22)) = v24;
  v26 = dword_63501C;
  *(_DWORD *)(dword_63501C + 32) = 8 * v48;
  *(_DWORD *)(v26 + 36) = v5 + 2048;
  *(_DWORD *)(v16 + 68) = 0;
  *(_DWORD *)(v16 + 8300) = 0;
  *(_DWORD *)(v16 + 16) = v16 + 16;
  *(_DWORD *)(v16 + 20) = v16 + 16;
  *(_DWORD *)(v16 + 12) = 1;
  v27 = PsGetCurrentServerSilo();
  *(_DWORD *)(v16 + 8412) = v27;
  if ( v27 )
  {
    v36 = (unsigned int *)PsGetServerSiloGlobals(v27);
    v28 = *(_DWORD *)(v16 + 8);
    do
    {
      v37 = __ldrex(v36);
      if ( v37 != -1 )
        break;
      v29 = __strex(v28, v36);
    }
    while ( v29 );
  }
  MiMarkSessionMasterProcess(v46[0], v16, v28, v29);
  *(_DWORD *)(v16 + 8332) = 4;
  *(_DWORD *)(v16 + 8328) = (((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000;
  *(_DWORD *)(v16 + 8336) = 1;
  *(_DWORD *)(v16 + 8340) = v21 + 3216;
  *(_DWORD *)(v16 + 8348) = v16 + 8300;
  *(_DWORD *)(v16 + 8352) = v16 + 3248;
  if ( (dword_682604 & 0x400000) != 0 )
  {
    v38 = *(_DWORD *)(v16 + 8);
    v46[0] = v16;
    v46[1] = v38;
    v49[0] = (int)v46;
    v49[1] = 0;
    v49[2] = 8;
    v49[3] = 0;
    EtwTraceKernelEvent(v49, 1, 0x20400000u, 587, 4200451);
  }
  return 0;
}
