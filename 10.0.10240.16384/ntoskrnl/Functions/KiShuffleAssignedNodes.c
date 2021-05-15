// KiShuffleAssignedNodes 
 
int __fastcall KiShuffleAssignedNodes(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // lr
  int v6; // r1
  unsigned int v7; // r3
  int result; // r0
  int v9; // r6
  unsigned int v10; // r10
  unsigned int v11; // r7
  int v12; // r2
  int v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r9
  int v16; // r5
  int v17; // r3
  int v18; // r2
  int v19; // r1
  unsigned int v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r4
  int v23; // r1
  unsigned int v24; // r1
  unsigned int v25; // r10
  unsigned int v26; // r3
  unsigned int v27; // r4
  int v28; // r1
  unsigned int v29; // r1
  unsigned int v30; // r5
  unsigned int v31; // r3
  unsigned int v32; // r4
  int v33; // r2
  int v34; // r1
  unsigned int v35; // r1
  unsigned int v36; // r3
  unsigned int v37; // r4
  int v38; // r1
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r4
  int v42; // r5
  int v43; // r0
  int v44; // r1
  unsigned int v46; // [sp+4h] [bp-64h]
  unsigned int v47; // [sp+4h] [bp-64h]
  int *v49; // [sp+Ch] [bp-5Ch]
  int v50; // [sp+10h] [bp-58h]
  int v51; // [sp+14h] [bp-54h]
  unsigned int v52; // [sp+18h] [bp-50h]
  int v53; // [sp+1Ch] [bp-4Ch]
  unsigned int v55; // [sp+24h] [bp-44h]
  unsigned int v56; // [sp+28h] [bp-40h]
  int v57; // [sp+2Ch] [bp-3Ch]
  int v58; // [sp+30h] [bp-38h]
  unsigned int v59; // [sp+34h] [bp-34h]
  int v60; // [sp+38h] [bp-30h]
  unsigned int v61; // [sp+3Ch] [bp-2Ch]
  int v62; // [sp+40h] [bp-28h]
  int v63; // [sp+44h] [bp-24h]

  v4 = a3;
  v49 = KeNodeDistance;
  v6 = a1;
  v7 = 0;
  v50 = (unsigned __int16)KeNumberNodes;
  v61 = 0;
  result = 2;
  do
  {
    v9 = 0;
    v57 = 0;
    v10 = 0;
    v55 = 0;
    if ( a2 )
    {
      v11 = 0;
      v59 = 0;
      while ( 1 )
      {
        v12 = *(_DWORD *)(v6 + 4 * v10);
        v51 = v12;
        if ( (*(_BYTE *)(v12 + 289) & 2) == 0 )
          goto LABEL_56;
        v13 = 16;
        v14 = 0;
        v56 = 0;
        v52 = 0;
        v53 = 16;
        v60 = 0;
        v15 = 0;
        do
        {
          v16 = *(_DWORD *)(v6 + 4 * v14);
          v62 = v16;
          if ( (*(_BYTE *)(v16 + 289) & 2) != 0 && v11 != v15 )
          {
            v17 = *(unsigned __int16 *)(v12 + 264);
            v63 = *(unsigned __int16 *)(v16 + 264);
            v58 = v17;
            if ( v17 != v63 )
            {
              v18 = *(unsigned __int8 *)(v12 + 288);
              if ( v11 >= v15 )
              {
                v19 = v17;
                v20 = *(unsigned __int8 *)(v16 + 288) - v18;
              }
              else
              {
                v19 = *(unsigned __int16 *)(v16 + 264);
                v20 = v18 - *(unsigned __int8 *)(v16 + 288);
              }
              if ( *(_DWORD *)(v4 + 4 * v19) < v20 )
                goto LABEL_49;
              v21 = 0;
              v46 = 0;
              v22 = 0;
              do
              {
                if ( v22 != v11 )
                {
                  v23 = *(_DWORD *)(a1 + 4 * v21);
                  if ( *(unsigned __int16 *)(v23 + 264) == v58 && (*(_BYTE *)(v23 + 289) & 2) != 0 )
                  {
                    v24 = v49[*(unsigned __int16 *)(v23 + 266)
                            + *(unsigned __int16 *)(*(_DWORD *)(a1 + 4 * v10) + 266) * v50];
                    if ( *(_WORD *)(a4 + 2 * v58) == 1 )
                      __brkdiv0();
                    v46 += v24 / ((unsigned int)*(unsigned __int16 *)(a4 + 2 * v58) - 1);
                  }
                }
                v21 = (unsigned __int16)(v22 + 1);
                v22 = v21;
              }
              while ( v21 < a2 );
              v25 = v46;
              v26 = 0;
              v27 = 0;
              do
              {
                if ( v27 != v52 )
                {
                  v28 = *(_DWORD *)(a1 + 4 * v26);
                  if ( *(unsigned __int16 *)(v28 + 264) == v63 && (*(_BYTE *)(v28 + 289) & 2) != 0 )
                  {
                    v29 = v49[*(unsigned __int16 *)(v28 + 266) + *(unsigned __int16 *)(v16 + 266) * v50];
                    if ( *(_WORD *)(a4 + 2 * v63) == 1 )
                      __brkdiv0();
                    v25 += v29 / ((unsigned int)*(unsigned __int16 *)(a4 + 2 * v63) - 1);
                  }
                }
                v26 = (unsigned __int16)(v27 + 1);
                v27 = v26;
              }
              while ( v26 < a2 );
              v11 = v59;
              v47 = v25;
              v30 = 0;
              v31 = 0;
              v32 = 0;
              do
              {
                v33 = a1;
                if ( v32 != v52 )
                {
                  v34 = *(_DWORD *)(a1 + 4 * v31);
                  if ( *(unsigned __int16 *)(v34 + 264) == v63 && (*(_BYTE *)(v34 + 289) & 2) != 0 )
                  {
                    v35 = v49[*(unsigned __int16 *)(v34 + 266)
                            + *(unsigned __int16 *)(*(_DWORD *)(a1 + 4 * v55) + 266) * v50];
                    if ( *(_WORD *)(a4 + 2 * v63) == 1 )
                      __brkdiv0();
                    v33 = a1;
                    v30 += v35 / ((unsigned int)*(unsigned __int16 *)(a4 + 2 * v63) - 1);
                  }
                }
                v31 = (unsigned __int16)(v32 + 1);
                v32 = v31;
              }
              while ( v31 < a2 );
              v36 = 0;
              v37 = 0;
              do
              {
                if ( v37 != v59 )
                {
                  v38 = *(_DWORD *)(v33 + 4 * v36);
                  if ( *(unsigned __int16 *)(v38 + 264) == v58 && (*(_BYTE *)(v38 + 289) & 2) != 0 )
                  {
                    v39 = v49[*(unsigned __int16 *)(v38 + 266) + *(unsigned __int16 *)(v62 + 266) * v50];
                    if ( *(_WORD *)(a4 + 2 * v58) == 1 )
                      __brkdiv0();
                    v30 += v39 / ((unsigned int)*(unsigned __int16 *)(a4 + 2 * v58) - 1);
                  }
                }
                v36 = (unsigned __int16)(v37 + 1);
                v33 = a1;
                v37 = v36;
              }
              while ( v36 < a2 );
              LOWORD(v15) = v52;
              v4 = a3;
              v10 = v55;
              if ( v30 >= v47 )
              {
                v13 = v53;
LABEL_49:
                v6 = a1;
                v12 = v51;
                goto LABEL_50;
              }
              v6 = a1;
              v12 = v51;
              if ( v56 >= v47 - v30 )
              {
                v13 = v53;
              }
              else
              {
                v13 = v60;
                v56 = v47 - v30;
                v53 = v60;
              }
            }
          }
LABEL_50:
          v14 = (unsigned __int16)(v15 + 1);
          v60 = v14;
          v15 = v14;
          v52 = v14;
        }
        while ( v14 < a2 );
        if ( v13 == 16 )
        {
          v9 = v57;
        }
        else
        {
          v40 = *(_DWORD *)(v6 + 4 * v13);
          v41 = *(unsigned __int16 *)(v12 + 264);
          v9 = 1;
          v42 = *(unsigned __int16 *)(v40 + 264);
          v57 = 1;
          *(_WORD *)(v12 + 264) = v42;
          *(_WORD *)(v40 + 264) = v41;
          v43 = *(unsigned __int8 *)(v12 + 288);
          v44 = *(unsigned __int8 *)(v40 + 288);
          *(_DWORD *)(v4 + 4 * v41) += v44 - v43;
          *(_DWORD *)(v4 + 4 * v42) += v43 - v44;
        }
        result = 2;
LABEL_56:
        v10 = (unsigned __int16)(v11 + 1);
        v11 = v10;
        v6 = a1;
        v59 = v10;
        v55 = v10;
        if ( v10 >= a2 )
        {
          v7 = v61;
          break;
        }
      }
    }
    v61 = ++v7;
  }
  while ( v9 && v7 < 0xA );
  return result;
}
