// KiDecrementProcessStackCount 
 
int __fastcall KiDecrementProcessStackCount(int result)
{
  int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r1
  int v4; // r7
  int v5; // lr
  unsigned int v6; // r2
  unsigned int v7; // r6
  unsigned int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r1
  int *v11; // r5
  int v12; // r1
  unsigned int v13; // r2

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 116);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 - 8, v2) );
  __dmb(0xBu);
  if ( (v3 & 0xFFFFFFF8) == 8 )
  {
    v4 = 0;
    v5 = KfRaiseIrql(2);
    do
      v6 = __ldrex((unsigned __int8 *)v1);
    while ( __strex(v6 | 0x80, (unsigned __int8 *)v1) );
    __dmb(0xBu);
    if ( v6 >> 7 )
    {
      result = sub_50CDC0();
    }
    else
    {
      v7 = *v2;
      if ( (*v2 & 7) == 0 && *(_DWORD *)(v1 + 40) != v1 + 40 && (v7 & 0xFFFFFFF8) == 0 )
      {
        while ( 1 )
        {
          v8 = v7;
          __dmb(0xBu);
          do
            v9 = __ldrex(v2);
          while ( v9 == v7 && __strex(v7 & 0xFFFFFFF8 | 3, v2) );
          v7 = v9;
          __dmb(0xBu);
          if ( v9 == v8 )
            break;
          if ( (v9 & 0xFFFFFFF8) != 0 )
            goto LABEL_17;
        }
        v4 = 1;
      }
LABEL_17:
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)v1);
      while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)v1) );
      result = KfLowerIrql(v5);
      if ( v4 )
      {
        v11 = (int *)(v1 + 84);
        __pld(&KiProcessOutSwapListHead);
        result = KiProcessOutSwapListHead;
        do
        {
          *v11 = result;
          v12 = result;
          __dmb(0xBu);
          do
            v13 = __ldrex((unsigned int *)&KiProcessOutSwapListHead);
          while ( v13 == result && __strex((unsigned int)v11, (unsigned int *)&KiProcessOutSwapListHead) );
          result = v13;
        }
        while ( v13 != v12 );
        if ( !v13 )
          result = KeSetEvent((int)&KiSwapEvent, 10, 0);
      }
    }
  }
  return result;
}
