// KiTraceCancelTimer2 
 
int *__fastcall KiTraceCancelTimer2(int a1, int a2)
{
  int v3; // [sp+8h] [bp-28h] BYREF
  int v4[8]; // [sp+10h] [bp-20h] BYREF

  v3 = -927066983 * (KiWaitNever ^ __ROR4__(bswap32(KiWaitAlways ^ a1) ^ a2, KiWaitNever));
  v4[0] = (int)&v3;
  v4[1] = 0;
  v4[2] = 4;
  v4[3] = 0;
  return EtwTraceKernelEvent(v4, 1, 0x40020000u, 3946, 1538);
}
