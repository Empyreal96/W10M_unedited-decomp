// PopPepAttemptAcitivityPromotion 
 
int __fastcall PopPepAttemptAcitivityPromotion(int result, int a2, int a3, int a4, unsigned int *a5)
{
  int v8; // r4
  int v9; // r7
  int v10; // r9
  int v11; // r1
  char *v12; // r6
  int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r6
  int v17; // r8
  int *v18; // r3
  int v19; // r1
  int i; // r2
  unsigned int v21; // r1
  unsigned int v22; // r1

  v8 = *(_DWORD *)&ActivityAttributes[124 * a4 + 8];
  v9 = result;
  if ( v8 )
  {
    v10 = *(unsigned __int8 *)(a3 + 16);
    if ( *(_BYTE *)(a3 + 16) )
    {
      result = sub_5401FC();
    }
    else
    {
      v11 = 0;
      v12 = (char *)&dword_403120[31 * a4 + 2] - result;
      v13 = result;
      while ( 1 )
      {
        result = *(_DWORD *)&v12[v13];
        if ( result )
        {
          if ( (**(_DWORD **)(v13 + 48) & result) != 0 )
            break;
        }
        ++v11;
        v13 += 4;
        if ( v11 > 0 )
        {
          if ( v8 == 2 )
          {
            v14 = *(_DWORD *)(a2 + 8);
            v15 = v14;
            v16 = v14;
          }
          else if ( v8 == 3 )
          {
            v15 = 0;
            v16 = 0;
            v14 = *(_DWORD *)(v9 + 120) - 1;
          }
          else
          {
            v15 = *(_DWORD *)(v9 + 120);
            v14 = 0;
            v16 = v15;
            if ( v15 )
            {
LABEL_13:
              if ( v10 )
                v18 = &dword_403138[2];
              else
                v18 = &dword_403120[2];
              v19 = 4;
              for ( i = v9 + 16; ; i += 4 )
              {
                result = *(int *)((char *)&v18[31 * a4] + i - v9);
                if ( result )
                {
                  if ( (**(_DWORD **)(i + 48) & result) != 0 )
                    break;
                }
                if ( ++v19 > 5 )
                {
                  result = 2;
                  *(_DWORD *)a3 = *(_DWORD *)a3 & 0xFFFFFFFC | 2;
                  *(_DWORD *)(a3 + 8) = *(_DWORD *)(a3 + 4);
                  __dmb(0xBu);
                  do
                    v21 = __ldrex(a5);
                  while ( __strex(v21 + 1, a5) );
                  __dmb(0xBu);
                  return result;
                }
              }
              return result;
            }
          }
          v17 = v9 + 168 * v15 + 176;
          while ( 1 )
          {
            result = PopPepShouldActivityWait(v17, a4, 1, 3, v10);
            if ( result == 1 )
              return result;
            ++v16;
            v17 += 168;
            if ( v16 > v14 )
              goto LABEL_13;
          }
        }
      }
    }
  }
  else
  {
    *(_DWORD *)a3 = *(_DWORD *)a3 & 0xFFFFFFFC | 2;
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(a3 + 4);
    __dmb(0xBu);
    do
      v22 = __ldrex(a5);
    while ( __strex(v22 + 1, a5) );
    __dmb(0xBu);
  }
  return result;
}
