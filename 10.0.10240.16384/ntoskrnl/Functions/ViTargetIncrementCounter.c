// ViTargetIncrementCounter 
 
int __fastcall ViTargetIncrementCounter(unsigned int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v7; // r0
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1
  _DWORD v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  result = ViTargetUpdateTreeAllowed(a1, a2);
  if ( result && (!ViDriverKernelBase || a1 < ViDriverKernelBase || a1 >= ViDriverKernelEnd) )
  {
    VfAvlInitializeLockContext((int)v11, 1);
    v7 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v11, a1, 1);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 24);
      if ( v8 )
      {
        __dmb(0xBu);
        v9 = (unsigned int *)(v8 + a2);
        do
          v10 = __ldrex(v9);
        while ( __strex(v10 + 1, v9) );
        __dmb(0xBu);
      }
    }
    result = VfAvlCleanupLockContext((int)v11);
  }
  return result;
}
