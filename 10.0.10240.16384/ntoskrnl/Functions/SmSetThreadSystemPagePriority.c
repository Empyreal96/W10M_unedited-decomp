// SmSetThreadSystemPagePriority 
 
int __fastcall SmSetThreadSystemPagePriority(int *a1, int a2, int a3)
{
  int v4; // r0

  v4 = *a1;
  if ( !v4 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *a1 = v4;
  }
  if ( !a3 )
    return PsSetSystemPagePriorityThread(v4, a2);
  PsRevertToUserPagePriorityThread(v4, a2);
  return 0;
}
