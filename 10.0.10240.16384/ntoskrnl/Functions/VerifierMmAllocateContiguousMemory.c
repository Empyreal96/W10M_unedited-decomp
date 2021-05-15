// VerifierMmAllocateContiguousMemory 
 
_BYTE *__fastcall VerifierMmAllocateContiguousMemory(int a1, int a2, __int64 a3)
{
  int v4; // r0
  _BYTE *v5; // r4
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int vars4; // [sp+2Ch] [bp+4h]
  int varg_r0; // [sp+30h] [bp+8h]

  varg_r0 = a1;
  v4 = VfFaultsInjectResourceFailure(0, a2, a3, SHIDWORD(a3));
  if ( v4 )
    return 0;
  if ( (MmVerifierData & 0x2000000) != 0 )
    v4 = 4;
  if ( (MmVerifierData & 0x2000000) == 0 )
    v4 = 64;
  v6 = ((int (__fastcall *)(int, __int64, __int64, __int16, int, int))pXdvMmAllocateContiguousNodeMemory)(
         a1,
         0i64,
         a3,
         0,
         0,
         v4);
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
