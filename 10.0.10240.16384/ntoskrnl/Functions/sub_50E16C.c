// sub_50E16C 
 
void __fastcall sub_50E16C(int a1)
{
  char v1; // r3

  __dmb(0xFu);
  v1 = *(_BYTE *)(a1 + 968);
  __dmb(0xBu);
  if ( (v1 & 8) == 0 )
    JUMPOUT(0x4A8DC6);
  JUMPOUT(0x4A8DC4);
}
