// CmpLogHiveInitializeEvent 
 
int *__fastcall CmpLogHiveInitializeEvent(int a1, int a2, unsigned __int16 *a3, int a4)
{
  int v4; // r1
  int *v5; // r2
  __int16 v7; // [sp+8h] [bp-88h] BYREF
  int v8; // [sp+Ch] [bp-84h] BYREF
  int v9[27]; // [sp+10h] [bp-80h] BYREF
  int varg_r0; // [sp+80h] [bp-10h] BYREF
  int varg_r1[2]; // [sp+84h] [bp-Ch] BYREF
  int varg_r3; // [sp+8Ch] [bp-4h] BYREF

  varg_r1[0] = a2;
  varg_r1[1] = (int)a3;
  varg_r3 = a4;
  varg_r0 = a1;
  v4 = 4;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  v7 = 0;
  v9[0] = (int)&varg_r0;
  v9[1] = 0;
  v9[2] = 4;
  v9[3] = 0;
  v9[4] = (int)varg_r1;
  v9[5] = 0;
  v9[6] = 4;
  v9[7] = 0;
  v9[8] = (int)&varg_r3;
  v9[9] = 0;
  v9[10] = 4;
  v9[11] = 0;
  v9[12] = (int)&v8;
  v9[13] = 0;
  v9[14] = 4;
  v9[15] = 0;
  if ( a3 && *((_DWORD *)a3 + 1) )
  {
    v9[16] = *((_DWORD *)a3 + 1);
    v9[17] = 0;
    v9[18] = *a3;
    v9[19] = 0;
    v4 = 5;
  }
  v5 = &v9[4 * v4];
  *v5 = (int)&v7;
  v5[2] = 2;
  v5[1] = 0;
  v5[3] = 0;
  return EtwTraceKernelEvent(v9, v4 + 1, 0x41000000u, 2340, 5249282);
}
