// EtwpComputeRegEntryEnableInfo 
 
unsigned int __fastcall EtwpComputeRegEntryEnableInfo(int a1, int a2)
{
  int v2; // r8
  int v3; // r7
  int v4; // r5
  int v5; // r6
  unsigned int result; // r0
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r2
  int v21; // r3

  v2 = *(unsigned __int8 *)(a1 + 51);
  v3 = *(unsigned __int8 *)(a1 + 52);
  v4 = *(_DWORD *)(a1 + 20);
  v5 = *(_DWORD *)(a1 + 16);
  memset((_BYTE *)a2, 0, 32);
  *(_DWORD *)(a2 + 24) = -1;
  *(_DWORD *)(a2 + 28) = -1;
  for ( result = 0; result < 8; ++result )
  {
    if ( ((1 << result) & v2) != 0 )
    {
      v8 = *(unsigned __int8 *)(a2 + 4);
      *(_DWORD *)a2 = 1;
      if ( v8 <= *(unsigned __int8 *)(v5 + 92) )
        LOBYTE(v8) = *(_BYTE *)(v5 + 92);
      v9 = *(_DWORD *)(a2 + 16);
      *(_BYTE *)(a2 + 4) = v8;
      v10 = *(_DWORD *)(v5 + 104) | v9;
      v11 = *(_DWORD *)(v5 + 108);
      v12 = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(a2 + 16) = v10;
      *(_DWORD *)(a2 + 20) = v12 | v11;
      v13 = *(_DWORD *)(v5 + 116);
      v14 = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(a2 + 24) &= *(_DWORD *)(v5 + 112);
      *(_DWORD *)(a2 + 28) = v14 & v13;
      *(_DWORD *)(a2 + 8) |= *(_DWORD *)(v5 + 96);
    }
    v5 += 32;
  }
  if ( v3 )
  {
    for ( result = 0; result < 8; ++result )
    {
      if ( ((1 << result) & v3) != 0 )
      {
        v15 = *(unsigned __int8 *)(a2 + 4);
        *(_DWORD *)a2 = 1;
        if ( v15 <= *(unsigned __int8 *)(v4 + 92) )
          LOBYTE(v15) = *(_BYTE *)(v4 + 92);
        v16 = *(_DWORD *)(a2 + 16);
        *(_BYTE *)(a2 + 4) = v15;
        v17 = *(_DWORD *)(v4 + 104) | v16;
        v18 = *(_DWORD *)(v4 + 108);
        v19 = *(_DWORD *)(a2 + 20);
        *(_DWORD *)(a2 + 16) = v17;
        *(_DWORD *)(a2 + 20) = v19 | v18;
        v20 = *(_DWORD *)(v4 + 116);
        v21 = *(_DWORD *)(a2 + 28);
        *(_DWORD *)(a2 + 24) &= *(_DWORD *)(v4 + 112);
        *(_DWORD *)(a2 + 28) = v21 & v20;
        *(_DWORD *)(a2 + 8) |= *(_DWORD *)(v4 + 96);
      }
      v4 += 32;
    }
  }
  return result;
}
