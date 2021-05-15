// VerifierPortKeReleaseSpinLockNoXdv 
 
int *__fastcall VerifierPortKeReleaseSpinLockNoXdv(unsigned int a1, int a2)
{
  _DWORD *v2; // r4
  unsigned int v4; // r0
  unsigned int v5; // r5
  unsigned int *v6; // r5
  int *result; // r0
  int var20[10]; // [sp+8h] [bp-20h] BYREF

  v2 = (_DWORD *)a1;
  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
  v4 = KeGetCurrentIrql(a1);
  v5 = v4;
  if ( v4 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v4, (int)v2, 0);
  v6 = (unsigned int *)ViKeLowerIrqlSanityChecks(v5, a2);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v2, var20[9]);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  result = (int *)KfLowerIrql(a2);
  if ( v6 )
  {
    *v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount(var20);
    v6[2] = var20[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v6[3] = 0;
    }
    else
    {
      result = (int *)RtlCaptureStackBackTrace(1u, 5u, (int)(v6 + 3), 0);
      if ( (unsigned int)result < 5 )
        v6[(_DWORD)result + 3] = 0;
    }
  }
  return result;
}
