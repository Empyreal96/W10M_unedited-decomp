// MiPrefetchControlArea 
 
int __fastcall MiPrefetchControlArea(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r7
  __int16 v10; // r3
  int v12; // r0
  __int16 v13; // r3
  _DWORD *v14; // [sp+18h] [bp-18h]

  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = MiPfPrepareSequentialReadList(0, a1, a3, a4);
  v9 = v8;
  if ( v8 >= 0 && v14 )
  {
    ++*(_BYTE *)(v7 + 974);
    v14[11] = 0;
    v9 = MiPfPutPagesInTransition(v14, 0);
    if ( v9 >= 0 && (_DWORD *)v14[14] != v14 + 14 )
    {
      MiPfExecuteReadList(v14, a7);
      MiPfCompletePrefetchIos(v14 + 14, 0);
    }
    v12 = MiReleaseReadListResources();
    v13 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v12);
    --*(_BYTE *)(v7 + 974);
    ExFreePoolWithTag((unsigned int)v14);
  }
  else
  {
    v10 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v8);
  }
  return v9;
}
