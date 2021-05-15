// CmpUnlockHashEntryByIndex 
 
int __fastcall CmpUnlockHashEntryByIndex(int a1, int a2)
{
  int v2; // r2

  v2 = *(_DWORD *)(a1 + 1844);
  __pld((void *)(v2 + 12 * a2));
  *(_DWORD *)(v2 + 12 * a2 + 4) = 0;
  if ( (*(_DWORD *)(v2 + 12 * a2) & 0xFFFFFFF0) <= 0x10 )
    JUMPOUT(0x7FC4F2);
  return sub_7FC4EC();
}
