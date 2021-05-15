// NtSubscribeWnfStateChange 
 
int __fastcall NtSubscribeWnfStateChange(int a1, int a2, int a3, _DWORD *a4)
{
  unsigned int v8; // r5
  int *v9; // r0
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16; // [sp+14h] [bp-24h]
  _DWORD *v17; // [sp+18h] [bp-20h]
  int varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  _DWORD *varg_r3; // [sp+4Ch] [bp+14h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v15 = 0;
  v16 = 0;
  if ( a4 )
  {
    ProbeForWrite(a4, 8, 1);
    *a4 = 0;
    a4[1] = 0;
  }
  if ( a4 )
    v9 = &v15;
  else
    v9 = 0;
  v10 = ExpWnfSubscribeWnfStateChange(v9, 0, a1, a2, 0, 0, a3, 1);
  v11 = v10;
  if ( v10 >= 0 && a4 )
  {
    *a4 = v15;
    a4[1] = v16;
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v11;
}
