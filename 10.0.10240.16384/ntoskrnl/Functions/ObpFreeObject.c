// ObpFreeObject 
 
int __fastcall ObpFreeObject(int a1)
{
  if ( (*(_BYTE *)(a1 + 14) & 1) == 0 )
    JUMPOUT(0x7FB0BE);
  return sub_7FB0B8();
}
