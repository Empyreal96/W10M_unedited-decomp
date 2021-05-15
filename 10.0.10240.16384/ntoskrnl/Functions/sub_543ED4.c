// sub_543ED4 
 
void __fastcall sub_543ED4(unsigned int a1)
{
  int v1; // r4

  if ( a1 >= 0xC0000000 && ((*(unsigned __int8 *)(v1 + 19) >> 5) & 1) != 0 )
    JUMPOUT(0x4B9692);
  JUMPOUT(0x4B9614);
}
