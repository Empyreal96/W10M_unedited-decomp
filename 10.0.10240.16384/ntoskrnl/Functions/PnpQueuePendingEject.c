// PnpQueuePendingEject 
 
int __fastcall PnpQueuePendingEject(int *a1, int a2)
{
  int **v3; // r1

  PpDevNodeLockTree(1, a2);
  v3 = (int **)dword_63073C;
  *a1 = (int)&IopPendingEjects;
  a1[1] = (int)v3;
  if ( *v3 != &IopPendingEjects )
    __fastfail(3u);
  *v3 = a1;
  dword_63073C = (int)a1;
  PpDevNodeUnlockTree(1);
  return 1;
}
