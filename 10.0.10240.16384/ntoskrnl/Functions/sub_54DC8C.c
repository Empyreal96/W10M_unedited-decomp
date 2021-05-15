// sub_54DC8C 
 
void __fastcall sub_54DC8C(int a1, unsigned int a2)
{
  int v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r3

  if ( a2 <= v3 )
  {
    v4 = a2 + 40 * v2;
    if ( v4 >= a2 && v4 < v3 )
      JUMPOUT(0x4E3F7C);
  }
  JUMPOUT(0x4E3F96);
}
