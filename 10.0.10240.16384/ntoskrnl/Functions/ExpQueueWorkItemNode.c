// ExpQueueWorkItemNode 
 
int __fastcall ExpQueueWorkItemNode(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int result; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3

  v4 = *(_DWORD *)(a3 + 4 * (a4 + 96));
  if ( (v4 & 1) != 0 )
    v4 = 0;
  result = KeInsertPriQueue(v4, a1, a2, 0, 0);
  v7 = *(_DWORD *)(v4 + 432);
  v8 = *(_DWORD *)(v4 + 424);
  __dmb(0xBu);
  if ( v8 < (2 * *(_DWORD *)(v4 + 428)) >> 1
    || v8 < v7
    && *(_DWORD *)(v4 + 8) == v4 + 8
    && (*(_DWORD *)(v4 + 4) || (v9 = *(_DWORD *)(v4 + 428), __dmb(0xBu), v9 < 0)) )
  {
    result = KeSetEvent(a3 + 856, 0, 0);
  }
  return result;
}
