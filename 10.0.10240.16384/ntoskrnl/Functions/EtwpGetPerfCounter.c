// EtwpGetPerfCounter 
 
__int64 __fastcall EtwpGetPerfCounter(int a1, __int64 a2)
{
  __int64 v4; // [sp+0h] [bp-8h] BYREF

  v4 = a2;
  KeQueryPerformanceCounter(&v4, 0);
  return v4;
}
