// KeRebaselineSystemTime 
 
int __fastcall KeRebaselineSystemTime(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // [sp+0h] [bp-8h] BYREF
  int v6; // [sp+4h] [bp-4h]

  v5 = a3;
  v6 = a4;
  result = KeQueryPerformanceCounter(&v5, 0);
  MEMORY[0xFFFF9348] = v5;
  MEMORY[0xFFFF934C] = v6;
  KiSystemTimeErrorAccumulator = 0i64;
  return result;
}
