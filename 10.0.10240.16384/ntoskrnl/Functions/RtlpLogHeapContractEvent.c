// RtlpLogHeapContractEvent 
 
int *__fastcall RtlpLogHeapContractEvent(_DWORD *a1, int a2, int a3, int a4, char a5, int a6)
{
  int v7; // r1
  int v8; // r3
  int v9; // r0
  _DWORD *v11; // [sp+8h] [bp-38h] BYREF
  int v12; // [sp+Ch] [bp-34h]
  int v13; // [sp+10h] [bp-30h]
  int v14; // [sp+14h] [bp-2Ch]
  int v15; // [sp+18h] [bp-28h]
  int v16; // [sp+1Ch] [bp-24h] BYREF
  int v17[2]; // [sp+20h] [bp-20h] BYREF
  int v18[6]; // [sp+28h] [bp-18h] BYREF

  v13 = a2;
  v14 = a4;
  v7 = a1[29];
  v15 = 0;
  v16 = 0;
  v17[0] = 0;
  v8 = a1[121];
  v11 = a1;
  v17[1] = v8 - 8 * v7;
  if ( a5 )
    v12 = a3 - a6;
  else
    v12 = a3;
  v9 = GetUCBytes((int)a1, &v16, v17);
  v15 = v16 - v9 - a1[140];
  v18[0] = (int)&v11;
  v18[1] = 0;
  v18[2] = 32;
  v18[3] = 0;
  return EtwTraceKernelEvent(v18, 1, 0x40000020u, 4138, 272636163);
}
