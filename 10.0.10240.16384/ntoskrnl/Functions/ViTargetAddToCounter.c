// ViTargetAddToCounter 
 
int __fastcall ViTargetAddToCounter(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v9; // r0
  int v10; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // r0
  unsigned int *v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r1
  _DWORD v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  result = ViTargetUpdateTreeAllowed(a1, a2);
  if ( result )
  {
    VfAvlInitializeLockContext((int)v17, 1);
    v9 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v17, a1, 1);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 24);
      if ( v10 )
      {
        __dmb(0xBu);
        v11 = (unsigned int *)(v10 + a2);
        do
          v12 = __ldrex(v11);
        while ( __strex(v12 + a4, v11) );
        __dmb(0xBu);
        v13 = v12 + a4;
        v14 = (unsigned int *)(v10 + a3);
        do
        {
          v16 = *v14;
          __dmb(0xBu);
          if ( v16 > v13 )
            break;
          __dmb(0xBu);
          do
            v15 = __ldrex(v14);
          while ( v15 == v16 && __strex(v13, v14) );
          __dmb(0xBu);
        }
        while ( v15 != v16 );
      }
    }
    result = VfAvlCleanupLockContext((int)v17);
  }
  return result;
}
