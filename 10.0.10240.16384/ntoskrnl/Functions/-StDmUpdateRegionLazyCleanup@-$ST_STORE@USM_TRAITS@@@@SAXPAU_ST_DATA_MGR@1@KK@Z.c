// -StDmUpdateRegionLazyCleanup@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@KK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmUpdateRegionLazyCleanup(int result, unsigned int a2, int a3)
{
  int v4; // r6
  int v5; // r1
  unsigned int *v6; // r5
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r0
  unsigned int v10; // r3
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r1

  v4 = result;
  if ( a3 )
  {
    v5 = a2 & 0x1F;
    v6 = (unsigned int *)(*(_DWORD *)(result + 124) + 4 * (a2 >> 5));
    if ( (((int)*v6 >> v5) & 1) == 0 )
      return result;
    LOBYTE(v7) = 1;
    if ( (unsigned int)(v5 + 1) > 0x20 )
    {
      if ( v5 )
      {
        __dmb(0xBu);
        do
          v9 = __ldrex(v6);
        while ( __strex(v9 & ~(((1 << (32 - v5)) - 1) << v5), v6) );
        __dmb(0xBu);
        v7 = v5 - 31;
        ++v6;
        if ( (unsigned int)(v5 - 31) >= 0x20 )
        {
          v10 = v7 >> 5;
          do
          {
            v7 -= 32;
            *v6++ = 0;
            --v10;
          }
          while ( v10 );
        }
        if ( !v7 )
          return ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(v4, v4 + 136);
      }
      __dmb(0xBu);
      v11 = ~((1 << v7) - 1);
      do
        v12 = __ldrex(v6);
      while ( __strex(v12 & v11, v6) );
    }
    else
    {
      __dmb(0xBu);
      do
        v8 = __ldrex(v6);
      while ( __strex(v8 & ~(1 << v5), v6) );
    }
    __dmb(0xBu);
    return ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(v4, v4 + 136);
  }
  v13 = *(_DWORD *)(result + 124);
  result = a2 >> 3;
  *(_BYTE *)((a2 >> 3) + v13) |= 1 << (a2 & 7);
  return result;
}
