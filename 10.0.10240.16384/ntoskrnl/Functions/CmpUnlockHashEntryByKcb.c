// CmpUnlockHashEntryByKcb 
 
int __fastcall CmpUnlockHashEntryByKcb(int a1)
{
  unsigned int v1; // r3
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r2
  int v6; // r0

  v1 = 101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9));
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1844)
            + 12 * ((v1 ^ (v1 >> 9)) & (*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1848) - 1))
            + 4) = 0;
  v2 = *(_DWORD *)(a1 + 20);
  v3 = 101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9));
  v4 = v3 ^ (v3 >> 9);
  v5 = *(_DWORD *)(v2 + 1844);
  v6 = v4 & (*(_DWORD *)(v2 + 1848) - 1);
  __pld((void *)(v5 + 12 * v6));
  if ( (*(_DWORD *)(v5 + 12 * v6) & 0xFFFFFFF0) <= 0x10 )
    JUMPOUT(0x7FDD0E);
  return sub_7FDD08();
}
