// AlpcpAllocateCompletionBuffer 
 
int __fastcall AlpcpAllocateCompletionBuffer(int a1, int a2)
{
  _DWORD *v2; // r6
  unsigned int v3; // r8
  int v4; // r7
  int v5; // r0
  int v6; // r5
  int v7; // r1
  unsigned int v8; // r10
  unsigned int v9; // r2
  unsigned int v10; // r4
  int v11; // r1
  int v12; // r0
  int v14; // [sp+0h] [bp-28h]
  int v15; // [sp+4h] [bp-24h]

  v2 = *(_DWORD **)(a1 + 212);
  v3 = a2 + 63;
  v4 = 0;
  v5 = v2[13];
  v6 = -1;
  v7 = v2[17] >> 5;
  v14 = v5;
  v15 = v7;
  v8 = v2[12] >> 2;
  if ( !v8 )
    return v6;
  while ( 1 )
  {
    v9 = v2[18];
    __dmb(0xBu);
    v10 = v9 & 0xFFFFFFE0;
    v11 = v5 + 4 * v7;
    if ( v9 >= v2[17] )
      v10 = 0;
    v12 = AlpcpAllocateFromBitmap(v5 + 4 * (v10 >> 5), v11, v3 >> 6);
    if ( v12 == -2 )
      goto LABEL_8;
    if ( v12 != -1 )
      break;
    if ( !v10 )
      return v6;
    v12 = AlpcpAllocateFromBitmap(v14, v14 + 4 * (v10 >> 5), v3 >> 6);
    if ( v12 != -2 )
      goto LABEL_11;
LABEL_8:
    v7 = v15;
    if ( ++v4 >= v8 )
      goto LABEL_11;
    v5 = v14;
  }
  v12 += v10;
LABEL_11:
  if ( v12 != -1 && v12 != -2 )
  {
    v2[18] = v12 + (v3 >> 6);
    v6 = v12 << 6;
  }
  return v6;
}
