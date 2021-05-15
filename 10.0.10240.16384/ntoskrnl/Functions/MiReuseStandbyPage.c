// MiReuseStandbyPage 
 
int __fastcall MiReuseStandbyPage(int a1)
{
  int result; // r0

  MiUnlinkPageFromList(a1, 0);
  result = MiRestoreTransitionPte(a1, 0);
  *(_DWORD *)(a1 + 8) = 128;
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xF8 | 5;
  return result;
}
