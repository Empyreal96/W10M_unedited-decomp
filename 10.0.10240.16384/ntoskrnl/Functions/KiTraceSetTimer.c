// KiTraceSetTimer 
 
int *__fastcall KiTraceSetTimer(int a1, int a2, int a3)
{
  unsigned int v4; // r2
  unsigned int v5; // r5
  int v6; // r2
  char v7; // r3
  char v8; // r2
  int v9; // r3
  int v10; // r1
  int v12[3]; // [sp+8h] [bp-38h] BYREF
  __int16 v13; // [sp+14h] [bp-2Ch]
  char v14; // [sp+16h] [bp-2Ah]
  char v15; // [sp+17h] [bp-29h]
  int v16; // [sp+18h] [bp-28h]
  char v17; // [sp+1Ch] [bp-24h]
  char v18; // [sp+1Dh] [bp-23h]
  __int16 v19; // [sp+1Eh] [bp-22h]
  int v20[8]; // [sp+20h] [bp-20h] BYREF

  v4 = *(_DWORD *)(a1 + 36);
  v12[0] = *(_DWORD *)(a1 + 16);
  v12[1] = *(_DWORD *)(a1 + 20);
  v16 = *(_DWORD *)(a1 + 40);
  v17 = *(_BYTE *)(a1 + 1) >> 2;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)a1);
  while ( __strex(v5 & 0xFFFFFF7F, (unsigned int *)a1) );
  if ( v4 >= KeNumberProcessors_0 )
    v6 = 0;
  else
    v6 = (int)*(&KiProcessorBlock + v4);
  v12[2] = a1;
  v13 = *(unsigned __int8 *)(v6 + 1052);
  v7 = *(_BYTE *)(v6 + 1053);
  v8 = 0;
  v15 = 0;
  v14 = v7;
  v18 = 0;
  v19 = 0;
  if ( v17 )
  {
    v8 = 1;
    v15 = 1;
  }
  if ( a2 )
    v15 = v8 | 2;
  if ( *(_DWORD *)(a1 + 40) )
  {
    v9 = 3922;
  }
  else
  {
    v9 = 3923;
    if ( !a3 )
    {
LABEL_16:
      v10 = 8395522;
      goto LABEL_17;
    }
    v9 = 3924;
  }
  if ( !a3 )
    goto LABEL_16;
  v10 = 1538;
LABEL_17:
  v20[0] = (int)v12;
  v20[1] = 0;
  v20[2] = 24;
  v20[3] = 0;
  return EtwTraceKernelEvent(v20, 1, 0x40020000u, v9, v10);
}
