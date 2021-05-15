// sub_69417C 
 
void __fastcall sub_69417C(int a1, int a2, unsigned int a3)
{
  int v3; // r5
  _BYTE *v4; // r7
  _BYTE *v5; // r8

  if ( (unsigned __int16)a3 >> 4 == 45 )
    *v4 = 1;
  if ( ((a3 >> 4) & 0xFC0) == 64 && (a3 & v3) == 0 )
  {
    *v4 = 1;
    *v5 = 1;
  }
  JUMPOUT(0x6924D8);
}
