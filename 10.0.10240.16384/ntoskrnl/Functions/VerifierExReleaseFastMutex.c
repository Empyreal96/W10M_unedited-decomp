// VerifierExReleaseFastMutex 
 
int *__fastcall VerifierExReleaseFastMutex(int a1, int a2, int a3, int a4)
{
  unsigned int *v5; // r5
  int *result; // r0
  int var10[6]; // [sp+0h] [bp-10h] BYREF

  var10[0] = a3;
  var10[1] = a4;
  v5 = (unsigned int *)ViExReleaseFastMutexCommon();
  VfDeadlockReleaseResource(a1, 3, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, var10[5]);
  result = (int *)pXdvExReleaseFastMutex(a1);
  if ( v5 )
  {
    *v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount(var10);
    v5[2] = var10[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v5[3] = 0;
    }
    else
    {
      result = (int *)RtlCaptureStackBackTrace(1u, 5u, (int)(v5 + 3), 0);
      if ( (unsigned int)result < 5 )
        v5[(_DWORD)result + 3] = 0;
    }
  }
  return result;
}
