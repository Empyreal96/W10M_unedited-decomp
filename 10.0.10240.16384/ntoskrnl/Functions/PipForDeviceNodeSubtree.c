// PipForDeviceNodeSubtree 
 
int __fastcall PipForDeviceNodeSubtree(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v8 = a4;
  v7 = a3;
  PpDevNodeLockTree(0, a2);
  v5 = PipForAllChildDeviceNodes(a1);
  PpDevNodeUnlockTree(0);
  return v5;
}
