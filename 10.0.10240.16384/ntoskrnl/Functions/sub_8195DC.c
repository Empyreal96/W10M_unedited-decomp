// sub_8195DC 
 
void __fastcall sub_8195DC(int a1, int a2)
{
  int v2; // r4
  int v3; // r6
  int v4; // r8
  unsigned int v5; // lr
  unsigned int v6; // r5
  unsigned int v7; // r2

  while ( 1 )
  {
    v6 = *(_DWORD *)(v3 + 4 * a1);
    if ( (v6 & v4) != 0 )
      break;
    *(_DWORD *)(v3 + 4 * a1) = *(_DWORD *)v6;
    v7 = (((*(_DWORD *)(v6 + 4) & v5) >> 24)
        + 37
        * (37
         * (37 * ((*(_BYTE *)(v6 + 4) & (unsigned __int8)v5) - 53) + ((unsigned __int16)(*(_WORD *)(v6 + 4) & v5) >> 8))
         + (unsigned __int8)((*(_DWORD *)(v6 + 4) & v5) >> 16))) & 0x1F;
    *(_DWORD *)v6 = *(_DWORD *)(a2 + 4 * v7);
    *(_DWORD *)(a2 + 4 * v7) = v6;
  }
  if ( (unsigned int)(a1 + 1) < *(_DWORD *)(v2 + 4) >> 5 )
    JUMPOUT(0x7B5440);
  JUMPOUT(0x7B53FE);
}
