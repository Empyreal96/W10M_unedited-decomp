// RtlpCombineAcls 
 
int __fastcall RtlpCombineAcls(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 *a4, unsigned __int8 *a5, unsigned int *a6, _DWORD *a7)
{
  unsigned int v8; // r5
  unsigned __int8 *v9; // r10
  unsigned __int8 *v10; // lr
  unsigned int v12; // r8
  unsigned int v13; // r2
  unsigned int v14; // r0
  unsigned __int8 *i; // r1
  unsigned int v16; // r3
  unsigned int v17; // r6
  int v18; // r0
  int v19; // r8
  unsigned int v20; // r1
  unsigned int v21; // r0
  int v22; // r9
  unsigned int v23; // r2
  unsigned int v24; // r7
  int n; // r6
  int result; // r0
  unsigned int v27; // r0
  unsigned __int8 *v28; // r1
  unsigned int v29; // r10
  unsigned __int8 *m; // r6
  unsigned int v31; // r0
  unsigned __int8 *j; // r1
  unsigned int v33; // r0
  unsigned __int8 *k; // r1
  unsigned int v35; // r0
  unsigned __int8 *l; // r1
  unsigned int v37; // r6
  int ii; // r4
  unsigned int v39; // r6
  int jj; // r4
  unsigned int v41; // r6
  int kk; // r4
  unsigned int v43; // lr
  unsigned int v44; // r2
  unsigned __int8 *v45; // [sp+0h] [bp-28h]
  unsigned __int8 *v46; // [sp+4h] [bp-24h]

  v45 = a4;
  v46 = a3;
  v8 = 0;
  v9 = a4;
  v10 = a3;
  v12 = 2;
  if ( a2 || a1 || a3 || a4 || a5 )
  {
    v13 = 8;
    if ( a1 )
    {
      v27 = 0;
      v28 = (unsigned __int8 *)(a1 + 8);
      if ( *(_WORD *)(a1 + 4) )
      {
        do
        {
          if ( *v28 <= 0x10u )
          {
            v43 = *v28 - 2;
            if ( v43 <= 0xE )
              __asm { ADD             PC, R3 }
          }
          ++v27;
          v28 += *((unsigned __int16 *)v28 + 1);
        }
        while ( v27 < *(unsigned __int16 *)(a1 + 4) );
        v10 = v46;
      }
    }
    if ( a2 )
    {
      v14 = 0;
      for ( i = a2 + 8; v14 < *((unsigned __int16 *)a2 + 2); i += *((unsigned __int16 *)i + 1) )
      {
        if ( *i == 17 )
        {
          if ( *((unsigned __int16 *)i + 1) + v13 < v13 )
            goto LABEL_84;
          v13 += *((unsigned __int16 *)i + 1);
          if ( a7 )
            *a7 |= 0x10u;
          if ( *a2 > v12 )
            v12 = *a2;
        }
        ++v14;
      }
    }
    if ( a5 )
    {
      v31 = 0;
      for ( j = a5 + 8; v31 < *((unsigned __int16 *)a5 + 2); j += *((unsigned __int16 *)j + 1) )
      {
        if ( *j == 20 )
        {
          if ( *((unsigned __int16 *)j + 1) + v13 < v13 )
            goto LABEL_84;
          v13 += *((unsigned __int16 *)j + 1);
          if ( a7 )
            *a7 |= 0x80u;
          if ( *a5 > v12 )
            v12 = *a5;
        }
        ++v31;
      }
    }
    if ( v10 )
    {
      v33 = 0;
      for ( k = v10 + 8; v33 < *((unsigned __int16 *)v10 + 2); k += *((unsigned __int16 *)k + 1) )
      {
        if ( *k == 18 )
        {
          if ( *((unsigned __int16 *)k + 1) + v13 < v13 )
            goto LABEL_84;
          v13 += *((unsigned __int16 *)k + 1);
          if ( a7 )
            *a7 |= 0x20u;
          if ( *v10 > v12 )
            v12 = *v10;
        }
        ++v33;
      }
    }
    if ( a4 )
    {
      v35 = 0;
      for ( l = a4 + 8; v35 < *((unsigned __int16 *)a4 + 2); l += *((unsigned __int16 *)l + 1) )
      {
        if ( *l == 19 )
        {
          if ( *((unsigned __int16 *)l + 1) + v13 < v13 )
            goto LABEL_84;
          v13 += *((unsigned __int16 *)l + 1);
          if ( a7 )
            *a7 |= 0x40u;
          if ( *a4 > v12 )
            v12 = *a4;
        }
        ++v35;
      }
    }
    v16 = v13 + 3;
    if ( v13 + 3 < v13 )
    {
LABEL_84:
      v19 = -1073741675;
    }
    else
    {
      v17 = v16 & 0xFFFFFFFC;
      v18 = ExAllocatePoolWithTag(1, v16 & 0xFFFFFFFC, 1683187027);
      v8 = v18;
      if ( v18 )
      {
        if ( v17 < 8 )
        {
          v19 = -1073741789;
        }
        else
        {
          if ( v12 - 2 > 2 )
          {
            v19 = -1073741811;
LABEL_21:
            if ( v19 >= 0 )
            {
              v20 = *(unsigned __int16 *)(v18 + 4);
              v21 = 0;
              v22 = 0;
              v23 = v8 + 8;
              if ( !*(_WORD *)(v8 + 4) )
              {
LABEL_23:
                if ( v23 <= *(unsigned __int16 *)(v8 + 2) + v8 )
                  v22 = v23;
                if ( a1 )
                {
                  v29 = 0;
                  for ( m = (unsigned __int8 *)(a1 + 8);
                        v29 < *(unsigned __int16 *)(a1 + 4);
                        m += *((unsigned __int16 *)m + 1) )
                  {
                    if ( *m <= 0x10u )
                    {
                      v44 = *m - 2;
                      if ( v44 <= 0xE )
                        __asm { ADD             PC, R3 }
                    }
                    ++v29;
                  }
                  v9 = v45;
                }
                if ( a2 )
                {
                  v24 = 0;
                  for ( n = (int)(a2 + 8); v24 < *((unsigned __int16 *)a2 + 2); n += *(unsigned __int16 *)(n + 2) )
                  {
                    if ( *(_BYTE *)n == 17 )
                    {
                      memmove(v22, n, *(unsigned __int16 *)(n + 2));
                      ++*(_WORD *)(v8 + 4);
                      v22 += *(unsigned __int16 *)(n + 2);
                    }
                    ++v24;
                  }
                }
                if ( a5 )
                {
                  v37 = 0;
                  for ( ii = (int)(a5 + 8); v37 < *((unsigned __int16 *)a5 + 2); ii += *(unsigned __int16 *)(ii + 2) )
                  {
                    if ( *(_BYTE *)ii == 20 )
                    {
                      memmove(v22, ii, *(unsigned __int16 *)(ii + 2));
                      ++*(_WORD *)(v8 + 4);
                      v22 += *(unsigned __int16 *)(ii + 2);
                    }
                    ++v37;
                  }
                }
                if ( v46 )
                {
                  v39 = 0;
                  for ( jj = (int)(v46 + 8); v39 < *((unsigned __int16 *)v46 + 2); jj += *(unsigned __int16 *)(jj + 2) )
                  {
                    if ( *(_BYTE *)jj == 18 )
                    {
                      memmove(v22, jj, *(unsigned __int16 *)(jj + 2));
                      ++*(_WORD *)(v8 + 4);
                      v22 += *(unsigned __int16 *)(jj + 2);
                    }
                    ++v39;
                  }
                }
                if ( v9 )
                {
                  v41 = 0;
                  for ( kk = (int)(v9 + 8); v41 < *((unsigned __int16 *)v9 + 2); kk += *(unsigned __int16 *)(kk + 2) )
                  {
                    if ( *(_BYTE *)kk == 19 )
                    {
                      memmove(v22, kk, *(unsigned __int16 *)(kk + 2));
                      ++*(_WORD *)(v8 + 4);
                      v22 += *(unsigned __int16 *)(kk + 2);
                    }
                    ++v41;
                  }
                }
                goto LABEL_34;
              }
              while ( v23 < *(unsigned __int16 *)(v8 + 2) + v8 )
              {
                ++v21;
                v23 += *(unsigned __int16 *)(v23 + 2);
                if ( v21 >= v20 )
                  goto LABEL_23;
              }
              v19 = -1073741699;
            }
            goto LABEL_97;
          }
          if ( v17 <= 0xFFFC )
          {
            *(_BYTE *)v18 = v12;
            *(_WORD *)(v18 + 2) = v17 & 0xFFFC;
            *(_BYTE *)(v18 + 1) = 0;
            *(_WORD *)(v18 + 4) = 0;
            *(_WORD *)(v18 + 6) = 0;
            v19 = 0;
            goto LABEL_21;
          }
          v19 = -1073741811;
        }
LABEL_97:
        ExFreePoolWithTag(v8);
        v8 = 0;
        goto LABEL_34;
      }
      v19 = -1073741801;
    }
LABEL_34:
    result = v19;
    *a6 = v8;
    return result;
  }
  result = 0;
  *a6 = 0;
  return result;
}
