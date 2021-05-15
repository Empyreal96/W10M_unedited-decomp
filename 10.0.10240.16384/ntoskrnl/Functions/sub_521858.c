// sub_521858 
 
void __fastcall sub_521858(int a1, int a2)
{
  int v2; // r4
  int v3; // r5

  if ( (*(_DWORD *)(v2 + 28) & 0x4000000) != 0 )
  {
    __mrc(15, 0, 13, 0, 3);
    if ( MiGetSharedProtos(v2, a2, v3) )
      JUMPOUT(0x4559C0);
    JUMPOUT(0x4559BC);
  }
  JUMPOUT(0x4559B4);
}
