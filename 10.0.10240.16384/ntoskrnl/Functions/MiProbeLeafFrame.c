// MiProbeLeafFrame 
 
int __fastcall MiProbeLeafFrame(int a1)
{
  unsigned int v2; // r7
  unsigned int v3; // r10
  int v4; // r8
  int v5; // r2
  unsigned int *v6; // r0
  unsigned int *v7; // t1
  unsigned int v8; // r3
  unsigned int v9; // r1
  int v10; // r7
  int v11; // r4
  int v12; // r5
  int v13; // r2
  int result; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r0
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r2
  int v20; // r2
  int v21; // r0
  int v22; // r4
  bool v23; // zf
  int v24; // r0
  int v25; // r4
  int v26; // r0
  int v27; // r3
  int v28; // r2
  unsigned int v29; // [sp+Ch] [bp-5Ch]
  unsigned int v30; // [sp+10h] [bp-58h] BYREF
  unsigned int v31; // [sp+14h] [bp-54h] BYREF
  _DWORD v32[2]; // [sp+18h] [bp-50h] BYREF
  char v33; // [sp+20h] [bp-48h]
  char v34[3]; // [sp+21h] [bp-47h] BYREF
  _DWORD *v35; // [sp+24h] [bp-44h]
  int v36; // [sp+28h] [bp-40h]
  int v37; // [sp+2Ch] [bp-3Ch]
  int v38; // [sp+30h] [bp-38h]

  v2 = *(_DWORD *)a1;
  v4 = *(_DWORD *)(a1 + 20);
  v29 = *(_DWORD *)a1;
  v30 = ((*(_DWORD *)a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = v30;
  v31 = ((v30 >> 10) & 0x3FFFFC) - 0x40000000;
  while ( 1 )
  {
    v5 = 1;
    v6 = &v31;
    do
    {
      v7 = (unsigned int *)*v6--;
      v8 = *v7;
      if ( (*v7 & 2) == 0 )
        goto LABEL_23;
      --v5;
    }
    while ( v5 );
    if ( (v8 & 0x400) != 0 )
    {
      if ( v4 && (v8 & 0x80) == 0 )
      {
        v27 = 1619;
        v28 = dword_6343CC;
        result = -1073741819;
        goto LABEL_72;
      }
      v11 = ((v2 >> 12) & 0x3FF) + (v8 >> 12);
LABEL_20:
      *(_DWORD *)(a1 + 52) = v11;
      return 0;
    }
    v9 = *(_DWORD *)v3;
    if ( (*(_DWORD *)v3 & 2) == 0 )
      goto LABEL_23;
    v10 = *(_DWORD *)(a1 + 28);
    if ( (v9 & 0x20) == 0 && v10 == 1 )
      break;
    v11 = v9 >> 12;
    if ( v9 >> 12 > dword_633850
      || dword_634C9C && ((*(_DWORD *)(dword_634C9C + 4 * (v9 >> 17)) >> (v11 & 0x1F)) & 1) == 0 )
    {
      v12 = 0;
    }
    else
    {
      v12 = MmPfnDatabase + 24 * v11;
    }
    if ( v4 )
    {
      if ( (v9 & 0x80) != 0 )
      {
        if ( (v9 & 0x200) == 0 || v10 != 1 || (*(_DWORD *)(*(_DWORD *)(a1 + 40) + 192) & 0x8000) == 0 )
        {
          v2 = v29;
          goto LABEL_16;
        }
        MiUnlockProbePacketWorkingSet(a1);
        v2 = v29;
        v25 = MmAccessFault(1, v29, 0, 0);
        MiLockProbePacketWorkingSet(a1);
        if ( v25 < 0 )
        {
          v27 = 1618;
          v28 = dword_6343C8;
          result = v25;
          goto LABEL_72;
        }
      }
      else if ( v10 == 5 )
      {
        v15 = dword_63389C;
        v2 = v29;
        if ( v29 < dword_63389C
          || *((_BYTE *)&MiState[2423]
             + ((int)(((v29 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 12 )
        {
          goto LABEL_24;
        }
        if ( v12 && (*(_DWORD *)(v12 + 20) & 0x8000000) == 0 )
        {
          if ( (MiFlags & 0x80000) != 0 && (*(_BYTE *)(v12 + 23) & 7) == 3 )
            MiClearPfnImageVerified(v12, 8, 9692, 3);
          goto LABEL_20;
        }
LABEL_77:
        if ( *(_BYTE *)(a1 + 32) != 1 )
          JUMPOUT(0x545172);
        if ( !MiCopyOnWriteEx(v2, v3, -1, *(unsigned __int8 *)(a1 + 44), 0) && *(_BYTE *)(a1 + 44) == 2 )
        {
          v27 = 1630;
          v28 = dword_6343F8;
          result = -1073741801;
          goto LABEL_72;
        }
      }
      else
      {
LABEL_23:
        v15 = dword_63389C;
LABEL_24:
        v16 = *(unsigned int **)(a1 + 48);
        if ( v16 != (unsigned int *)MmBadPointer )
        {
          if ( *(_BYTE *)(a1 + 32) == 1 )
          {
            MiUnlockWorkingSetExclusive((int)v16, *(unsigned __int8 *)(a1 + 44));
          }
          else
          {
            v17 = *(unsigned __int8 *)(a1 + 44);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v16);
            }
            else
            {
              __dmb(0xBu);
              do
                v18 = __ldrex(v16);
              while ( __strex(v18 & 0xBFFFFFFF, v16) );
              __dmb(0xBu);
              do
                v19 = __ldrex(v16);
              while ( __strex(v19 - 1, v16) );
            }
            KfLowerIrql(v17);
          }
          v15 = dword_63389C;
        }
        v2 = v3 << 10;
        v20 = *(_DWORD *)(a1 + 4) - (v3 << 10);
        v34[0] = 0;
        v35 = v32;
        v32[0] = v3 << 10;
        v32[1] = v20;
        v33 = 2;
        v21 = 0;
        v37 = 0;
        v38 = 0;
        v29 = v3 << 10;
        v36 = 1;
        if ( v4 )
        {
          v21 = 1;
          if ( *(_DWORD *)(a1 + 28) == 5
            && v2 >= v15
            && *((_BYTE *)&MiState[2423] + ((int)(((v2 >> 20) & 0xFFC) - ((v15 >> 20) & 0xFFC)) >> 2)) == 12 )
          {
            v21 = 0;
          }
        }
        v22 = MmAccessFault(v21, v3 << 10, 0, (int)v34);
        if ( v22 < 0 && *(_DWORD *)(a1 + 28) == 1 && *(_DWORD *)(*(_DWORD *)(a1 + 40) + 780) )
          v22 = MiDeliverPicoExceptionForProbedPage(v3 << 10, v4);
        MiLockProbePacketWorkingSet(a1);
        if ( v22 < 0 )
        {
          v27 = 1617;
          v28 = dword_6343C4;
          result = v22;
          goto LABEL_72;
        }
      }
    }
    else
    {
      v23 = v10 == 5;
      v2 = v29;
      if ( v23
        && v29 >= dword_63389C
        && *((_BYTE *)&MiState[2423] + ((int)(((v29 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 12 )
      {
        if ( !v12 )
          goto LABEL_20;
        if ( (*(_DWORD *)(v12 + 20) & 0x8000000) != 0 )
          return sub_54513C();
      }
LABEL_16:
      if ( !v12 )
        goto LABEL_20;
      v13 = *(_DWORD *)(v12 + 20);
      if ( (v13 & 0x7000000) != 0x1000000 && (*(_DWORD *)(v12 + 4) & 0x80000000) == 0 )
        goto LABEL_77;
      if ( v4 )
        goto LABEL_20;
      if ( (v13 & 0x8000000) == 0 )
        goto LABEL_20;
      v24 = *(_DWORD *)(a1 + 40);
      if ( !v24 )
        goto LABEL_20;
      if ( !*(_DWORD *)(v24 + 272) )
        goto LABEL_20;
      v26 = MiLocateCloneAddress(v24);
      if ( !v26 )
        goto LABEL_20;
      if ( MEMORY[0xC0402140] <= *(_QWORD *)(v26 + 40) )
        goto LABEL_77;
      result = MiSplitReducedCommitClonePage(a1, &v30);
      if ( result < 0 )
      {
        v27 = 1629;
        v28 = dword_6343F4;
        goto LABEL_72;
      }
      v3 = v30;
    }
  }
  v27 = 1620;
  v28 = dword_6343D0;
  result = -1073741819;
LABEL_72:
  MiState[v27] = v28 + 1;
  return result;
}
