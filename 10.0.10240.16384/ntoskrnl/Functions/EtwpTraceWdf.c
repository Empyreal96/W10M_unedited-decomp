// EtwpTraceWdf 
 
int *__fastcall EtwpTraceWdf(int a1, int a2, unsigned int a3, int a4, unsigned __int8 a5)
{
  int v6[8]; // [sp+8h] [bp-20h] BYREF

  v6[0] = a1;
  v6[2] = a2;
  v6[1] = 0;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, a3, a4, a5 | (unsigned int)&dword_401800);
}
