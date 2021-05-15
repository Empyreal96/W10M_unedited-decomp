// VerifierMmAllocateContiguousMemorySpecifyCache 
 
_BYTE *__fastcall VerifierMmAllocateContiguousMemorySpecifyCache(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _BYTE *v10; // r4
  int v11; // r2
  int v12; // r0
  int v13; // r2
  int v14; // r3
  int vars4; // [sp+2Ch] [bp+4h]
  unsigned int varg_r0; // [sp+30h] [bp+8h]

  varg_r0 = a1;
  if ( VfFaultsInjectResourceFailure(0, a2, a3, a4) )
    return 0;
  v11 = 4;
  if ( a9 == 1 )
  {
    if ( (MmVerifierData & 0x2000000) == 0 )
      v11 = 64;
  }
  else if ( a9 == 2 )
  {
    v11 = 1028;
  }
  else
  {
    v11 = 516;
  }
  v12 = pXdvMmAllocateContiguousNodeMemory(
          a1,
          pXdvMmAllocateContiguousNodeMemory,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          v11,
          0x80000000);
  v10 = (_BYTE *)v12;
  v14 = VfPoolTraces;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v12, a1);
  if ( v10 )
  {
    VfFillAllocatedMemory(v10, a1, v13, v14);
    if ( (MmVerifierData & 8) != 0 )
      ViTargetTrackContiguousMemory(vars4, (int)v10, a1, MmVerifierData);
  }
  return v10;
}
