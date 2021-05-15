// ViKeRaiseIrqlSanityChecks 
 
unsigned int *__fastcall ViKeRaiseIrqlSanityChecks(unsigned int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r6
  unsigned int *v6; // r4
  unsigned int v7; // r0
  unsigned int v9[8]; // [sp+8h] [bp-20h] BYREF

  v4 = KeGetCurrentIrql(a1);
  v5 = v4;
  if ( (MmVerifierData & 2) != 0 )
  {
    if ( v4 > a1 && !a2 )
      VerifierBugCheckIfAppropriate(196, 48, v4, a1, 0);
    if ( a1 > 0xF )
      VerifierBugCheckIfAppropriate(196, 48, v5, a1, 0);
  }
  v6 = (unsigned int *)VfKeIrqlTransitionReserveLogEntry(v5, a1);
  if ( v6 )
  {
    *v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    KeQueryTickCount((int *)v9);
    v6[2] = v9[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v6[3] = 0;
    }
    else
    {
      v7 = RtlCaptureStackBackTrace(2u, 5u, (int)(v6 + 3), 0);
      if ( v7 < 5 )
        v6[v7 + 3] = 0;
    }
  }
  if ( (MmVerifierData & 2) != 0 && KeAreInterruptsEnabled() && v5 < 2 && a1 >= 2 )
    MmVerifierTrimMemory();
  return v6;
}
