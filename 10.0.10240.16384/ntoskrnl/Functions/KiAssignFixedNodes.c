// KiAssignFixedNodes 
 
int __fastcall KiAssignFixedNodes(int a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6)
{
  unsigned int v6; // r8
  int v7; // r1
  int v8; // r7
  int v9; // r9
  int v10; // r5
  int v11; // r3
  unsigned __int16 i; // r1
  int v13; // r2
  unsigned int v14; // r0
  int v15; // r2
  int v16; // r2
  unsigned int v17; // r5
  int v18; // r1
  int v19; // r4
  unsigned __int16 v20; // r7
  int v21; // r2
  int v22; // r2
  int v23; // r1
  int v24; // r2
  int v27; // [sp+4h] [bp-2Ch]
  int v29; // [sp+Ch] [bp-24h]

  v6 = a2;
  v29 = a1;
  v7 = KiMaximumGroupSize;
  v8 = a5;
  v27 = KiMaximumGroupSize;
  v9 = a1;
  v10 = 0;
  do
  {
    v11 = 0;
    *(_WORD *)(a6 + 2 * v10) = 0;
    *(_DWORD *)(a5 + 4 * v10) = v7;
    v10 = (unsigned __int16)(v10 + 1);
  }
  while ( !v10 );
  if ( v6 )
  {
    for ( i = 0; i < v6; v11 = ++i )
    {
      v13 = *(_DWORD *)(a1 + 4 * v11);
      *(_WORD *)(v13 + 264) = -1;
      *(_BYTE *)(v13 + 289) &= 0xFDu;
    }
    v7 = v27;
  }
  v14 = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      v15 = *(_DWORD *)(v9 + 4 * v14);
      if ( (*(_BYTE *)(v15 + 289) & 8) != 0 )
      {
        if ( v14 >= a3 )
        {
          v17 = v7;
          v18 = 0;
          v19 = 1;
          if ( !a3 )
            goto LABEL_21;
          v20 = 0;
          do
          {
            if ( *(_DWORD *)(a5 + 4 * v18) >= (unsigned int)*(unsigned __int8 *)(*(_DWORD *)(v9 + 4 * v14) + 288)
              && *(unsigned __int16 *)(a6 + 2 * v18) < v17 )
            {
              v17 = *(unsigned __int16 *)(a6 + 2 * v18);
              v19 = v18;
            }
            v18 = ++v20;
          }
          while ( v20 < a3 );
          v6 = a2;
          v9 = v29;
          v8 = a5;
          if ( v19 == 1 )
          {
LABEL_21:
            if ( !a4 )
              return 0;
            if ( !*(_WORD *)(v15 + 266) )
            {
              if ( (*(_BYTE *)(v15 + 289) & 2) == 0 )
              {
                do
                  v14 = (unsigned __int16)(v14 - 1);
                while ( (*(_BYTE *)(*(_DWORD *)(v9 + 4 * v14) + 289) & 2) == 0 );
              }
              v22 = *(_DWORD *)(v9 + 4 * v14);
              v23 = *(unsigned __int16 *)(v22 + 264);
              *(_WORD *)(v22 + 264) = -1;
              *(_BYTE *)(v22 + 289) &= 0xFDu;
              v24 = *(unsigned __int8 *)(v22 + 288);
              --*(_WORD *)(a6 + 2 * v23);
              *(_DWORD *)(v8 + 4 * v23) += v24;
            }
          }
          else
          {
            *(_WORD *)(v15 + 264) = v19;
            *(_BYTE *)(v15 + 289) |= 2u;
            v21 = *(unsigned __int8 *)(v15 + 288);
            ++*(_WORD *)(a6 + 2 * v19);
            *(_DWORD *)(a5 + 4 * v19) -= v21;
          }
        }
        else
        {
          *(_WORD *)(v15 + 264) = v14;
          *(_BYTE *)(v15 + 289) |= 2u;
          v16 = *(unsigned __int8 *)(v15 + 288);
          ++*(_WORD *)(a6 + 2 * v14);
          *(_DWORD *)(v8 + 4 * v14) -= v16;
        }
      }
      v14 = (unsigned __int16)(v14 + 1);
      if ( v14 >= v6 )
        return 1;
      v7 = v27;
    }
  }
  return 1;
}
