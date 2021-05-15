// sub_7DD410 
 
void sub_7DD410()
{
  unsigned int v0; // r7
  int v1; // r8
  int v2; // r9

  if ( **(_WORD **)(v1 + 4) == 92 )
  {
    if ( v0 <= 1 )
      JUMPOUT(0x6E9E12);
    if ( **(_WORD **)(v2 + 4) == 92 )
      JUMPOUT(0x6E9ED0);
  }
  JUMPOUT(0x6E9E0E);
}
