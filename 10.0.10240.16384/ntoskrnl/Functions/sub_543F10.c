// sub_543F10 
 
void __fastcall sub_543F10(int a1, int a2)
{
  int v2; // r6

  if ( ((*(unsigned __int16 *)(v2 + 16) >> 1) & 2) == 0 && MiCanPageMove(a2) )
    JUMPOUT(0x4B9734);
  JUMPOUT(0x4B972E);
}
