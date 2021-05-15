// ViPoolLogStackTrace 
 
int __fastcall ViPoolLogStackTrace(int result, int a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r2
  int *v4; // r4
  int v5; // r3
  unsigned int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3

  if ( VfPoolTraces )
  {
    __dmb(0xBu);
    do
    {
      v2 = __ldrex(&VfPoolTracesIndex);
      v3 = v2 + 1;
    }
    while ( __strex(v3, &VfPoolTracesIndex) );
    __dmb(0xBu);
    v4 = (int *)(VfPoolTraces + ((v3 & (VfPoolTracesLength - 1)) << 6));
    v5 = __mrc(15, 0, 13, 0, 3);
    v4[1] = a2;
    v4[2] = v5 & 0xFFFFFFC0;
    *v4 = result;
    if ( (VfOptionFlags & 2) != 0 )
    {
      v4[3] = 0;
    }
    else
    {
      v6 = KeGetCurrentIrql(result);
      if ( v6 > 1 || RtlEnoughStackSpaceForStackCapture(v6, v7, v8, v9) )
      {
        result = ViPoolLogStackCallout((int)v4);
      }
      else
      {
        result = KeExpandKernelStackAndCalloutEx((int)ViPoolLogStackCallout, (int)v4, 720, 1, 0);
        if ( result < 0 )
          v4[3] = 0;
      }
    }
  }
  return result;
}
