// MiEndingOffset 
 
unsigned __int64 __fastcall MiEndingOffset(int a1)
{
  int v2; // r0
  unsigned int v3; // r2

  if ( (*(_DWORD *)(*(_DWORD *)a1 + 28) & 0x20) != 0 )
  {
    v3 = (((unsigned __int64)*(unsigned int *)(a1 + 20) << 9)
        + __PAIR64__(*(_DWORD *)(a1 + 24) >> 23, *(_DWORD *)(a1 + 24) << 9)) >> 32;
    v2 = (*(_DWORD *)(a1 + 20) << 9) + (*(_DWORD *)(a1 + 24) << 9);
  }
  else
  {
    v3 = (__PAIR64__(*(_DWORD *)(a1 + 24) >> 20, *(_DWORD *)(a1 + 24) << 12)
        + __PAIR64__(
            (*(_DWORD *)(a1 + 20) >> 20) | (*(unsigned __int16 *)(a1 + 16) >> 6 << 12),
            *(_DWORD *)(a1 + 20) << 12)) >> 32;
    v2 = (*(_DWORD *)(a1 + 24) << 12) + (*(_DWORD *)(a1 + 20) << 12);
  }
  return __PAIR64__(v3, v2) + (*(unsigned __int16 *)(a1 + 18) >> 4);
}
