// VfDevObjWMIRegistrationControl 
 
void __fastcall VfDevObjWMIRegistrationControl(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r0
  _DWORD v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[1] = a3;
  v11[2] = a4;
  if ( (MmVerifierData & 0x10) != 0 && a2 >= 0 )
  {
    VfAvlInitializeLockContext((int)v11, 1);
    v6 = VfAvlLookupTreeNode(ViDevObjAvl, (int)v11, v5, 0);
    if ( v6 )
    {
      switch ( a2 )
      {
        case 1:
          goto LABEL_7;
        case 2:
          __dmb(0xBu);
          v9 = (unsigned int *)(v6 + 8);
          do
            v10 = __ldrex(v9);
          while ( __strex(v10 & 0xFFFFFFFE, v9) );
          goto LABEL_9;
        case 3:
LABEL_7:
          __dmb(0xBu);
          v7 = (unsigned int *)(v6 + 8);
          do
            v8 = __ldrex(v7);
          while ( __strex(v8 | 1, v7) );
LABEL_9:
          __dmb(0xBu);
          break;
      }
    }
    VfAvlCleanupLockContext((int)v11);
  }
}
