// sub_7BF24C 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7BF24C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r1
  int i; // r2
  int v11; // r3
  unsigned int v12; // r1
  __int16 v13; // r3
  int j; // r4
  unsigned int v15; // r5
  int v16; // r6
  unsigned int v17; // r2
  int v18; // [sp-2Ch] [bp-2Ch] BYREF

  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v17 + 0x134);
  if ( *(_BYTE *)(v15 + 264) )
  {
    v9 = 0;
    a1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v16 <= 0 )
      goto LABEL_11;
    for ( i = 0; i < v16; i = (char)(i + 1) )
    {
      v11 = *(_DWORD *)(*(_DWORD *)(v15 + 4 * i + 316) + 92);
      __dmb(0xBu);
      if ( v11 == a1 )
        v9 = 1;
    }
    if ( !v9 )
LABEL_11:
      a1 = KeWaitForSingleObject(v15 + 268, 0, 0, 0, 0);
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(a1);
  if ( v16 > 0 )
  {
    for ( j = 0; j < v16; j = (char)(j + 1) )
      KeFreeInterrupt(*(_DWORD **)(v15 + 4 * j + 316));
  }
  IopDestroyActiveConnectBlock((int)&v18);
  ExFreePoolWithTag(v15);
  __asm { POP.W           {R4-R6,R11,PC} }
}
