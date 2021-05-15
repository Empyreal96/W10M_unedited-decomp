// sub_7F3358 
 
void __fastcall sub_7F3358(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  unsigned int v8; // r1
  int v9; // r3

  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(a1);
  __asm { POP.W           {R4,R5,R11,PC} }
}
