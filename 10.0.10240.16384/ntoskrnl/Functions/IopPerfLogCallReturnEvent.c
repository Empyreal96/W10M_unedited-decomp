// IopPerfLogCallReturnEvent 
 
int *__fastcall IopPerfLogCallReturnEvent(int a1, int a2)
{
  int v3[2]; // [sp+8h] [bp-28h] BYREF
  int v4[8]; // [sp+10h] [bp-20h] BYREF

  v3[1] = a2;
  v4[0] = (int)v3;
  v4[1] = 0;
  v4[2] = 8;
  v4[3] = 0;
  v3[0] = a1;
  return EtwTraceKernelEvent(v4, 1, 0x20000010u, 291, 4200450);
}
