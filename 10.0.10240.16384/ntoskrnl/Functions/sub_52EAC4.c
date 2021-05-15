// sub_52EAC4 
 
void sub_52EAC4()
{
  int v0; // r7
  _DWORD *v1; // r10
  int v2; // lr
  unsigned int v3; // r2

  v3 = *(_DWORD *)(v0 + 2344);
  *(_DWORD *)(v0 + 2340) = v2;
  if ( v3 < 0x5F5E100 )
    *(_DWORD *)(v0 + 2344) = *v1 + v3;
  JUMPOUT(0x47E1FE);
}
