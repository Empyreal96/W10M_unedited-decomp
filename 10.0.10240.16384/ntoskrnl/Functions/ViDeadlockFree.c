// ViDeadlockFree 
 
int __fastcall ViDeadlockFree(int result, int a2)
{
  bool v3; // zf
  _DWORD *v4; // r1
  void *v5; // r0

  v3 = a2 == 1;
  v4 = (_DWORD *)result;
  if ( v3 )
  {
    v5 = &ViDeadlockResourceLookaside;
  }
  else if ( a2 == 2 )
  {
    v5 = &ViDeadlockNodeLookaside;
  }
  else
  {
    if ( a2 != 3 )
      return result;
    v5 = &ViDeadlockThreadLookaside;
  }
  return ExFreeToNPagedLookasideList((int)v5, v4);
}
