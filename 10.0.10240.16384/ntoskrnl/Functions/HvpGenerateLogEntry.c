// HvpGenerateLogEntry 
 
int __fastcall HvpGenerateLogEntry(int *a1, int a2, int a3)
{
  int v4; // r10
  int v5; // r3
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r9
  int v9; // r0
  int *v10; // r7
  int result; // r0
  int v12; // r4
  int v13; // r5
  int v14; // r3
  char *v15; // r8
  int v16; // r4
  unsigned int v17; // r8
  unsigned int v18; // r4
  int v19; // r4
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r0
  _BYTE *v24; // r0
  int v25; // r0
  char *v26; // [sp+10h] [bp-40h] BYREF
  unsigned int v27; // [sp+14h] [bp-3Ch] BYREF
  int v28; // [sp+18h] [bp-38h] BYREF
  int *v29; // [sp+1Ch] [bp-34h]
  int **v30; // [sp+20h] [bp-30h]
  unsigned int *v31; // [sp+24h] [bp-2Ch]
  int v32; // [sp+28h] [bp-28h] BYREF
  int v33; // [sp+2Ch] [bp-24h]

  v33 = 0;
  v4 = 0;
  v5 = a1[27];
  v6 = 0;
  v30 = (int **)a2;
  v31 = (unsigned int *)a3;
  if ( !v5 )
  {
    v5 = 0;
    v33 = 0;
    v4 = 1;
    v6 = 512;
  }
  v26 = (char *)HvpCountSetRangesInVector(a1 + 9, a2, a3, v5);
  v7 = RtlNumberOfSetBits((unsigned int *)a1 + 9);
  CmpLogDirtyVectorUse((int)a1, 1u, (unsigned int)v26, v7);
  v8 = (v6 + 8 * (_DWORD)&v26[64 * a1[11]] + 4135) & 0xFFFFF000;
  v9 = ExAllocatePoolWithTag(5, v8, 1867074883);
  v10 = (int *)v9;
  if ( !v9 )
    return sub_805DCC();
  v12 = 0;
  if ( v4 )
  {
    memmove(v9, a1[8], 0x200u);
    v10[1] = a1[25];
    v10[2] = a1[25];
    v10[7] = 6;
    v10[10] = a1[238];
    v10[11] = 1;
    v10[127] = HvpHeaderCheckSum(v10);
    v12 = 128;
  }
  v13 = (int)&v10[v12];
  v29 = &v10[v12];
  memset(&v10[v12], 0, 40);
  v10[v12 + 1] = v8;
  v10[v12] = 1162638920;
  if ( v4 )
    *(_DWORD *)(v13 + 4) = v8 - 512;
  *(_DWORD *)(v13 + 12) = a1[25];
  *(_DWORD *)(v13 + 8) = 0;
  if ( (*(_DWORD *)(a1[8] + 144) & 1) != 0 )
    *(_DWORD *)(v13 + 8) = 1;
  v14 = a1[238];
  v15 = v26;
  v16 = v12 * 4 + 40;
  *(_DWORD *)(v13 + 16) = v14;
  *(_DWORD *)(v13 + 20) = v15;
  v26 = v15;
  HvpGenerateLogMetadata(a1 + 9, (int *)((char *)v10 + v16), (unsigned int *)&v26, v14);
  v17 = v16 + 8 * (_DWORD)v15;
  v26 = 0;
  if ( v17 < v8 )
  {
    do
    {
      if ( !HvpFindNextDirtyBlock((int)a1, (char **)a1 + 9, &v26, &v28, &v27, &v32, 0) )
        break;
      v18 = v27;
      memmove((int)v10 + v17, v28, v27);
      v17 += v18;
    }
    while ( v17 < v8 );
    v13 = (int)v29;
  }
  v19 = RtlNumberOfSetBits((unsigned int *)a1 + 9);
  v23 = HvpCountSetRangesInVector(a1 + 9, v20, v21, v22);
  v24 = (_BYTE *)CmpLogDirtyVectorUse((int)a1, 2u, v23, v19);
  if ( v17 < v8 )
    v24 = memset((_BYTE *)v10 + v17, 0, v8 - v17);
  v25 = SymCryptMarvin32((int)v24, (__int64 *)(v13 + 40), *(_DWORD *)(v13 + 4) - 40, (_DWORD *)(v13 + 24));
  SymCryptMarvin32(v25, (__int64 *)v13, 0x20u, (_DWORD *)(v13 + 32));
  result = 0;
  *v30 = v10;
  *v31 = v8;
  return result;
}
