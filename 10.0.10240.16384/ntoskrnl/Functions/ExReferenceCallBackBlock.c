// ExReferenceCallBackBlock 
 
int __fastcall ExReferenceCallBackBlock(_DWORD *a1)
{
  unsigned int v2; // r1
  _DWORD *v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int *v10; // r0
  unsigned int v11; // r1
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1

  __pld(a1);
  v2 = *a1;
  if ( (*a1 & 7) != 0 )
  {
    do
    {
      do
        v5 = __ldrex(a1);
      while ( v5 == v2 && __strex(v2 - 1, a1) );
      __dmb(0xBu);
      if ( v5 == v2 )
        break;
      v2 = v5;
    }
    while ( (v5 & 7) != 0 );
  }
  if ( !v2 )
    return 0;
  if ( (v2 & 7) == 0 )
    return sub_546D58();
  v4 = (_DWORD *)(v2 & 0xFFFFFFF8);
  if ( (v2 & 7) == 1 && ExAcquireRundownProtectionEx(v4, 7) )
  {
    __pld(a1);
    v6 = *a1;
    if ( (*a1 & 7) == 0 )
    {
      while ( v4 == (_DWORD *)(v6 & 0xFFFFFFF8) )
      {
        do
          v7 = __ldrex(a1);
        while ( v7 == v6 && __strex(v6 + 7, a1) );
        __dmb(0xBu);
        if ( v7 == v6 )
          return (int)v4;
        v6 = v7;
        if ( (v7 & 7) != 0 )
          break;
      }
    }
    __pld(v4);
    v8 = *v4;
    if ( (*v4 & 1) != 0 )
    {
LABEL_26:
      v10 = (unsigned int *)(v8 & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 - 7, v10) );
      __dmb(0xBu);
      if ( v11 == 7 )
      {
        __dmb(0xBu);
        v12 = (unsigned __int8 *)(v10 + 5);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 & 0xFE, v12) );
        __dmb(0xBu);
        if ( (v13 & 1) == 0 )
          KeSetEvent((int)(v10 + 1), 0, 0);
      }
    }
    else
    {
      while ( 1 )
      {
        __dmb(0xBu);
        do
          v9 = __ldrex(v4);
        while ( v9 == v8 && __strex(v8 - 14, v4) );
        __dmb(0xBu);
        if ( v9 == v8 )
          break;
        v8 = v9;
        if ( (v9 & 1) != 0 )
          goto LABEL_26;
      }
    }
  }
  return (int)v4;
}
