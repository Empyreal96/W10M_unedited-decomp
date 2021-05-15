// VerifierKeEnterCriticalRegion 
 
unsigned int __fastcall VerifierKeEnterCriticalRegion(unsigned int a1)
{
  unsigned int result; // r0
  unsigned int v2; // r2
  unsigned int v3; // r2
  int v4; // r3
  unsigned int *v5; // r4

  if ( (MmVerifierData & 2) != 0 && (MmVerifierData & 0x20000) == 0 )
  {
    a1 = KeGetCurrentIrql(a1);
    if ( a1 > 1 )
      a1 = VerifierBugCheckIfAppropriate(196, 282, a1, 0, 0);
  }
  result = pXdvKeEnterCriticalRegion(a1);
  if ( VfKeCriticalRegionTraces )
  {
    __dmb(0xBu);
    do
    {
      v2 = __ldrex(&VfKeCriticalRegionTracesIndex);
      v3 = v2 + 1;
    }
    while ( __strex(v3, &VfKeCriticalRegionTracesIndex) );
    __dmb(0xBu);
    v4 = VfKeCriticalRegionTracesLength;
    __dmb(0xBu);
    v5 = (unsigned int *)(VfKeCriticalRegionTraces + 32 * (v3 & (v4 - 1)));
    *v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = RtlCaptureStackBackTrace(0, 7u, (int)(v5 + 1), 0);
    if ( result < 7 )
      v5[result + 1] = 0;
  }
  return result;
}
