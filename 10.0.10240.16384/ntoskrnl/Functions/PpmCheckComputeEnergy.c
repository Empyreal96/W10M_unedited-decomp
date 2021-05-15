// PpmCheckComputeEnergy 
 
int PpmCheckComputeEnergy()
{
  unsigned int v0; // r5
  unsigned int v1; // r2
  int v2; // r6
  int v3; // lr
  int v4; // r3
  int v5; // r1
  _DWORD *v6; // r4
  int v7; // r0
  int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r2
  char *v15; // r5
  int *v16; // r4
  int v17; // r6
  unsigned int v18; // r2
  unsigned int v19; // t1
  int v20; // lr
  unsigned int v22; // [sp+0h] [bp-68h]
  int v23[2]; // [sp+8h] [bp-60h] BYREF
  _DWORD v24[2]; // [sp+10h] [bp-58h] BYREF
  _DWORD v25[4]; // [sp+18h] [bp-50h] BYREF
  _DWORD v26[4]; // [sp+28h] [bp-40h] BYREF
  char v27[48]; // [sp+38h] [bp-30h] BYREF

  if ( !PopComputeEnergy )
    return 1;
  v23[1] = 32;
  v25[0] = 0;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v23[0] = 32;
  v0 = dword_681D78[0];
  v26[0] = 0;
  v26[1] = 0;
  v26[2] = 0;
  v26[3] = 0;
  while ( v0 )
  {
    v1 = __clz(__rbit(v0));
    v0 &= ~(1 << v1);
    v22 = v1;
    if ( v1 >= KeNumberProcessors_0 )
      v2 = 0;
    else
      v2 = (int)*(&KiProcessorBlock + v1);
    v3 = *(unsigned __int8 *)(v2 + 2986);
    v4 = *(_DWORD *)(v2 + 3256);
    v5 = v26[2 * v3];
    v6 = &v26[2 * v3];
    v7 = v6[1];
    v23[v3] = v1;
    v8 = *(_DWORD *)(v2 + 3260);
    *v6 = v5 + v4;
    v9 = v8 + __CFADD__(v5, v4) + v7;
    v10 = v25[2 * v3];
    v6[1] = v9;
    *(_QWORD *)&v25[2 * v3] = __PAIR64__(v25[2 * v3 + 1], v10) + *(_QWORD *)(v2 + 3264);
    v11 = *(_DWORD *)(v2 + 3200);
    v12 = *(_DWORD *)(v2 + 3204);
    if ( v11 && v12 )
    {
      v13 = *(_DWORD *)(v12 + 44);
      v14 = *(_DWORD *)(v11 + 148);
      if ( v13 >= v14 )
        v13 = v14;
    }
    else
    {
      v13 = 100;
    }
    v24[v3] = v13;
    *(_DWORD *)(v2 + 3256) = 0;
    *(_DWORD *)(v2 + 3260) = 0;
    *(_DWORD *)(v2 + 3264) = 0;
    *(_DWORD *)(v2 + 3268) = 0;
  }
  ((void (__fastcall *)(_DWORD *, _DWORD *, _DWORD *, char *, unsigned int))PopComputeEnergy)(v26, v25, v24, v27, v22);
  v15 = v27;
  v16 = v23;
  v17 = 2;
  do
  {
    v19 = *v16++;
    v18 = v19;
    if ( v19 != 32 )
    {
      if ( v18 >= KeNumberProcessors_0 )
        v20 = 0;
      else
        v20 = (int)*(&KiProcessorBlock + v18);
      *(_QWORD *)(v20 + 3248) += *(_QWORD *)v15;
    }
    v15 += 8;
    --v17;
  }
  while ( v17 );
  return 1;
}
