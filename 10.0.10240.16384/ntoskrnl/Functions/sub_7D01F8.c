// sub_7D01F8 
 
void sub_7D01F8()
{
  int v0; // r5
  _DWORD *v1; // r6
  int v2; // r3

  v2 = v1[1];
  if ( (v2 & v0) != 0 || (v2 & 0x10) != 0 )
    *v1 |= 0x200u;
  if ( (v1[1] & 0x402) == 0 )
    JUMPOUT(0x78A324);
  JUMPOUT(0x78A30C);
}
