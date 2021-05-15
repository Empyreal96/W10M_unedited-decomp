// KeQueryInterruptTimePrecise 
 
int __fastcall KeQueryInterruptTimePrecise(unsigned int *a1)
{
  __int64 v2; // r0
  int v3; // r4
  int v4; // r5
  unsigned int v5; // r10
  int v6; // r1
  int v8; // r8
  int v9; // r1
  unsigned int v10; // r5
  int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // [sp+0h] [bp-40h]
  unsigned int v14; // [sp+4h] [bp-3Ch]
  unsigned int v15; // [sp+8h] [bp-38h]
  int v16; // [sp+Ch] [bp-34h]
  int v17[10]; // [sp+18h] [bp-28h] BYREF

  v2 = RtlBeginReadTickLock(-27840);
  v3 = HIDWORD(v2);
  v4 = v2;
  v13 = MEMORY[0xFFFF9350];
  v15 = MEMORY[0xFFFF9354];
  v16 = MEMORY[0xFFFF9008];
  KeQueryPerformanceCounter(v17, 0);
  v5 = v17[0];
  v14 = v17[1];
  if ( !RtlTryEndReadTickLock(-27840, v6, v4, v3) )
    return sub_547B84();
  *a1 = v5;
  a1[1] = v14;
  v8 = 0;
  if ( v14 >= v15 && (v14 > v15 || v5 > v13) )
  {
    v10 = (__PAIR64__(v14, v5) - __PAIR64__(v15, v13) - 1) >> 32;
    v9 = v5 - v13 - 1;
    if ( MEMORY[0xFFFF9369] )
    {
      v10 = __PAIR64__(v10, v9) << MEMORY[0xFFFF9369] >> 32;
      v9 <<= MEMORY[0xFFFF9369];
    }
    v12 = (MEMORY[0xFFFF9364] * (unsigned __int64)(unsigned int)v9) >> 32;
    v11 = MEMORY[0xFFFF9364] * v9;
    if ( v10 )
    {
      v8 = v10 * MEMORY[0xFFFF9364] + ((MEMORY[0xFFFF9360] * (unsigned __int64)v10 + __PAIR64__(v12, v11)) >> 32);
    }
    else
    {
      v17[0] = (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v9) >> 32;
      v8 = (__PAIR64__(v12, (MEMORY[0xFFFF9360] * (unsigned __int64)(unsigned int)v9) >> 32) + (unsigned int)v11) >> 32;
    }
  }
  return v16 + v8;
}
