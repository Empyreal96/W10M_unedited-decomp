// ViExTryToAcquireFastMutexCommon 
 
int __fastcall ViExTryToAcquireFastMutexCommon(int a1, int a2, int a3, int a4)
{
  char v5; // r0
  char v6; // r4
  int v7; // r5
  unsigned int *v8; // r4
  unsigned int v9; // r0
  int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  if ( (MmVerifierData & 0x800) != 0 )
    v5 = ViExCheckAPCLevelOrBelow(a1, a1, a2);
  else
    v5 = KeGetCurrentIrql(a1);
  v6 = v5;
  v7 = pXdvExTryToAcquireFastMutex(a1);
  if ( v7 )
  {
    v8 = (unsigned int *)VfKeIrqlTransitionReserveLogEntry(v6, 1);
    if ( v8 )
    {
      *v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      KeQueryTickCount(v11);
      v8[2] = v11[0];
      if ( (VfOptionFlags & 0x40) != 0 )
      {
        v8[3] = 0;
      }
      else
      {
        v9 = RtlCaptureStackBackTrace(2u, 5u, (int)(v8 + 3), 0);
        if ( v9 < 5 )
          v8[v9 + 3] = 0;
      }
    }
  }
  return v7;
}
