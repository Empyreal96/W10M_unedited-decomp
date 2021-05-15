// ViTargetFreeContiguousMemory 
 
int __fastcall ViTargetFreeContiguousMemory(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v7; // r0
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  result = ViTargetUpdateTreeAllowed(a1, a2);
  if ( result )
  {
    VfAvlInitializeLockContext((int)v8, 0);
    v7 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v8, a1, 1);
    if ( !v7 || (v7 = ViTargetFreeContiguousMemoryFromNode(a2, v7)) == 0 )
      VfAvlEnumerateNodes(v7, v8);
    result = VfAvlCleanupLockContext((int)v8);
  }
  return result;
}
