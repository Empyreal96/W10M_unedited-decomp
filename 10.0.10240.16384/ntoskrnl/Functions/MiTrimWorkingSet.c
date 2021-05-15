// MiTrimWorkingSet 
 
int __fastcall MiTrimWorkingSet(int a1, unsigned int *a2, int a3, unsigned int a4, char a5)
{
  unsigned int v6; // r4
  unsigned int v8; // r8
  _DWORD *v9; // r7
  int v10; // r9
  int v11; // r3
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r2
  int v18; // r4
  unsigned int v19; // r5
  unsigned int v20; // r10
  int v21; // lr
  int v22; // r0
  int v23; // r10
  int v24; // r9
  int v25; // r3
  int v26; // r8
  unsigned int v27; // r8
  _DWORD *v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r2
  int v32; // r3
  int v33; // r10
  unsigned int v34; // r9
  int v35; // r1
  unsigned __int8 *v36; // r3
  unsigned int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r1
  unsigned int v40; // r3
  unsigned int v41; // r3
  unsigned int v42; // r2
  unsigned int v43; // r2
  unsigned int v44; // r3
  unsigned int v45; // r10
  unsigned int v46; // r5
  unsigned int v47; // r2
  unsigned int v48; // r4
  unsigned int v49; // r0
  int v50; // r1
  unsigned int v52; // [sp+0h] [bp-108h]
  int v53; // [sp+4h] [bp-104h]
  int v54; // [sp+8h] [bp-100h]
  unsigned int v55; // [sp+Ch] [bp-FCh]
  unsigned int v56; // [sp+10h] [bp-F8h]
  unsigned int v57; // [sp+14h] [bp-F4h]
  unsigned int v58; // [sp+18h] [bp-F0h]
  unsigned int v59; // [sp+1Ch] [bp-ECh] BYREF
  int v60; // [sp+20h] [bp-E8h]
  int v61; // [sp+24h] [bp-E4h]
  unsigned int v62; // [sp+28h] [bp-E0h]
  unsigned int v63; // [sp+2Ch] [bp-DCh]
  unsigned int v64; // [sp+30h] [bp-D8h]
  int v65; // [sp+34h] [bp-D4h]
  int v66; // [sp+38h] [bp-D0h]
  int v67; // [sp+3Ch] [bp-CCh]
  int v68; // [sp+40h] [bp-C8h]
  int v69; // [sp+44h] [bp-C4h]
  unsigned int v70; // [sp+48h] [bp-C0h]
  unsigned int v71; // [sp+4Ch] [bp-BCh]
  int v72; // [sp+50h] [bp-B8h]
  unsigned int v73; // [sp+54h] [bp-B4h]
  int v74; // [sp+58h] [bp-B0h]
  int v75; // [sp+5Ch] [bp-ACh]
  unsigned int v76[42]; // [sp+60h] [bp-A8h] BYREF

  v65 = a3;
  v6 = a4 & 0xF;
  v72 = dword_6404B8;
  v70 = a4;
  v75 = a1;
  v66 = a1;
  if ( (a5 & 2) != 0 )
    v6 |= 0x20u;
  if ( (a5 & 4) != 0 )
    v6 |= 0x40u;
  v67 = (a5 & 8) != 0;
  v8 = 0;
  v52 = 0;
  v76[0] = 0;
  if ( dword_634484 )
    v6 |= 0x10u;
  v9 = (_DWORD *)a2[23];
  v10 = a1;
  v53 = a1;
  v11 = v9[9];
  v68 = 0;
  v12 = 0;
  v13 = v6 & 0xF;
  v56 = 0;
  v58 = v13;
  v71 = a4;
  if ( v11 == 16 )
  {
    v14 = v6 & 0xFFFFFFF0 | 7;
    v13 = 2 * (v14 & 0xF) + 1;
    v71 = 2 * a4;
    v15 = v9[v13 + 15];
    v58 = v13;
    v6 = v14 | 0x100;
  }
  else
  {
    v16 = a2[15];
    v17 = v9[1];
    if ( v16 <= v17 )
      return 0;
    v15 = v16 - v17;
  }
  v19 = v9[3];
  v55 = v15;
  v73 = v9[2];
  if ( v19 > v73 || v19 < v9[1] )
    v19 = v9[1];
  v20 = 0xFFFFF;
  v69 = 0;
  v63 = 0xFFFFF;
  v64 = v19;
  v62 = 0xFFFFF;
LABEL_16:
  v54 = 0;
  v59 = v20;
  v60 = 0;
  v57 = v20;
  v6 |= 0x80u;
  if ( v10 )
  {
    v21 = (int)&v9[v13];
    v61 = v21;
    while ( (v6 & 0x100) != 0 )
    {
      if ( v12 >= v15 )
      {
        v19 = v20;
      }
      else
      {
        v56 = v12 + 1;
        v22 = MiRotateHeadWsle(v9, v13);
        v21 = v61;
        v13 = v58;
        v19 = v22;
      }
      if ( v19 != v20 )
        goto LABEL_28;
      if ( v13 > v71 )
      {
        if ( (v13 & 1) == 0 )
          v6 = v6 & 0xFFFFFFF0 | (v6 - 1) & 0xF;
        v21 -= 4;
        v15 = *(_DWORD *)(v21 + 60);
        --v13;
        v12 = 0;
        v55 = v15;
        v56 = 0;
        v58 = v13;
        v61 = v21;
LABEL_101:
        if ( v10 )
          continue;
      }
      goto LABEL_102;
    }
    v63 = v19 + 1;
    v56 = v12 + 1;
LABEL_28:
    v74 = 32;
    while ( 1 )
    {
      v23 = v9[63];
      ++v68;
      v24 = v9[9] * v19;
      v25 = v65;
      v26 = *(_DWORD *)(v24 + v23);
      if ( v65 != 17 )
      {
        if ( (++v69, (v69 & 0xF) == 0) && ExSpinLockIsContended(a2) || KeShouldYieldProcessor() )
        {
          v25 = 1;
          v60 = 1;
        }
      }
      if ( (v26 & 1) == 0 || MiTrimThisWsle((int)a2, v19, v6, v25) != 1 )
        break;
      v27 = *(_DWORD *)(v24 + v23);
      if ( MiAddWsleToTrimList(v76, v19, v6, &v59) != 1 )
        goto LABEL_48;
      if ( (v6 & 0x10) != 0 )
      {
        v28 = (_DWORD *)(((v27 >> 10) & 0x3FFFFC) - 0x40000000);
        if ( (*v28 & 0x10) != 0 && (v27 & 0xE00) != 3584 )
          MiLogPageAccess(a2, v28);
      }
      v8 = v76[0];
      v29 = v53 - 1;
      v30 = v74 - 1;
      v52 = v76[0];
      --v53;
      --v74;
      if ( v76[0] == 32 || !v30 || !v29 )
      {
        v31 = v59;
        v32 = 1;
        v54 = 1;
        v57 = v59;
        goto LABEL_51;
      }
      v19 = MiIsNextVaTrimCandidate((int)a2, v76, v76[0] - 1, v6);
      if ( v19 == v62 || v60 )
      {
LABEL_48:
        v8 = v76[0];
        v31 = v59;
        v52 = v76[0];
        v57 = v59;
LABEL_50:
        v32 = v54;
LABEL_51:
        v33 = v60;
        if ( v60 == 1 )
        {
          v32 = 1;
          v54 = 1;
        }
        if ( v32 )
          goto LABEL_59;
        if ( (v6 & 0x80) == 0 )
          goto LABEL_62;
        v34 = v62;
        if ( v31 == v62 )
          goto LABEL_62;
        v6 &= 0xFFFFFF7F;
        v19 = MiIsNextVaTrimCandidate((int)a2, v76, v31, v6);
        if ( v19 == v34 )
        {
          v8 = v76[0];
          v32 = v54;
          v52 = v76[0];
LABEL_59:
          if ( v32 == 1 )
          {
            v54 = 0;
            if ( v8 )
            {
              v8 = 0;
              v52 = 0;
              v10 = v53 + MiFreeWsleList((int)a2, v76, v67);
              v53 = v10;
              v76[0] = 0;
              goto LABEL_63;
            }
          }
LABEL_62:
          v10 = v53;
LABEL_63:
          if ( v33 == 1 )
          {
            v60 = 0;
            v9[3] = v19;
            if ( (a5 & 1) != 0 )
            {
              v35 = v66;
              *(_DWORD *)(v72 + 4 * v70 + 1360) = *(_DWORD *)(v72 + 4 * v70 + 1360) - v10 + v66;
              a2[26] = a2[26] - v10 + v35;
            }
            MiUnlockWorkingSetExclusive((int)a2, v65);
            v66 = v10;
            v65 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2);
            }
            else
            {
              v36 = (unsigned __int8 *)a2 + 3;
              do
                v37 = __ldrex(v36);
              while ( __strex(v37 | 0x80, v36) );
              __dmb(0xBu);
              if ( v37 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire(a2);
              while ( 1 )
              {
                v38 = *a2;
                if ( (*a2 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (v38 & 0x40000000) == 0 )
                {
                  do
                    v39 = __ldrex(a2);
                  while ( v39 == v38 && __strex(v38 | 0x40000000, a2) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
              v8 = v52;
            }
            if ( (v6 & 0x100) != 0 )
            {
              v40 = *(_DWORD *)(v61 + 60);
            }
            else
            {
              v41 = a2[15];
              v42 = v9[1];
              if ( v41 > v42 )
                v40 = v41 - v42;
              else
                v40 = 0;
            }
            if ( v40 < v55 )
              v55 = v40;
            v19 = v9[3];
            v43 = v9[2];
            v73 = v43;
            if ( v19 > v43 || (v44 = v9[1], v19 < v44) )
            {
              v44 = v9[1];
              v19 = v44;
            }
            if ( v64 > v43 || v64 < v44 )
              v64 = v44;
            v45 = v19;
            v63 = v19;
          }
          else
          {
            v45 = v63;
            v43 = v73;
          }
          if ( ((v6 >> 8) & 1) != 0 )
          {
            v15 = v55;
            v12 = v56;
            goto LABEL_100;
          }
          v19 = v45;
          if ( v45 > v43 )
            v19 = v9[1];
          v15 = v55;
          v12 = v56;
          if ( v56 < v55 )
          {
LABEL_100:
            v21 = v61;
            v20 = v62;
            v13 = v58;
            v6 |= 0x80u;
            v57 = v62;
            v59 = v62;
            goto LABEL_101;
          }
LABEL_102:
          if ( v8 )
          {
            v10 += MiFreeWsleList((int)a2, v76, v67);
            v53 = v10;
            if ( v10 )
            {
              if ( v19 != v64 )
              {
                v8 = 0;
                v20 = v62;
                v13 = v58;
                v15 = v55;
                v12 = v56;
                v52 = 0;
                v76[0] = 0;
                goto LABEL_16;
              }
            }
          }
          goto LABEL_106;
        }
        v52 = v76[0];
      }
      else
      {
        v52 = v76[0];
        v57 = v59;
      }
    }
    v8 = v52;
    v31 = v57;
    goto LABEL_50;
  }
LABEL_106:
  v9[3] = v19;
  v46 = v9[4];
  v47 = a2[15];
  v48 = v46 - v47 + 1;
  if ( v9[1] == v47 )
    goto LABEL_111;
  v49 = v9[9];
  if ( !v49 )
    __brkdiv0();
  if ( v48 >= 0x4000 / v49 && v48 >= v46 >> 3 )
LABEL_111:
    MiRemoveWorkingSetPages((int)a2);
  if ( (a5 & 1) != 0 )
  {
    v50 = v66;
    *(_DWORD *)(v72 + 4 * v70 + 1360) = *(_DWORD *)(v72 + 4 * v70 + 1360) - v10 + v66;
    a2[26] = a2[26] - v10 + v50;
  }
  v18 = v75 - v10;
  MiLogTrimWs((int)a2, v68, v75 - v10);
  return v18;
}
