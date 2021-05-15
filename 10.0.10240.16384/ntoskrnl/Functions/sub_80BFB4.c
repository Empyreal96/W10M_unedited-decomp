// sub_80BFB4 
 
void __fastcall sub_80BFB4(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // r4
  int v6; // r5
  unsigned int v7; // r6

  if ( LdrpGetImageSize(v6, &a5) != -1073741701 )
  {
    if ( a5 && (v5 < v7 || v5 >= a5 + v7) )
      JUMPOUT(0x79163A);
    JUMPOUT(0x79164E);
  }
  JUMPOUT(0x79165A);
}
