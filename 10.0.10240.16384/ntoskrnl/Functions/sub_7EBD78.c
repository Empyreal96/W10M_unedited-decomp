// sub_7EBD78 
 
void __fastcall sub_7EBD78(int a1)
{
  int v1; // r4

  if ( PspCheckJobAccessState(a1, v1) < 0 )
    JUMPOUT(0x7662CC);
  JUMPOUT(0x7662B0);
}
