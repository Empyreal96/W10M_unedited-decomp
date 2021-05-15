// PspReleaseReturnedQuota 
 
int __fastcall PspReleaseReturnedQuota(int a1, int a2)
{
  _DWORD *v3; // r6
  _DWORD *v4; // lr
  int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r1

  v3 = *(_DWORD **)(a2 + 20);
  v4 = (_DWORD *)(a2 + 20);
  v5 = 0;
  if ( v3 != (_DWORD *)(a2 + 20) )
  {
    do
    {
      __dmb(0xBu);
      v6 = v3 - 1;
      do
        v7 = __ldrex(v6);
      while ( __strex(0, v6) );
      __dmb(0xBu);
      v5 += v7;
      if ( !v3[64 * (4 - a1) - 34] )
      {
        __dmb(0xBu);
        v8 = v3 - 2;
        do
          v9 = __ldrex(v8);
        while ( __strex(0, v8) );
        __dmb(0xBu);
        v5 += v9;
      }
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != v4 );
    if ( v5 )
      (*(void (**)(void))(a2 + 16))();
  }
  return v5;
}
