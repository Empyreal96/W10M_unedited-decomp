// MiCaptureAndResetWorkingSetAccessBits 
 
int __fastcall MiCaptureAndResetWorkingSetAccessBits(int a1, char a2)
{
  int *v3; // r4
  _DWORD *v4; // r9
  int v5; // r1
  int v6; // r2
  _DWORD *v7; // r6
  int *v8; // r8
  int v9; // r7
  int v10; // r10
  int v11; // r3
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r7
  int result; // r0
  int v16; // [sp+8h] [bp-C0h]
  unsigned int i; // [sp+Ch] [bp-BCh]
  int v18; // [sp+10h] [bp-B8h] BYREF
  char v19; // [sp+14h] [bp-B4h]
  char v20; // [sp+15h] [bp-B3h]
  int v21; // [sp+18h] [bp-B0h]
  int v22; // [sp+1Ch] [bp-ACh]
  int v23; // [sp+20h] [bp-A8h]
  int v24; // [sp+24h] [bp-A4h]

  if ( (a2 & 0x10) != 0 )
  {
    v22 = 0;
    v23 = 0;
    v19 = 0;
    v20 = 0;
    v21 = 33;
    v3 = &v18;
    v24 = 0;
    v18 = MiTbFlushType(a1);
  }
  else
  {
    v3 = 0;
  }
  v4 = *(_DWORD **)(a1 + 92);
  v5 = v4[9];
  v6 = v4[63];
  v16 = dword_634484;
  v7 = (_DWORD *)(v6 + v4[1] * v5);
  for ( i = v6 + v4[2] * v5; (unsigned int)v7 <= i; v5 = 0x80000000 )
  {
    if ( (*v7 & 1) == 0 )
      goto LABEL_24;
    v8 = (int *)(((*v7 >> 10) & 0x3FFFFC) - 0x40000000);
    v9 = *v8;
    v10 = MmPfnDatabase + 24 * ((unsigned int)*v8 >> 12);
    v11 = *(_DWORD *)(v10 + 4);
    if ( (v11 & 0x80000000) == 0 && MiDemoteCombinedPte((unsigned int)v8, v11 | 0x80000000) == 1 )
      v9 = *v8;
    if ( (v9 & 0x10) == 0 )
      goto LABEL_24;
    v12 = (*v7 >> 9) & 7;
    if ( v12 != 7 )
      goto LABEL_15;
    v13 = *(_BYTE *)(v10 + 19) & 7;
    if ( (*(_BYTE *)(v10 + 19) & 8) != 0 )
      v13 = 5;
    if ( v13 < dword_634498 )
    {
      v14 = 0;
    }
    else
    {
LABEL_15:
      v14 = 1;
      if ( (unsigned int)(v12 - 1) <= 5 )
      {
        MiUpdateWorkingSetAgeDistribution(a1, v12, -1);
        MiSetWsleAge((int)v4, v7, 0);
      }
    }
    if ( MiClearPteAccessed(a1, v10, (unsigned int)v8, v7, (int)v3, v16) != 1 )
      goto LABEL_24;
    if ( v14 == 1 && v16 )
    {
      if ( v3 )
        goto LABEL_23;
      MiLogPageAccess(a1, v8);
    }
    if ( v3 )
LABEL_23:
      MiFlushTbListEarly((int)v3, 0);
LABEL_24:
    v7 = (_DWORD *)((char *)v7 + v4[9]);
  }
  if ( v3 )
    MiFlushTbList((unsigned int)v3, v5);
  result = *(_DWORD *)(a1 + 8);
  if ( result )
  {
    result = MiEmptyPageAccessLog();
    *(_DWORD *)(a1 + 8) = 0;
  }
  return result;
}
