// sub_5311C8 
 
void sub_5311C8()
{
  int v0; // r4
  int v1; // r10
  int v2; // r2

  v2 = *(_DWORD *)(v0 + 8);
  if ( (v2 & v1) != 0 )
    *(_DWORD *)(v0 + 8) = v2 & ~v1;
  JUMPOUT(0x489030);
}
