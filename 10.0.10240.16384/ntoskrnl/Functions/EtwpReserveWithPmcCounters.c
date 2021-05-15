// EtwpReserveWithPmcCounters 
 
int __fastcall EtwpReserveWithPmcCounters(_DWORD *a1, __int16 a2, int a3, unsigned int *a4, int a5, int a6)
{
  int v7; // r4
  int v8; // r6
  int v9; // r7
  unsigned int v10; // r10
  unsigned int v11; // r4
  int v12; // r0
  int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r0
  int v19; // [sp+10h] [bp-20h]

  v7 = *(_DWORD *)(a1[157] + 28);
  v19 = a1[157];
  __dmb(0xBu);
  v8 = (unsigned __int8)v7;
  v9 = (unsigned __int8)v7 + 2;
  v10 = a3 + 8 * v9;
  v11 = KeGetCurrentIrql(a1);
  if ( v11 < 2 )
    KfRaiseIrql(2);
  v12 = EtwpReserveTraceBuffer(a1, v10, a4, (__int64 *)a5, a6);
  v13 = v12;
  if ( v12 )
  {
    *(_DWORD *)(v12 + 8) = *(_DWORD *)a5;
    v15 = *(_DWORD *)(a5 + 4);
    *(_WORD *)(v12 + 4) = v10;
    *(_DWORD *)(v12 + 12) = v15;
    *(_DWORD *)v12 = (unsigned __int8)a6 | ((v8 | 0xFFC01000) << 8);
    *(_WORD *)(v12 + 6) = a2;
    v16 = *(_DWORD *)(v19 + 4 * *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) + 32);
    if ( v16 )
      off_617A94(v16, v13 + 16);
    else
      memset((_BYTE *)(v13 + 16), 0, 8 * v8);
    if ( v11 < 2 )
      KfLowerIrql(v11);
    result = v13 + 8 * v9;
  }
  else
  {
    if ( v11 < 2 )
      KfLowerIrql(v11);
    result = 0;
  }
  return result;
}
