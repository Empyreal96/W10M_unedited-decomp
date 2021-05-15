// sub_80D890 
 
void __fastcall sub_80D890(int a1, int a2, int a3, int a4)
{
  if ( a4 != 2 && a4 != 4 && a4 != 6 )
  {
    if ( a4 == 3 )
      JUMPOUT(0x794D8C);
    JUMPOUT(0x794DB0);
  }
  JUMPOUT(0x794DA6);
}
