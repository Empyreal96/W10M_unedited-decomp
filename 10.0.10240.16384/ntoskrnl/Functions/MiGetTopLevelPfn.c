// MiGetTopLevelPfn 
 
int __fastcall MiGetTopLevelPfn(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r5
  int v7; // r0
  int v8; // r7
  int v9; // r0
  int *v10; // r4
  unsigned __int8 *v11; // r3
  int v12; // lr
  unsigned int v13; // r1
  unsigned int v14; // r4
  int *v15; // r6
  int v16; // r3
  int v17; // t1
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned __int8 *v21; // r1
  int v22; // r3
  unsigned int v23; // r2
  _DWORD *v24; // [sp+0h] [bp-20h] BYREF
  int v25; // [sp+4h] [bp-1Ch]
  int v26; // [sp+8h] [bp-18h]

  v24 = a2;
  v25 = a3;
  v26 = a4;
  v5 = MmPfnDatabase;
  v6 = a1;
  v7 = *(_DWORD *)(a1 + 20);
  v24 = 0;
  v25 = 0;
  v8 = 0;
  v9 = v7 & 0xFFFFF;
  if ( v9 != (v6 - MmPfnDatabase) / 24 )
  {
    v10 = (int *)&v24;
    while ( 1 )
    {
      v6 = v5 + 24 * v9;
      *v10++ = v6;
      v11 = (unsigned __int8 *)(v6 + 15);
      ++v8;
      v12 = v9;
      do
        v13 = __ldrex(v11);
      while ( __strex(v13 | 0x80, v11) );
      __dmb(0xBu);
      if ( v13 >> 7 )
      {
        v21 = (unsigned __int8 *)(v6 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v22 = *(_DWORD *)(v6 + 12);
            __dmb(0xBu);
          }
          while ( v22 < 0 );
          do
            v23 = __ldrex(v21);
          while ( __strex(v23 | 0x80, v21) );
          __dmb(0xBu);
        }
        while ( v23 >> 7 );
      }
      v9 = *(_DWORD *)(v6 + 20) & 0xFFFFF;
      if ( v9 == v12 )
        break;
      v5 = MmPfnDatabase;
    }
  }
  if ( a2 )
    *a2 = v8;
  v14 = 0;
  v15 = (int *)&v24;
  do
  {
    v17 = *v15++;
    v16 = v17;
    if ( !v17 )
      break;
    if ( v16 != v6 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(v16 + 12);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 & 0x7FFFFFFF, v18) );
    }
    ++v14;
  }
  while ( v14 < 2 );
  return v6;
}
