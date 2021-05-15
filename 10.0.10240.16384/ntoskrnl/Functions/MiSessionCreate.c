// MiSessionCreate 
 
int __fastcall MiSessionCreate(int *a1)
{
  unsigned int v1; // r5
  int v2; // r10
  int v3; // r7
  unsigned int v5; // r8
  int v6; // r8
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  unsigned int v19; // r4
  int v20; // r5
  int v21; // r8
  unsigned int v22; // r1
  unsigned int v23; // r0
  int v24; // r0
  __int16 v25; // r3
  unsigned int v26; // r0
  int v27; // r0
  __int16 v28; // r3
  unsigned int v29; // r0
  int v30; // r0
  __int16 v31; // r3
  unsigned int v32; // [sp+14h] [bp-34h]
  unsigned int v33; // [sp+18h] [bp-30h]
  unsigned int v34; // [sp+1Ch] [bp-2Ch]
  unsigned int v35; // [sp+20h] [bp-28h]
  unsigned int v37; // [sp+28h] [bp-20h]

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(v1 + 0x74);
  v3 = *(_DWORD *)(v1 + 0x150);
  if ( (*(_DWORD *)(v2 + 192) & 0x10000) != 0 )
    return sub_80F830();
  v5 = -4194304 - dword_63389C;
  v37 = -4194304 - dword_63389C;
  if ( MmIsSessionLeaderProcess(v3) )
    goto LABEL_18;
  if ( dword_633788 )
  {
    if ( PsIsCurrentThreadInServerSilo() )
    {
      --*(_WORD *)(v1 + 308);
      v21 = KeAbPreAcquire((unsigned int)&dword_63378C, 0, 0);
      do
        v22 = __ldrex((unsigned __int8 *)&dword_63378C);
      while ( __strex(v22 | 1, (unsigned __int8 *)&dword_63378C) );
      __dmb(0xBu);
      if ( (v22 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&dword_63378C, v21, (unsigned int)&dword_63378C);
      if ( v21 )
        *(_BYTE *)(v21 + 14) |= 1u;
      if ( !*((_DWORD *)PsGetCurrentServerSiloGlobals() + 7) )
      {
        *((_DWORD *)PsGetCurrentServerSiloGlobals() + 7) = v3;
        ObfReferenceObject(v3);
      }
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&dword_63378C);
      while ( __strex(v23 - 1, (unsigned int *)&dword_63378C) );
      if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)&dword_63378C);
      v24 = KeAbPostRelease((unsigned int)&dword_63378C);
      v25 = *(_WORD *)(v1 + 308) + 1;
      *(_WORD *)(v1 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
        KiCheckForKernelApcDelivery(v24);
    }
    if ( MmIsSessionLeaderProcess(v3) )
      goto LABEL_18;
    return -1073741796;
  }
  v32 = (((unsigned int)(-4194304 - dword_63389C) >> 15) + 4095) & 0xFFFFF000;
  v33 = (((v5 >> 19) + 4095) & 0xFFFFF000) + v32 + 0x10000;
  v34 = ((16 * ((unsigned int)(-4194304 - dword_63389C) >> 12) + 4194559) & 0xFFC00000) + 4096;
  v35 = (unsigned int)(-4194304 - dword_63389C) >> 12;
  --*(_WORD *)(v1 + 310);
  v6 = KeAbPreAcquire((unsigned int)&dword_63378C, 0, 0);
  do
    v7 = __ldrex((unsigned __int8 *)&dword_63378C);
  while ( __strex(v7 | 1, (unsigned __int8 *)&dword_63378C) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_63378C, v6, (unsigned int)&dword_63378C);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( dword_633788 )
  {
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)&dword_63378C);
    while ( __strex(v26 - 1, (unsigned int *)&dword_63378C) );
    if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_63378C);
    v27 = KeAbPostRelease((unsigned int)&dword_63378C);
    v28 = *(_WORD *)(v1 + 310) + 1;
    *(_WORD *)(v1 + 310) = v28;
    if ( !v28 && *(_DWORD *)(v1 + 100) != v1 + 100 )
      KiCheckForKernelApcDelivery(v27);
    if ( dword_633788 == v3 )
      goto LABEL_18;
    return -1073741796;
  }
  v8 = MiObtainSystemVa(((v34 + 4 * v35 + 0x3FFFFF) & 0xFFC00000) >> 22, 11);
  MmSessionSpace = v8;
  if ( !v8 )
  {
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)&dword_63378C);
    while ( __strex(v29 - 1, (unsigned int *)&dword_63378C) );
    if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_63378C);
    v30 = KeAbPostRelease((unsigned int)&dword_63378C);
    v31 = *(_WORD *)(v1 + 310) + 1;
    *(_WORD *)(v1 + 310) = v31;
    if ( !v31 && *(_DWORD *)(v1 + 100) != v1 + 100 )
      KiCheckForKernelApcDelivery(v30);
    return -1073741670;
  }
  dword_63377C = v32 + v8 + 0x10000;
  dword_63501C = v8 + 8260;
  dword_633790 = v33 + v8;
  dword_633794 = v34 + v8;
  dword_633798 = v34 + v8 + 4 * v35;
  dword_633788 = v3;
  *((_DWORD *)PsGetServerSiloGlobals(0) + 7) = v3;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&dword_63378C);
  while ( __strex(v9 - 1, (unsigned int *)&dword_63378C) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_63378C);
  v10 = KeAbPostRelease((unsigned int)&dword_63378C);
  v11 = (__int16)(*(_WORD *)(v1 + 310) + 1);
  *(_WORD *)(v1 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(v10);
  ObfReferenceObject(v3);
LABEL_18:
  v12 = MiSessionCreateInternal(a1);
  if ( v12 >= 0 )
  {
    v13 = *(_DWORD *)(v2 + 324);
    __dmb(0xBu);
    *(_DWORD *)(v13 + 3248) = 0;
    *(_BYTE *)(v13 + 3360) = *(_BYTE *)(v13 + 3360) & 0xF8 | 1;
    v14 = MiInitializeDynamicBitmap(v13 + 8320, dword_63377C, HIWORD(v37), 0);
    if ( !v14 )
      goto LABEL_29;
    v12 = MiSessionInitializeWorkingSetList(v14, v15, v16, v17);
    if ( v12 < 0 )
      goto LABEL_30;
    *(_DWORD *)(v13 + 36) = dword_63389C;
    *(_DWORD *)(v13 + 40) = -4194305;
    v12 = MiInitializeSessionPool();
    if ( v12 < 0 )
      goto LABEL_30;
    MiInitializeSpecialPool(33);
    v18 = ExAllocatePoolWithTag(33, 1, 1819242320);
    if ( v18 )
      ExFreePoolWithTag(v18);
    v19 = 8;
    v20 = v13 + 128;
    do
    {
      ExInitializePagedLookasideList(v20, 0, 0, 33, v19, 1819242320, 256);
      v19 += 8;
      v20 += 128;
    }
    while ( v19 < 0xC8 );
    *(_DWORD *)(v13 + 4) |= 1u;
    if ( MiInitializeSystemSpaceMap(v13 + 3200) )
    {
      v12 = MiSessionObjectCreate();
      if ( v12 >= 0 )
        return v12;
    }
    else
    {
LABEL_29:
      v12 = -1073741670;
    }
LABEL_30:
    MiDereferenceSession();
  }
  return v12;
}
