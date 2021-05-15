// VerifierKeLeaveCriticalRegion 
 
int __fastcall VerifierKeLeaveCriticalRegion(unsigned int a1)
{
  unsigned int v1; // r2
  unsigned int v2; // r2
  int v3; // r3
  unsigned int *v4; // r4

  if ( (MmVerifierData & 2) != 0 && (MmVerifierData & 0x20000) == 0 )
  {
    a1 = KeGetCurrentIrql(a1);
    if ( a1 > 1 )
      a1 = VerifierBugCheckIfAppropriate(196, 283, a1, 0, 0);
  }
  if ( *(__int16 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) > 0 )
    a1 = VerifierBugCheckIfAppropriate(196, 62, 0, 0, 0);
  if ( VfKeCriticalRegionTraces )
  {
    __dmb(0xBu);
    do
    {
      v1 = __ldrex(&VfKeCriticalRegionTracesIndex);
      v2 = v1 + 1;
    }
    while ( __strex(v2, &VfKeCriticalRegionTracesIndex) );
    __dmb(0xBu);
    v3 = VfKeCriticalRegionTracesLength;
    __dmb(0xBu);
    v4 = (unsigned int *)(VfKeCriticalRegionTraces + 32 * (v2 & (v3 - 1)));
    *v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    a1 = RtlCaptureStackBackTrace(0, 7u, (int)(v4 + 1), 0);
    if ( a1 < 7 )
      v4[a1 + 1] = 0;
  }
  return pXdvKeLeaveCriticalRegion(a1);
}
