// ViFaultsTracesLog 
 
unsigned int __fastcall ViFaultsTracesLog(unsigned int result)
{
  unsigned int v1; // r2
  unsigned int v2; // r2
  unsigned int *v3; // r4

  if ( ViFaultTraces )
  {
    __dmb(0xBu);
    do
    {
      v1 = __ldrex(&ViFaultTracesIndex);
      v2 = v1 + 1;
    }
    while ( __strex(v2, &ViFaultTracesIndex) );
    __dmb(0xBu);
    v3 = (unsigned int *)(ViFaultTraces + 36 * ((ViFaultTracesLength - 1) & v2));
    *v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = RtlCaptureStackBackTrace(result, 8u, (int)(v3 + 1), 0);
    if ( result < 8 )
      v3[result + 1] = 0;
  }
  return result;
}
