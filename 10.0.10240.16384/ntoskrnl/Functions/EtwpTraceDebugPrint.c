// EtwpTraceDebugPrint 
 
int __fastcall EtwpTraceDebugPrint(unsigned __int16 *a1, int a2, int a3)
{
  unsigned int v3; // r3
  int v4; // r2
  int v5; // r3
  _DWORD v7[4]; // [sp+8h] [bp-50h] BYREF
  int v8[16]; // [sp+18h] [bp-40h] BYREF

  v3 = *a1;
  v7[0] = a2;
  v7[1] = a3;
  v4 = 512;
  if ( v3 <= 0x200 )
    v4 = v3;
  v8[0] = (int)v7;
  v8[1] = 0;
  v8[2] = 8;
  v8[3] = 0;
  v5 = *((_DWORD *)a1 + 1);
  v8[6] = v4;
  v8[4] = v5;
  v8[5] = 0;
  v8[7] = 0;
  v8[8] = (int)&EtwpNull;
  v8[9] = 0;
  v8[10] = 1;
  v8[11] = 0;
  return EtwTraceKernelEvent(v8, 3, 0x40000, 2592, 5249282);
}
