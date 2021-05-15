// EtwpTraceFltIo 
 
int *__fastcall EtwpTraceFltIo(int a1, int a2, unsigned int a3, int a4)
{
  int v5[8]; // [sp+8h] [bp-20h] BYREF

  v5[2] = a2;
  v5[3] = 0;
  v5[0] = a1;
  v5[1] = 0;
  return EtwTraceKernelEvent(v5, 1, a3, a4, 5249283);
}
