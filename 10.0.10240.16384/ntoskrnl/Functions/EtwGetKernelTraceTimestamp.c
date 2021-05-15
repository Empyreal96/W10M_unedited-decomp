// EtwGetKernelTraceTimestamp 
 
int __fastcall EtwGetKernelTraceTimestamp(__int64 a1)
{
  int v1; // r9
  int v2; // r8
  unsigned int v3; // r4
  unsigned int i; // r5
  unsigned int v5; // r2
  int (*v6)(void); // r3
  unsigned int v8; // [sp+0h] [bp-30h]
  __int64 v9[5]; // [sp+8h] [bp-28h] BYREF

  v1 = a1;
  v2 = 0;
  v3 = EtwpActiveSystemLoggers;
  for ( i = __clz(__rbit(EtwpActiveSystemLoggers)); 1 != (unsigned __int8)(i >> 5); i = __clz(__rbit(v3)) )
  {
    v3 &= v3 - 1;
    if ( &EtwpGroupMasks[8 * i] && (EtwpGroupMasks[8 * i + (HIDWORD(a1) >> 29)] & HIDWORD(a1) & 0x1FFFFFFF) != 0 )
    {
      LODWORD(a1) = 1;
      v2 |= 1 << EtwpSystemLogger[2 * i + 1];
    }
  }
  v5 = 0;
  v8 = 0;
  do
  {
    if ( ((1 << v5) & v2) != 0 )
    {
      v6 = (int (*)(void))*(&EtwpSystemTimeStamp + v5);
      if ( (char *)v6 == (char *)EtwpGetPerfCounter )
      {
        KeQueryPerformanceCounter(v9, 0);
        a1 = v9[0];
      }
      else
      {
        LODWORD(a1) = v6();
      }
      *(_QWORD *)(v1 + 8 * v8) = a1;
    }
    else
    {
      *(_DWORD *)(v1 + 8 * v5) = 0;
      *(_DWORD *)(v1 + 8 * v5 + 4) = 0;
    }
    v5 = v8 + 1;
    v8 = v5;
  }
  while ( v5 < 2 );
  return a1;
}
