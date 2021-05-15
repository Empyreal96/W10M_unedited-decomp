// EtwpUpdateGroupMasks 
 
int __fastcall EtwpUpdateGroupMasks(int *a1, int a2)
{
  int v4; // r0
  unsigned int v6; // r4
  int *v7; // r5
  int v8; // r0
  int v9; // t1
  int v10; // r8
  int v11; // r2
  int v12; // r3
  int v13; // r4
  _DWORD *v14; // r7
  int v15; // r2
  int v16; // r3
  int v17; // r4
  int v18; // r4
  unsigned int *v19; // r9
  unsigned int v20; // r1
  unsigned __int8 *v21; // r9
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2
  _DWORD *v25; // r7
  int v26; // r3
  int v27; // [sp+0h] [bp-68h]
  int v28; // [sp+4h] [bp-64h]
  char v29[32]; // [sp+8h] [bp-60h] BYREF
  char v30[64]; // [sp+28h] [bp-40h] BYREF

  v4 = EtwpMapEnableFlags(a2, 1);
  if ( a2 )
    return sub_7D01F8(v4);
  v21 = (unsigned __int8 *)(a1 + 126);
  v22 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
  v23 = v22;
  do
    v24 = __ldrex(v21);
  while ( __strex(v24 | 1, v21) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 126, v22, (unsigned int)(a1 + 126));
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  v28 = *((unsigned __int8 *)a1 + 610);
  v25 = &EtwpGroupMasks[8 * v28];
  if ( v25 )
  {
    v26 = v25[1];
    if ( (v26 & 4) != 0 && (v26 & 0x100) != 0 )
      EtwpCCSwapStop(a1[31], 1, 256);
  }
  v6 = 0;
  v7 = &EtwpGroupMasks[8 * v28];
  do
  {
    v8 = *(_DWORD *)v6;
    v9 = *v7++;
    *(_DWORD *)&v29[v6] = v9 & ~*(_DWORD *)v6;
    *(_DWORD *)&v30[v6] = v8 & ~v9;
    v6 += 4;
  }
  while ( v6 < 0x20 );
  v10 = *a1;
  EtwpLogGroupMask(*a1, v25, 32);
  if ( (a1[3] & 0x400) != 0 )
  {
    v27 = 1;
  }
  else
  {
    v27 = 0;
    EtwpKernelTraceRundown(v29, v10, 0);
  }
  v11 = MEMORY[4];
  v12 = MEMORY[8];
  v13 = MEMORY[0xC];
  *v25 = MEMORY[0];
  v25[1] = v11;
  v25[2] = v12;
  v25[3] = v13;
  v14 = v25 + 4;
  v15 = MEMORY[0x14];
  v16 = MEMORY[0x18];
  v17 = MEMORY[0x1C];
  *v14 = MEMORY[0x10];
  v14[1] = v15;
  v14[2] = v16;
  v14[3] = v17;
  v18 = EtwpUpdateKernelGroupMasks(v10, v28);
  v19 = (unsigned int *)(a1 + 126);
  if ( v18 >= 0 )
  {
    EtwpLogGroupMask(v10, 0, 5);
    if ( !v27 || (a1[152] & 2) != 0 )
      EtwpKernelTraceRundown(v30, v10, 1);
  }
  EtwpLogAlwaysPresentRundown(v10);
  __dmb(0xBu);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 - 1, v19) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock(v19);
  KeAbPostRelease((unsigned int)v19);
  return v18;
}
