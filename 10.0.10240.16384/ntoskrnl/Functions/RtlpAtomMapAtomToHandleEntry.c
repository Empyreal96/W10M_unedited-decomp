// RtlpAtomMapAtomToHandleEntry 
 
int __fastcall RtlpAtomMapAtomToHandleEntry(int a1, __int16 a2)
{
  unsigned int v3; // r2
  unsigned int *v4; // r0
  int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r1
  unsigned int v9; // r1
  __int16 v10; // r3
  unsigned int v11; // r1
  __int16 v12; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = ExMapHandleToPointer(*(_DWORD *)(a1 + 12), 4 * a2);
  if ( v4 )
  {
    v5 = *(_DWORD *)(a1 + 12);
    v6 = *v4 & 0xFFFFFFF8;
    __dmb(0xBu);
    do
      v7 = __ldrex(v4);
    while ( __strex(v7 + 1, v4) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(v5 + 32) )
      return sub_81759C();
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery((int)v4);
  }
  else
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(0);
    v6 = 0;
  }
  return v6;
}
