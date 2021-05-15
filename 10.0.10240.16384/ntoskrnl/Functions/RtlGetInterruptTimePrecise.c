// RtlGetInterruptTimePrecise 
 
int __fastcall RtlGetInterruptTimePrecise(_DWORD *a1)
{
  __int64 v2; // kr08_8
  int v3; // r1
  int v4; // r2
  int v5; // r6
  unsigned __int64 v6; // kr10_8
  unsigned int v8; // r0
  unsigned int v9; // r4
  unsigned __int64 v10; // [sp+0h] [bp-38h]
  int v11; // [sp+8h] [bp-30h]
  int v12[10]; // [sp+10h] [bp-28h] BYREF

  while ( 1 )
  {
    v2 = MEMORY[0xFFFF9340];
    __dmb(0xBu);
    if ( (v2 & 1) == 0 )
    {
      v10 = MEMORY[0xFFFF9350];
      v11 = MEMORY[0xFFFF9008];
      KeQueryPerformanceCounter(v12, 0);
      __dmb(0xBu);
      if ( MEMORY[0xFFFF9340] == v2 )
        break;
    }
    __dmb(0xAu);
    __yield();
  }
  v4 = v12[0];
  v3 = v12[1];
  v5 = 0;
  *a1 = v12[0];
  a1[1] = v3;
  if ( __PAIR64__(v3, v4) > v10 )
  {
    v6 = __PAIR64__(v3, v4) - v10 - 1;
    if ( MEMORY[0xFFFF9369] )
      return sub_54118C();
    v9 = (MEMORY[0xFFFF9364] * (unsigned __int64)(unsigned int)v6) >> 32;
    v8 = MEMORY[0xFFFF9364] * v6;
    if ( HIDWORD(v6) )
    {
      v5 = HIDWORD(v6) * MEMORY[0xFFFF9364]
         + ((MEMORY[0xFFFF9360] * (unsigned __int64)HIDWORD(v6) + __PAIR64__(v9, v8)) >> 32);
    }
    else
    {
      v5 = (__PAIR64__(v9, (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v6) >> 32) + v8) >> 32;
      v12[0] = (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v6) >> 32;
    }
  }
  return v11 + v5;
}
