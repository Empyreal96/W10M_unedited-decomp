// KeUserModeCallback 
 
int __fastcall KeUserModeCallback(int a1, int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r9
  int v6; // r5
  int v7; // r0
  int v8; // r0
  unsigned int v9; // r3
  int v10; // r4
  int v11; // r0
  int v12; // r8
  int *v13; // r2
  int v14; // r1
  _DWORD *v15; // r9
  int v17; // [sp+0h] [bp-50h]
  int v18; // [sp+4h] [bp-4Ch]
  _DWORD *v20; // [sp+14h] [bp-3Ch]
  int v21; // [sp+18h] [bp-38h]
  int v24; // [sp+24h] [bp-2Ch]
  int vars4; // [sp+54h] [bp+4h]
  int varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+60h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v24 = a4;
  v5 = a3;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v6 + 0x4C) & 0x1000) != 0 )
    KeBugCheckEx(263, v6, 0, 0, 0);
  v7 = KeGetCurrentIrql(a1);
  if ( v7 )
  {
    v8 = KeGetCurrentIrql(v7);
    KeBugCheckEx(74, vars4, v8, 0, 0);
  }
  if ( *(_BYTE *)(v6 + 362) || *(_DWORD *)(v6 + 308) )
    KeBugCheckEx(1, vars4, *(unsigned __int8 *)(v6 + 362), *(_DWORD *)(v6 + 308), 0);
  v9 = (unsigned __int8)(*(_BYTE *)(v6 + 447) + 1);
  *(_BYTE *)(v6 + 447) = v9;
  if ( v9 <= 0x1F )
  {
    v11 = MmCreateKernelStack(
            0,
            *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)(v6 + 364)) + 590) + 266),
            v6);
    v12 = v11;
    if ( v11 )
    {
      v13 = (int *)(v11 - 24);
      *v13 = v11;
      v13[1] = v11 - KeKernelStackSize;
      v13[2] = *(_DWORD *)(v6 + 40);
      v13[3] = *(_DWORD *)(v6 + 36);
      v13[5] = *(_DWORD *)(v6 + 32);
      v20 = *(_DWORD **)(v6 + 96);
      v21 = v20[29];
      v14 = ((v5 + 7) & 0xFFFFFFF8) + 32;
      v15 = (_DWORD *)((v21 - v14) & 0xFFFFFFF8);
      ProbeForWrite((unsigned int)v15, v14, 8);
      memmove((int)(v15 + 6), a2, a3);
      *v15 = v15 + 6;
      v15[1] = a3;
      v15[2] = a1;
      v15[4] = v21;
      v15[5] = v20[32];
      v15[3] = v20[30];
      v20[29] = v15;
      KiCallUserMode(v24, a5, v12 - 24, v12, v17, v18);
    }
    --*(_BYTE *)(v6 + 447);
    v10 = -1073741801;
  }
  else
  {
    *(_BYTE *)(v6 + 447) = v9 - 1;
    v10 = -1073741571;
  }
  return v10;
}
