// PpmParkApplyPolicy 
 
void PpmParkApplyPolicy()
{
  int *v0; // r2
  int v1; // r9
  unsigned int v2; // r8
  signed int v3; // r7
  unsigned __int8 v4; // r5
  int v5; // r10
  unsigned __int8 v6; // r3
  int v7; // r4
  unsigned int v8; // r2
  int v9; // lr
  int v10; // r1
  unsigned __int8 *v11; // r6
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r10
  unsigned int i; // r8
  int v17; // lr
  int v18; // r4
  int v19; // r4
  unsigned int v20; // r2
  unsigned int v21; // r1
  unsigned __int8 *v22; // r3
  unsigned int v23; // r3
  int v24; // r3
  unsigned __int16 j; // r5
  int v26; // r4
  int v27; // r0
  unsigned __int8 v28; // r3
  unsigned int v29; // r3
  unsigned int v30; // r3
  unsigned int v31; // r3
  unsigned __int8 v32; // r3
  unsigned int v33; // r3
  unsigned int v34; // r3
  unsigned int v35; // r2
  int v36; // r1
  unsigned int v37; // r3
  unsigned int v38; // r2
  int v39; // r1
  unsigned int v40; // r3
  char v41; // r2
  char v42; // [sp+0h] [bp-50h] BYREF
  char v43; // [sp+1h] [bp-4Fh]
  char v44[2]; // [sp+2h] [bp-4Eh] BYREF
  int v45; // [sp+4h] [bp-4Ch]
  unsigned int v46; // [sp+8h] [bp-48h]
  unsigned int v47; // [sp+Ch] [bp-44h]
  int v48; // [sp+10h] [bp-40h]
  unsigned int v49; // [sp+14h] [bp-3Ch]
  int v50; // [sp+18h] [bp-38h]
  int v51; // [sp+1Ch] [bp-34h]
  unsigned int v52; // [sp+20h] [bp-30h]
  int v53; // [sp+24h] [bp-2Ch]
  int v54; // [sp+28h] [bp-28h]
  int v55; // [sp+2Ch] [bp-24h]
  int v56; // [sp+30h] [bp-20h]

  if ( PpmParkNodes )
  {
    v0 = &PpmCurrentProfile[44 * dword_61EC0C];
    v42 = *((_BYTE *)v0 + 120);
    v43 = *((_BYTE *)v0 + 121);
    v44[0] = *((_BYTE *)v0 + 122);
    v44[1] = *((_BYTE *)v0 + 123);
    if ( (dword_6174A8 & 1) != 0 )
    {
      v46 = 32;
    }
    else
    {
      v28 = PpmParkInitialClass1UnParkCount;
      if ( (unsigned int)PpmParkInitialClass1UnParkCount > 0x20 )
        v28 = 32;
      v46 = v28;
      v43 = 0;
    }
    v1 = PpmParkLpiCap;
    v2 = PpmParkNumNodes;
    v52 = PpmParkNumNodes;
    if ( !PpmParkNumNodes )
      __brkdiv0();
    v3 = (unsigned __int8)PpmParkGranularity;
    if ( !PpmParkGranularity )
      __brkdiv0();
    v4 = PpmParkLpiCap / (unsigned int)PpmParkNumNodes
       - PpmParkLpiCap / (unsigned int)PpmParkNumNodes % (unsigned __int8)PpmParkGranularity;
    v5 = PpmParkThermalCap;
    if ( !PpmParkNumNodes )
      __brkdiv0();
    if ( !PpmParkGranularity )
      __brkdiv0();
    v6 = PpmParkThermalCap / (unsigned int)PpmParkNumNodes
       - PpmParkThermalCap / (unsigned int)PpmParkNumNodes % (unsigned __int8)PpmParkGranularity;
    v7 = PpmParkNodes;
    v8 = 0;
    v45 = PpmParkNodes;
    if ( PpmParkNumNodes )
    {
      v9 = v6;
      v10 = v4;
      v49 = 0;
      v50 = v4;
      v55 = PpmHeteroPolicy;
      v56 = v6;
      while ( 1 )
      {
        v11 = (unsigned __int8 *)(v7 + 88 * v8);
        v12 = v11[6];
        if ( v50 > v12 - v3 )
        {
          sub_529858();
          return;
        }
        v11[70] = v10;
        v53 = v1 - v10;
        v13 = v9;
        if ( v9 > v12 - v3 )
          v13 = (unsigned __int8)(v12 - v3);
        v14 = 0;
        v54 = v5 - v13;
        v15 = v46;
        v11[72] = v13;
        v48 = 0;
        for ( i = 0; i < 2; ++i )
        {
          v17 = v11[i + 64];
          v51 = v17;
          if ( v17 )
          {
            if ( !v3 )
              __brkdiv0();
            v18 = (unsigned __int8)((int)((unsigned __int64)(1374389535i64 * ((unsigned __int8)v44[i] * v17 + 50)) >> 32) >> 5);
            v47 = (unsigned __int8)((v17 - v18) % v3 + v18);
            v19 = (unsigned __int8)((int)((unsigned __int64)(1374389535i64 * ((unsigned __int8)*(&v42 + i) * v17 + 50)) >> 32) >> 5);
            v20 = (unsigned __int8)((v17 - v19) % v3 + v19);
            if ( i )
            {
              v29 = v47;
              if ( v47 >= v15 )
                v29 = v15;
              v21 = v29;
            }
            else
            {
              v21 = v47;
            }
            if ( (unsigned __int8)((v17 - v19) % v3) + (_BYTE)v19 )
            {
              if ( v3 > v20 )
                LOBYTE(v20) = v3;
              v20 = (unsigned __int8)v20;
            }
            if ( v21 < v20 )
              LOBYTE(v21) = v20;
            v14 = (unsigned __int8)(v48 + v20);
            v22 = &v11[i];
            v22[68] = v21;
            v22[66] = v20;
            v48 = v14;
          }
        }
        v2 = v52;
        v1 = v53;
        v5 = v54;
        if ( !v14 )
        {
          v23 = v11[68];
          v11[66] = v3;
          if ( (unsigned __int8)v3 > v23 )
            LOBYTE(v23) = v3;
          v11[68] = v23;
        }
        if ( v55 == 2 )
        {
          v30 = v11[66];
          v11[75] = 0;
          if ( v30 <= 1 )
            LOBYTE(v30) = 1;
          v11[66] = v30;
          v31 = v11[68];
          if ( v31 <= 1 )
            LOBYTE(v31) = 1;
          v11[68] = v31;
          v11[67] = 0;
          v11[69] = 0;
          v32 = v11[82] | 4;
        }
        else
        {
          if ( v55 != 3 || !v11[65] )
            goto LABEL_38;
          v33 = v11[67];
          v11[74] = 0;
          v11[66] = 0;
          v11[68] = 0;
          if ( v33 <= 1 )
            LOBYTE(v33) = 1;
          v11[67] = v33;
          v34 = v11[69];
          if ( v34 <= 1 )
            LOBYTE(v34) = 1;
          v11[69] = v34;
          v32 = v11[82] | 2;
        }
        v11[82] = v32;
LABEL_38:
        v10 = v50;
        v7 = v45;
        v9 = v56;
        v8 = (unsigned __int16)(v49 + 1);
        v49 = v8;
        if ( v8 >= v2 )
          goto LABEL_39;
      }
    }
    do
    {
LABEL_39:
      if ( !v1 )
        goto LABEL_40;
      v35 = 0;
    }
    while ( !v2 );
    while ( v1 )
    {
      v36 = v7 + 88 * v35;
      if ( *(_BYTE *)(v36 + 6) )
      {
        v37 = (unsigned __int8)(*(_BYTE *)(v36 + 70) + v3);
        if ( v37 < *(unsigned __int8 *)(v36 + 6) )
        {
          *(_BYTE *)(v36 + 70) = v37;
          v1 -= v3;
        }
      }
      v35 = (unsigned __int16)(v35 + 1);
      if ( v35 >= v2 )
        goto LABEL_39;
    }
LABEL_40:
    while ( v5 )
    {
      v38 = 0;
      if ( v2 )
      {
        while ( v5 )
        {
          v39 = v7 + 88 * v38;
          if ( *(_BYTE *)(v39 + 6) )
          {
            v40 = (unsigned __int8)(*(_BYTE *)(v39 + 72) + v3);
            if ( v40 < *(unsigned __int8 *)(v39 + 6) )
            {
              *(_BYTE *)(v39 + 72) = v40;
              v5 -= v3;
            }
          }
          v38 = (unsigned __int16)(v38 + 1);
          if ( v38 >= v2 )
            goto LABEL_40;
        }
        break;
      }
    }
    v24 = 0;
    if ( v2 )
    {
      for ( j = 0; j < v2; v24 = ++j )
      {
        v26 = v7 + 88 * v24;
        v27 = *(unsigned __int8 *)(v26 + 6);
        if ( *(unsigned __int8 *)(v26 + 71) == v27 - *(unsigned __int8 *)(v26 + 70)
          && *(unsigned __int8 *)(v26 + 73) == v27 - *(unsigned __int8 *)(v26 + 72) )
        {
          v7 = v45;
        }
        else
        {
          PpmEventParkNodeCapChange(*(unsigned __int16 *)(v26 + 4), *(_DWORD *)(v26 + 8));
          v41 = *(_BYTE *)(v26 + 6);
          v2 = PpmParkNumNodes;
          *(_BYTE *)(v26 + 71) = v41 - *(_BYTE *)(v26 + 70);
          *(_BYTE *)(v26 + 73) = v41 - *(_BYTE *)(v26 + 72);
          v7 = PpmParkNodes;
          v45 = PpmParkNodes;
        }
      }
    }
  }
}
