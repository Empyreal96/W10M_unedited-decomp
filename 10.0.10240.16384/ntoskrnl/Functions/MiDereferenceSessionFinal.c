// MiDereferenceSessionFinal 
 
int __fastcall MiDereferenceSessionFinal(int a1, int a2, int a3)
{
  int v3; // r3
  unsigned int v4; // r4
  int v5; // r9
  _DWORD *v6; // r7
  int v7; // r0
  int (__fastcall *v8)(_DWORD); // r3
  _DWORD *v9; // r5
  int v10; // r6
  int v11; // r0
  int v12; // r2
  int v13; // r6
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r2
  __int16 v18; // r3
  int v19; // r3
  int v20; // r4
  int v21; // r5
  int v22; // r6
  unsigned int v23; // r0
  int v24; // r2
  unsigned int v25; // r4
  int result; // r0
  int v27; // [sp+8h] [bp-30h] BYREF
  int v28; // [sp+Ch] [bp-2Ch]
  int v29; // [sp+10h] [bp-28h]
  int v30; // [sp+14h] [bp-24h]

  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = v3 & 0xFFFFFFC0;
  v5 = *(_DWORD *)((v3 & 0xFFFFFFC0) + 0x74);
  v6 = *(_DWORD **)(v5 + 324);
  v7 = MiUnlinkSessionWorkingSet((int)v6, a2, a3, v3);
  if ( v6[12] )
  {
    KeSetEvent(v6[11], 1, 0);
    v7 = ObCloseHandle(v6[12]);
  }
  v8 = (int (__fastcall *)(_DWORD))v6[845];
  if ( (unsigned int)v8 > 1 )
    v7 = v8(0);
  MiSessionUnloadAllImages(v7);
  ExSessionDeleted(v6[2]);
  MiFreeSessionSpaceMap();
  if ( (v6[1] & 1) != 0 )
  {
    v9 = v6 + 32;
    v10 = 24;
    do
    {
      ExDrainPoolLookasideList(v9);
      v9 += 32;
      --v10;
    }
    while ( v10 );
    v11 = ExDeferredFreePool((int)(v6 + 864), 0);
    v12 = v6[2072];
    if ( v12 )
      KeBugCheckEx(236, v6[2], v12, 0, 0);
    MiCheckSessionPoolAllocations(v11);
  }
  --*(_WORD *)(v4 + 310);
  v13 = KeAbPreAcquire((unsigned int)&dword_63378C, 0, 0);
  do
    v14 = __ldrex((unsigned __int8 *)&dword_63378C);
  while ( __strex(v14 | 1, (unsigned __int8 *)&dword_63378C) );
  __dmb(0xBu);
  if ( (v14 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_63378C, v13, (unsigned int)&dword_63378C);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  v6[1] |= 0x20u;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&dword_63378C);
  while ( __strex(v15 - 1, (unsigned int *)&dword_63378C) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_63378C);
  v16 = KeAbPostRelease((unsigned int)&dword_63378C);
  v18 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v18;
  if ( !v18 )
  {
    v17 = v4 + 100;
    if ( *(_DWORD *)(v4 + 100) != v4 + 100 )
      v16 = KiCheckForKernelApcDelivery(v16);
  }
  v19 = *(_DWORD *)(v5 + 232);
  if ( v19 )
  {
    MiSessionUnlinkProcess(v16, v5, v17, v19);
    *(_DWORD *)(v5 + 232) = 0;
  }
  MiDeleteSessionAddressSpace((unsigned int)v6, &v27);
  MiDetachProcessFromSession(0);
  v20 = v27;
  v21 = v28;
  v22 = v30;
  MiReturnResidentAvailable(v27);
  do
    v23 = __ldrex(&dword_634A2C[15]);
  while ( __strex(v23 + v20, &dword_634A2C[15]) );
  MiReturnResidentAvailable(v6[824]);
  v24 = v6[824];
  do
    v25 = __ldrex(&dword_634A2C[14]);
  while ( __strex(v25 + v24, &dword_634A2C[14]) );
  MiReturnCommit((int)MiSystemPartition, v22 - v21);
  result = v6[2103];
  if ( result )
    result = PspDereferenceSiloObject(result);
  v6[2103] = 0;
  return result;
}
