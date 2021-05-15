// KeSetCoalescableTimer 
 
int __fastcall KeSetCoalescableTimer(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, int a5)
{
  int v5; // r5
  int v6; // r8
  int v7; // r4
  int v8; // kr08_4
  int v9; // r5
  unsigned int v10; // r6
  int v11; // r0
  unsigned int v12; // r3
  __int64 varg_r0; // [sp+38h] [bp+8h]
  __int64 varg_r2; // [sp+40h] [bp+10h]
  int varg_r2a; // [sp+40h] [bp+10h]
  unsigned int varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  HIDWORD(a1) = HIDWORD(a2);
  v5 = 0;
  varg_r2 = a2;
  v6 = a1;
  if ( a4 )
  {
    HIDWORD(a2) = 10000 * a4;
    if ( is_mul_ok(a4, 0x2710u) && HIDWORD(a2) <= 0xFC0000 )
    {
      v7 = a3;
    }
    else
    {
      v8 = HIDWORD(a2) - 16515072;
      HIDWORD(a2) = (10000 * (unsigned __int64)a4 - 16515072) >> 32;
      LODWORD(a1) = v8;
      if ( a1 >= 0 )
      {
        v10 = (unsigned __int64)(a2 + a1) >> 32;
        v9 = a2 + v8;
        if ( a2 + a1 < __SPAIR64__(HIDWORD(a1), a2) )
        {
          v9 = -1;
          v10 = 0x7FFFFFFF;
        }
      }
      else
      {
        v10 = (__PAIR64__(HIDWORD(a1), a2) - __PAIR64__(HIDWORD(a2), v8)) >> 32;
        v9 = a2 - v8;
        if ( (__int64)(__PAIR64__(HIDWORD(a1), a2) - __PAIR64__(HIDWORD(a2), v8)) > __SPAIR64__(HIDWORD(a1), a2) )
        {
          v9 = 0;
          v10 = 0x80000000;
        }
      }
      v7 = a3;
      if ( a3 )
      {
        LODWORD(a2) = v8;
        v11 = _rt_sdiv64(10000i64, a2);
        v7 = -1;
        if ( v11 + a3 >= a3 )
          v7 = v11 + a3;
      }
      a2 = (unsigned int)v9 | 0xFC000000000000i64;
      varg_r2a = v9;
      varg_r3 = v10;
      HIDWORD(a1) = v10;
    }
    v12 = HIDWORD(a2) >> 18;
    if ( v12 > 0x3F )
      LOBYTE(v12) = 63;
    v5 = (unsigned __int8)(4 * v12);
  }
  else
  {
    v7 = a3;
  }
  return KiSetTimerEx(v6, HIDWORD(a1), a2, HIDWORD(a1), v7, v5, a5);
}
