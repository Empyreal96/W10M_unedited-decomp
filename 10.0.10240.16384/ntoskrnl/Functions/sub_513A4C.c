// sub_513A4C 
 
void __fastcall sub_513A4C(char a1, char a2, int a3)
{
  int v3; // r4

  if ( a3 == 2 )
  {
    if ( !*(_WORD *)(v3 + 16) )
      JUMPOUT(0x42F1A4);
  }
  else if ( a3 == 6
         && (a1 & 0x10) == 0
         && *(_WORD *)(v3 + 16) == 1
         && (*(_BYTE *)(v3 + 23) & 7) != 2
         && (a2 & 8) == 0
         && *(_DWORD *)v3 )
  {
    JUMPOUT(0x42F158);
  }
  JUMPOUT(0x42F1C2);
}
