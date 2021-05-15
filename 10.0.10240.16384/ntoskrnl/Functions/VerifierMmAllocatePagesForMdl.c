// VerifierMmAllocatePagesForMdl 
 
int __fastcall VerifierMmAllocatePagesForMdl(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r0
  int v12; // r5
  int vars4; // [sp+24h] [bp+4h]

  ViMmValidateIrql((MmVerifierData & 0x20000) != 0);
  if ( VfFaultsInjectResourceFailure(0, v7, v8, v9) )
    return 0;
  v11 = pXdvMmAllocatePagesForMdl(a1, a2, a3, a4, a5, a6, a7);
  v10 = v11;
  if ( v11 )
  {
    v12 = *(__int16 *)(v11 + 4);
    if ( (MmVerifierData & 0x1000) != 0 )
      ViTargetAddToCounter(vars4, 120, 124, *(_DWORD *)(v11 + 20));
  }
  else
  {
    v12 = 28;
  }
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v10, v12);
  return v10;
}
