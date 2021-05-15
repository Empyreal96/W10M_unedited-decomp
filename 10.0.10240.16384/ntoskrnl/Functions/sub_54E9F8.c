// sub_54E9F8 
 
void sub_54E9F8()
{
  int v0; // r4
  int v1; // r7
  _DWORD *v2; // r1
  unsigned int v3; // r2

  v2 = *(_DWORD **)(v0 + 792);
  v3 = 8 * (*v2 + 1);
  if ( v3 > 0x2BC )
    v3 = 700;
  memmove(v1 + 100, (int)v2, v3);
  JUMPOUT(0x4E75D6);
}
