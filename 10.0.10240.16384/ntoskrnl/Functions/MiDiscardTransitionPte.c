// MiDiscardTransitionPte 
 
int __fastcall MiDiscardTransitionPte(int a1)
{
  unsigned int v2; // r4

  v2 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
  MiRestoreTransitionPte(a1, 0);
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(a1 + 18) &= 0xC7u;
  *(_BYTE *)(a1 + 19) &= 0xDFu;
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a1 + 12) & 0xFFF00000 | 0x40000000;
  return MiInsertPageInFreeOrZeroedList(v2 + (v2 >> 31), 2);
}
