// sub_7C525C 
 
void __fastcall sub_7C525C(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4

  if ( a4 > 4 )
  {
    if ( a4 > 8 || v4 >= 4 )
LABEL_7:
      JUMPOUT(0x6C202E);
  }
  else if ( v4 >= 3 )
  {
    goto LABEL_7;
  }
  JUMPOUT(0x6C208E);
}
