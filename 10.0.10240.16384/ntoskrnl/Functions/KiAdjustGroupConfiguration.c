// KiAdjustGroupConfiguration 
 
unsigned int __fastcall KiAdjustGroupConfiguration(unsigned int result)
{
  char v1; // r3
  int v2; // r7
  unsigned int v3; // r6
  unsigned int v4; // r10
  unsigned int v5; // r9
  int v6; // lr
  int v7; // r1
  unsigned __int16 v8; // r0
  unsigned int v9; // r5
  int v10; // r3
  unsigned __int16 v11; // r4
  int v12; // r2
  unsigned int v13; // r4
  int v14; // r1
  unsigned int v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // r2
  unsigned __int16 i; // r1
  int v20; // r3
  unsigned __int16 j; // r4
  int v22; // r2
  __int16 v23; // r2
  char v24; // r3
  int v25; // r3
  unsigned __int16 k; // r1
  int v27; // r2
  unsigned int v28; // r1
  unsigned int v29; // r5
  unsigned int v30; // r4
  unsigned __int16 v31; // lr
  int v32; // r9
  int v33; // r10
  int v34; // r2
  unsigned __int16 l; // r1
  unsigned int v36; // r5
  int v37; // lr
  int v38; // r1
  unsigned __int16 m; // r4
  unsigned int v40; // r1
  unsigned int v41; // r3
  unsigned int v42; // r4
  int v43; // r2
  unsigned int v44; // r1
  unsigned int v45; // r6
  int v46; // r2
  unsigned __int16 n; // r4
  int v48; // r1
  int v49; // [sp+0h] [bp-78h]
  int v50; // [sp+4h] [bp-74h]
  char v51[4]; // [sp+8h] [bp-70h]
  unsigned int v52; // [sp+Ch] [bp-6Ch]
  unsigned int v53; // [sp+10h] [bp-68h]
  _DWORD v54[24]; // [sp+18h] [bp-60h]

  v49 = 0;
  v1 = *(_BYTE *)(result + 289);
  v2 = result;
  v50 = result;
  if ( (v1 & 8) == 0 && !*(_DWORD *)(result + 260) )
  {
    v3 = *(unsigned __int16 *)(result + 264);
    v4 = (unsigned __int16)KiActiveGroups;
    v52 = (unsigned __int16)KiActiveGroups;
    if ( v3 >= (unsigned __int16)KiActiveGroups )
    {
      v5 = (unsigned __int16)KiMaximumGroups;
      v6 = KiMaximumGroupSize;
      v7 = 0;
      v53 = (unsigned __int16)KiMaximumGroups;
      if ( KiMaximumGroups )
      {
        v8 = 0;
        do
        {
          *(&v49 + v7) = v6;
          v7 = ++v8;
        }
        while ( v8 < v5 );
      }
      v9 = (unsigned __int16)KeNumberNodes;
      v10 = 0;
      if ( KeNumberNodes )
      {
        v11 = 0;
        do
        {
          v12 = (int)*(&KeNodeBlock + v10);
          if ( (*(_BYTE *)(v12 + 289) & 2) != 0 )
            *(&v49 + *(unsigned __int16 *)(v12 + 264)) -= *(unsigned __int8 *)(v12 + 288);
          v10 = ++v11;
        }
        while ( v11 < v9 );
      }
      v13 = 0;
      if ( v9 )
      {
        while ( 1 )
        {
          v14 = (int)*(&KeNodeBlock + v13);
          if ( (*(_BYTE *)(v14 + 289) & 2) != 0 && (*(_BYTE *)(v14 + 289) & 8) == 0 && !*(_DWORD *)(v14 + 260) )
          {
            result = *(unsigned __int16 *)(v14 + 264);
            if ( result < v4 )
            {
              v15 = *(unsigned __int8 *)(v14 + 288);
              v16 = *(unsigned __int8 *)(v2 + 288);
              if ( v15 <= v16 )
              {
                v17 = v16 - v15;
              }
              else
              {
                result = *(unsigned __int16 *)(v2 + 264);
                v17 = v15 - v16;
              }
              if ( *(&v49 + result) >= v17 )
                break;
            }
          }
          v13 = (unsigned __int16)(v13 + 1);
          if ( v13 >= v9 )
            goto LABEL_22;
        }
        v23 = *(_WORD *)(v14 + 264);
        *(_WORD *)(v14 + 264) = v3;
        *(_BYTE *)(v14 + 289) &= 0xFBu;
        v24 = *(_BYTE *)(v2 + 289);
        *(_WORD *)(v2 + 264) = v23;
        *(_BYTE *)(v2 + 289) = v24 | 4;
      }
      else
      {
LABEL_22:
        v18 = 0;
        if ( v5 )
        {
          for ( i = 0; i < v5; v18 = ++i )
            *(_DWORD *)&v51[4 * v18] = v6;
        }
        v20 = 0;
        if ( v9 )
        {
          for ( j = 0; j < v9; v20 = ++j )
          {
            v22 = (int)*(&KeNodeBlock + v20);
            if ( (*(_BYTE *)(v22 + 289) & 2) != 0 && ((*(_BYTE *)(v22 + 289) & 8) != 0 || *(_DWORD *)(v22 + 260)) )
              *(_DWORD *)&v51[4 * *(unsigned __int16 *)(v22 + 264)] -= *(unsigned __int8 *)(v22 + 288);
          }
        }
        result = 0;
        v25 = 0;
        if ( v9 )
        {
          for ( k = 0; k < v9; v25 = ++k )
          {
            v27 = (int)*(&KeNodeBlock + v25);
            if ( (*(_BYTE *)(v27 + 289) & 2) != 0 && (*(_BYTE *)(v27 + 289) & 8) == 0 && !*(_DWORD *)(v27 + 260) )
            {
              v54[result] = v27;
              result = (unsigned __int16)(result + 1);
            }
          }
        }
        LOWORD(v28) = 0;
        if ( (int)(result - 1) > 0 )
        {
          v29 = 0;
          do
          {
            v28 = (unsigned __int16)(v28 + 1);
            v30 = v28;
            v31 = v28;
            if ( v28 < result )
            {
              do
              {
                v32 = v54[v30];
                v33 = v54[v29];
                if ( *(unsigned __int8 *)(v33 + 288) < (unsigned int)*(unsigned __int8 *)(v32 + 288) )
                {
                  v54[v29] = v32;
                  v54[v30] = v33;
                }
                v30 = ++v31;
              }
              while ( v31 < result );
            }
            v29 = v28;
          }
          while ( (int)v28 < (int)(result - 1) );
          v2 = v50;
          v4 = v52;
          v5 = v53;
        }
        v34 = 0;
        if ( result )
        {
          for ( l = 0; l < result; v34 = ++l )
            *(_WORD *)(v54[v34] + 266) = *(_WORD *)(v54[v34] + 264);
        }
        v36 = 0;
        v37 = 0;
        if ( v4 )
        {
          while ( 1 )
          {
            v38 = 0;
            if ( v5 )
            {
              for ( m = 0; m < v5; v38 = ++m )
                *(&v49 + v38) = *(_DWORD *)&v51[4 * v38];
            }
            v40 = *(&v49 + v36);
            v41 = *(unsigned __int8 *)(v2 + 288);
            if ( v40 >= v41 )
            {
              v42 = 0;
              *(&v49 + v36) = v40 - v41;
              for ( *(_WORD *)(v2 + 264) = v36; v42 < result; v42 = (unsigned __int16)(v42 + 1) )
              {
                v43 = v54[v42];
                if ( v43 != v2 )
                {
                  v44 = 0;
                  if ( v5 )
                  {
                    while ( 1 )
                    {
                      v45 = *(&v49 + v44);
                      if ( v45 >= *(unsigned __int8 *)(v43 + 288) )
                        break;
                      v44 = (unsigned __int16)(v44 + 1);
                      if ( v44 >= v5 )
                        goto LABEL_64;
                    }
                    *(_WORD *)(v43 + 264) = v44;
                    *(&v49 + v44) = v45 - *(unsigned __int8 *)(v43 + 288);
LABEL_64:
                    v2 = v50;
                  }
                  if ( v44 == v5 )
                    break;
                }
              }
              if ( v42 == result )
                break;
            }
            v36 = (unsigned __int16)(v36 + 1);
            if ( v36 >= v4 )
              goto LABEL_71;
          }
          v37 = 1;
        }
LABEL_71:
        v46 = 0;
        if ( result )
        {
          for ( n = 0; n < result; v46 = ++n )
          {
            v48 = v54[v46];
            if ( v37 )
              *(_BYTE *)(v48 + 289) ^= (*(_BYTE *)(v48 + 289) ^ (4 * (*(unsigned __int16 *)(v48 + 264) < v4))) & 4;
            else
              *(_WORD *)(v48 + 264) = *(_WORD *)(v48 + 266);
            *(_WORD *)(v48 + 266) = 0;
          }
        }
      }
    }
  }
  return result;
}
