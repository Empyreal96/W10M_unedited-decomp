// sub_969F34 
 
void sub_969F34()
{
  int v0; // r6
  int v1; // r7
  int v2; // r3
  int v3; // r3

  v2 = *(_DWORD *)(v1 + 16);
  if ( v0 )
    v3 = v2 | 0x4000;
  else
    v3 = v2 | 0x2000;
  *(_DWORD *)(v1 + 16) = v3;
  JUMPOUT(0x9540CC);
}
