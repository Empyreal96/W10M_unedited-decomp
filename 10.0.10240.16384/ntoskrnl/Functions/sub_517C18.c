// sub_517C18 
 
void __fastcall sub_517C18(int a1, int a2, int a3, unsigned int a4)
{
  if ( (a4 < 9 || a4 > 0xA) && (a4 < 0xD || a4 > 0xE) && a4 != 17 && a4 != 20 && a4 != 18 && a4 != 19 )
  {
    if ( a4 != 4 && (a4 < 5 || a4 > 8) && (a4 < 0xB || a4 > 0xC) && (a4 < 0xF || a4 > 0x10) )
      JUMPOUT(0x439EEE);
    JUMPOUT(0x439EE0);
  }
  JUMPOUT(0x439EDC);
}
