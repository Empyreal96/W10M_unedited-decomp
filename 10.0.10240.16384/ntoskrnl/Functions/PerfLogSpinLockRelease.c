// PerfLogSpinLockRelease 
 
unsigned int __fastcall PerfLogSpinLockRelease(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  char v6; // r7
  unsigned int v7; // r5
  unsigned int v8; // r1
  int v9; // r10
  unsigned int v10; // r8
  unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r8
  int v15; // r3
  char v16; // r3
  int v17; // r2
  int v18; // r3
  bool v19; // zf
  char v20; // r3
  unsigned int v21; // r7
  unsigned int *v22; // r5
  unsigned int v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r3
  unsigned int *v26; // r4
  unsigned int v27; // r1
  unsigned int v28; // r2
  unsigned int v29; // r3
  char v30; // lr
  unsigned int v31; // [sp+8h] [bp-78h]
  int v34; // [sp+18h] [bp-68h]
  int v35[10]; // [sp+20h] [bp-60h] BYREF
  char v36; // [sp+48h] [bp-38h]
  char v37; // [sp+49h] [bp-37h]
  char v38; // [sp+4Ah] [bp-36h]
  int v39[12]; // [sp+50h] [bp-30h] BYREF

  v34 = result;
  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
  v5 = v4 + 1600;
  v6 = *(_BYTE *)(v4 + 1856);
  if ( v6 )
  {
    LOBYTE(v7) = *(_BYTE *)(v4 + 1856);
    while ( 1 )
    {
      v7 = (unsigned __int8)(v7 - 1);
      if ( *(_DWORD *)(v5 + 32 * v7 + 8) == result )
        break;
      if ( !v7 )
      {
        ++*(_DWORD *)(v4 + 1864);
        return result;
      }
    }
    v8 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v31 = v8;
    v9 = v5 + 32 * v7;
    if ( !*(_BYTE *)(v4 + 1857) )
    {
      if ( EtwpSpinLockHoldThreshold && a3 - *(_DWORD *)v9 > (unsigned int)EtwpSpinLockHoldThreshold )
        goto LABEL_18;
      v10 = *(_DWORD *)(v9 + 16);
      if ( v10 >= EtwpSpinLockSpinThreshold )
      {
        v11 = *(_DWORD *)(v8 + 3716);
        if ( !EtwpSpinLockContentionSampleRate )
          __brkdiv0();
        result = v11 / EtwpSpinLockContentionSampleRate;
        if ( !(v11 % EtwpSpinLockContentionSampleRate) )
          goto LABEL_18;
        v8 = v31;
      }
      if ( !v10 )
      {
        v12 = *(_DWORD *)(v8 + 3712) - *(_DWORD *)(v8 + 3716);
        if ( !EtwpSpinLockAcquireSampleRate )
          __brkdiv0();
        result = v12 / EtwpSpinLockAcquireSampleRate;
        if ( !(v12 % EtwpSpinLockAcquireSampleRate) )
        {
LABEL_18:
          v13 = 1;
          goto LABEL_20;
        }
      }
    }
    v13 = 0;
LABEL_20:
    if ( !v13 )
      goto LABEL_33;
    v14 = *(unsigned __int8 *)(v31 + 16);
    *(_BYTE *)(v4 + 1857) = 1;
    v35[0] = v34;
    v35[1] = a2;
    v35[4] = a3;
    v35[5] = a4;
    v15 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
    v37 = v6;
    v35[8] = v15;
    v36 = KeGetCurrentIrql(result);
    v35[2] = *(_DWORD *)v9;
    v35[3] = *(_DWORD *)(v9 + 4);
    v35[6] = *(_DWORD *)(v9 + 12);
    v35[7] = *(_DWORD *)(v9 + 16);
    v35[9] = *(_DWORD *)(v31 + 2304) - *(_DWORD *)(v9 + 20);
    v16 = *(_BYTE *)(v9 + 24);
    v38 = v16;
    if ( v14 == 1 )
    {
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v17 = 0;
      }
      else
      {
        __disable_irq();
        v17 = 1;
      }
      v18 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      if ( v17 )
        __enable_irq();
      v19 = (v18 & 0x10001) == 0;
      v16 = v38;
      if ( !v19 )
      {
        v20 = v38 | 0x40;
LABEL_31:
        v38 = v20;
        goto LABEL_32;
      }
    }
    else if ( !v14 )
    {
LABEL_32:
      v39[0] = (int)v35;
      v39[1] = 0;
      v39[2] = 48;
      v39[3] = 0;
      result = (unsigned int)EtwTraceKernelEvent(v39, 1, 0x20010000u, 1321, 1538);
      *(_BYTE *)(v4 + 1857) = 0;
LABEL_33:
      v21 = (unsigned __int8)(v6 - 1);
      while ( 1 )
      {
        v30 = v7;
        if ( v7 >= v21 )
          break;
        v22 = (unsigned int *)(v5 + 32 * v7);
        v23 = v22[9];
        v24 = v22[10];
        v25 = v22[11];
        v26 = v22 + 12;
        *v22 = v22[8];
        v22[1] = v23;
        v22[2] = v24;
        v22[3] = v25;
        v22 += 4;
        result = *v26;
        v27 = v26[1];
        v28 = v26[2];
        v29 = v26[3];
        *v22 = *v26;
        v22[1] = v27;
        v22[2] = v28;
        v22[3] = v29;
        v7 = (unsigned __int8)(v30 + 1);
      }
      --*(_BYTE *)(v5 + 256);
      return result;
    }
    v20 = v16 | 0x80;
    goto LABEL_31;
  }
  return result;
}
