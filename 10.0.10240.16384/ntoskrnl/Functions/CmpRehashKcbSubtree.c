// CmpRehashKcbSubtree 
 
int __fastcall CmpRehashKcbSubtree(int a1, int a2)
{
  int v2; // r4
  int v3; // r7
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int v7; // r6
  unsigned int v8; // r8

  v2 = 0;
  v3 = a2;
  v4 = a2;
  if ( a1 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 40);
      *(_DWORD *)(v4 + 40) = v2;
      v2 = v4;
      v4 = v5;
    }
    while ( v2 != a1 );
  }
  v6 = 0;
  if ( v2 )
  {
    do
    {
      v7 = *(_DWORD *)(v2 + 40);
      *(_DWORD *)(v2 + 40) = v4;
      v8 = CmpComputeKcbConvKey(v2);
      if ( v8 != *(_DWORD *)(v2 + 12) )
      {
        CmpRemoveKeyHash(*(_DWORD *)(v3 + 20), (_DWORD *)(v2 + 12));
        *(_DWORD *)(v2 + 12) = v8;
        CmpInsertKeyHash(*(_DWORD *)(v3 + 20), (_DWORD *)(v2 + 12), 0);
        v6 = 1;
      }
      v4 = v2;
      v2 = v7;
    }
    while ( v7 );
  }
  return v6;
}
