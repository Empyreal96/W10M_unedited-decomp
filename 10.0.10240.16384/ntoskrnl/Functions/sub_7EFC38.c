// sub_7EFC38 
 
void __fastcall sub_7EFC38(int a1, int a2, int a3, int a4)
{
  bool v4; // zf

  if ( a4 == 25 )
  {
    v4 = a3 == 18;
  }
  else
  {
    if ( !a4 )
      goto LABEL_7;
    v4 = a4 == 1;
  }
  if ( !v4 )
    JUMPOUT(0x784BAA);
LABEL_7:
  JUMPOUT(0x784B1C);
}
