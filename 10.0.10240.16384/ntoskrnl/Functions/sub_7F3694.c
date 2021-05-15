// sub_7F3694 
 
void __fastcall sub_7F3694(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, unsigned int a11)
{
  if ( (((a11 >> 1) + 4095) & 0xFFFFF000) >= 0x10000 )
    JUMPOUT(0x70D61C);
  JUMPOUT(0x70D644);
}
