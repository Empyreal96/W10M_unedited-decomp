// sub_7E9974 
 
void sub_7E9974()
{
  int v0; // r5
  int v1; // r6
  int v2; // r2
  int v3; // r3
  int v4; // r2

  if ( !v1 || (v2 = *(_DWORD *)(v1 + 356)) == 0 || (v3 = *(_DWORD *)(v0 + 192), v4 = v2 & v3, v3 == v4) && v4 )
    JUMPOUT(0x7034A0);
  JUMPOUT(0x703498);
}
