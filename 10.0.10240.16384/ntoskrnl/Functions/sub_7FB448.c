// sub_7FB448 
 
void sub_7FB448()
{
  unsigned int v0; // r5
  unsigned int v1; // r6
  unsigned int v2; // r7
  int v3; // r8

  while ( v0 < (unsigned int)*(unsigned __int16 *)(v3 + 2) + v3 )
  {
    ++v2;
    v0 += *(unsigned __int16 *)(v0 + 2);
    if ( v2 >= v1 )
      JUMPOUT(0x72EC16);
  }
  JUMPOUT(0x72EF24);
}
