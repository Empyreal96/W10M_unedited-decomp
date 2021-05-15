// sub_53A1E0 
 
void __fastcall sub_53A1E0(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r4
  unsigned int *v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r2
  int v10; // r3
  unsigned int v11; // r4
  unsigned int v12; // r2
  int i; // r3
  int v14; // r4
  unsigned __int8 *v15; // r1
  int v16; // r3
  int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r2

  if ( v6 && (a4 & 0x80000) == 0 )
    v6 = 0;
  if ( (*(_WORD *)(v5 + 2) & 3u) <= 1 )
  {
    v9 = *(_DWORD *)(v7 + 4);
    v10 = *(_DWORD *)(v7 + 20);
    v11 = v9 | 0x80000000;
    if ( (v10 & 0x8000000) == 0 && (v10 & 0x7000000) == 50331648 )
    {
      if ( !v6 )
        goto LABEL_39;
      if ( v9 )
      {
        v12 = v11 << 10;
        *v6 = v11 << 10;
        i = dword_63389C;
        if ( v11 << 10 < dword_63389C )
        {
          if ( v8 )
          {
            v14 = 17;
          }
          else
          {
            v14 = KfRaiseIrql(2);
            v15 = (unsigned __int8 *)(v7 + 15);
            do
              v12 = __ldrex(v15);
            while ( __strex(v12 | 0x80, v15) );
            __dmb(0xBu);
            for ( i = v12 >> 7; v12 >> 7; i = v12 >> 7 )
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v16 = *(_DWORD *)(v7 + 12);
                __dmb(0xBu);
              }
              while ( (v16 & 0x80000000) != 0 );
              do
                v12 = __ldrex(v15);
              while ( __strex(v12 | 0x80, v15) );
              __dmb(0xBu);
            }
          }
          v17 = MiGetTopLevelPfn(v7, 0, v12, i);
          __dmb(0xBu);
          v18 = (unsigned int *)(v17 + 12);
          do
            v19 = __ldrex(v18);
          while ( __strex(v19 & 0x7FFFFFFF, v18) );
          if ( !v8 )
          {
            __dmb(0xBu);
            v20 = (unsigned int *)(v7 + 12);
            do
              v21 = __ldrex(v20);
            while ( __strex(v21 & 0x7FFFFFFF, v20) );
            KfLowerIrql(v14);
          }
          goto LABEL_38;
        }
      }
      else
      {
        *v6 = 0;
      }
      v6[1] = 0;
      goto LABEL_39;
    }
    if ( MiIsStrongCodeImagePage(v7, &a5, v9) )
    {
      if ( !a5 )
        goto LABEL_39;
      v22 = a5[1];
      if ( v11 >= v22 && v11 < v22 + 4 * a5[7] )
      {
        if ( v6 )
        {
          v23 = *a5;
          v6[1] = *(_DWORD *)(*(_DWORD *)(*a5 + 56) + 8);
          *v6 = ((v11 - *(_DWORD *)(v23 + 84)) << 10) & 0xFFFFF000;
        }
LABEL_39:
        JUMPOUT(0x499C4E);
      }
    }
  }
  else if ( (*(_BYTE *)(v7 + 23) & 7) == 3 && MiCanPageMove(v7) )
  {
    goto LABEL_39;
  }
LABEL_38:
  JUMPOUT(0x499C4C);
}
