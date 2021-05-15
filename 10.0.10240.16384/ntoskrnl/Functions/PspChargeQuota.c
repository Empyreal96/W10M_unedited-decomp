// PspChargeQuota 
 
int __fastcall PspChargeQuota(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r5
  unsigned __int8 v6; // lr
  unsigned int v7; // r4
  unsigned int *v10; // r9
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r4
  unsigned int *v15; // r5
  unsigned int v16; // t1
  unsigned int *v18; // r1
  unsigned int v19; // r3
  unsigned int v20; // r4
  unsigned int v21; // r0
  unsigned int *v22; // r5
  unsigned int v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // [sp+8h] [bp-28h] BYREF
  int v31; // [sp+Ch] [bp-24h]

  v4 = (unsigned int *)(a1 + (a3 << 8));
  v6 = PspResourceFlags[8 * a3];
  v7 = *v4;
  v31 = v6;
  __dmb(0xBu);
  __dmb(0xFu);
  v10 = v4 + 32;
  while ( 2 )
  {
    v11 = *v10;
    v30 = *v10;
    __dmb(0xBu);
    while ( 1 )
    {
      v12 = v7 + a4;
      if ( v7 + a4 < v7 )
        return dword_6825A4[2 * a3];
      if ( v12 <= v11 )
        break;
      if ( (v6 & 1) == 0 || !v4[34] )
        return dword_6825A4[2 * a3];
      __dmb(0xBu);
      v27 = v4 + 33;
      do
        v28 = __ldrex(v27);
      while ( __strex(0, v27) );
      __dmb(0xBu);
      if ( v28 )
      {
        __dmb(0xBu);
        do
          v29 = __ldrex(v10);
        while ( __strex(v29 + v28, v10) );
        __dmb(0xBu);
        v11 = v29 + v28;
        v30 = v11;
      }
      else
      {
        if ( !PspExpandQuota(a3, (int)v4, v7, a4, &v30) )
          return dword_6825A4[2 * a3];
        v11 = v30;
        v6 = v31;
      }
    }
    __dmb(0xBu);
    do
      v13 = __ldrex(v4);
    while ( v13 == v7 && __strex(v12, v4) );
    __dmb(0xBu);
    if ( v13 != v7 )
    {
      v7 = v13;
      continue;
    }
    break;
  }
  v16 = v4[1];
  v15 = v4 + 1;
  v14 = v16;
  __dmb(0xBu);
  if ( v12 > v16 )
  {
    do
    {
      v25 = v14;
      __dmb(0xBu);
      do
        v26 = __ldrex(v15);
      while ( v26 == v14 && __strex(v12, v15) );
      v14 = v26;
      __dmb(0xBu);
    }
    while ( v26 != v25 && v12 > v26 );
  }
  if ( a2 )
  {
    if ( (v6 & 4) != 0 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(a2 + 4 * (a3 + 52));
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 + a4, v18) );
      __dmb(0xBu);
      v20 = v19 + a4;
      v21 = *(_DWORD *)(a2 + 4 * (a3 + 54));
      v22 = (unsigned int *)(a2 + 4 * (a3 + 54));
      __dmb(0xBu);
      if ( v19 + a4 > v21 )
      {
        do
        {
          v23 = v21;
          __dmb(0xBu);
          do
            v24 = __ldrex(v22);
          while ( v24 == v21 && __strex(v20, v22) );
          v21 = v24;
          __dmb(0xBu);
        }
        while ( v24 != v23 && v20 > v24 );
      }
    }
  }
  return 0;
}
