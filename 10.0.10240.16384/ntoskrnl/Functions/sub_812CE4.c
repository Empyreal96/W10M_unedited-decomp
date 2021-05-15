// sub_812CE4 
 
void __fastcall sub_812CE4(int a1, int a2, int a3, int a4)
{
  int v4; // r4

  if ( (a4 & a2) != 0 )
  {
    BiDeleteBootEntry(*(_DWORD *)(v4 + 24));
    JUMPOUT(0x7A4564);
  }
  if ( a3 )
    JUMPOUT(0x7A4550);
  JUMPOUT(0x7A4556);
}
