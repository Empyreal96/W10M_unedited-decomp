// sub_51F008 
 
void __fastcall sub_51F008(int a1, int a2, unsigned int a3)
{
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & a2) != 0 && a3 >= 2 )
    JUMPOUT(0x44E7BC);
  JUMPOUT(0x44E82E);
}
