// IopAllocateIrpCleanup 
 
int __fastcall IopAllocateIrpCleanup(int a1, int a2)
{
  unsigned int *v3; // r2
  unsigned int v4; // r1
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  if ( a2 )
    ObfDereferenceObject(a2);
  if ( (*(_DWORD *)(a1 + 44) & 2) != 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned int *)(a1 + 68);
    do
      v4 = __ldrex(v3);
    while ( __strex(0, v3) );
    __dmb(0xBu);
    if ( *(_DWORD *)(a1 + 64) )
      KeSetEvent(a1 + 76, 0, 0);
    v5 = ObfDereferenceObject(a1);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(_WORD *)(v6 + 0x134) + 1;
    *(_WORD *)(v6 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v5);
  }
  return ObfDereferenceObject(a1);
}
