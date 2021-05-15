// VerifierKeReleaseInStackQueuedSpinLockNoReboot 
 
int *__fastcall VerifierKeReleaseInStackQueuedSpinLockNoReboot(int a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r4
  unsigned int *v4; // r4
  int *result; // r0
  unsigned int v6[6]; // [sp+8h] [bp-18h] BYREF

  v2 = KeGetCurrentIrql(a1);
  v3 = v2;
  if ( v2 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v2, a1, 0);
  v4 = (unsigned int *)ViKeLowerIrqlSanityChecks(v3, *(unsigned __int8 *)(a1 + 8));
  result = (int *)pXdvKeReleaseInStackQueuedSpinLock(a1);
  if ( v4 )
  {
    *v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount((int *)v6);
    v4[2] = v6[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v4[3] = 0;
    }
    else
    {
      result = (int *)RtlCaptureStackBackTrace(1u, 5u, (int)(v4 + 3), 0);
      if ( (unsigned int)result < 5 )
        v4[(_DWORD)result + 3] = 0;
    }
  }
  return result;
}
