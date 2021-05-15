// VerifierMmAllocatePagesForMdlEx 
 
int __fastcall VerifierMmAllocatePagesForMdlEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r0
  int v14; // r5
  int vars4; // [sp+34h] [bp+4h]

  ViMmValidateIrql((MmVerifierData & 0x20000) != 0);
  if ( VfFaultsInjectResourceFailure(0, v9, v10, v11) )
    return 0;
  v13 = pXdvMmAllocatePagesForMdlEx(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  v12 = v13;
  if ( v13 )
  {
    v14 = *(__int16 *)(v13 + 4);
    VfFillAllocatePagesForMdl(v13, a8, a9);
    if ( (MmVerifierData & 0x1000) != 0 )
      ViTargetAddToCounter(vars4, 120, 124, *(_DWORD *)(v12 + 20));
  }
  else
  {
    v14 = 28;
  }
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v12, v14);
  return v12;
}
