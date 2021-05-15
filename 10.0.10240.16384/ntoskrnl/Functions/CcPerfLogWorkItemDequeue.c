// CcPerfLogWorkItemDequeue 
 
int *__fastcall CcPerfLogWorkItemDequeue(int a1)
{
  int v2; // [sp+8h] [bp-28h] BYREF
  int v3[8]; // [sp+10h] [bp-20h] BYREF

  v3[0] = (int)&v2;
  v3[1] = 0;
  v3[2] = 4;
  v3[3] = 0;
  v2 = a1;
  return EtwTraceKernelEvent(v3, 1, 0x80020000, 5633, 4200706);
}
