// RtlSparseBitmapCtxStart 
 
int __fastcall RtlSparseBitmapCtxStart(_DWORD *a1, int a2)
{
  int v3; // r6
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int result; // r0

  v3 = *(_DWORD *)(a2 + 28);
  if ( (v3 & 2) != 0 )
    return -1073741811;
  v5 = *(_DWORD *)(a2 + 12);
  if ( !v5 )
    __brkdiv0();
  v6 = _rt_udiv64(v5, *(_QWORD *)a2 + v5 - 1i64);
  if ( v7 || !v6 || !is_mul_ok(4u, v6) )
    return -1073741811;
  v8 = *(_DWORD *)(a2 + 20);
  a1[6] = 0;
  a1[7] = v6;
  a1[4] = v8;
  v9 = *(_DWORD *)(a2 + 24);
  a1[8] = v5;
  a1[5] = v9;
  a1[11] = *(_DWORD *)(a2 + 8);
  a1[10] = 4 * (((v5 + 31) >> 5) + 3);
  result = 0;
  a1[9] = *(_DWORD *)(a2 + 16);
  a1[12] = a1[12] & 0xFFFFFFF8 | v3 & 7;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
