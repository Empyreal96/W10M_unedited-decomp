// MiSetInPagePriority 
 
int __fastcall MiSetInPagePriority(int result, unsigned int a2, unsigned int a3)
{
  char v3; // r3

  if ( a3 >= 5 || a2 <= a3 )
    v3 = *(_BYTE *)(result + 115) & 0xFB;
  else
    v3 = *(_BYTE *)(result + 115) | 4;
  *(_BYTE *)(result + 115) = v3;
  *(_BYTE *)(result + 114) = (*(_BYTE *)(result + 114) & 0xF8 | a3 & 7) & 0x8F | (16 * (a3 & 7));
  return result;
}
