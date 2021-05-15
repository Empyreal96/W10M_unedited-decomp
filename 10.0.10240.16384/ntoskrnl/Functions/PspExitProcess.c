// PspExitProcess 
 
int __fastcall PspExitProcess(int a1, int a2)
{
  unsigned int *v4; // r2
  unsigned int v5; // r5
  int result; // r0

  __dmb(0xBu);
  v4 = (unsigned int *)(a2 + 192);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 4, v4) );
  __dmb(0xBu);
  __mrc(15, 0, 13, 0, 3);
  if ( a1 )
    return sub_803020();
  result = *(_DWORD *)(a2 + 376);
  if ( !result )
    goto LABEL_6;
  if ( result != 1 )
  {
    result = ObfDereferenceObject(result);
LABEL_6:
    *(_DWORD *)(a2 + 376) = 1;
  }
  if ( a1 )
  {
    if ( *(int *)(a2 + 192) < 0 )
      ExCleanTimerResolutionRequest();
    DbgkFlushErrorPort(a2);
    result = PfProcessExitNotification(a2);
  }
  return result;
}
