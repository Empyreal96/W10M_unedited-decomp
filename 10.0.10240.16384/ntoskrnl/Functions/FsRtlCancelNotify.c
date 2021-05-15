// FsRtlCancelNotify 
 
int __fastcall FsRtlCancelNotify(int a1, int a2)
{
  _DWORD *v2; // r10
  int v3; // r4
  unsigned int *v4; // r2
  unsigned int v5; // r0
  int v6; // r3
  unsigned int v7; // r6
  unsigned int v8; // r9
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r0
  _DWORD *v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r0
  int v17; // r6
  unsigned int v18; // r8
  unsigned int v19; // r3
  int v20; // r1
  int v21; // lr
  int v22; // r0
  int v23; // r0
  int result; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r1
  int v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r1
  __int16 v30; // r3
  int v31; // [sp+Ch] [bp-4Ch]
  unsigned int *v32; // [sp+20h] [bp-38h]
  unsigned int v33; // [sp+24h] [bp-34h]

  v2 = (_DWORD *)a2;
  v31 = 0;
  v3 = *(_DWORD *)(a2 + 28);
  __dmb(0xBu);
  v4 = (unsigned int *)(a2 + 56);
  do
    v5 = __ldrex(v4);
  while ( __strex(0, v4) );
  __dmb(0xBu);
  *(_DWORD *)(a2 + 28) = 0;
  KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  v32 = *(unsigned int **)v3;
  v7 = *(_DWORD *)v3;
  v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v33 != *(_DWORD *)(v7 + 32) )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = KeAbPreAcquire(v7, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      ExpAcquireFastMutexContended(v7, v9);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    *(_DWORD *)(v7 + 4) = v8;
    *(_DWORD *)(v7 + 32) = v33;
  }
  ++*(_DWORD *)(v7 + 36);
  if ( v2[22] )
  {
    v12 = v2[22];
    v13 = (_DWORD *)v2[23];
    if ( *(_DWORD **)(v12 + 4) != v2 + 22 || (_DWORD *)*v13 != v2 + 22 )
      __fastfail(3u);
    *v13 = v12;
    *(_DWORD *)(v12 + 4) = v13;
  }
  *(_BYTE *)(v2[24] + 3) |= 1u;
  v14 = *(_DWORD *)(v3 + 48);
  if ( v14 && !*(_DWORD *)(v3 + 44) )
  {
    if ( (v15 = v2[1]) != 0
      && ((*(_WORD *)(v15 + 6) & 5) == 0 ? (v16 = MmMapLockedPagesSpecifyCache(v15, 0, 1, 0, 0, 1073741840)) : (v16 = *(_DWORD *)(v15 + 12)),
          v14 = *(_DWORD *)(v3 + 48),
          v16 == v14)
      || v14 == v2[3] )
    {
      v17 = 0;
      v18 = 0;
      v19 = *(_DWORD *)(v3 + 60);
      if ( *(_DWORD *)(v3 + 24) == v3 + 24 )
      {
        if ( *(_DWORD *)(v3 + 52) >= v19 )
          v18 = *(_DWORD *)(v3 + 52);
      }
      else
      {
        v20 = *(_DWORD *)(v3 + 24);
        v21 = *(_DWORD *)(v20 + 8);
        if ( *(_DWORD *)(v21 + 8) >= v19 )
        {
          if ( *(_DWORD *)(v20 - 76) )
          {
            v17 = *(_DWORD *)(v20 - 76);
          }
          else
          {
            v22 = *(_DWORD *)(v20 - 84);
            if ( v22 )
            {
              if ( (*(_WORD *)(v22 + 6) & 5) != 0 )
                v17 = *(_DWORD *)(v22 + 12);
              else
                v17 = MmMapLockedPagesSpecifyCache(v22, 0, 1, 0, 0, 1073741840);
            }
          }
          v18 = *(_DWORD *)(v21 + 8);
          if ( v18 > *(_DWORD *)(v3 + 52) )
            v18 = *(_DWORD *)(v3 + 52);
        }
      }
      if ( v18 )
      {
        if ( !v17 )
        {
          v23 = PsChargeProcessPoolQuota(*(_DWORD *)(v3 + 72), 1, v18);
          if ( v23 < 0 )
            RtlRaiseStatus(v23);
          v17 = ExAllocatePoolWithTag(17, v18);
          *(_DWORD *)(v3 + 44) = v17;
        }
        memmove(v17, *(_DWORD *)(v3 + 48), *(_DWORD *)(v3 + 60));
        *(_DWORD *)(v3 + 56) = v18;
        *(_DWORD *)(v3 + 48) = v17;
      }
      else
      {
        *(_WORD *)(v3 + 36) |= 2u;
      }
      if ( (*(_WORD *)(v3 + 36) & 2) != 0 )
      {
        *(_DWORD *)(v3 + 48) = 0;
        *(_DWORD *)(v3 + 44) = 0;
        *(_DWORD *)(v3 + 64) = 0;
        *(_DWORD *)(v3 + 60) = 0;
        *(_DWORD *)(v3 + 56) = 0;
      }
    }
  }
  v2[6] = -1073741536;
  result = pIofCompleteRequest(v2, 1);
  __dmb(0xBu);
  v25 = (unsigned int *)(v3 + 68);
  do
    v26 = __ldrex(v25);
  while ( __strex(v26 - 1, v25) );
  __dmb(0xBu);
  if ( !*(_DWORD *)(v3 + 68) )
  {
    if ( *(_DWORD *)(v3 + 44) )
    {
      PsReturnProcessPagedPoolQuota(*(_DWORD *)(v3 + 72), *(_DWORD *)(v3 + 56));
      ExFreePoolWithTag(*(_DWORD *)(v3 + 44), 0);
    }
    if ( (*(_WORD *)(v3 + 36) & 0x40) != 0 || *(_DWORD *)(v3 + 80) )
      v31 = *(_DWORD *)(v3 + 12);
    result = ExFreePoolWithTag(v3, 0);
  }
  v27 = v32[9] - 1;
  v32[9] = v27;
  if ( !v27 )
  {
    v32[8] = 0;
    v32[1] = 0;
    __dmb(0xBu);
    do
      v28 = __ldrex(v32);
    while ( !v28 && __strex(1u, v32) );
    if ( v28 )
      ExpReleaseFastMutexContended(v32, v28);
    result = KeAbPostRelease((unsigned int)v32);
  }
  if ( v31 )
  {
    SeReleaseSubjectContext(v31);
    result = ExFreePoolWithTag(v31, 0);
  }
  v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v30 = *(_WORD *)(v29 + 0x134) + 1;
  *(_WORD *)(v29 + 308) = v30;
  if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
