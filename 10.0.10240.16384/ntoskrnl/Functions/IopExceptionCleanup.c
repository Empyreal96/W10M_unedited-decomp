// IopExceptionCleanup 
 
int __fastcall IopExceptionCleanup(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v6; // r0
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v6 = *(_DWORD *)(a2 + 12);
  if ( v6 )
    ExFreePoolWithTag(v6);
  v9 = *(_DWORD *)(a2 + 4);
  if ( v9 )
    IoFreeMdl(v9);
  IoFreeIrp(a2);
  if ( (*(_DWORD *)(a1 + 44) & 2) != 0 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(a1 + 68);
    do
      v11 = __ldrex(v10);
    while ( __strex(0, v10) );
    __dmb(0xBu);
    if ( *(_DWORD *)(a1 + 64) )
      KeSetEvent(a1 + 76, 0, 0);
    v12 = ObfDereferenceObject(a1);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
  }
  if ( a3 )
    ObfDereferenceObject(a3);
  if ( a4 )
    ExFreePoolWithTag(a4);
  return ObfDereferenceObject(a1);
}
