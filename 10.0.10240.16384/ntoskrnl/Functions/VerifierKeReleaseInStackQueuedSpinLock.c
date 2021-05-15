// VerifierKeReleaseInStackQueuedSpinLock 
 
int *__fastcall VerifierKeReleaseInStackQueuedSpinLock(int a1)
{
  int v2; // r1
  int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r4
  unsigned int *v6; // r4
  int *result; // r0
  int var18[8]; // [sp+8h] [bp-18h] BYREF

  v2 = *(_DWORD *)(a1 + 4);
  __dmb(0xBu);
  v3 = VfDeadlockReleaseResource(v2 & 0xFFFFFFFC, 6, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, var18[7]);
  v4 = KeGetCurrentIrql(v3);
  v5 = v4;
  if ( v4 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v4, a1, 0);
  v6 = (unsigned int *)ViKeLowerIrqlSanityChecks(v5, *(unsigned __int8 *)(a1 + 8));
  result = (int *)pXdvKeReleaseInStackQueuedSpinLock(a1);
  if ( v6 )
  {
    *v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount(var18);
    v6[2] = var18[0];
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
