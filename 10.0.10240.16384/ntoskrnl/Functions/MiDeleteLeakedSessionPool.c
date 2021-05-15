// MiDeleteLeakedSessionPool 
 
int MiDeleteLeakedSessionPool()
{
  unsigned int v0; // r5
  int v1; // r6
  unsigned int v2; // r0
  unsigned int v3; // r4
  unsigned int v4; // r3
  int v5; // r4
  unsigned int *v6; // r2
  int result; // r0
  unsigned int v8; // r4
  unsigned int v9; // [sp+0h] [bp-30h] BYREF
  unsigned int v10[2]; // [sp+8h] [bp-28h] BYREF
  int v11; // [sp+10h] [bp-20h] BYREF
  int v12; // [sp+14h] [bp-1Ch]
  int v13; // [sp+18h] [bp-18h]
  int v14; // [sp+1Ch] [bp-14h]

  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v0 = 0;
  v1 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v10[1] = v1 + 8196;
  v10[0] = 512;
  do
  {
    v2 = RtlFindSetBits(v10, 1u, v0);
    v3 = v2;
    if ( v2 < v0 || v2 == -1 )
      break;
    v4 = RtlFindNextForwardRunClear((int)v10, v2, (int)&v9) ? v9 : v10[0];
    v0 += v4 - v3;
    MiDeleteSessionPoolRange(v1, dword_63389C + (v3 << 22), (v4 - v3) << 22, &v11);
  }
  while ( v0 < v10[0] );
  v5 = v14;
  MiReturnCommit((int)MiSystemPartition, v14 - v12);
  v6 = (unsigned int *)(v1 + 32);
  *(_DWORD *)(v1 + 3244) -= v5;
  result = -v5;
  do
    v8 = __ldrex(v6);
  while ( __strex(v8 + result, v6) );
  return result;
}
