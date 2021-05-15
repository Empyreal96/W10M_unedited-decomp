// CmpCleanUpKCBCacheTable 
 
int __fastcall CmpCleanUpKCBCacheTable(int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int v4; // r5
  int v6; // r6
  int result; // r0
  unsigned int v8; // r4
  int *v9; // r8
  int *v10; // r7
  int v11; // r6
  int v13; // [sp+10h] [bp-30h]
  unsigned int v14; // [sp+14h] [bp-2Ch]
  int v15; // [sp+1Ch] [bp-24h]

  v3 = *(_DWORD *)(a1 + 1848);
  v4 = *(_DWORD *)(a1 + 1844);
  v6 = a3;
  v14 = v3;
  v15 = v4;
  result = CmpRunDownDelayDerefKCBEngine(a2);
LABEL_2:
  v13 = 0;
  v8 = 0;
  v9 = (int *)(v4 + 8);
  while ( v8 < v3 )
  {
    if ( !v6 )
      return sub_806148(result);
    v10 = v9;
    if ( *v9 )
    {
      do
      {
        v11 = *v10;
        CmpLockKcbExclusive((_DWORD *)(*v10 - 12));
        if ( *(_DWORD *)(v11 - 12) || a2 && *(_DWORD *)(a2 + 20) != *(_DWORD *)(v11 + 8) )
        {
          v10 = (int *)(v11 + 4);
          result = CmpUnlockKcb((_DWORD *)(v11 - 12));
        }
        else
        {
          CmpRemoveFromDelayedClose(v11 - 12);
          CmpCleanUpKcbCacheWithLock((_DWORD *)(v11 - 12), a3);
          result = CmpUnlockKcb((_DWORD *)(v11 - 12));
          v13 = 1;
          v10 = v9;
        }
      }
      while ( *v10 );
      v6 = a3;
    }
    v3 = v14;
    if ( v13 )
    {
      v4 = v15;
      goto LABEL_2;
    }
    ++v8;
    v9 += 3;
  }
  return result;
}
