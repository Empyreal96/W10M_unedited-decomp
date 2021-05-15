// MmPrefetchForCacheManager 
 
int __fastcall MmPrefetchForCacheManager(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  unsigned int v9; // r6
  int v10; // r7
  int result; // r0
  int v12; // r0
  __int16 v13; // r3
  _DWORD *v14; // [sp+18h] [bp-20h]

  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = **(_DWORD **)(a1 + 20);
  if ( (*(_DWORD *)(v10 + 28) & 0x40000000) != 0 )
    return 0;
  if ( dword_634484 )
    return sub_806674();
  if ( MiPfPrepareSequentialReadList(0, v10, a3, a4) < 0 || !v14 )
    return 0;
  v14[11] = 1;
  if ( !*a9 )
    --*(_WORD *)(v9 + 310);
  v12 = MiPfPutPagesInTransition(v14, 0);
  if ( v12 < 0 || (_DWORD *)v14[14] == v14 + 14 )
  {
    if ( !*a9 )
    {
      v13 = *(_WORD *)(v9 + 310) + 1;
      *(_WORD *)(v9 + 310) = v13;
      if ( !v13 && *(_DWORD *)(v9 + 100) != v9 + 100 )
        KiCheckForKernelApcDelivery(v12);
    }
    MiReleaseReadListResources();
    ExFreePoolWithTag((unsigned int)v14);
    return 0;
  }
  MiPfExecuteReadList(v14, 1);
  result = 1;
  *v14 = *a9;
  *a9 = v14;
  return result;
}
