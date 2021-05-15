// ViDeadlockCheckDuplicatesAmongChildren 
 
int __fastcall ViDeadlockCheckDuplicatesAmongChildren(int result, int a2, int a3)
{
  _DWORD *v3; // r5
  int v4; // r4
  _DWORD *v5; // r6
  _DWORD *v8; // r7

  v3 = *(_DWORD **)(result + 4);
  v4 = 0;
  v5 = (_DWORD *)(result + 4);
  while ( v3 != v5 )
  {
    v8 = v3 - 3;
    v3 = (_DWORD *)*v3;
    result = ViDeadlockSimilarNodes(v8, a2);
    if ( result )
    {
      if ( v4 )
        result = ViDeadlockMergeNodes(a2, v8, a3);
      else
        v4 = 1;
    }
  }
  return result;
}
