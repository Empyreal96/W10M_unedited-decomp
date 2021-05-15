// VerifierMmAllocateContiguousNodeMemory 
 
_BYTE *__fastcall VerifierMmAllocateContiguousNodeMemory(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _BYTE *v14; // r4
  int v15; // r0
  int v16; // r2
  int v17; // r3
  int vars4; // [sp+24h] [bp+4h]
  unsigned int varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  VfCheckPageProtection(a9, vars4);
  if ( VfFaultsInjectResourceFailure(0, v11, v12, v13) )
    return 0;
  v15 = pXdvMmAllocateContiguousNodeMemory(a1, pXdvMmAllocateContiguousNodeMemory, a3, a4, a5, a6, a7, a8, a9, a10);
  v14 = (_BYTE *)v15;
  v17 = VfPoolTraces;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v15, a1);
  if ( v14 )
  {
    VfFillAllocatedMemory(v14, a1, v16, v17);
    if ( (MmVerifierData & 8) != 0 )
      ViTargetTrackContiguousMemory(vars4, (int)v14, a1, MmVerifierData);
  }
  return v14;
}
