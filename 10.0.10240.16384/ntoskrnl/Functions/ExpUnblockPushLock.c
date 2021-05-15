// ExpUnblockPushLock 
 
unsigned int *__fastcall ExpUnblockPushLock(unsigned int *result, int a2, int a3)
{
  int v5; // r9
  int v6; // r8
  unsigned int v7; // r4
  int v8; // r6
  unsigned int v9; // r7
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1

  v5 = (int)result;
  v6 = 0;
  do
    v7 = __ldrex(result);
  while ( __strex(0, result) );
  v8 = 2;
  if ( v7 )
  {
    if ( *(_DWORD *)(v7 + 16) )
    {
      result = (unsigned int *)KfRaiseIrql(2);
      v8 = (int)result;
    }
    do
    {
      if ( v7 == a2 )
        v6 = 1;
      v9 = *(_DWORD *)(v7 + 16);
      __dmb(0xBu);
      v10 = (unsigned __int8 *)(v7 + 32);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0xFD, v10) );
      __dmb(0xBu);
      if ( !((unsigned __int8)(v11 & 2) >> 1) )
        result = (unsigned int *)KeSetEvent(v7, 1, 0);
      v7 = v9;
    }
    while ( v9 );
  }
  if ( v8 != 2 )
    result = (unsigned int *)KfLowerIrql(v8);
  if ( a2 && !v6 )
  {
    if ( a3 )
      result = (unsigned int *)sub_50BA34();
    else
      result = (unsigned int *)ExTimedWaitForUnblockPushLock(v5, a2);
  }
  return result;
}
