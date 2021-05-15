// sub_80E7F8 
 
void sub_80E7F8()
{
  int v0; // r5
  int v1; // r6
  _DWORD *v2; // r1
  int v3; // r2

  v2 = *(_DWORD **)(v1 + 4);
  v3 = v0 + 28;
  *(_DWORD *)(v0 + 28) = v1;
  *(_DWORD *)(v0 + 32) = v2;
  if ( *v2 == v1 )
  {
    *v2 = v3;
    *(_DWORD *)(v1 + 4) = v3;
    JUMPOUT(0x7979DA);
  }
  __fastfail(3u);
}
