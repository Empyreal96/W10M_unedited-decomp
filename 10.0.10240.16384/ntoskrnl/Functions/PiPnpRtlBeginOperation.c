// PiPnpRtlBeginOperation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiPnpRtlBeginOperation(int *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r5
  int v8; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r0
  int *v13; // r2
  int v14; // r1 OVERLAPPED
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19[6]; // [sp+8h] [bp-18h] BYREF

  v19[0] = a4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19[0] = 0;
  *a1 = 0;
  v6 = PiPnpRtlGetCurrentOperation(v19);
  v7 = v6;
  if ( v6 == -1073741275 )
  {
    v7 = 0;
  }
  else if ( v6 < 0 )
  {
    return v7;
  }
  v8 = v19[0];
  if ( v19[0] )
  {
    ++*(_DWORD *)(v19[0] + 76);
  }
  else
  {
    v9 = ExAllocatePoolWithTag(1, 80, 1097887312);
    v8 = v9;
    if ( !v9 )
      return -1073741670;
    *(_DWORD *)(v9 + 76) = 1;
    *(_DWORD *)(v9 + 8) = v5;
    RtlInitializeGenericTableAvl(
      v9 + 12,
      (unsigned int)PiPnpRtlObjectEventCompareObjects,
      (unsigned int)PiPnpRtlOperationAllocateGenericTableEntry,
      (int)PiPnpRtlOperationFreeGenericTableEntry,
      0);
    *(_DWORD *)(v8 + 68) = v8 + 68;
    *(_DWORD *)(v8 + 72) = v8 + 68;
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(__int16 *)(v10 + 0x134) - 1;
    *(_WORD *)(v10 + 308) = v11;
    v12 = ExAcquireResourceExclusiveLite((int)&PiPnpRtlActiveOperationsLock, 1, v10, v11);
    v13 = &PiPnpRtlActiveOperations;
    v14 = PiPnpRtlActiveOperations;
    *(_QWORD *)v8 = *(_QWORD *)&v14;
    if ( *(int **)(v14 + 4) != &PiPnpRtlActiveOperations )
      sub_7C6758(v12);
    *(_DWORD *)(v14 + 4) = v8;
    PiPnpRtlActiveOperations = v8;
    v15 = ExReleaseResourceLite((int)&PiPnpRtlActiveOperationsLock);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
  }
  *a1 = v8;
  return v7;
}
