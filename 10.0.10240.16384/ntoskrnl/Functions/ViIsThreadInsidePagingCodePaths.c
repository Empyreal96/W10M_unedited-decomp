// ViIsThreadInsidePagingCodePaths 
 
int __fastcall ViIsThreadInsidePagingCodePaths(int a1)
{
  int v1; // r5
  int v2; // r4
  unsigned int v3; // r6
  _DWORD *v4; // r0
  int v5; // r3

  v1 = 0;
  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = ViRaiseIrqlToDpcLevel(a1);
  ViDeadlockDetectionLock(0);
  v4 = ViDeadlockSearchThread(v2 & 0xFFFFFFC0);
  if ( v4 )
  {
    v5 = v4[6];
    __dmb(0xBu);
    if ( v5 )
      v1 = 1;
  }
  ViDeadlockDetectionUnlock(0);
  ViLowerIrql(v3);
  return v1;
}
