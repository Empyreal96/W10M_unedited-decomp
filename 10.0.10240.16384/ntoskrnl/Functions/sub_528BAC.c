// sub_528BAC 
 
void __fastcall sub_528BAC(int a1, int *a2)
{
  int v2; // r4
  int v3; // r5
  unsigned int v4; // r6
  int v5; // t1

  while ( (unsigned int)a2 <= v4 )
  {
    v5 = *a2++;
    if ( (*(_DWORD *)(a1 + 24 * v5 + 4) | 0x80000000) == v2 )
      JUMPOUT(0x4DEA86);
  }
  *(_BYTE *)(v3 + 112) |= 1u;
  JUMPOUT(0x4DEAC6);
}
