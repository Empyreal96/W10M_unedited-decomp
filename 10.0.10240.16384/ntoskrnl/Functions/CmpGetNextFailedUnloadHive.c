// CmpGetNextFailedUnloadHive 
 
int __fastcall CmpGetNextFailedUnloadHive(int a1)
{
  int v1; // r4
  int *v2; // r5

  v1 = 0;
  if ( a1 )
    v2 = (int *)(a1 + 1824);
  else
    v2 = &CmpFailedUnloadListHead;
  CmpLockHiveListShared();
  if ( (int *)*v2 != &CmpFailedUnloadListHead )
    v1 = *v2 - 1824;
  CmpUnlockHiveList();
  return v1;
}
