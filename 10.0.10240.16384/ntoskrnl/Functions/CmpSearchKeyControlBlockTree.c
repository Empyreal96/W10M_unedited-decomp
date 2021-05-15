// CmpSearchKeyControlBlockTree 
 
int __fastcall CmpSearchKeyControlBlockTree(int (__fastcall *a1)(int, int, int), int a2, int a3)
{
  unsigned int v3; // r10
  unsigned int v4; // r6
  int *v6; // r8
  int *v7; // r5
  int i; // r3
  int v9; // t1
  int v10; // r4
  int v11; // r0
  int v12; // r9
  int v13; // r0
  bool v14; // zf
  _DWORD *v15; // r0
  int v16; // r5

  v3 = *(_DWORD *)(a2 + 1848);
  v4 = 0;
  if ( v3 )
  {
    v6 = (int *)(*(_DWORD *)(a2 + 1844) + 8);
    while ( 2 )
    {
      CmpLockHashEntryByIndexExclusive(a2, v4);
      v7 = v6;
      v9 = *v6;
      v6 += 3;
      for ( i = v9; i; i = *v7 )
      {
        v10 = *v7;
        CmpLockKcbExclusive((_DWORD *)(*v7 - 12));
        v11 = v10 - 12;
        if ( *(_DWORD *)(v10 - 12) )
        {
          v12 = *(_DWORD *)(v10 + 4);
          v13 = a1(v11, a2, a3);
          if ( v13 == 1 )
          {
            v16 = 1;
            goto LABEL_18;
          }
          if ( v13 == 3 )
          {
            v16 = 0;
LABEL_18:
            CmpUnlockKcb((_DWORD *)(v10 - 12));
            CmpUnlockHashEntryByIndex(a2, v4);
            return v16;
          }
          v14 = v13 == 2;
          v15 = (_DWORD *)(v10 - 12);
          if ( v14 )
          {
            CmpUnlockKcb(v15);
            *v7 = v12;
          }
          else
          {
            v7 = (int *)(v10 + 4);
            CmpUnlockKcb(v15);
          }
        }
        else
        {
          CmpRemoveFromDelayedClose(v11);
          CmpCleanUpKcbCacheWithLock((_DWORD *)(v10 - 12), 0);
          CmpUnlockKcb((_DWORD *)(v10 - 12));
          v7 = v6 - 3;
        }
      }
      CmpUnlockHashEntryByIndex(a2, v4++);
      if ( v4 < v3 )
        continue;
      break;
    }
  }
  return 1;
}
