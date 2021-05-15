// EtwpTraceNetwork 
 
int *__fastcall EtwpTraceNetwork(unsigned __int16 a1, int a2, int a3)
{
  int v5[8]; // [sp+8h] [bp-20h] BYREF

  v5[0] = a2;
  v5[1] = 0;
  v5[2] = a3;
  v5[3] = 0;
  if ( (dword_61AD40 & 0x10000) != 0 )
    EtwpNetProvTraceNetwork((int)v5, a1);
  return EtwTraceKernelEvent(v5, 1, 0x10000u, a1, 4200450);
}
