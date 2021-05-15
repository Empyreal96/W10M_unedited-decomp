// VfRemLockDeleteMemoryRange 
 
int __fastcall VfRemLockDeleteMemoryRange(int result, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r3
  _DWORD *v7; // r4
  unsigned int v8; // r5
  int v9; // r2
  int v10; // r4
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = result;
  v6 = ViRemLockInitialized;
  __dmb(0xBu);
  if ( v6 )
  {
    result = VfAvlHasAnyNodes(ViRemLockAvl);
    if ( result )
    {
      v7 = &VfPoolDelayFreeData;
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = 0;
      while ( v8 != v7[6] )
      {
        ++v9;
        v7 += 12;
        if ( v9 >= 2 )
        {
          VfAvlInitializeLockContext((int)v11, 1);
          v10 = VfAvlLookupTreeNode(ViRemLockAvl, (int)v11, v5, a2);
          result = VfAvlCleanupLockContext((int)v11);
          if ( v10 )
          {
            do
              result = ViRemLockDeleteFirstTreeNode(v5, a2);
            while ( result );
          }
          return result;
        }
      }
    }
  }
  return result;
}
