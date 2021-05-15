// CmpLogHiveDestroyEvent 
 
int *__fastcall CmpLogHiveDestroyEvent(int a1, int a2)
{
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int *v5; // r3
  int v6; // r1
  int *v7; // r2
  int v8; // r3
  int *v9; // r3
  __int16 v11[4]; // [sp+8h] [bp-70h] BYREF
  int var68[27]; // [sp+10h] [bp-68h] BYREF
  int vars8[2]; // [sp+80h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  v11[0] = 0;
  var68[0] = (int)vars8;
  var68[1] = 0;
  v2 = *(_DWORD *)(a1 + 1980);
  var68[2] = 4;
  v3 = *(_DWORD *)(a1 + 1988);
  v4 = 1;
  var68[3] = 0;
  if ( v2 )
  {
    var68[4] = v2;
    var68[5] = 0;
    var68[6] = *(unsigned __int16 *)(a1 + 1976);
    var68[7] = 0;
    v4 = 2;
  }
  v5 = &var68[4 * v4];
  v6 = v4 + 1;
  *v5 = (int)v11;
  v5[1] = 0;
  v5[2] = 2;
  v5[3] = 0;
  if ( v3 )
  {
    v7 = &var68[4 * v6];
    v8 = *(unsigned __int16 *)(a1 + 1984);
    *v7 = v3;
    v7[1] = 0;
    v7[2] = v8;
    v7[3] = 0;
    ++v6;
  }
  v9 = &var68[4 * v6];
  *v9 = (int)v11;
  v9[1] = 0;
  v9[2] = 2;
  v9[3] = 0;
  return EtwTraceKernelEvent(var68, v6 + 1, 0x41000000u, 2341, 5249282);
}
