// KiPerformGroupConfiguration 
 
int __fastcall KiPerformGroupConfiguration(int a1)
{
  int v1; // r6
  unsigned int v2; // r4
  int v3; // r5
  unsigned int v4; // r8
  unsigned __int16 v5; // r9
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r1
  int result; // r0
  int v10; // r5
  unsigned __int16 v11; // r9
  int v12; // r8
  unsigned __int16 i; // r9
  _DWORD *v14; // r5
  int v15; // r5
  int v16; // r0
  int v17; // r3
  unsigned __int16 j; // r1
  int v19; // r2
  int v20; // r3
  int v21; // t1
  int v22; // r3
  int v23; // r1
  unsigned __int16 v24; // r0
  int v25; // r2
  unsigned int v26; // r6
  int v27; // r2
  unsigned int v28; // r1
  int v29; // r2
  int v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r2
  __int16 v33; // r2
  int v34; // r1
  int v35; // r3
  unsigned __int16 k; // r1
  unsigned int v37; // r6
  unsigned int v38; // r5
  unsigned int v39; // r2
  int v40; // r10
  int *v41; // lr
  unsigned int v42; // r4
  unsigned int v43; // r3
  unsigned int v44; // r1
  int v45; // r2
  int v46; // r1
  unsigned __int16 l; // r4
  unsigned int v48; // r1
  unsigned int v49; // r6
  unsigned int v50; // r4
  unsigned __int16 v51; // r7
  int v52; // r3
  int v53; // r2
  unsigned int v54; // r4
  unsigned int v55; // r0
  unsigned __int16 v56; // r1
  int v57; // r2
  int v58; // [sp+8h] [bp-80h] BYREF
  int v59; // [sp+Ch] [bp-7Ch] BYREF
  unsigned int v60; // [sp+10h] [bp-78h]
  unsigned int v61; // [sp+14h] [bp-74h]
  unsigned int v62; // [sp+18h] [bp-70h]
  int v63; // [sp+1Ch] [bp-6Ch] BYREF
  int v64; // [sp+20h] [bp-68h] BYREF
  int v65; // [sp+24h] [bp-64h] BYREF
  _DWORD v66[24]; // [sp+28h] [bp-60h] BYREF

  v1 = 0;
  v2 = (unsigned __int16)KeNumberNodes;
  v3 = 0;
  v59 = a1;
  v60 = 0;
  v62 = 0;
  v4 = 0;
  v58 = 0;
  v5 = 0;
  if ( KeNumberNodes )
  {
    do
    {
      v6 = ((int (__fastcall *)(int, _DWORD *))KiQueryNodeCapacity)(v3, &v64);
      v7 = v62;
      v8 = (int)*(&KeNodeBlock + v3);
      *(_BYTE *)(v8 + 288) = v64;
      v62 = v7 + v64;
      if ( v64 )
        v4 = (unsigned __int16)(v4 + 1);
      if ( !PnpQueryProximityId )
        return sub_966584(v6);
      ((void (__fastcall *)(int, int, int *))PnpQueryProximityId)(v3, v8 + 276, &v63);
      PnpQueryProximityNode(v63, (char *)*(&KeNodeBlock + v3) + 268);
      if ( *((_DWORD *)*(&KeNodeBlock + v3) + 69) == v63 )
        ++v1;
      v2 = (unsigned __int16)KeNumberNodes;
      v3 = ++v5;
    }
    while ( v5 < (unsigned int)(unsigned __int16)KeNumberNodes );
    v58 = v1;
    v60 = v4;
  }
  if ( v2 > 1 )
  {
    KeNodeDistance = (int *)ExAllocatePoolWithTag(512, 4 * v2 * v2, 538993995);
    if ( !KeNodeDistance )
      KeBugCheckEx(50, -1073741670, 0, 0, 0);
    v2 = (unsigned __int16)KeNumberNodes;
  }
  v10 = 0;
  if ( v2 )
  {
    v11 = 0;
    v61 = 0;
    do
    {
      v12 = 0;
      if ( v2 )
      {
        for ( i = 0; i < v2; v12 = ++i )
        {
          KiQueryNodeDistance(v10, v12, &v65);
          v2 = (unsigned __int16)KeNumberNodes;
          KeNodeDistance[v12 + (unsigned __int16)KeNumberNodes * v10] = v65;
        }
        v11 = v61;
      }
      v10 = ++v11;
      v61 = v11;
    }
    while ( v11 < v2 );
    v1 = v58;
    v4 = v60;
  }
  result = 2;
  v14 = *(_DWORD **)(*(_DWORD *)(v59 + 132) + 120);
  if ( v14 && v1 == *v14 )
  {
    v17 = 0;
    if ( v2 )
    {
      for ( j = 0; j < v2; v17 = ++j )
      {
        v19 = (int)*(&KeNodeBlock + v17);
        *(_WORD *)(v19 + 264) = -1;
        *(_BYTE *)(v19 + 289) &= 0xFDu;
      }
    }
    if ( v1 )
    {
      while ( 1 )
      {
        --v1;
        if ( PnpQueryProximityNode(v14[1], &v58) )
          break;
        v21 = v14[2];
        v14 += 2;
        v20 = v21;
        if ( v21 )
        {
          if ( v20 != 0xFFFF )
            break;
        }
        v2 = (unsigned __int16)KeNumberNodes;
        v22 = 0;
        if ( KeNumberNodes )
        {
          v23 = (unsigned __int16)v58;
          v24 = 0;
          do
          {
            v25 = (int)*(&KeNodeBlock + v22);
            if ( *(unsigned __int16 *)(v25 + 268) == v23 )
            {
              *(_WORD *)(v25 + 264) = *v14;
              *(_BYTE *)(v25 + 289) |= 2u;
              v23 = (unsigned __int16)v58;
            }
            v22 = ++v24;
          }
          while ( v24 < v2 );
        }
        if ( !v1 )
        {
          result = 2;
          goto LABEL_44;
        }
      }
    }
    else
    {
LABEL_44:
      if ( *((unsigned __int16 *)KeNodeBlock + 132) != 0xFFFF )
      {
        v26 = KiMaximumGroupSize;
        v27 = 0;
        do
        {
          *(&v60 + v27) = v26;
          v27 = (unsigned __int16)(v27 + 1);
        }
        while ( !v27 );
        v28 = 0;
        if ( !v2 )
        {
LABEL_54:
          v33 = 0;
          KiMaximumGroups = 0;
          v34 = 0;
          do
          {
            if ( *(&v60 + v34) < v26 )
              KiMaximumGroups = ++v33;
            v34 = (unsigned __int16)(v34 + 1);
          }
          while ( !v34 );
          v35 = 0;
          if ( v2 )
          {
            for ( k = 0; k < v2; v35 = ++k )
              *((_BYTE *)*(&KeNodeBlock + v35) + 289) |= 8u;
          }
          return result;
        }
        while ( 1 )
        {
          v29 = (int)*(&KeNodeBlock + v28);
          if ( (*(_BYTE *)(v29 + 289) & 2) == 0 )
            break;
          v30 = *(unsigned __int16 *)(v29 + 264);
          if ( v30 == 0xFFFF )
          {
            *(_BYTE *)(v29 + 289) &= 0xFDu;
          }
          else
          {
            v31 = *(unsigned __int8 *)(v29 + 288);
            v32 = *(&v60 + v30);
            if ( v32 < v31 )
              break;
            *(&v60 + v30) = v32 - v31;
          }
          v28 = (unsigned __int16)(v28 + 1);
          result = 2;
          if ( v28 >= v2 )
            goto LABEL_54;
        }
      }
    }
  }
  v15 = v59;
  if ( strstr(*(_BYTE **)(v59 + 120), "MAXGROUP=OFF") )
  {
    v16 = 0;
LABEL_64:
    KiMaximizeGroupsCreated = v16;
    goto LABEL_23;
  }
  if ( strstr(*(_BYTE **)(v15 + 120), "MAXGROUP") )
  {
    v16 = 1;
    goto LABEL_64;
  }
  v16 = (unsigned __int8)KiMaximizeGroupsCreated;
LABEL_23:
  if ( v4 == 1 )
    return KiAssignAllNodesToGroup0(v16);
  v37 = KiMaximumGroupSize;
  v61 = KiMaximumGroupSize;
  if ( !v16 && v62 <= KiMaximumGroupSize )
    return KiAssignAllNodesToGroup0(v16);
  v38 = (unsigned __int16)KeNumberNodes;
  v39 = 0;
  v40 = 0;
  if ( KeNumberNodes )
  {
    v41 = KeNodeDistance;
    v42 = 0;
    do
    {
      v43 = 0;
      if ( v38 )
      {
        v44 = 0;
        while ( v42 == v44 || v41[v43 + v38 * v39] == 0xFFFF )
        {
          v43 = (unsigned __int16)(v44 + 1);
          v44 = v43;
          if ( v43 >= v38 )
            goto LABEL_75;
        }
        v45 = (int)*(&KeNodeBlock + v39);
        *(_BYTE *)(v45 + 289) |= 8u;
        v40 += *(unsigned __int8 *)(v45 + 288);
      }
LABEL_75:
      v39 = (unsigned __int16)(v42 + 1);
      v42 = v39;
    }
    while ( v39 < v38 );
  }
  v46 = 0;
  if ( v38 )
  {
    for ( l = 0; l < v38; v46 = ++l )
      v66[v46] = *(&KeNodeBlock + v46);
  }
  LOWORD(v48) = 0;
  if ( (int)(v38 - 1) > 0 )
  {
    v49 = 0;
    do
    {
      v48 = (unsigned __int16)(v48 + 1);
      v50 = v48;
      v51 = v48;
      if ( v48 < v38 )
      {
        do
        {
          v52 = v66[v50];
          v59 = v66[v49];
          v60 = v52;
          if ( *(unsigned __int8 *)(v59 + 288) < (unsigned int)*(unsigned __int8 *)(v52 + 288) )
          {
            v53 = v59;
            v66[v49] = v60;
            v66[v50] = v53;
          }
          v50 = ++v51;
        }
        while ( v51 < v38 );
      }
      v49 = v48;
    }
    while ( (int)v48 < (int)(v38 - 1) );
    v37 = v61;
  }
  if ( v40 )
  {
    if ( v16 )
    {
      v54 = v4;
    }
    else
    {
      if ( !v37 )
        __brkdiv0();
      v54 = (unsigned __int16)((v37 + v40 - 1) / v37);
    }
  }
  else
  {
    v54 = 1;
  }
  if ( v54 > 1 )
    v54 = 1;
  while ( v54 <= 1 && !KiAssignFixedNodes(v66, v4, v54, v54 == 1, &v59, &v58) )
    v54 = (unsigned __int16)(v54 + 1);
  KiShuffleAssignedNodes(v66, v4, &v59, &v58);
  v55 = KiAssignAdjustableNodes(v66, v4);
  if ( v54 <= v55 )
    LOWORD(v54) = v55;
  KiMaximumGroups = v54;
  result = *((unsigned __int16 *)KeNodeBlock + 132);
  if ( v4 < v38 )
  {
    v56 = v4;
    do
    {
      v57 = v66[v4];
      *(_WORD *)(v57 + 264) = result;
      *(_BYTE *)(v57 + 289) |= 2u;
      v4 = ++v56;
    }
    while ( v56 < v38 );
  }
  return result;
}
