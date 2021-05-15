// sub_549CD8 
 
void __fastcall sub_549CD8(int a1, int a2)
{
  int v2; // r4

  v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  if ( v2
    && (*(_DWORD *)(v2 + 4) & 0x20) == 0
    && ((*(_DWORD *)(*(_DWORD *)(v2 + 8296) + 4 * ((unsigned int)(a1 - *(_DWORD *)(a2 + 3612)) >> 27)) >> (((unsigned int)(a1 - *(_DWORD *)(a2 + 3612)) >> 22) & 0x1F)) & 1) != 0 )
  {
    JUMPOUT(0x4CA770);
  }
  JUMPOUT(0x4CA76E);
}
