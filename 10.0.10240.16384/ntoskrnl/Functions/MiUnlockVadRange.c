// MiUnlockVadRange 
 
int __fastcall MiUnlockVadRange(int a1, unsigned int a2, int a3)
{
  int v5; // r7
  _DWORD *v6; // r0
  unsigned int v7; // r4
  _DWORD *v8; // r2
  int v9; // r3
  _DWORD *i; // r3
  unsigned int *v12; // r5
  unsigned int v13; // r1
  _DWORD *v14; // r3

  v5 = __mrc(15, 0, 13, 0, 3);
  if ( a2 == -1 )
  {
    v14 = *(_DWORD **)(a1 + 636);
    v6 = 0;
    while ( v14 )
    {
      v6 = v14;
      v14 = (_DWORD *)*v14;
    }
  }
  else
  {
    v6 = MiLocateAddress(a2);
  }
  if ( !a3 )
    return UNLOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
  while ( 1 )
  {
    v7 = v6[1];
    v8 = v6;
    if ( v7 )
    {
      for ( i = *(_DWORD **)v7; i; i = (_DWORD *)*i )
        v7 = (unsigned int)i;
    }
    else
    {
      v9 = v6[2];
      while ( 1 )
      {
        v7 = v9 & 0xFFFFFFFC;
        if ( (v9 & 0xFFFFFFFC) == 0 || *(_DWORD **)v7 == v8 )
          break;
        v9 = *(_DWORD *)(v7 + 8);
        v8 = (_DWORD *)v7;
      }
    }
    if ( a3 == 1 )
    {
      MiUnlockVad(v5 & 0xFFFFFFC0, (int)v6);
      return UNLOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
    }
    v12 = v6 + 6;
    __dmb(0xBu);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 - 1, v12) );
    if ( (v13 & 2) != 0 )
      break;
    KeAbPostRelease((unsigned int)(v6 + 6));
    v6 = (_DWORD *)v7;
    if ( !--a3 )
      return UNLOCK_ADDRESS_SPACE_SHARED(v5 & 0xFFFFFFC0, a1);
  }
  return sub_7D41B4();
}
