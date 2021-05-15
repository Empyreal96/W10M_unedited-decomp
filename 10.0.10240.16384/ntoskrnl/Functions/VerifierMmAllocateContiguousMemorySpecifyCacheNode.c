// VerifierMmAllocateContiguousMemorySpecifyCacheNode 
 
_BYTE *__fastcall VerifierMmAllocateContiguousMemorySpecifyCacheNode(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _BYTE *v11; // r4
  int v12; // r2
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int vars4; // [sp+2Ch] [bp+4h]
  unsigned int varg_r0; // [sp+30h] [bp+8h]

  varg_r0 = a1;
  if ( VfFaultsInjectResourceFailure(0, a2, a3, a4) )
    return 0;
  v12 = 4;
  if ( a9 == 1 )
  {
    if ( (MmVerifierData & 0x2000000) == 0 )
      v12 = 64;
  }
  else if ( a9 == 2 )
  {
    v12 = 1028;
  }
  else
  {
    v12 = 516;
  }
  v13 = pXdvMmAllocateContiguousNodeMemory(a1, pXdvMmAllocateContiguousNodeMemory, a3, a4, a5, a6, a7, a8, v12, a10);
  v11 = (_BYTE *)v13;
  v15 = VfPoolTraces;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v13, a1);
  if ( v11 )
  {
    VfFillAllocatedMemory(v11, a1, v14, v15);
    if ( (MmVerifierData & 8) != 0 )
      ViTargetTrackContiguousMemory(vars4, (int)v11, a1, MmVerifierData);
  }
  return v11;
}
