// ExSaAllocate 
 
int __fastcall ExSaAllocate(int a1, int a2)
{
  int *v2; // r3
  int v3; // r0
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r1
  __int16 v8; // r3

  if ( (a2 & 0xFFFFFFFE) != 0 )
    KeBugCheckEx(365, a2, 0, 0, 0);
  if ( (a2 & 1) != 0 )
    v2 = &ExSaPagedSlotAllocator;
  else
    v2 = &ExSaNonPagedSlotAllocator;
  v3 = *v2;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 310);
  v5 = ExpSaAllocatorAllocate(v3, 2);
  v6 = v5;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_WORD *)(v7 + 0x136) + 1;
  *(_WORD *)(v7 + 310) = v8;
  if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v5);
  return v6;
}
