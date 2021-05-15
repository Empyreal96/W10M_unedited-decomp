// ViDeadlockCheckDuplicatesAmongRoots 
 
int __fastcall ViDeadlockCheckDuplicatesAmongRoots(int result, int a2)
{
  int v2; // r3
  int v4; // r8
  _DWORD *v5; // r4
  _DWORD *v6; // r7
  int v7; // r6
  _DWORD *v8; // r5
  int v9; // r3

  v2 = *(_DWORD *)(result + 28);
  v4 = result;
  v5 = *(_DWORD **)(v2 + 16);
  v6 = (_DWORD *)(v2 + 16);
  v7 = 0;
  while ( v5 != v6 )
  {
    v8 = v5 - 5;
    v9 = *(v5 - 5);
    v5 = (_DWORD *)*v5;
    if ( !v9 )
    {
      result = ViDeadlockSimilarNodes(v8, v4);
      if ( result )
      {
        if ( v7 )
          result = ViDeadlockMergeNodes(v4, v8, a2);
        else
          v7 = 1;
      }
    }
  }
  return result;
}
