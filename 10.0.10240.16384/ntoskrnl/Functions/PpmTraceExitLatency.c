// PpmTraceExitLatency 
 
int __fastcall PpmTraceExitLatency(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r0
  int v10; // r4
  __int64 v12; // [sp+8h] [bp-40h] BYREF
  int v13; // [sp+10h] [bp-38h]
  int v14; // [sp+14h] [bp-34h]
  _DWORD v15[12]; // [sp+18h] [bp-30h] BYREF

  v8 = PopFxSystemLatencyLimit;
  v10 = -1;
  __dmb(0xBu);
  if ( v8 == -1 )
    return 0;
  if ( a5 != -1 )
  {
    KeQueryPerformanceCounter(&v12, 0);
    v10 = PpmConvertTimeTo(v12 - *a6, (unsigned __int64)(v12 - *(_QWORD *)a6) >> 32) + a5;
  }
  if ( (dword_682608 & 0x4000000) != 0 )
  {
    if ( a5 == -1 )
      a4 |= 4u;
    v12 = (unsigned int)v15;
    v13 = 20;
    v14 = 0;
    v15[0] = a4;
    v15[1] = a3;
    v15[2] = a2;
    v15[3] = a5;
    v15[4] = v10;
    EtwTraceKernelEvent((int *)&v12, 1, 0x44000000u, 4668, 1538);
  }
  return 1;
}
