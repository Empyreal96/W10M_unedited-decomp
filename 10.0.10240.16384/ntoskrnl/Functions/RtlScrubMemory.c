// RtlScrubMemory 
 
int __fastcall RtlScrubMemory(int *a1)
{
  __int64 v2; // r0
  int v3; // r4
  unsigned int v4; // r5
  int result; // r0

  LODWORD(v2) = ReadTimeStampCounter();
  v3 = HIDWORD(v2) << 28;
  v4 = v2;
  RtlFillMemoryUlong(a1, 0x1000u, v2 >> 4);
  KeInvalidateRangeAllCaches((int)a1, 4096);
  if ( RtlCompareMemoryUlong(a1, (char *)0x1000, v3 | (v4 >> 4)) == (char *)4096
    && RtlpGenericBasicMATSPlus(a1)
    && RtlpGenericBasicInverseCoupling(a1)
    && RtlpGenericBasicStride6(a1)
    && RtlpGenericRandomPatternWorker(a1) )
  {
    result = 0;
  }
  else
  {
    result = -1073740023;
  }
  return result;
}
