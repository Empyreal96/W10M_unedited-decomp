// VfFillAllocatedMemory 
 
_BYTE *__fastcall VfFillAllocatedMemory(_BYTE *a1, unsigned int a2, int a3, int a4)
{
  int v6; // r3
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  KeQueryPerformanceCounter(v8, 0);
  if ( a2 < 0x100 )
    return memset(a1, LOBYTE(v8[0]) | 1, a2);
  v6 = LOBYTE(v8[0]) | 1 | ((LOBYTE(v8[0]) | 1) << 8);
  return RtlFillMemoryUlong(a1, 0x100u, v6 | (v6 << 16));
}
