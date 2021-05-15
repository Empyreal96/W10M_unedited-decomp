// sub_7DD3E8 
 
void sub_7DD3E8()
{
  int v0; // r4
  int v1; // r5
  int v2; // r7

  if ( *(_DWORD *)(v2 + 8) == v1 )
  {
    *(_WORD *)v0 = 2051;
    *(_DWORD *)(v0 + 4) = 0;
    *(_DWORD *)(v0 + 8) = *(_DWORD *)(v1 + 8);
    *(_DWORD *)(v1 + 8) = v0;
    JUMPOUT(0x6E9CE8);
  }
  JUMPOUT(0x6E9D22);
}
