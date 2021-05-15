// PerfLogExecutiveResourceWait 
 
int *__fastcall PerfLogExecutiveResourceWait(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  int v5; // r0
  int v6; // r1
  int v7; // r7
  int v8; // r8
  unsigned int v9; // r3
  unsigned int v10; // r6
  int v11; // r9
  int v12; // r10
  int *result; // r0
  int *v14; // r4
  unsigned __int64 v15; // r6
  int v16; // [sp+8h] [bp-70h]
  _DWORD v19[2]; // [sp+18h] [bp-60h] BYREF
  unsigned __int64 v20; // [sp+20h] [bp-58h]
  int v21; // [sp+28h] [bp-50h]
  int v22; // [sp+2Ch] [bp-4Ch]
  unsigned int v23; // [sp+30h] [bp-48h]
  int v24; // [sp+34h] [bp-44h]
  int v25; // [sp+38h] [bp-40h]
  int v26; // [sp+3Ch] [bp-3Ch]
  int v27; // [sp+40h] [bp-38h]
  int v28[12]; // [sp+48h] [bp-30h] BYREF

  v3 = a2;
  v5 = ReadTimeStampCounter();
  v7 = v6;
  v8 = v5;
  v9 = (unsigned int)KeGetPcr();
  v10 = (v9 & 0xFFFFF000) + 1408;
  v11 = *(unsigned __int8 *)((v9 & 0xFFFFF000) + 0x99C);
  v12 = *(unsigned __int8 *)((v9 & 0xFFFFF000) + 0x99D);
  ++*(_DWORD *)((v9 & 0xFFFFF000) + 0x14B0);
  LOWORD(v16) = v11;
  HIWORD(v16) = (unsigned __int8)v12;
  result = EtwpGetTrackingLockSlotForThread(v3, a1 & 0xFFFF0000);
  v14 = result;
  if ( result )
  {
    ++*(_DWORD *)(v10 + 3892);
    if ( a1 == 65572 || a1 == 65604 )
    {
      result[7] = 4;
      *result = v8;
      result[1] = v7;
      result[5] = v16;
    }
    else if ( a1 == 66084 || a1 == 66116 )
    {
      if ( result[7] == 4 && *((unsigned __int16 *)result + 10) == v11 && *((unsigned __int8 *)result + 22) == v12 )
        v15 = __PAIR64__(v7, v8) - *(_QWORD *)result;
      else
        v15 = 0i64;
      if ( !EtwpExecutiveResourceTimeout )
        __brkdiv0();
      result = (int *)(a3 / EtwpExecutiveResourceTimeout);
      if ( !(a3 % EtwpExecutiveResourceTimeout) )
      {
        v25 = a2;
        v26 = a1;
        v19[0] = 0;
        v19[1] = 0;
        v23 = a3;
        v20 = v15;
        v21 = *v14;
        v22 = v14[1];
        v27 = 0;
        v24 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
        v28[0] = (int)v19;
        v28[1] = 0;
        v28[2] = 48;
        v28[3] = 0;
        result = EtwTraceKernelEvent(v28, 1, 0x20020000u, 1323, 22026242);
      }
    }
  }
  return result;
}
