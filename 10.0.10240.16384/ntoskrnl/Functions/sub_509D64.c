// sub_509D64 
 
void __fastcall sub_509D64(int a1)
{
  if ( (a1 & 0xFFFFFFF8) == 24 && (a1 & 7) != 0 )
    JUMPOUT(0x42C5DA);
  JUMPOUT(0x42C5CC);
}
