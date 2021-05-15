// MiReplenishNonPagedSlists 
 
int __fastcall MiReplenishNonPagedSlists(__int64 *a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v5; // lr
  unsigned int v6; // r5
  unsigned int v7; // r4
  __int64 v8; // kr00_8
  unsigned int v9; // r7
  int v10; // r9
  int v11; // r4
  int v12; // r6
  unsigned int v13; // r5
  _DWORD *v14; // r10
  int v15; // r3
  int v16; // r2
  unsigned int v19; // [sp+4h] [bp-3Ch]
  int v20; // [sp+8h] [bp-38h]
  int v21; // [sp+Ch] [bp-34h]
  unsigned int v22[10]; // [sp+18h] [bp-28h] BYREF

  v5 = a4;
  v19 = dword_6337E8 + 176 * a2;
  v6 = MiState[a5];
  v7 = *(unsigned __int16 *)(v19 + 8 * (a5 + 3) + 4);
  if ( v7 >= v6 >> 1 )
    return 0;
  v8 = *a1;
  v9 = a4 & 0xFFFFFC00;
  if ( a4 + 2 * a5 > *(_DWORD *)a1 + (a4 & 0xFFFFFC00) )
    return 0;
  v10 = (unsigned __int16)(v6 - v7);
  v22[1] = HIDWORD(v8) + 4 * (v9 >> 5);
  v22[0] = v8 - v9;
  if ( (unsigned int)v8 - v9 > 0x400 )
    v22[0] = 1024;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  if ( v10 )
  {
    do
    {
      v15 = RtlFindClearBitsAndSet(v22, a5, v5);
      v21 = v15;
      if ( v15 == -1 )
        break;
      v16 = a3 + v15 + v9;
      v20 = *(_DWORD *)(v19 + 136) + (v16 << 12);
      MiAllocatingNonPagedPoolVa(v19, 0, v16, a5);
      *(_DWORD *)v20 = dword_634C80 ^ v20;
      *(_DWORD *)(v20 + 8) = v13;
      if ( !v13 )
        v14 = (_DWORD *)(v20 + 8);
      v10 = (unsigned __int16)(v10 - 1);
      ++v12;
      v13 = v20 + 8;
      v5 = v21 + a5;
    }
    while ( v10 );
    v11 = 0;
    if ( v13 )
    {
      InterlockedPushListSList((unsigned __int64 *)(v19 + 8 * (a5 + 3)), v13, v14, v12);
      v11 = v12 * a5;
    }
  }
  return v11;
}
