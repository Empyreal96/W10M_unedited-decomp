// PiPnpRtlEnsureObjectCached 
 
int __fastcall PiPnpRtlEnsureObjectCached(int a1, unsigned __int16 *a2)
{
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r2
  int v17; // r1
  int v18; // r3
  unsigned int v19; // r2
  int v20; // r6
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // [sp+0h] [bp-20h] BYREF
  int v25; // [sp+4h] [bp-1Ch] BYREF
  int v26[6]; // [sp+8h] [bp-18h] BYREF

  v24 = 0;
  v25 = 0;
  v26[0] = 0;
  v3 = PiDmGetObject(1, (int)a2, (int *)&v24);
  v4 = v3;
  if ( v3 >= 0 )
  {
    v4 = 0;
LABEL_3:
    v5 = v24;
    goto LABEL_4;
  }
  if ( v3 != -1073741772 )
    goto LABEL_3;
  v4 = PiDmAddCacheReferenceForObject(1, a2, (int *)&v24);
  if ( v4 < 0 )
    goto LABEL_3;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v5 = v24;
  v8 = KeAbPreAcquire(v24, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v10 | 1, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)v5, v8, v5);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_DWORD *)(v5 + 24);
  __pld((void *)v5);
  *(_DWORD *)(v5 + 24) = v11 | 1;
  v12 = *(_DWORD *)v5;
  if ( (*(_DWORD *)v5 & 0xFFFFFFF0) <= 0x10 )
    v13 = 0;
  else
    v13 = v12 - 16;
  if ( (v12 & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v5);
  while ( v14 == v12 && __strex(v13, (unsigned int *)v5) );
  if ( v14 != v12 )
LABEL_23:
    ExfReleasePushLock((_DWORD *)v5, v12);
  v15 = KeAbPostRelease(v5);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
  *(_WORD *)(v17 + 308) = v18;
  if ( !(_WORD)v18 )
  {
    v18 = *(_DWORD *)(v17 + 100);
    v16 = v17 + 100;
    if ( v18 != v17 + 100 )
    {
      v18 = *(__int16 *)(v17 + 310);
      if ( !*(_WORD *)(v17 + 310) )
        KiCheckForKernelApcDelivery(v15);
    }
  }
  if ( PiPnpRtlBeginOperation(&v25, v17, v16, v18) >= 0 )
  {
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v19 + 308);
    ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
    v20 = PiPnpRtlObjectEventCreate((int)a2, 1, v25, v26);
    v21 = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = *(_WORD *)(v22 + 0x134) + 1;
    *(_WORD *)(v22 + 308) = v23;
    if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
      KiCheckForKernelApcDelivery(v21);
    if ( v20 >= 0 && v26[0] )
      *(_DWORD *)(v26[0] + 4) |= 1u;
    PiPnpRtlEndOperation(v25);
  }
LABEL_4:
  if ( v5 )
    PiDmObjectRelease(v5);
  return v4;
}
