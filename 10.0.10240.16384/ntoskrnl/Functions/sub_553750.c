// sub_553750 
 
void __fastcall sub_553750(int a1, int a2, int a3, char a4)
{
  if ( (a4 & 0xE) == 0 )
  {
    if ( *(_DWORD *)(a3 + 24) )
      JUMPOUT(0x4F3F5C);
  }
  JUMPOUT(0x4F3F62);
}
