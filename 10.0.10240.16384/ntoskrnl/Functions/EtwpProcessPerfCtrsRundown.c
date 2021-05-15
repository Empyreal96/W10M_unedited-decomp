// EtwpProcessPerfCtrsRundown 
 
int __fastcall EtwpProcessPerfCtrsRundown(_DWORD *a1, int a2, int a3)
{
  int v5; // r0
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v13[11]; // [sp+8h] [bp-60h] BYREF
  int v14; // [sp+34h] [bp-34h]
  int v15; // [sp+38h] [bp-30h]
  int v16; // [sp+3Ch] [bp-2Ch]
  int v17; // [sp+40h] [bp-28h]
  int v18[8]; // [sp+48h] [bp-20h] BYREF

  v13[0] = a1[44];
  v5 = ObGetProcessHandleCount((int)a1, 0, a3, v13[0]);
  v13[1] = a1[148];
  v13[2] = v5;
  v13[9] = a1[57];
  v13[4] = a1[56];
  v13[10] = a1[136] << 12;
  v13[5] = a1[144] << 12;
  v6 = a1[53];
  __dmb(0xBu);
  v15 = v6;
  v7 = a1[55];
  __dmb(0xBu);
  v13[7] = v7;
  v8 = a1[52];
  __dmb(0xBu);
  v16 = v8;
  v9 = a1[54];
  __dmb(0xBu);
  v13[8] = v9;
  v10 = a1[121];
  __dmb(0xBu);
  v14 = v10 << 12;
  v11 = a1[122];
  __dmb(0xBu);
  v13[6] = v11 << 12;
  v17 = v14;
  v18[0] = (int)v13;
  v18[1] = 0;
  v18[2] = 60;
  v18[3] = 0;
  return EtwpLogKernelEvent(v18, a2, 1, 801, 4200450);
}
