// sub_50F8A0 
 
void sub_50F8A0()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int v3; // r8

  if ( byte_61EA54 || v1 )
  {
    *(_DWORD *)(v0 + 36) = v3;
    if ( !v1 && (*(_DWORD *)(v0 + 16) & 8) == 0 )
      --*(_DWORD *)(v2 + 24);
  }
  JUMPOUT(0x425B9C);
}
