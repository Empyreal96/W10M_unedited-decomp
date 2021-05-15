// ViDeadlockAllocate 
 
int __fastcall ViDeadlockAllocate(int a1)
{
  int result; // r0
  void *v2; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1

  switch ( a1 )
  {
    case 1:
      v2 = &ViDeadlockResourceLookaside;
      break;
    case 2:
      v2 = &ViDeadlockNodeLookaside;
      break;
    case 3:
      v2 = &ViDeadlockThreadLookaside;
      break;
    default:
      return 0;
  }
  result = ExAllocateFromNPagedLookasideList((int)v2);
  if ( !result )
  {
    ViDeadlockState |= 1u;
    v3 = (unsigned int *)(ViDeadlockGlobals + 16400);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 + 1, v3) );
  }
  return result;
}
