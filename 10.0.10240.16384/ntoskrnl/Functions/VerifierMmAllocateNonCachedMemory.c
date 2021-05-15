// VerifierMmAllocateNonCachedMemory 
 
_BYTE *__fastcall VerifierMmAllocateNonCachedMemory(unsigned int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int vars4; // [sp+Ch] [bp+4h]

  if ( VfFaultsInjectResourceFailure(0, a2, a3, a4) )
    return 0;
  v6 = pXdvMmAllocateNonCachedMemory(a1);
  v5 = (_BYTE *)v6;
  v8 = VfPoolTraces;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v6, a1);
  if ( v5 )
  {
    VfFillAllocatedMemory(v5, a1, v7, v8);
    if ( (MmVerifierData & 8) != 0 )
      ViTargetTrackContiguousMemory(vars4, (int)v5, a1, MmVerifierData);
  }
  return v5;
}
