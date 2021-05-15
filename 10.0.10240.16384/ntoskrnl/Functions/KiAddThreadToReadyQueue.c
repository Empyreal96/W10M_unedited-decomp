// KiAddThreadToReadyQueue 
 
void __fastcall KiAddThreadToReadyQueue(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v6; // r5
  int v8; // r0
  int v9; // r2
  int v10; // r3
  int *v11; // r2
  int *v12; // r1
  int v13; // r4
  unsigned int *v14; // r5
  unsigned int *v15; // r1
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r7
  unsigned int **v19; // r6
  _DWORD *v20; // r1
  _DWORD *v21; // r2
  _DWORD *v22; // r4

  v6 = a2;
  if ( a4 )
  {
    if ( !a2 )
    {
      v6 = *(_DWORD *)(a3 + 68);
      if ( v6 )
        v6 += a1[588];
    }
    __dmb(0xBu);
    *(_BYTE *)(a3 + 132) = 1;
    if ( v6 && (*(_DWORD *)(a3 + 80) & 0x600) == 0 && KiGetThreadEffectiveRankNonZero(a3, v6, 0) )
    {
      KiAddThreadToScbQueue((int)a1, v6, a3, a5);
    }
    else
    {
      v8 = *(char *)(a3 + 123);
      v9 = a1[864];
      if ( (*(_DWORD *)(a3 + 80) & 0x1000) != 0 && v9 && (*(_DWORD *)(a3 + 356) & v9) == v9 )
      {
        v14 = (unsigned int *)a1[865];
        v15 = &v14[2 * v8 + 2];
        while ( 1 )
        {
          do
            v16 = __ldrex(v14);
          while ( __strex(1u, v14) );
          __dmb(0xBu);
          if ( !v16 )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( *v14 );
        }
        v17 = (unsigned int *)(a3 + 144);
        if ( a5 )
        {
          v18 = *v15;
          *v17 = *v15;
          *(_DWORD *)(a3 + 148) = v15;
          if ( *(unsigned int **)(v18 + 4) != v15 )
            __fastfail(3u);
          *(_DWORD *)(v18 + 4) = v17;
          *v15 = (unsigned int)v17;
          *((_BYTE *)a1 + (v8 >> 3) + 1936) &= ~(1 << (v8 & 7));
        }
        else
        {
          v19 = (unsigned int **)v15[1];
          *v17 = (unsigned int)v15;
          *(_DWORD *)(a3 + 148) = v19;
          if ( *v19 != v15 )
            __fastfail(3u);
          *v19 = v17;
          v15[1] = (unsigned int)v17;
        }
        v14[1] |= 1 << v8;
        *(_DWORD *)(a3 + 328) |= 0x80000000;
        __dmb(0xBu);
        *v14 = 0;
      }
      else
      {
        v10 = v8 + 256;
        if ( a5 )
        {
          v11 = &a1[2 * v10];
          v12 = (int *)(a3 + 144);
          v13 = *v11;
          *v12 = *v11;
          v12[1] = (int)v11;
          if ( *(int **)(v13 + 4) != v11 )
            __fastfail(3u);
          *(_DWORD *)(v13 + 4) = v12;
          *v11 = (int)v12;
          *((_BYTE *)a1 + (v8 >> 3) + 1936) |= 1 << (v8 & 7);
        }
        else
        {
          v20 = &a1[2 * v10];
          v21 = (_DWORD *)(a3 + 144);
          v22 = (_DWORD *)v20[1];
          *v21 = v20;
          v21[1] = v22;
          if ( (_DWORD *)*v22 != v20 )
            __fastfail(3u);
          *v22 = v21;
          v20[1] = v21;
        }
        a1[483] |= 1 << v8;
      }
    }
  }
  else
  {
    sub_50FDA0();
  }
}
