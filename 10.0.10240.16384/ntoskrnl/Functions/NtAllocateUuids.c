// NtAllocateUuids 
 
int __fastcall NtAllocateUuids(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  _DWORD *v6; // r0
  _DWORD *v7; // r0
  unsigned int v8; // r5
  int v9; // r0
  int v10; // r10
  unsigned int v11; // r2
  int v12; // r10
  unsigned int v13; // r1
  int v14; // r0
  __int16 v15; // r3
  int v16; // r4
  int v17; // r10
  unsigned int v18; // r1
  int v19; // r0
  __int16 v20; // r3
  _DWORD *v22; // [sp+8h] [bp-38h]
  _DWORD *v23; // [sp+Ch] [bp-34h]
  int v24; // [sp+10h] [bp-30h] BYREF
  int v25; // [sp+14h] [bp-2Ch] BYREF
  _DWORD _18[16]; // [sp+18h] [bp-28h] BYREF

  _18[15] = a4;
  v23 = (_DWORD *)a3;
  _18[14] = a3;
  v22 = (_DWORD *)a2;
  _18[13] = a2;
  _18[12] = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v6 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v6 = (_DWORD *)MmUserProbeAddress;
    *v6 = *v6;
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v6);
    v7 = (_DWORD *)a3;
    if ( a3 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
    if ( a4 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a4 = *(_BYTE *)a4;
    *(_BYTE *)(a4 + 5) = *(_BYTE *)(a4 + 5);
  }
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)&ExpUuidLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)&ExpUuidLock);
  while ( __strex(v11 | 1, (unsigned __int8 *)&ExpUuidLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpUuidLock, v9, (unsigned int)&ExpUuidLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = ExpAllocateUuids(_18, &v24, &v25);
  if ( v12 >= 0 )
  {
    ExpUuidSaveSequenceNumberIf();
    v17 = (unsigned __int8)ExpUuidCacheValid;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&ExpUuidLock);
    while ( __strex(v18 - 1, (unsigned int *)&ExpUuidLock) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ExpUuidLock);
    v19 = KeAbPostRelease((unsigned int)&ExpUuidLock);
    v20 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v19);
    *(_DWORD *)a1 = _18[0];
    *(_DWORD *)(a1 + 4) = _18[1];
    *v22 = v24;
    *v23 = v25;
    *(_DWORD *)a4 = *(int *)((char *)&dword_9203CC + 2);
    *(_WORD *)(a4 + 4) = word_9203D2;
    if ( v17 )
      v16 = 0;
    else
      v16 = 1073872982;
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&ExpUuidLock);
    while ( __strex(v13 - 1, (unsigned int *)&ExpUuidLock) );
    if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ExpUuidLock);
    v14 = KeAbPostRelease((unsigned int)&ExpUuidLock);
    v15 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v14);
    v16 = v12;
  }
  return v16;
}
