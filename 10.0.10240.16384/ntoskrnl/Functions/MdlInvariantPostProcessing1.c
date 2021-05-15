// MdlInvariantPostProcessing1 
 
int __fastcall MdlInvariantPostProcessing1(__int64 a1, int a2)
{
  int v2; // r6
  int v4; // r5
  int v5; // r2
  unsigned int *v6; // r2
  int v7; // r4
  int *v8; // r5
  int v9; // r4
  int v10; // t1
  unsigned int v11; // r7
  int v12; // r2
  int v13; // r1
  unsigned int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r9
  int v20; // r5

  v2 = HIDWORD(a1);
  v4 = a1;
  if ( **(_DWORD **)(HIDWORD(a1) + 4) )
    return a1;
  LODWORD(a1) = KeGetCurrentIrql(a1);
  if ( (unsigned int)a1 < 2 && *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20) == -1 )
    return a1;
  if ( (MmVerifierData & 0x2000) != 0 && (MmVerifierData & 0x4000) == 0 && *(char *)(v2 + 35) != *(char *)(v2 + 34) )
    return a1;
  LODWORD(a1) = MmMdlPageContentsState(*(_DWORD *)(v2 + 4), 2);
  if ( (_DWORD)a1 != 1 )
    return a1;
  v5 = *(_DWORD *)(v4 + 132);
  if ( v5 )
    *(_DWORD *)(v5 + 8) = *(_DWORD *)(v2 + 4);
  v6 = *(unsigned int **)(v4 + 132);
  if ( v6 )
  {
    a1 = *v6;
    if ( *v6 )
    {
      v8 = (int *)v6[1];
      while ( 1 )
      {
        v10 = *v8;
        v8 += 8;
        v9 = v10;
        if ( v10 )
        {
          if ( v9 == *(_DWORD *)(v2 + 4) )
            break;
        }
        if ( ++HIDWORD(a1) >= (unsigned int)a1 )
          goto LABEL_17;
      }
      v7 = v6[1] + 32 * HIDWORD(a1);
    }
    else
    {
LABEL_17:
      v7 = 0;
    }
    if ( v7 )
      goto LABEL_20;
  }
  else
  {
    v7 = 0;
  }
  if ( *(_BYTE *)a2 == 4 )
    return a1;
LABEL_20:
  LODWORD(a1) = *(_DWORD *)(v2 + 4);
  if ( (*(_WORD *)(a1 + 6) & 5) != 0 )
  {
    v11 = *(_DWORD *)(a1 + 12);
  }
  else
  {
    LODWORD(a1) = MmMapLockedPagesSpecifyCache(a1, 0, 1, 0, 0, 32);
    v11 = a1;
  }
  if ( !v11 )
    return a1;
  if ( !v7 || (v12 = *(_DWORD *)(v7 + 20), v13 = *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20), v12 == v13) )
  {
    if ( *(_BYTE *)a2 == 4 )
    {
      LODWORD(a1) = RtlpComputeCrcInternal(v11, *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20), 0, 0, &Crc64Ctrl);
      if ( a1 != *(_QWORD *)(v7 + 8) )
      {
        v15 = *(_DWORD *)(a2 + 24);
        goto LABEL_30;
      }
      return a1;
    }
  }
  else
  {
    v14 = *(_DWORD *)(v7 + 16);
    if ( v11 < v14 || v13 + v11 > v12 + v14 )
    {
      v15 = *(_DWORD *)(a2 + 24);
      if ( *(_BYTE *)a2 == 4 )
      {
LABEL_30:
        v16 = 4112;
LABEL_39:
        LODWORD(a1) = VerifierBugCheckIfAppropriate(196, v16, v15);
        return a1;
      }
LABEL_38:
      v16 = 4113;
      goto LABEL_39;
    }
  }
  if ( *(_BYTE *)a2 == 3 )
  {
    LODWORD(a1) = KeGetCurrentIrql(a1);
    if ( (unsigned int)a1 < 2 )
    {
      v17 = RtlpComputeCrcInternal(v11, *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20), 0, 0, &Crc64Ctrl);
      v19 = v18;
      v20 = v17;
      KeDelayExecutionThread(0, 0, (unsigned int *)IovMdlInvariant10Milliseconds);
      LODWORD(a1) = RtlpComputeCrcInternal(v11, *(_DWORD *)(*(_DWORD *)(v2 + 4) + 20), 0, 0, &Crc64Ctrl);
      if ( __PAIR64__(v19, v20) != a1 )
      {
        v15 = *(_DWORD *)(a2 + 24);
        goto LABEL_38;
      }
    }
  }
  return a1;
}
