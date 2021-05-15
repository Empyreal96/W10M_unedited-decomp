// MiLockProtoPoolPage 
 
int __fastcall MiLockProtoPoolPage(unsigned int a1, _BYTE *a2)
{
  unsigned int v2; // r4
  unsigned int v5; // r6
  int v6; // r5
  char v7; // r0
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  unsigned int v10; // r3
  int v11; // r0
  unsigned int *v12; // r6
  int v13; // r8
  unsigned int *v14; // r2
  unsigned int v15; // r0
  int result; // r0
  unsigned __int8 *v17; // r1
  unsigned int v18; // r2
  int v19; // r3
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned int *v23; // r9
  unsigned int v24; // r1
  __int16 v25; // r3
  __int16 v26; // r3
  unsigned __int8 *v27; // r1
  unsigned int v28; // r2
  unsigned int v29; // r3
  unsigned int v30; // r2
  int v31; // r3
  unsigned int v32; // r2
  unsigned int *v33; // r2
  unsigned int v34; // r0
  unsigned int *v35; // r8
  unsigned __int8 *v36; // r10
  unsigned int v37; // r1
  __int16 v38; // r3
  __int16 v39; // r3
  unsigned int v40; // r2
  unsigned int v41; // r3
  unsigned int v42; // r2
  int v43; // r0
  unsigned int *v44; // r2
  unsigned int v45; // r4

  v2 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  do
  {
    if ( (v2 & 2) == 0 || (v2 & 0x100) != 0 )
      return 0;
    v5 = v2 >> 12;
  }
  while ( !MI_IS_PFN(v2 >> 12) );
  v6 = MmPfnDatabase + 24 * v5;
  if ( a2 )
  {
    v7 = KfRaiseIrql(2);
    v8 = (unsigned __int8 *)(v6 + 15);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v31 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( (v31 & 0x80000000) != 0 );
        do
          v32 = __ldrex(v8);
        while ( __strex(v32 | 0x80, v8) );
        __dmb(0xBu);
      }
      while ( v32 >> 7 );
    }
    *a2 = v7;
  }
  else
  {
    v17 = (unsigned __int8 *)(v6 + 15);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 0x80, v17) );
    __dmb(0xBu);
    if ( v18 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v19 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( (v19 & 0x80000000) != 0 );
        do
          v20 = __ldrex(v17);
        while ( __strex(v20 | 0x80, v17) );
        __dmb(0xBu);
      }
      while ( v20 >> 7 );
    }
  }
  v10 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (v10 & 2) != 0 && (v10 & 0x100) == 0 && v5 == v10 >> 12 )
  {
    v11 = MiAddLockedPageCharge(v6, 1);
    v12 = (unsigned int *)(*(_DWORD *)(v6 + 4) | 0x80000000);
    if ( !a2 )
    {
      if ( (*(_BYTE *)(v6 + 18) & 0x20) != 0 )
      {
        v35 = (unsigned int *)(v6 + 12);
        v36 = (unsigned __int8 *)(v6 + 15);
        do
        {
          __dmb(0xBu);
          do
            v37 = __ldrex(v35);
          while ( __strex(v37 & 0x7FFFFFFF, v35) );
          v38 = *(_WORD *)(v6 + 18);
          __dmb(0xBu);
          if ( (v38 & 0x20) != 0 )
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v39 = *(_WORD *)(v6 + 18);
              __dmb(0xBu);
            }
            while ( (v39 & 0x20) != 0 );
          }
          KfRaiseIrql(2);
          do
            v40 = __ldrex(v36);
          while ( __strex(v40 | 0x80, v36) );
          __dmb(0xBu);
          if ( v40 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v41 = *v35;
                __dmb(0xBu);
              }
              while ( (v41 & 0x80000000) != 0 );
              do
                v42 = __ldrex(v36);
              while ( __strex(v42 | 0x80, v36) );
              __dmb(0xBu);
            }
            while ( v42 >> 7 );
          }
        }
        while ( (*(_BYTE *)(v6 + 18) & 0x20) != 0 );
      }
      *(_BYTE *)(v6 + 18) |= 0x20u;
      if ( (*(_DWORD *)(v6 + 12) & 0x40000000) == 0 && (*v12 & 0x10) == 0 )
        MI_WRITE_VALID_PTE_VOLATILE(v12, 1);
      __dmb(0xBu);
      v21 = (unsigned int *)(v6 + 12);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 & 0x7FFFFFFF, v21) );
      return v6;
    }
    v13 = (unsigned __int8)*a2;
    if ( (*(_BYTE *)(v6 + 18) & 0x20) == 0 )
    {
LABEL_15:
      *(_BYTE *)(v6 + 18) |= 0x20u;
      if ( (*(_DWORD *)(v6 + 12) & 0x40000000) == 0 && (*v12 & 0x10) == 0 )
        MI_WRITE_VALID_PTE_VOLATILE(v12, 1);
      __dmb(0xBu);
      v14 = (unsigned int *)(v6 + 12);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 & 0x7FFFFFFF, v14) );
      return v6;
    }
    v23 = (unsigned int *)(v6 + 12);
    while ( 1 )
    {
      __dmb(0xBu);
      if ( v13 == 17 )
        break;
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 & 0x7FFFFFFF, v23) );
      KfLowerIrql(v13);
      v25 = *(_WORD *)(v6 + 18);
      __dmb(0xBu);
      if ( (v25 & 0x20) != 0 )
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v26 = *(_WORD *)(v6 + 18);
          __dmb(0xBu);
        }
        while ( (v26 & 0x20) != 0 );
      }
      v11 = KfRaiseIrql(2);
      v27 = (unsigned __int8 *)(v6 + 15);
      do
        v28 = __ldrex(v27);
      while ( __strex(v28 | 0x80, v27) );
      __dmb(0xBu);
      if ( v28 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v29 = *v23;
            __dmb(0xBu);
          }
          while ( (v29 & 0x80000000) != 0 );
          do
            v30 = __ldrex(v27);
          while ( __strex(v30 | 0x80, v27) );
          __dmb(0xBu);
        }
        while ( v30 >> 7 );
      }
      if ( (*(_BYTE *)(v6 + 18) & 0x20) == 0 )
        goto LABEL_15;
    }
    result = sub_543E88(v11);
  }
  else
  {
    if ( a2 )
    {
      v43 = (unsigned __int8)*a2;
      __dmb(0xBu);
      v44 = (unsigned int *)(v6 + 12);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 & 0x7FFFFFFF, v44) );
      KfLowerIrql(v43);
    }
    else
    {
      __dmb(0xBu);
      v33 = (unsigned int *)(v6 + 12);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 & 0x7FFFFFFF, v33) );
    }
    result = 0;
  }
  return result;
}
