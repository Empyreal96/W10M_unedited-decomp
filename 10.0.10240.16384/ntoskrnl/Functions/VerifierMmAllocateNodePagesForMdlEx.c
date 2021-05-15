// VerifierMmAllocateNodePagesForMdlEx 
 
int __fastcall VerifierMmAllocateNodePagesForMdlEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int v14; // r0
  int v15; // r5
  int vars4; // [sp+2Ch] [bp+4h]

  ViMmValidateIrql(0);
  if ( VfFaultsInjectResourceFailure(0, v10, v11, v12) )
    return 0;
  v14 = pXdvMmAllocateNodePagesForMdlEx(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = v14;
  if ( v14 )
  {
    v15 = *(__int16 *)(v14 + 4);
    VfFillAllocatePagesForMdl(v14, a8, a10);
    if ( (MmVerifierData & 0x1000) != 0 )
      ViTargetAddToCounter(vars4, 120, 124, *(_DWORD *)(v13 + 20));
  }
  else
  {
    v15 = 28;
  }
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v13, v15);
  return v13;
}
