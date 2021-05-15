// RtlpLogHeapExtendEvent 
 
int *__fastcall RtlpLogHeapExtendEvent(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r0
  _DWORD v8[4]; // [sp+8h] [bp-38h] BYREF
  int v9; // [sp+18h] [bp-28h]
  int v10; // [sp+1Ch] [bp-24h] BYREF
  int v11[2]; // [sp+20h] [bp-20h] BYREF
  int v12[6]; // [sp+28h] [bp-18h] BYREF

  v8[2] = a2;
  v8[3] = a4;
  v9 = 0;
  v10 = 0;
  v11[0] = 0;
  v5 = a1[121];
  v8[0] = a1;
  v8[1] = a3;
  v11[1] = v5 - 8 * a1[29];
  v6 = GetUCBytes((int)a1, &v10, v11);
  v9 = v10 - a1[140] - v6;
  v12[0] = (int)v8;
  v12[1] = 0;
  v12[2] = 32;
  v12[3] = 0;
  return EtwTraceKernelEvent(v12, 1, 0x40000020u, 4133, 272636163);
}
