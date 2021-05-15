// KsepStringSplitMultiString 
 
int __fastcall KsepStringSplitMultiString(unsigned __int16 *a1, unsigned int a2, int *a3, unsigned int *a4)
{
  unsigned __int16 *v4; // r7
  unsigned int v5; // r4
  int v6; // r6
  unsigned int v7; // r5
  unsigned __int16 *v8; // r5
  unsigned int v9; // r5
  unsigned __int16 *v10; // r1
  unsigned int v11; // r2
  unsigned int v13; // r2
  unsigned int v14; // r2
  _WORD *v15; // r3
  int v16; // r0
  int v17; // r4
  int v18; // r8
  unsigned int v19; // r10
  int v20; // r2
  int v21; // r4
  int v22; // r9
  unsigned int v23; // r2
  unsigned int v24; // r2
  _WORD *v25; // r3
  _DWORD *v26; // r7
  unsigned int v28; // [sp+0h] [bp-28h]

  v4 = a1;
  v5 = a2 >> 1;
  v6 = 0;
  v7 = 0;
  if ( a1 && (a2 & 1) == 0 && a3 && a4 )
  {
    if ( v5 < 3 || (v8 = &a1[v5], *(v8 - 1)) || *(v8 - 2) )
    {
      v17 = -1073741811;
    }
    else
    {
      v9 = 0;
      v10 = a1;
      v11 = v5;
      do
      {
        if ( !*v10++ )
          ++v9;
        --v11;
      }
      while ( v11 );
      if ( v9 < 2 )
      {
        __dmb(0xBu);
        do
        {
          v13 = __ldrex(&KsepHistoryErrorsIndex);
          v14 = v13 + 1;
        }
        while ( __strex(v14, &KsepHistoryErrorsIndex) );
        __dmb(0xBu);
        v15 = &KsepHistoryErrors[4 * (v14 & 0x3F)];
        *((_DWORD *)v15 + 1) = -1073740768;
        v15[1] = 3;
        LOBYTE(v15) = KsepDebugFlag;
        KsepHistoryErrors[4 * (v14 & 0x3F)] = 952;
        if ( ((unsigned __int8)v15 & 4) != 0 )
          RtlAssert((int)"NullCount >= 2", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 952, 0);
      }
      v7 = v9 - 1;
      v16 = KsepPoolAllocatePaged(8 * v7);
      v6 = v16;
      if ( v16 )
      {
        v18 = 0;
        v19 = 0;
        v28 = v5 - 1;
        v20 = 0;
        v21 = 1;
        v22 = v16;
        do
        {
          if ( !v4[v21 - 1] )
          {
            if ( KsepStringDuplicate(v22, (unsigned __int16 *)((char *)v4 + v20)) < 0 )
            {
              v17 = -1073741801;
              goto LABEL_33;
            }
            v20 = v21 * 2;
            ++v18;
            v22 += 8;
          }
          ++v19;
          ++v21;
        }
        while ( v19 < v28 );
        if ( v18 != v7 )
        {
          __dmb(0xBu);
          do
          {
            v23 = __ldrex(&KsepHistoryErrorsIndex);
            v24 = v23 + 1;
          }
          while ( __strex(v24, &KsepHistoryErrorsIndex) );
          __dmb(0xBu);
          v25 = &KsepHistoryErrors[4 * (v24 & 0x3F)];
          *((_DWORD *)v25 + 1) = -1073740768;
          v25[1] = 3;
          *v25 = 992;
          if ( (KsepDebugFlag & 4) != 0 )
            RtlAssert((int)"Count == StringsVectorSize", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 992, 0);
        }
        *a4 = v7;
        v17 = 0;
        *a3 = v6;
      }
      else
      {
        v17 = -1073741801;
      }
    }
  }
  else
  {
    v17 = -1073741811;
LABEL_33:
    if ( v6 )
    {
      if ( v7 )
      {
        v26 = (_DWORD *)v6;
        do
        {
          KsepStringFree(v26);
          v26 += 2;
          --v7;
        }
        while ( v7 );
      }
      KsepPoolFreePaged(v6);
    }
  }
  return v17;
}
