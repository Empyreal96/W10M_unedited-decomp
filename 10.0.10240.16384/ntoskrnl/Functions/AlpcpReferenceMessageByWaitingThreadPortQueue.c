// AlpcpReferenceMessageByWaitingThreadPortQueue 
 
_DWORD *__fastcall AlpcpReferenceMessageByWaitingThreadPortQueue(int a1, _DWORD **a2)
{
  _DWORD *result; // r0
  int v4; // r6
  bool v5; // zf
  unsigned int *v6; // r7
  int v7; // r5
  int v8; // r4

  for ( result = *a2; result != a2; result = (_DWORD *)*result )
  {
    if ( result[4] == a1 )
    {
      v4 = *(result - 3);
      v5 = v4 == 0;
      if ( v4 <= 0 )
      {
LABEL_11:
        if ( !v5 )
          KeBugCheckEx(24, 0, (int)result, 32, v4);
      }
      else
      {
        v6 = result - 3;
        while ( 1 )
        {
          v7 = v4;
          __dmb(0xBu);
          do
            v8 = __ldrex(v6);
          while ( v8 == v4 && __strex(v4 + 1, v6) );
          v4 = v8;
          __dmb(0xBu);
          if ( v8 == v7 )
            break;
          if ( v8 <= 0 )
          {
            v5 = v8 == 0;
            goto LABEL_11;
          }
        }
        if ( v8 != -1 )
          return result;
      }
    }
  }
  return 0;
}
