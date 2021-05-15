// PspReturnQuota 
 
int __fastcall PspReturnQuota(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int *v5; // r9
  unsigned int v6; // r5
  int v7; // lr
  unsigned int *v9; // r10
  unsigned int v10; // r7
  int result; // r0
  char *v12; // lr
  unsigned int v13; // r4
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r0
  unsigned int v17; // r1
  int v18; // r2
  char v20; // [sp+10h] [bp-20h]

  v5 = (unsigned int *)(a1 + (a3 << 8));
  v6 = *v5;
  v7 = a3;
  v20 = PspResourceFlags[8 * a3];
  __dmb(0xBu);
  v9 = v5 + 32;
  v10 = v5[32];
  __dmb(0xBu);
  if ( v5[34] )
  {
    v12 = (char *)&PspQuotaExpansionDescriptors + 28 * a3;
    if ( v10 > v6 )
    {
      v13 = *((_DWORD *)v12 + 1);
      if ( v10 - v6 > v13 )
      {
        if ( v13 > a4 )
          v13 = a4;
        __dmb(0xBu);
        do
          v15 = __ldrex(v9);
        while ( v15 == v10 && __strex(v10 - v13, v9) );
        __dmb(0xBu);
        if ( v15 == v10 )
        {
          __dmb(0xBu);
          v16 = v5 + 33;
          do
            v17 = __ldrex(v16);
          while ( __strex(v17 + v13, v16) );
          __dmb(0xBu);
          if ( v17 + v13 > *((_DWORD *)v12 + 1) )
          {
            __dmb(0xBu);
            do
              v18 = __ldrex(v16);
            while ( __strex(0, v16) );
            __dmb(0xBu);
            if ( v18 )
              PspReturnResourceQuota(a3, (int)v5, v18, 0);
          }
        }
      }
    }
    v7 = a3;
  }
  while ( 1 )
  {
    if ( a4 >= v6 )
      return sub_52CA28();
    __dmb(0xBu);
    do
      result = __ldrex(v5);
    while ( result == v6 && __strex(v6 - a4, v5) );
    __dmb(0xBu);
    if ( result == v6 )
      break;
    v6 = result;
  }
  if ( a2 && (v20 & 4) != 0 )
  {
    __dmb(0xBu);
    v14 = (unsigned int *)(a2 + 4 * (v7 + 52));
    do
      result = __ldrex(v14);
    while ( __strex(result - a4, v14) );
    __dmb(0xBu);
  }
  return result;
}
