// ViExAcquireFastMutexCommon 
 
unsigned int __fastcall ViExAcquireFastMutexCommon(int a1, int a2, int a3, int a4)
{
  char v5; // r0
  char v6; // r4
  unsigned int result; // r0
  unsigned int v8; // r4
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  if ( (MmVerifierData & 0x800) != 0 )
    v5 = ViExCheckAPCLevelOrBelow(a1, a1, a2);
  else
    v5 = KeGetCurrentIrql(a1);
  v6 = v5;
  pXdvExAcquireFastMutex(a1);
  result = VfKeIrqlTransitionReserveLogEntry(v6, 1);
  v8 = result;
  if ( result )
  {
    *(_DWORD *)result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = (unsigned int)KeQueryTickCount(v9);
    *(_DWORD *)(v8 + 8) = v9[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      *(_DWORD *)(v8 + 12) = 0;
    }
    else
    {
      result = RtlCaptureStackBackTrace(2u, 5u, v8 + 12, 0);
      if ( result < 5 )
        *(_DWORD *)(v8 + 4 * result + 12) = 0;
    }
  }
  return result;
}
