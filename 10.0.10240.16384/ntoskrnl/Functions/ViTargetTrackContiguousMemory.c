// ViTargetTrackContiguousMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ViTargetTrackContiguousMemory(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD *v8; // r4
  int v9; // r5
  int v10; // r0
  int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r3
  int v14; // r2
  _DWORD *v15; // r1
  BOOL v16; // r1
  _DWORD v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a2;
  v17[1] = a3;
  v17[2] = a4;
  result = ViTargetUpdateTreeAllowed(a1, a2);
  if ( result )
  {
    result = ExAllocatePoolWithTag(512, 20, 1631807062);
    v8 = (_DWORD *)result;
    if ( result )
    {
      *(_DWORD *)(result + 16) = a1;
      *(_QWORD *)(result + 8) = *(_QWORD *)&a2;
      v9 = 0;
      VfAvlInitializeLockContext((int)v17, 0);
      v10 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v17, a1, 1);
      if ( v10 )
      {
        v11 = *(_DWORD *)(v10 + 24);
        if ( v11 )
        {
          dword_61D2B8 += a3;
          v12 = *(_DWORD *)(v11 + 128) + a3;
          v13 = *(_DWORD *)(v11 + 132);
          *(_DWORD *)(v11 + 128) = v12;
          if ( v13 < v12 )
            *(_DWORD *)(v11 + 132) = v12;
          v14 = v11 + 136;
          v15 = *(_DWORD **)(v14 + 4);
          *v8 = v14;
          v8[1] = v15;
          if ( *v15 != v14 )
            __fastfail(3u);
          *v15 = v8;
          *(_DWORD *)(v14 + 4) = v8;
          v9 = 1;
        }
      }
      result = VfAvlCleanupLockContext((int)v17);
      if ( !v9 )
      {
        v16 = KeGetCurrentIrql(result) != 2;
        result = VfPoolDelayFreeIfPossible((int)v8, v16);
      }
    }
  }
  return result;
}
