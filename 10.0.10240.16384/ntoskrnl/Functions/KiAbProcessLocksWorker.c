// KiAbProcessLocksWorker 
 
__int64 __fastcall KiAbProcessLocksWorker(__int64 a1, int a2, int a3)
{
  _DWORD **v4; // r5
  _DWORD **v5; // r6
  _DWORD *v7; // r2
  _DWORD *v8; // r4
  unsigned __int16 *v9; // r2
  unsigned int v10; // r1
  _DWORD *v11; // r4
  _DWORD *v12; // r4
  unsigned __int16 *v13; // r2
  unsigned int v14; // r1

  v4 = (_DWORD **)HIDWORD(a1);
  v5 = (_DWORD **)a1;
  if ( a3 )
  {
    while ( *v4 )
    {
      v11 = *v4;
      if ( *v4 )
        *v4 = (_DWORD *)*v11;
      v12 = v11 - 195;
      v12[195] = 1;
      __dmb(0xFu);
      if ( *((_BYTE *)v12 + 811) )
        KiAbProcessThreadLocks(v12, 0, 0, 1, a2, v5, 0);
      __dmb(0xBu);
      v13 = (unsigned __int16 *)(v12 + 202);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 - 1, v13) );
      __dmb(0xBu);
    }
    v4 = 0;
  }
  while ( *v5 )
  {
    v7 = *v5;
    if ( *v5 )
      *v5 = (_DWORD *)*v7;
    v8 = v7 - 194;
    *v7 = 1;
    __dmb(0xFu);
    if ( *((_BYTE *)v7 - 291) )
      KiAbProcessThreadLocks(v8, 0, 1, 0, a2, v5, v4);
    __dmb(0xBu);
    v9 = (unsigned __int16 *)(v8 + 202);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 - 1, v9) );
    __dmb(0xBu);
  }
  return a1;
}
