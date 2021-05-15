// sub_7F78E8 
 
void sub_7F78E8()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v4; // r8

  memset((_BYTE *)v0, 0, 4 * v1);
  *(_DWORD *)v0 = 0;
  *(_DWORD *)(v0 + 4) = v3;
  *(_DWORD *)(v0 + 28) = v4;
  *(_DWORD *)(v0 + 32) = v2;
  if ( !v3 )
    JUMPOUT(0x71C784);
  JUMPOUT(0x71C764);
}
