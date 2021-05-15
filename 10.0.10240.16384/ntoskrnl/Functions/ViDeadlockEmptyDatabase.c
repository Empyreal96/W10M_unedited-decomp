// ViDeadlockEmptyDatabase 
 
int __fastcall ViDeadlockEmptyDatabase(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r7
  _DWORD *v6; // r6
  int v7; // r2
  int v8; // r1
  _DWORD *v9; // r8
  _DWORD *v10; // r4
  int v11; // r2
  unsigned int i; // r5
  _DWORD *j; // r8
  _DWORD *v14; // r4
  int v15; // r3
  int result; // r0
  _DWORD *v17; // r4
  _DWORD *v18; // r4
  _DWORD *v19; // r4
  _DWORD *v20; // [sp+0h] [bp-28h] BYREF
  unsigned int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]

  v22 = a4;
  v4 = 0;
  v20 = 0;
  v5 = 0;
  v6 = 0;
  v21 = ViRaiseIrqlToDpcLevel(a1);
  ViDeadlockDetectionLock(1);
  __dmb(0xBu);
  ViDeadlockDetectionEnabled = 0;
  v7 = ViDeadlockGlobals;
  if ( ViDeadlockGlobals )
  {
    v8 = *(_DWORD *)(ViDeadlockGlobals + 16);
    do
    {
      v9 = *(_DWORD **)((char *)v4 + v8);
      while ( v9 != (_DWORD *)((char *)v4 + v8) )
      {
        v10 = v9 - 6;
        v9 = (_DWORD *)*v9;
        ViDeadlockRemoveResource(v10, 1, &v20);
        v7 = ViDeadlockGlobals;
        *v10 = v6;
        v6 = v10;
        v8 = *(_DWORD *)(v7 + 16);
      }
      v4 += 2;
    }
    while ( (unsigned int)v4 < 0x1FF8 );
    v11 = *(_DWORD *)(v7 + 8208);
    for ( i = 0; i < 0x1FF8; i += 8 )
    {
      for ( j = *(_DWORD **)(i + v11); j != (_DWORD *)(i + v11); v11 = *(_DWORD *)(v15 + 8208) )
      {
        v14 = j - 3;
        j = (_DWORD *)*j;
        ViDeadlockRemoveThread(v14, 1);
        v15 = ViDeadlockGlobals;
        *v14 = v5;
        v5 = v14;
      }
    }
    v4 = v20;
  }
  ViDeadlockDetectionUnlock((int *)1);
  result = ViLowerIrql(v21);
  if ( v5 )
  {
    do
    {
      v17 = (_DWORD *)*v5;
      result = ViDeadlockFree(v5, 3);
      v5 = v17;
    }
    while ( v17 );
  }
  if ( v4 )
  {
    do
    {
      v18 = (_DWORD *)*v4;
      result = ViDeadlockFree(v4, 2);
      v4 = v18;
    }
    while ( v18 );
  }
  if ( v6 )
  {
    do
    {
      v19 = (_DWORD *)*v6;
      result = ExFreeToNPagedLookasideList((int)&ViDeadlockResourceLookaside, v6);
      v6 = v19;
    }
    while ( v19 );
  }
  return result;
}
