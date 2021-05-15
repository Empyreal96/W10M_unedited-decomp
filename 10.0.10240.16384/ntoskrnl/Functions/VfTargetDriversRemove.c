// VfTargetDriversRemove 
 
int __fastcall VfTargetDriversRemove(int result)
{
  int v1; // r3
  int v2; // r9
  _DWORD *v3; // r4
  _DWORD *v4; // r0
  int v5; // r3
  int v6; // r4
  int v7; // r5
  int v8; // r1
  int v9; // r3
  int v10; // r0
  BOOL v11; // r1
  _BYTE v12[8]; // [sp+0h] [bp-40h] BYREF
  _DWORD v13[6]; // [sp+8h] [bp-38h] BYREF
  int v14; // [sp+20h] [bp-20h]

  if ( !VfSafeMode )
  {
    v1 = ViTargetInitialized;
    __dmb(0xBu);
    if ( v1 )
    {
      v2 = *(_DWORD *)(result + 24);
      v3 = 0;
      VfAvlInitializeLockContext((int)v12, 0);
      v4 = (_DWORD *)VfAvlLookupTreeNode(&ViTargetDriversAvl, v12, v2, 1);
      if ( v4 )
      {
        if ( v4[6] )
          return sub_5192DC();
        v5 = v4[1];
        v6 = v4[2];
        v7 = v4[3];
        v13[0] = *v4;
        v13[1] = v5;
        v13[2] = v6;
        v13[3] = v7;
        v8 = v4[5];
        v9 = v4[6];
        v13[4] = v4[4];
        v13[5] = v8;
        v14 = v9;
        if ( v9 )
          --dword_61D2B4;
        v3 = (_DWORD *)VfAvlDeleteTreeNode(&ViTargetDriversAvl, v12, v2, 1);
      }
      result = VfAvlCleanupLockContext((int)v12);
      if ( v3 )
      {
        VfThunkRemoveTargetNotify(v13);
        v10 = v14;
        if ( v14 )
          v10 = ExFreePoolWithTag(v14, 1146512982);
        if ( dword_61D2B0 == 1 )
        {
          result = ExFreeToNPagedLookasideList((int)&ViAvlNodeLookaside, v3);
        }
        else
        {
          v11 = KeGetCurrentIrql(v10) != 2;
          result = VfPoolDelayFreeIfPossible(v3, v11);
        }
      }
    }
  }
  return result;
}
