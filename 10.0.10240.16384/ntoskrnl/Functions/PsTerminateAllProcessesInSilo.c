// PsTerminateAllProcessesInSilo 
 
int __fastcall PsTerminateAllProcessesInSilo(int a1, int a2)
{
  unsigned int v4; // r2
  int v5; // r4
  int v6; // r7
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned int v14; // r2
  int i; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  __int16 v19; // r3
  __int16 v20; // r3
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r8
  int j; // r4
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  int v28; // r0
  unsigned int v29; // r2
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  int v34; // [sp+0h] [bp-30h]
  unsigned int v35; // [sp+8h] [bp-28h] BYREF
  int v36; // [sp+Ch] [bp-24h]

  v34 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  ExAcquireResourceSharedLite(a1 + 28, 1);
  v5 = *(_DWORD *)(a1 + 108);
  v6 = a1 + 104;
  while ( v6 != v5 )
  {
    if ( (*(_DWORD *)(v5 - 72) & 0x100) == 0 && (*(_DWORD *)(v5 - 616) & 8) == 0 && ObReferenceObjectSafe(v5 - 808) )
    {
      v7 = ExReleaseResourceLite(a1 + 28);
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = *(_WORD *)(v8 + 0x136) + 1;
      *(_WORD *)(v8 + 310) = v9;
      if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 )
        KiCheckForKernelApcDelivery(v7);
      if ( PsTerminateProcess(v5 - 808, a2) >= 0 )
        v34 = 1;
      ObfDereferenceObject(v5 - 808);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 310);
      ExAcquireResourceSharedLite(a1 + 28, 1);
      v5 = a1 + 104;
    }
    v5 = *(_DWORD *)(v5 + 4);
  }
  v11 = ExReleaseResourceLite(a1 + 28);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x136) + 1;
  *(_WORD *)(v12 + 310) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 )
    KiCheckForKernelApcDelivery(v11);
  v35 = -10000000;
  v36 = -1;
  KeDelayExecutionThread(0, 0, &v35);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 310);
  ExAcquireResourceSharedLite(a1 + 28, 1);
  for ( i = *(_DWORD *)(a1 + 108); v6 != i; i = *(_DWORD *)(i + 4) )
  {
    if ( (*(_DWORD *)(i - 72) & 0x100) == 0
      && (*(_DWORD *)(i - 616) & 8) != 0
      && i - 808 != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    {
      v16 = ExReleaseResourceLite(a1 + 28);
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x136) + 1;
      *(_WORD *)(v17 + 310) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 )
        KiCheckForKernelApcDelivery(v16);
      v19 = PspDebugFlags;
      __dmb(0xBu);
      if ( (v19 & 0x100) != 0 )
      {
        v20 = PspDebugFlags;
        __dmb(0xBu);
        if ( (v20 & 0x200) != 0 )
          __debugbreak();
      }
      v35 = -30000000;
      v36 = -1;
      KeDelayExecutionThread(0, 0, &v35);
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v21 + 310);
      ExAcquireResourceSharedLite(a1 + 28, 1);
      i = a1 + 104;
    }
  }
  v22 = PspGetServerSiloForSilo(a1);
  v23 = *(_DWORD *)PsGetServerSiloGlobals(v22);
  for ( j = *(_DWORD *)(a1 + 108); v6 != j; j = *(_DWORD *)(j + 4) )
  {
    if ( MmGetSessionId(j - 808) != v23 && (*(_DWORD *)(j - 616) & 8) == 0 && ObReferenceObjectSafe(j - 808) )
    {
      v25 = ExReleaseResourceLite(a1 + 28);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x136) + 1;
      *(_WORD *)(v26 + 310) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 )
        KiCheckForKernelApcDelivery(v25);
      v28 = MmGetSessionId(j - 808);
      CsrShutdownSynchronization(a1, v28, j - 808);
      ObfDereferenceObject(j - 808);
      v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v29 + 310);
      ExAcquireResourceSharedLite(a1 + 28, 1);
      j = a1 + 104;
    }
  }
  v30 = ExReleaseResourceLite(a1 + 28);
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x136) + 1;
  *(_WORD *)(v31 + 310) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 )
    KiCheckForKernelApcDelivery(v30);
  return v34;
}
