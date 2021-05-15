// sub_96B214 
 
void __fastcall sub_96B214(__int16 a1)
{
  int v1; // r4
  int v2; // r3

  if ( !*(_WORD *)(v1 + 16) )
  {
    v2 = *(_DWORD *)(v1 + 20);
    *(_WORD *)(v1 + 16) = a1;
    *(_DWORD *)(v1 + 20) = v2 & 0xFFF00000;
    *(_DWORD *)(v1 + 4) = -1073741824;
    *(_DWORD *)(v1 + 12) = *(_DWORD *)(v1 + 12) & 0xC0000000 | 1;
    *(_BYTE *)(v1 + 18) = *(_BYTE *)(v1 + 18) & 0x38 | 0x45;
    *(_DWORD *)(v1 + 20) = *(_DWORD *)(v1 + 20) & 0xFFFFFFF | (MiPageToNode() << 28);
  }
  JUMPOUT(0x956702);
}
