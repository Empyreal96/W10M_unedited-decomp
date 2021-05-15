// PfpScenCtxScenarioSet 
 
unsigned int __fastcall PfpScenCtxScenarioSet(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r1
  int v13; // r0
  int v14; // r2
  int v15; // r4
  int v16; // r1
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int result; // r0
  int v22; // [sp+0h] [bp-20h] BYREF
  unsigned int v23; // [sp+4h] [bp-1Ch]
  int v24; // [sp+8h] [bp-18h]

  v24 = a4;
  v22 = 0;
  v23 = 0;
  if ( a3 == 1 || a3 == 2 || a3 == 5 )
    PfpServiceMainThreadBoostPrep(a1, &v22);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(a1, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v11 | 1, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v9, a1);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( !a3 && *(_DWORD *)(a1 + 28) != a2 )
    goto LABEL_31;
  v12 = *(_DWORD *)(a1 + 28);
  if ( v12 )
  {
    PfpScenCtxPrefetchStateSet(a1, v12, 0, 1);
    v13 = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 4) & 0xFFFFFFF3 | 8;
    if ( v13 )
      KeSetEvent(v13, 0, 0);
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(a1 + 4) &= 0xFFFFFFF3;
    if ( *(_DWORD *)(a1 + 28) )
      goto LABEL_19;
  }
  if ( a3 )
LABEL_19:
    v14 = 1;
  else
    v14 = 0;
  *(_DWORD *)(a1 + 28) = a3;
  if ( a3 )
    ++*(_DWORD *)(a1 + 32);
  if ( a3 == 3 )
    *(_DWORD *)(a1 + 36) = a4;
  if ( v14 )
  {
    v15 = v22;
    if ( a3 )
    {
      if ( v22 )
      {
        PfpServiceMainThreadBoost((_DWORD *)a1, &v22);
        v15 = v22;
        v16 = 0;
      }
      else
      {
        v16 = 4;
      }
    }
    else
    {
      v16 = 1;
    }
    KeSetEvent(*(_DWORD *)(a1 + 40), v16, 0);
  }
  else
  {
LABEL_31:
    v15 = v22;
  }
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)a1);
  while ( __strex(v17 - 1, (unsigned int *)a1) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  v18 = KeAbPostRelease(a1);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  if ( v15 )
    ObDereferenceObjectDeferDelete(v15);
  result = v23;
  if ( v23 )
    result = ExFreePoolWithTag(v23);
  return result;
}
