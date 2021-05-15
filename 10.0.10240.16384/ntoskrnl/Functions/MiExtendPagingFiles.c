// MiExtendPagingFiles 
 
unsigned int __fastcall MiExtendPagingFiles(unsigned int result)
{
  unsigned int v1; // r5
  _DWORD *v2; // r7
  unsigned int v3; // r9
  unsigned int v4; // r3
  unsigned int v5; // r6
  int v6; // r6
  int v7; // r2
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r1
  __int16 v11; // r3
  BOOL v12; // r8
  char v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r3
  _DWORD *v17; // r1
  unsigned int v18; // r4
  int v19; // r3
  __int16 v20; // r2
  unsigned int v21; // r10
  _DWORD *v22; // r3
  __int16 v23; // r2
  _DWORD *v24; // [sp+8h] [bp-20h]

  v1 = result;
  v2 = *(_DWORD **)(result + 12);
  v3 = *(_DWORD *)(result + 16);
  v4 = *(unsigned __int8 *)(result + 44);
  v5 = v2[899];
  __dmb(0xBu);
  if ( !v5 )
    return result;
  if ( v4 < v5 )
  {
    v6 = v2[v4 + 900];
    if ( *(_DWORD *)(v6 + 4) - *(_DWORD *)v6 < v3 )
      return result;
    result = MiAttemptPageFileExtension(v6, v3);
    v8 = result;
    if ( result )
    {
      v9 = *(unsigned __int8 *)(v1 + 47);
      if ( (v9 & 2) != 0 )
      {
        v10 = result;
        result = v6;
        MiUpdatePagingFileMinimum(v6, v10, v7, v9);
      }
    }
    v11 = *(_WORD *)(v6 + 96);
    v12 = (v11 & 0x10) == 0 && (v11 & 0x40) == 0;
    goto LABEL_28;
  }
  v13 = *(_BYTE *)(result + 47);
  result = 1;
  if ( (v13 & 1) == 0 )
  {
    v14 = v2[961];
    v15 = v2[1029];
    v16 = v2[807] + v14 + v3;
    if ( v16 < v14 )
      return result;
    if ( v16 <= v15 )
    {
      *(_DWORD *)(v1 + 20) = 1;
      return result;
    }
    v3 = v16 - v15;
  }
  result = 0;
  v17 = v2;
  v18 = v5;
  do
  {
    v19 = v17[900];
    v20 = *(_WORD *)(v19 + 96);
    if ( (v20 & 0x40) == 0 && (v20 & 0x10) == 0 )
      result += *(_DWORD *)(v19 + 4) - *(_DWORD *)v19;
    ++v17;
    --v18;
  }
  while ( v18 );
  if ( result >= v3 )
  {
    v8 = 0;
    v21 = 0;
    v12 = 1;
    v22 = v2;
    v24 = v2;
    do
    {
      result = v22[900];
      v23 = *(_WORD *)(result + 96);
      if ( (v23 & 0x40) == 0 && (v23 & 0x10) == 0 )
      {
        result = MiAttemptPageFileExtension(result, v3 - v8);
        v8 += result;
        if ( v8 >= v3 )
          break;
        v22 = v24;
      }
      ++v21;
      v24 = ++v22;
    }
    while ( v21 < v5 );
LABEL_28:
    if ( v8 )
    {
      *(_DWORD *)(v1 + 20) = v8;
      if ( v12 )
        result = MiIncreaseCommitLimits(v2, v8, 0, 0, 0);
    }
  }
  return result;
}
