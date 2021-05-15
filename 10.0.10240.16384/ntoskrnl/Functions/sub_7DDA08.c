// sub_7DDA08 
 
void sub_7DDA08()
{
  int v0; // r4
  int v1; // r8

  if ( (*(_DWORD *)(v0 + 4) & ~v1) + (unsigned int)*(unsigned __int8 *)(v0 + 7) < v1 + 33554177 )
    JUMPOUT(0x6EB8A0);
  JUMPOUT(0x6EB8EC);
}
