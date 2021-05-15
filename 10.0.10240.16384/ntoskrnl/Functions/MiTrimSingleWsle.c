// MiTrimSingleWsle 
 
int __fastcall MiTrimSingleWsle(int a1, unsigned int a2)
{
  _DWORD *v3; // r7
  _DWORD *v5; // r0
  int v6; // r4
  int v7; // r3

  v3 = *(_DWORD **)(a1 + 92);
  v5 = (_DWORD *)(((*(_DWORD *)(v3[9] * a2 + v3[63]) >> 10) & 0x3FFFFC) - 0x40000000);
  v6 = MmPfnDatabase + 24 * (*v5 >> 12);
  v7 = *(_DWORD *)(v6 + 4);
  if ( v7 >= 0 )
    MiDemoteCombinedPte((unsigned int)v5, v7 | 0x80000000);
  if ( (*(_DWORD *)(v6 + 12) & 0x3FFFFFFFu) > 1 && (*(_DWORD *)(v6 + 20) & 0x8000000) == 0
    || (*(_BYTE *)(a1 + 112) & 7) != 0 && *(unsigned __int16 *)(v6 + 16) > 1u
    || !MiRemoveSingleWsle(a1, a2) )
  {
    return 0;
  }
  v3[3] = a2 + 1;
  return 1;
}
