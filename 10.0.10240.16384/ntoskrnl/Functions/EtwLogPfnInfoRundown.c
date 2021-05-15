// EtwLogPfnInfoRundown 
 
int __fastcall EtwLogPfnInfoRundown(int result, int a2, int *a3)
{
  int v5; // r3
  unsigned int v6; // r5
  int i; // r8
  int v8; // r3
  int v9; // r2
  int v10[18]; // [sp+8h] [bp-48h] BYREF

  if ( result )
    v5 = *(_DWORD *)(result + 176);
  else
    v5 = -1;
  *a3 = v5;
  v10[0] = (int)a3;
  v10[1] = 0;
  v10[2] = 4;
  v10[3] = 0;
  v10[4] = (int)(a3 + 1);
  v10[5] = 0;
  v6 = a3[1];
  v10[6] = 4;
  v10[7] = 0;
  for ( i = (int)(a3 + 2); v6; v6 -= v9 )
  {
    v8 = 2726;
    if ( v6 <= 0xAA6 )
      v8 = v6;
    a3[1] = v8;
    v10[10] = 24 * v8;
    v10[11] = 0;
    v10[8] = i;
    v10[9] = 0;
    result = EtwpLogKernelEvent(v10, a2, 3, 644, 4200450);
    v9 = a3[1];
    i += 24 * v9;
  }
  return result;
}
