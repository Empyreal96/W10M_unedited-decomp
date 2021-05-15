// sub_525FC0 
 
void __fastcall sub_525FC0(int a1, int a2)
{
  int v2; // r4

  if ( MiCheckSecuredVad(v2, a2 << 12, (a1 + 1) << 12, 85) < 0 )
    JUMPOUT(0x460B78);
  JUMPOUT(0x460B6C);
}
