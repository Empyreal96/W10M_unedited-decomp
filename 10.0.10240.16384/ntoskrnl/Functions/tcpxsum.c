// tcpxsum 
 
int __fastcall tcpxsum(unsigned __int32 a1, uint32x4_t *a2, unsigned int a3)
{
  int32x4_t v3; // q0
  uint32x4_t v4; // q2
  bool v5; // cf
  uint32x4_t v6; // q0
  uint32x4_t v7; // q1
  uint32x4_t v8; // q1
  unsigned __int32 v9; // r3
  unsigned __int32 v10; // r12
  unsigned __int32 v11; // r3
  int v12; // r3
  int32x4x2_t v14; // 0:q2.16,16:q0.16

  a1 = (unsigned __int16)a1;
  __pld(a2);
  if ( a3 >= 0x10 )
  {
    v4 = 0ui64;
    v5 = a3 >= 0x20;
    a3 -= 32;
    if ( v5 )
    {
      v5 = a3 >= 0x20;
      a3 -= 32;
      __pld(&a2[2]);
      for ( ; v5; v4 = vpadalq_u32(vpadalq_u32(v4, v6), v7) )
      {
        __pld(&a2[4]);
        v5 = a3 >= 0x20;
        a3 -= 32;
        v6 = *a2;
        v7 = a2[1];
        a2 += 2;
      }
      v3 = *a2;
      v8 = a2[1];
      a2 += 2;
      v4 = vpadalq_u32(vpadalq_u32(v4, v3), v8);
    }
    if ( (a3 & 0x10) != 0 )
    {
      v3 = *a2++;
      v4 = vpadalq_u32(v4, v3);
    }
    v14 = vzipq_s32(vpaddlq_u16(vpaddlq_u32(vpaddlq_u32(v4))), v3);
    a1 = (unsigned __int16)a1 + vaddq_s32(v14.val[0], v14.val[1]).n128_u32[0];
  }
  if ( (a3 & 8) != 0 )
  {
    v9 = a2->n128_u32[0];
    v10 = a2->n128_u32[1];
    a2 = (uint32x4_t *)((char *)a2 + 8);
    a1 += (unsigned __int16)v9
        + (unsigned __int16)__ROR4__(v9, 16)
        + (unsigned __int16)v10
        + (unsigned __int16)__ROR4__(v10, 16);
  }
  if ( (a3 & 4) != 0 )
  {
    v11 = a2->n128_u32[0];
    a2 = (uint32x4_t *)((char *)a2 + 4);
    a1 += (unsigned __int16)v11 + (unsigned __int16)__ROR4__(v11, 16);
  }
  if ( (a3 & 2) != 0 )
  {
    v12 = a2->n128_u16[0];
    a2 = (uint32x4_t *)((char *)a2 + 2);
    a1 += v12;
  }
  if ( (a3 & 1) != 0 )
    a1 += a2->n128_u8[0];
  return __CFADD__(a1, a1 << 16) + (unsigned __int16)__ROR4__(65537 * a1, 16);
}
