// MiComputeImagePteIndex 
 
int __fastcall MiComputeImagePteIndex(int a1)
{
  _WORD *v1; // r5

  v1 = (_WORD *)(*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC)));
  if ( (v1[9] & 2) != 0 )
    return sub_521858();
  if ( *(_DWORD *)((*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC))) + 0xC) )
    JUMPOUT(0x521870);
  return (int)((*(_DWORD *)(a1 + 4) | 0x80000000) - *(_DWORD *)(*(_DWORD *)v1 + 84)) >> 2;
}
