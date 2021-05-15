// CmpUnlockDeletedHashEntryByKcb 
 
int __fastcall CmpUnlockDeletedHashEntryByKcb(int a1)
{
  unsigned int v1; // r3
  unsigned int v2; // r3
  _DWORD *v3; // r4

  v1 = 101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9));
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1852)
            + 12 * ((*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1856) - 1) & (v1 ^ (v1 >> 9)))
            + 4) = 0;
  v2 = 101027 * (*(_DWORD *)(a1 + 12) ^ (*(_DWORD *)(a1 + 12) >> 9));
  v3 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1852)
                + 12 * ((*(_DWORD *)(*(_DWORD *)(a1 + 20) + 1856) - 1) & (v2 ^ (v2 >> 9))));
  __pld(v3);
  if ( (*v3 & 0xFFFFFFF0) <= 0x10 )
    JUMPOUT(0x7D2556);
  return sub_7D2550();
}
