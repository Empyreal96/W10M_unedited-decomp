// PerfInfoLogIpi 
 
int __fastcall PerfInfoLogIpi(int a1, int a2)
{
  int varsC; // [sp+14h] [bp+Ch] BYREF

  varsC = a2;
  return EtwTraceTimedEvent(3931, 0x40400000u, (int)&varsC, 4, 4196866, a1);
}
