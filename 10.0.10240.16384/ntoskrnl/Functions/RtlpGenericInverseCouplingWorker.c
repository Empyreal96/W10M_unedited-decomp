// RtlpGenericInverseCouplingWorker 
 
int __fastcall RtlpGenericInverseCouplingWorker(int a1, int a2, _DWORD *a3)
{
  _DWORD *v7; // r3

  RtlFillMemoryUlong(a3, 0x1000u, a1);
  KeInvalidateRangeAllCaches((int)a3, 4096);
  if ( !RtlpTestAndFillMemoryUp(a1, a1, a3) )
    return 0;
  KeInvalidateRangeAllCaches((int)a3, 4096);
  if ( !RtlpTestMemory(a1, a3) )
    return 0;
  RtlFillMemoryUlong(a3, 0x1000u, a1);
  KeInvalidateRangeAllCaches((int)a3, 4096);
  RtlFillMemoryUlong(a3, 0x1000u, a2);
  KeInvalidateRangeAllCaches((int)a3, 4096);
  if ( !RtlpTestMemory(a2, a3) )
    return 0;
  RtlFillMemoryUlong(a3, 0x1000u, a1);
  KeInvalidateRangeAllCaches((int)a3, 4096);
  v7 = a3 + 1024;
  do
    *--v7 = a2;
  while ( v7 != a3 );
  KeInvalidateRangeAllCaches((int)a3, 4096);
  return RtlpTestMemory(a2, a3);
}
