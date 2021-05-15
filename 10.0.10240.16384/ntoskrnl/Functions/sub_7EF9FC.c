// sub_7EF9FC 
 
void sub_7EF9FC()
{
  int v0; // r4
  _DWORD *v1; // r5
  int v2; // lr
  int v3; // r1

  v3 = v1[15];
  if ( v3 && v1[18] )
  {
    *(_DWORD *)(v0 + 4) = v3;
    *(_WORD *)(v3 + 10) = v2;
    *(_DWORD *)(*(_DWORD *)(v0 + 4) + 8) |= v1[19] << 16;
    v1[19] = v2;
    JUMPOUT(0x784140);
  }
  JUMPOUT(0x78413C);
}
