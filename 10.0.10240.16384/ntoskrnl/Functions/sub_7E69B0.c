// sub_7E69B0 
 
void sub_7E69B0()
{
  int v0; // r4
  int v1; // r5
  unsigned int v2; // r6
  char v3; // r7
  int v4; // r8
  unsigned int v5; // r3

  if ( v0 == v4 || (v3 & 2) != 0 )
  {
    if ( (v3 & 2) != 0 )
      v5 = v1 << 16;
    else
      v5 = 0x10000;
    if ( v5 >= v2 )
      JUMPOUT(0x6F2BD2);
  }
  JUMPOUT(0x6F2BBE);
}
