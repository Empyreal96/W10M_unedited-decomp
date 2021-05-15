// MiUpdateLargePagePfns 
 
int __fastcall MiUpdateLargePagePfns(int a1, int a2)
{
  int v2; // r6
  int v3; // r8
  int v4; // r7
  _DWORD *v5; // r4
  _DWORD *v6; // r9
  unsigned int *v7; // r5
  int v8; // r0
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r3
  unsigned int v16; // r1

  v2 = a2;
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v4 = 0;
  v5 = (_DWORD *)(MmPfnDatabase + 24 * a2);
  v6 = v5 + 6144;
  v7 = v5 + 3;
  do
  {
    v8 = KfRaiseIrql(2);
    v9 = (unsigned __int8 *)v7 + 3;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v10 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v11 = *v7;
        __dmb(0xBu);
      }
      while ( v11 < 0 );
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 | 0x80, v9) );
    }
    v12 = v5[5] & 0xF9FFFFFD | 0x10FFFFD;
    v5[1] = -1073741824;
    v13 = v5[3];
    v5[5] = v12;
    v5[3] = v13 | 0x40000000;
    if ( v5[2] == 128 )
    {
      v14 = a1 + 16 * (dword_633814 & v2 | (v12 >> 28 << byte_6337F5));
      *v5 = *(_DWORD *)(v14 + 12);
      v15 = *(_DWORD *)(v14 + 8);
      *(_DWORD *)(v14 + 12) = v5;
      *(_DWORD *)(v14 + 8) = v15 + 1;
      v4 = 1;
    }
    else
    {
      v5[2] = 128;
      *v5 = v3;
    }
    __dmb(0xBu);
    do
      v16 = __ldrex(v7);
    while ( __strex(v16 & 0x7FFFFFFF, v7) );
    KfLowerIrql(v8);
    v5 += 6;
    ++v2;
    v7 += 6;
  }
  while ( v5 != v6 );
  return v4;
}
