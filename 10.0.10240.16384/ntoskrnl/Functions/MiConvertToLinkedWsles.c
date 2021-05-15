// MiConvertToLinkedWsles 
 
int __fastcall MiConvertToLinkedWsles(int a1)
{
  _DWORD *v2; // r5
  int v3; // r2
  int v4; // r0
  unsigned int v5; // r8
  unsigned int v7; // r10
  unsigned int v8; // r9
  int v9; // r2
  unsigned int v10; // lr
  int v11; // r6
  int v12; // r0
  unsigned int v13; // r7
  int v14; // r2
  _DWORD *v15; // r3
  int v16; // r2
  unsigned int v17; // r3
  int *v18; // r7
  _DWORD *v19; // r8
  int v20; // t1
  int v21; // r2
  unsigned int v22; // r7
  int v23; // r6
  unsigned int v24; // r0
  unsigned int v25; // r0

  v2 = *(_DWORD **)(a1 + 92);
  v3 = *(_DWORD *)(a1 + 60);
  if ( (((unsigned __int16)v2[63] + 16 * (_WORD)v3) & 0xFFF) == 0
    || ((4096 - (((unsigned __int16)v2[63] + 16 * (_WORD)v3) & 0xFFF)) & 0xFFFFFFF0) < 0x80
    || (*(_BYTE *)(a1 + 115) & 2) != 0 )
  {
    return 0;
  }
  MiRemoveWorkingSetPages(a1);
  v4 = v2[63];
  v5 = v4 + 16 * *(_DWORD *)(a1 + 60);
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
    return sub_51A1B4();
  v7 = v4 + 4 * (v2[4] + 1);
  v8 = v7;
  v9 = *(_DWORD *)(a1 + 48) + 4;
  v10 = v4 + v2[9] * v9;
  v11 = 0;
  v2[9] = 16;
  if ( v4 + 16 * v9 > v10 && (*(_BYTE *)(a1 + 112) & 7) != 1 )
  {
    v12 = MiComputeWslePagesNeeded(v10);
    v11 = v12;
    if ( v12 )
    {
      if ( MiChargeCommit(MiSystemPartition, v12, 0) )
      {
        if ( MiChargeResident(MiSystemPartition, v11, 1024) )
        {
          do
            v24 = __ldrex(&dword_634A2C[41]);
          while ( __strex(v24 + v11, &dword_634A2C[41]) );
          *(_DWORD *)(a1 + 72) += v11;
          goto LABEL_9;
        }
        v2[9] = 4;
        MiReturnCommit(MiSystemPartition, v11);
      }
      else
      {
        v2[9] = 4;
      }
      return 0;
    }
  }
LABEL_9:
  if ( v7 < v5 )
  {
    v13 = ((((_WORD)v5 - (_WORD)v7) & 0xFFF) != 0) + ((v5 - v7) >> 12) + 1024;
    while ( dword_640580 > v13 && MiMapNewWorkingSetPage(a1, v8) )
    {
      v8 += 4096;
      --v13;
      if ( v8 >= v5 )
        goto LABEL_14;
    }
    v2[9] = 4;
    if ( v8 != v7 )
      MiDeleteExcessWorkingSetPages(a1, ((v7 >> 10) & 0x3FFFFC) - 0x40000000, ((v8 >> 10) & 0x3FFFFC) - 0x40000000);
    if ( v11 )
    {
      MiReturnCommit(MiSystemPartition, v11);
      MiReturnResidentAvailable(v11);
      do
        v25 = __ldrex(&dword_634A2C[42]);
      while ( __strex(v25 + v11, &dword_634A2C[42]) );
      *(_DWORD *)(a1 + 72) -= v11;
    }
    return 0;
  }
LABEL_14:
  v14 = 16;
  v15 = v2;
  do
  {
    v15[31] = 0xFFFFF;
    v15[32] = 0xFFFFF;
    v15 += 2;
    --v14;
  }
  while ( v14 );
  v16 = *(_DWORD *)(a1 + 60);
  v17 = v2[63];
  if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
    --v16;
  v18 = (int *)(v17 + 4 * v16);
  v19 = (_DWORD *)(v17 + 16 * v16);
  if ( (unsigned int)v18 >= v17 )
  {
    do
    {
      v20 = *v18--;
      *v19 = v20;
      v19 -= 4;
      if ( (v18[1] & 1) == 0 )
        break;
      MiInsertWsle(v2, v19 + 4, 1);
    }
    while ( (unsigned int)v18 >= v2[63] );
  }
  *v2 = 0xFFFFF;
  v21 = *(_DWORD *)(a1 + 60);
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
    ++v21;
  v22 = (4096 - (((unsigned __int16)v2[63] + 16 * (_WORD)v21) & 0xFFFu)) >> 4;
  v23 = v22 + v21 - 1;
  for ( v2[4] = v23; v22; --v22 )
    MiReleaseWsle(v23--, a1, 0, 0);
  return 1;
}
