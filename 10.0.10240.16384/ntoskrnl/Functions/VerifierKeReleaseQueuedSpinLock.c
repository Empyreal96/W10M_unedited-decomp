// VerifierKeReleaseQueuedSpinLock 
 
int *__fastcall VerifierKeReleaseQueuedSpinLock(int a1, int a2)
{
  unsigned int v4; // r0
  unsigned int v5; // r4
  unsigned int *v6; // r4
  int *result; // r0
  unsigned int v8[6]; // [sp+8h] [bp-18h] BYREF

  v4 = KeGetCurrentIrql(a1);
  v5 = v4;
  if ( KernelVerifier == 1 && v4 < 2 )
    VerifierBugCheckIfAppropriate(196, 54, v4, a1, a2);
  v6 = (unsigned int *)ViKeLowerIrqlSanityChecks(v5, a2);
  result = (int *)pXdvKeReleaseQueuedSpinLock(a1, a2);
  if ( v6 )
  {
    *v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount((int *)v8);
    v6[2] = v8[0];
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
