// KdpPrompt 
 
int __fastcall KdpPrompt(int *a1, unsigned int a2, int a3, unsigned int a4, char a5, int a6, int a7)
{
  int v7; // r6
  int v9; // r5
  int *v10; // r8
  _BYTE *v11; // r3
  __int64 v12; // r2
  int v13; // r4
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r4
  _BYTE v19[512]; // [sp-200h] [bp-438h] BYREF
  int v20[128]; // [sp+0h] [bp-238h] BYREF
  int v21; // [sp+200h] [bp-38h] BYREF
  _BYTE *v22; // [sp+204h] [bp-34h]
  int *v23; // [sp+20Ch] [bp-2Ch]
  unsigned __int16 v24; // [sp+210h] [bp-28h] BYREF
  int *v25; // [sp+214h] [bp-24h]
  int *varg_r0; // [sp+240h] [bp+8h]
  unsigned int varg_r1; // [sp+244h] [bp+Ch]
  int varg_r2; // [sp+248h] [bp+10h]
  unsigned int varg_r3; // [sp+24Ch] [bp+14h]

  v7 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  v9 = a2;
  varg_r1 = a2;
  v10 = a1;
  varg_r0 = a1;
  if ( a2 > 0x200 )
  {
    v9 = 512;
    LOWORD(varg_r1) = 512;
  }
  if ( a4 > 0x200 )
  {
    v7 = 512;
    LOWORD(varg_r3) = 512;
  }
  if ( a5 )
  {
    if ( v9 && ((unsigned int)a1 + v9 > MmUserProbeAddress || (int *)((char *)a1 + v9) < a1) )
      *(_BYTE *)MmUserProbeAddress = 0;
    v23 = v20;
    KdpQuickMoveMemory((int)v20, a1, v9);
    v10 = v20;
    varg_r0 = v20;
    ProbeForWrite(a3, v7, 1);
    v11 = v19;
    v23 = (int *)v19;
  }
  else
  {
    v11 = (_BYTE *)a3;
  }
  v22 = v11;
  LOWORD(v21) = 0;
  HIWORD(v21) = v7;
  v25 = v10;
  v24 = v9;
  KdLogDbgPrint(&v24);
  v13 = KdEnterDebugger(a6, a7, v12);
  while ( KdpPromptString(&v24, &v21) == 1 )
    ;
  KdExitDebugger(v13, v14, v15, v16);
  v17 = (unsigned __int16)v21;
  if ( a5 == 1 )
    KdpQuickMoveMemory(a3, v22, (unsigned __int16)v21);
  return v17;
}
