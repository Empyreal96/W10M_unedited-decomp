// MiStoreUpdatePagefileHash 
 
void __fastcall MiStoreUpdatePagefileHash(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r4
  int v5; // r7
  int v6; // r6
  int v7; // lr
  __int16 *v8; // r10
  unsigned int v9; // r8
  bool v10; // zf
  _DWORD *v11; // r3
  int v12; // r9
  int v13; // r5
  int v14; // r10
  int v15; // lr
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned __int8 *v18; // r1
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r3
  unsigned int *v22; // r2
  unsigned int v23; // r0
  int v24; // [sp+8h] [bp-30h]
  __int16 *v25; // [sp+Ch] [bp-2Ch]
  _DWORD *v28; // [sp+18h] [bp-20h]

  v4 = 0;
  v5 = 0;
  v6 = 2;
  v7 = 0;
  v24 = 0;
  v25 = 0;
  v8 = 0;
  v9 = 0;
  v10 = a4 == 0;
  v11 = (_DWORD *)(a3 + 28);
  if ( !v10 )
  {
    do
    {
      v28 = v11 + 1;
      if ( *v11 == dword_6348F4 )
      {
        v12 = 2;
        v13 = v5;
      }
      else
      {
        v14 = MmPfnDatabase + 24 * *v11;
        v15 = KfRaiseIrql(2);
        v16 = (unsigned __int8 *)(v14 + 15);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 | 0x80, v16) );
        __dmb(0xBu);
        if ( v17 >> 7 )
        {
          v18 = (unsigned __int8 *)(v14 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v19 = *(_DWORD *)(v14 + 12);
              __dmb(0xBu);
            }
            while ( v19 < 0 );
            do
              v20 = __ldrex(v18);
            while ( __strex(v20 | 0x80, v18) );
            __dmb(0xBu);
          }
          while ( v20 >> 7 );
        }
        v21 = *(_DWORD *)(v14 + 8);
        if ( (v21 & 0x10) != 0 )
          v13 = v21 >> 13;
        else
          v13 = 0;
        v12 = (v21 >> 2) & 1;
        __dmb(0xBu);
        v22 = (unsigned int *)(v14 + 12);
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 & 0x7FFFFFFF, v22) );
        KfLowerIrql(v15);
        v7 = v24;
        v8 = v25;
        if ( !v25 )
        {
          v8 = MiSystemPartition;
          v25 = MiSystemPartition;
        }
      }
      if ( v6 == v12 && v13 == v5 )
      {
        ++v4;
      }
      else
      {
        if ( v6 != 2 )
          MiMapPageFileHash(*(_DWORD *)&v8[2 * v6 + 1800], a3, v9 - v4, v7, v4);
        v6 = v12;
        v7 = v13;
        v24 = v13;
        v5 = v13;
        v4 = 1;
      }
      ++v9;
      ++v5;
      v11 = v28;
    }
    while ( v9 < a4 );
    if ( v6 != 2 )
      MiMapPageFileHash(*(_DWORD *)&v8[2 * v6 + 1800], a3, v9 - v4, v7, v4);
  }
}
