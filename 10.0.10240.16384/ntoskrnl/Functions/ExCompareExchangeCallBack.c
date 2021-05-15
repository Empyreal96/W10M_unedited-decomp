// ExCompareExchangeCallBack 
 
int __fastcall ExCompareExchangeCallBack(_DWORD *a1, int *a2, int a3)
{
  unsigned int i; // r6
  int v7; // r1
  unsigned int v8; // r0
  int result; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int *v12; // r0
  unsigned int v13; // r1
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1

  if ( a2 && !ExAcquireRundownProtectionEx(a2, 8) )
    return 0;
  __pld(a1);
  for ( i = *a1; (i ^ a3) <= 7; i = v11 )
  {
    v10 = a2 ? (unsigned int)a2 | 7 : 0;
    __dmb(0xBu);
    do
      v11 = __ldrex(a1);
    while ( v11 == i && __strex(v10, a1) );
    if ( v11 == i )
      break;
  }
  if ( (i & 0xFFFFFFF8) != a3 )
  {
    if ( a2 )
    {
      __pld(a2);
      v7 = *a2;
      if ( (*a2 & 1) != 0 )
      {
LABEL_25:
        v12 = (unsigned int *)(v7 & 0xFFFFFFFE);
        __dmb(0xBu);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 - 8, v12) );
        __dmb(0xBu);
        if ( v13 == 8 )
        {
          __dmb(0xBu);
          v14 = (unsigned __int8 *)(v12 + 5);
          do
            v15 = __ldrex(v14);
          while ( __strex(v15 & 0xFE, v14) );
          __dmb(0xBu);
          if ( (v15 & 1) == 0 )
            KeSetEvent((int)(v12 + 1), 0, 0);
        }
      }
      else
      {
        while ( 1 )
        {
          __dmb(0xBu);
          do
            v8 = __ldrex((unsigned int *)a2);
          while ( v8 == v7 && __strex(v7 - 16, (unsigned int *)a2) );
          __dmb(0xBu);
          if ( v8 == v7 )
            break;
          v7 = v8;
          if ( (v8 & 1) != 0 )
            goto LABEL_25;
        }
      }
    }
    return 0;
  }
  if ( (i & 0xFFFFFFF8) != 0 )
    result = sub_528F28();
  else
    result = 1;
  return result;
}
