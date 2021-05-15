// sub_540AA4 
 
void __fastcall sub_540AA4(int a1)
{
  unsigned int v1; // r1
  int v2; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = (__int16)(*(_WORD *)(v1 + 0x136) + 1);
  *(_WORD *)(v1 + 310) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(a1);
  JUMPOUT(0x4AD6EE);
}
