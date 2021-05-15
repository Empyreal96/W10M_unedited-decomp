// sub_509D7C 
 
void __fastcall sub_509D7C(int a1, int a2, int a3)
{
  unsigned int v3; // r2
  int v4; // r0

  v3 = (a3 & 0xFFFFF000) << 10;
  v4 = 4;
  do
  {
    __mcr(15, 0, v3, 8, 3, 3);
    v3 += 0x100000;
    --v4;
  }
  while ( v4 );
  JUMPOUT(0x42E2EA);
}
