// sub_50C79C 
 
void __fastcall sub_50C79C(int a1, int a2, char a3, int a4)
{
  int v4; // r6
  int v5; // r7

  if ( a4 == 5 )
  {
    *(_BYTE *)(v4 + 72) = a3 & 0xF8 | 6;
    JUMPOUT(0x47D620);
  }
  if ( a4 == 3 )
    *(_BYTE *)(v5 + 9) = 2;
  JUMPOUT(0x47D618);
}
