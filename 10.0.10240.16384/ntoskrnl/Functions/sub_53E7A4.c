// sub_53E7A4 
 
void __fastcall sub_53E7A4(int a1, int a2, int a3)
{
  if ( (a3 & 2) == 0 && ((a3 & 0x400) == 0 || (a3 & 0xFFFFE000) == -8192) )
    JUMPOUT(0x4A6D5E);
  JUMPOUT(0x4A6D5C);
}
