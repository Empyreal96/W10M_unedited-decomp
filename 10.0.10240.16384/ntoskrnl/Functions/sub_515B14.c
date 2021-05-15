// sub_515B14 
 
void sub_515B14()
{
  char v0; // r4
  int v1; // r5
  int v2; // r7
  int v3; // r8
  int v4; // r9
  int v5; // r0
  char v6; // r2

  v5 = *(_DWORD *)(v2 + 4) + v1;
  v6 = *(_BYTE *)(v5 + v4) & ~((1 << v0) - 1);
  *(_BYTE *)(v5 + v4) = v6;
  *(_BYTE *)(v5 + v4) = *(_BYTE *)(*(_DWORD *)(v3 + 4) + v1) & ((1 << v0) - 1) | v6;
  JUMPOUT(0x4348B2);
}
