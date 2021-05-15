// CmpUpgradeKcbLockToExclusive 
 
int __fastcall CmpUpgradeKcbLockToExclusive(int a1)
{
  CmpUnlockKcb(a1);
  return CmpLockKcbExclusive(a1);
}
