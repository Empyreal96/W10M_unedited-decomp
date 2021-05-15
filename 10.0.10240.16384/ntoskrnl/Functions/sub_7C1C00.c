// sub_7C1C00 
 
void __fastcall sub_7C1C00(int a1)
{
  int v1; // r5
  unsigned int *v2; // r2
  unsigned int v3; // r4

  if ( PspCheckJobAccessState(a1, v1) < 0 )
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(v1 + 188);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 | 2, v2) );
    __dmb(0xBu);
    JUMPOUT(0x6AA606);
  }
  JUMPOUT(0x6AA5E0);
}
