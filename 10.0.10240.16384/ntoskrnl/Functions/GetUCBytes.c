// GetUCBytes 
 
int __fastcall GetUCBytes(int a1, int *a2, _DWORD *a3)
{
  int v3; // r6
  _DWORD *v4; // r5
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int result; // r0

  v3 = 0;
  *a3 = 0;
  v4 = *(_DWORD **)(a1 + 164);
  while ( 1 )
  {
    v6 = *a2;
    if ( v4 == (_DWORD *)(a1 + 164) )
      break;
    *a2 = v6 + (v4[4] << 12);
    *a3 += v4[8];
    v5 = v4[7];
    v4 = (_DWORD *)*v4;
    v3 += v5 << 12;
  }
  v7 = *(_DWORD *)(a1 + 492);
  result = v3;
  *a2 = v6 + v7;
  return result;
}
