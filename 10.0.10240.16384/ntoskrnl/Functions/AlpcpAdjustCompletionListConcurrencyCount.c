// AlpcpAdjustCompletionListConcurrencyCount 
 
int __fastcall AlpcpAdjustCompletionListConcurrencyCount(int result, unsigned int a2)
{
  int v2; // r3
  _DWORD *v4; // r6
  unsigned int v5; // r5
  unsigned int *v6; // r8
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r7

  v2 = *(_DWORD *)(result + 212);
  v4 = (_DWORD *)result;
  v5 = *(_DWORD *)(v2 + 76);
  if ( v5 != a2 )
  {
    v6 = (unsigned int *)(v2 + 76);
    do
    {
      v7 = v5;
      __dmb(0xBu);
      do
        v8 = __ldrex(v6);
      while ( v8 == v5 && __strex(a2, v6) );
      v5 = v8;
      __dmb(0xBu);
      if ( v8 == v7 )
      {
        if ( !v4[4] )
          return result;
        if ( v7 < a2 )
        {
          v9 = a2 - v7;
          do
          {
            result = AlpcpQueueIoCompletionPort(v4, 1, 0);
            --v9;
          }
          while ( v9 );
        }
      }
      else if ( v8 >= a2 )
      {
        return result;
      }
    }
    while ( v5 != a2 );
  }
  return result;
}
