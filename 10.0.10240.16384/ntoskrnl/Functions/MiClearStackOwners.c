// MiClearStackOwners 
 
int __fastcall MiClearStackOwners(int a1, char a2)
{
  int v2; // lr
  int v3; // r6
  int v5; // r5
  unsigned int v6; // r7
  unsigned int *v7; // r5
  unsigned int v8; // r4
  _DWORD *v9; // r1
  unsigned __int8 *v10; // r3
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r4
  unsigned __int8 *v15; // r0
  int v16; // r3
  unsigned int v17; // r2

  v2 = 1;
  v3 = -1;
  if ( (a2 & 1) != 0 )
    return sub_5482C0();
  v5 = a1 - 4 * (unsigned __int8)byte_634840;
  v6 = v5 + 4 * ((unsigned __int8)byte_634840 + 1);
  v7 = (unsigned int *)(v5 + 4);
  if ( (unsigned int)v7 >= v6 )
    return 1;
  do
  {
    v8 = *v7;
    if ( (*v7 & 2) != 0 )
    {
      v9 = (_DWORD *)(MmPfnDatabase + 24 * (v8 >> 12));
      v10 = (unsigned __int8 *)v9 + 15;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x80, v10) );
      __dmb(0xBu);
      if ( v11 >> 7 )
      {
        v15 = (unsigned __int8 *)v9 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v16 = v9[3];
            __dmb(0xBu);
          }
          while ( v16 < 0 );
          do
            v17 = __ldrex(v15);
          while ( __strex(v17 | 0x80, v15) );
          __dmb(0xBu);
        }
        while ( v17 >> 7 );
      }
      if ( v8 == *v7 )
      {
        v12 = v9[5];
        if ( v3 == -1 )
        {
          v3 = v12 >> 28;
        }
        else if ( v3 != v12 >> 28 )
        {
          v2 = 0;
        }
        *v9 = 0;
        ++v7;
      }
      __dmb(0xBu);
      v13 = v9 + 3;
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 & 0x7FFFFFFF, v13) );
    }
    else
    {
      ++v7;
    }
  }
  while ( (unsigned int)v7 < v6 );
  return v2;
}
