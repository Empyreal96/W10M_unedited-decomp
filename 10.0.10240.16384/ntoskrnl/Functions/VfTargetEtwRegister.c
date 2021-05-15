// VfTargetEtwRegister 
 
unsigned int __fastcall VfTargetEtwRegister(unsigned int result, int a2, int a3, int a4)
{
  unsigned int v6; // r8
  int v7; // r5
  _DWORD *v8; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r2
  _DWORD *v12; // r1
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a2;
  v13[1] = a3;
  v13[2] = a4;
  v6 = result;
  if ( !VfSafeMode )
  {
    v7 = 0;
    v8 = (_DWORD *)ExAllocatePoolWithTag(512, 24, 1413834326);
    VfAvlInitializeLockContext((int)v13, 0);
    v9 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v13, a3, 1);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 24);
      if ( v8 )
      {
        if ( v10 )
        {
          v11 = v10 + 8;
          v8[2] = v6;
          v8[3] = a2;
          v8[4] = a3;
          v12 = *(_DWORD **)(v11 + 4);
          *v8 = v11;
          v8[1] = v12;
          if ( *v12 != v11 )
            __fastfail(3u);
          *v12 = v8;
          *(_DWORD *)(v11 + 4) = v8;
          v7 = 1;
        }
      }
      else if ( v10 )
      {
        *(_DWORD *)(v10 + 16) |= 1u;
      }
    }
    result = VfAvlCleanupLockContext((int)v13);
    if ( !v7 )
    {
      if ( v8 )
        result = ExFreePoolWithTag((unsigned int)v8);
    }
  }
  return result;
}
