// sub_7D1614 
 
void __fastcall sub_7D1614(int a1)
{
  unsigned int v1; // r1
  __int16 v2; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_WORD *)(v1 + 0x134) + 1;
  *(_WORD *)(v1 + 308) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x6D07EC);
}
