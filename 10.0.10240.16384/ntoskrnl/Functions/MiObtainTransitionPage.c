// MiObtainTransitionPage 
 
int __fastcall MiObtainTransitionPage(int a1, int a2, int a3, int a4, int *a5)
{
  int v9; // r0
  unsigned int *v11; // r8
  unsigned int v12; // r1
  unsigned int v13; // r2
  int v14; // r4
  int v15; // r1
  int v16; // r2
  int v17; // r0
  int v18; // r4
  int v19; // r6
  int v20; // r0
  int v21; // r7
  unsigned __int8 *v22; // r1
  unsigned int v23; // r2
  unsigned int v24; // r3
  unsigned int v25; // r1
  int v26; // r4
  unsigned int *v27; // r2
  unsigned int v28; // r4
  int v29; // r3
  unsigned int v30; // r1

  if ( *(_WORD *)(a1 + 16) )
  {
    __dmb(0xBu);
    v27 = (unsigned int *)(a1 + 12);
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    KfLowerIrql(a2);
    return 0;
  }
  v9 = MiCanPageMove(a1);
  __dmb(0xBu);
  if ( !v9 )
    return sub_513450();
  v11 = (unsigned int *)(a1 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  KfLowerIrql(a2);
  v13 = dword_640580;
  if ( (unsigned int)dword_640580 >= 0x80
    || (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) != 0 && v13 >= 2 )
  {
    v14 = (a1 - MmPfnDatabase) / 24;
    if ( a4 == -1 )
    {
      v15 = (MiPageToNode((a1 - MmPfnDatabase) / 24, 0) << byte_6337F5) | dword_633814 & v14;
      v16 = 32;
    }
    else
    {
      v15 = a4 & ~dword_633814 | dword_633814 & v14;
      v16 = 16;
    }
    v17 = MiGetPage(&MiSystemPartition, v15, v16);
    v18 = v17;
    if ( v17 != -1 )
    {
      v19 = MmPfnDatabase + 24 * v17;
      v20 = KfRaiseIrql(2);
      v21 = v20;
      v22 = (unsigned __int8 *)(a1 + 15);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 | 0x80, v22) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v23 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v29 = *v11;
          __dmb(0xBu);
        }
        while ( v29 < 0 );
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 | 0x80, v22) );
      }
      if ( v19 != a1 )
      {
        v24 = *(_BYTE *)(a1 + 18) & 7;
        if ( v24 < 2 || v24 > 4 )
        {
          v26 = 2;
        }
        else
        {
          if ( !*(_WORD *)(a1 + 16) )
          {
            MiReplaceTransitionPage(a1, v19, a3);
            goto LABEL_18;
          }
          v26 = 0;
        }
        __dmb(0xBu);
        do
          v30 = __ldrex(v11);
        while ( __strex(v30 & 0x7FFFFFFF, v11) );
        KfLowerIrql(v20);
        MiReleaseFreshPage(v19);
        return v26;
      }
      v18 = -1;
LABEL_18:
      *(_DWORD *)(a1 + 8) = 128;
      __dmb(0xBu);
      do
        v25 = __ldrex(v11);
      while ( __strex(v25 & 0x7FFFFFFF, v11) );
      KfLowerIrql(v21);
      if ( a5 )
        *a5 = v18;
      return 3;
    }
  }
  return 1;
}
