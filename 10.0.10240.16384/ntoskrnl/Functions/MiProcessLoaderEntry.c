// MiProcessLoaderEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiProcessLoaderEntry(int *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r6
  int v7; // r3
  int v8; // r0
  int **v9; // r1
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int result; // r0
  __int16 v14; // r3
  int *v15; // r1 OVERLAPPED
  int **v16; // r2 OVERLAPPED
  int v17; // r0
  _DWORD v18[4]; // [sp+0h] [bp-10h] BYREF

  v18[0] = a4;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, a3, v7);
  if ( a2 == 1 )
  {
    v8 = MmLockLoadedModuleListExclusive(v18);
    v9 = (int **)dword_62127C;
    *a1 = (int)&PsLoadedModuleList;
    a1[1] = (int)v9;
    if ( *v9 != &PsLoadedModuleList )
      sub_51565C(v8);
    v10 = LOBYTE(v18[0]);
    *v9 = a1;
    dword_62127C = (int)a1;
    MmUnlockLoadedModuleListExclusive(v10);
    RtlInsertInvertedFunctionTable(a1[6], a1[8], v11, v12);
  }
  else
  {
    RtlRemoveInvertedFunctionTable(a1[6]);
    MmLockLoadedModuleListExclusive(v18);
    *(_QWORD *)&v15 = *(_QWORD *)a1;
    if ( *(int **)(*a1 + 4) != a1 || *v16 != a1 )
      __fastfail(3u);
    v17 = LOBYTE(v18[0]);
    *v16 = v15;
    v15[1] = (int)v16;
    MmUnlockLoadedModuleListExclusive(v17);
  }
  result = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v14 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
