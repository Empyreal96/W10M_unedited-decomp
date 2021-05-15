// CmpMarkKcbDeletedAndCache 
 
int __fastcall CmpMarkKcbDeletedAndCache(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0

  v2 = a1[1];
  v3 = a1[5];
  a1[1] = v2 | 0x20000;
  CmpRemoveKeyHash(v3, a1 + 3);
  CmpLockDeletedHashEntryExclusiveByKcb(a1);
  CmpInsertKeyHashToDeletedKcbTable(a1[5], a1 + 3);
  return CmpUnlockDeletedHashEntryByKcb(a1);
}
