// sub_7D258C 
 
int __fastcall sub_7D258C(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int *v5; // r4
  int *v6; // r5
  int v7; // r6
  int v8; // r7
  __int16 v9; // r8
  unsigned int *v10; // r5
  int v11; // r6
  int (__fastcall *v12)(int, int, unsigned int); // [sp-4h] [bp-4h]

  do
  {
    if ( *(v5 - 2) )
      a1 = CmpFlushNotify((int)(v5 - 4), v8, 0);
    *((_WORD *)v5 + 4) |= v9;
    v5 = (int *)*v5;
  }
  while ( v5 != v6 );
  v10 = (unsigned int *)(v7 + 72);
  v11 = 4;
  do
  {
    v3 = *v10;
    __dmb(0xBu);
    if ( v3 && v3 != 1 && v3 != 2 )
    {
      __dmb(0xBu);
      a2 = 2;
      do
        a3 = __ldrex(v10);
      while ( a3 == v3 && __strex(2u, v10) );
      __dmb(0xBu);
      if ( a3 == v3 )
      {
        if ( *(_DWORD *)(v3 + 8) )
          a1 = CmpFlushNotify(v3, v8, 0);
        *(_WORD *)(v3 + 24) |= v9;
        __dmb(0xBu);
        do
          a3 = __ldrex(v10);
        while ( a3 == 2 && __strex(v3, v10) );
        __dmb(0xBu);
      }
    }
    ++v10;
    --v11;
  }
  while ( v11 );
  return v12(a1, a2, a3);
}
