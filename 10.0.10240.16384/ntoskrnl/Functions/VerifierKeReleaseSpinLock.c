// VerifierKeReleaseSpinLock 
 
unsigned int __fastcall VerifierKeReleaseSpinLock(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v6; // r0
  unsigned int v7; // r5
  unsigned int *v8; // r5
  unsigned int v9; // r0
  unsigned int v11; // [sp+0h] [bp-20h]
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v11 = a1;
  v12[0] = a3;
  v12[1] = a4;
  v4 = a1;
  if ( a1 < MmHighestUserAddress || a1 + 4 < a1 )
    a1 = VerifierBugCheckIfAppropriate(196, 224, a1, 4, 0);
  v6 = KeGetCurrentIrql(a1);
  v7 = v6;
  if ( v6 < 2 )
    VerifierBugCheckIfAppropriate(196, 50, v6, v4, 0);
  v8 = (unsigned int *)ViKeLowerIrqlSanityChecks(v7, a2);
  VfDeadlockReleaseResource(v4, 5, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  pXdvKeReleaseSpinLock(v4, a2);
  if ( v8 )
  {
    *v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    KeQueryTickCount(v12);
    v8[2] = v12[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v8[3] = 0;
    }
    else
    {
      v9 = RtlCaptureStackBackTrace(1u, 5u, (int)(v8 + 3), 0);
      if ( v9 < 5 )
        v8[v9 + 3] = 0;
    }
  }
  return v11;
}
