// MiLeapPrefetch 
 
int __fastcall MiLeapPrefetch(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // r7
  int v4; // r6
  int v5; // r2
  _DWORD *v6; // r4
  unsigned int *v7; // r7
  int v8; // r5
  unsigned int v9; // r2
  int v10; // r0
  __int16 v11; // r3
  unsigned int *v12; // r7
  int v13; // r5
  int v14; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r0
  unsigned int v17; // r1
  unsigned int v18; // r2
  _DWORD *v20; // r2
  unsigned int v21; // r0
  _DWORD *v22; // r3
  unsigned int v23; // r1
  unsigned int *v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r2
  _DWORD *i; // r3
  int v28; // r3
  unsigned int *v29; // r0
  _DWORD *v30; // r3
  unsigned int v31; // r2
  unsigned int v32; // r3
  unsigned int *v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r2
  unsigned int v36; // r1
  unsigned int v37; // r2
  unsigned int v38; // [sp+0h] [bp-20h]

  v2 = a2;
  if ( a2 )
  {
LABEL_72:
    v30 = (_DWORD *)(a1[1] + 8 * a1[3]);
    v31 = *v30 & 0xFFFFF000;
    if ( v2 < v31 || v2 >= v31 + ((v30[1] + (*v30 & 0xFFFu) + 4095) >> 12 << 12) )
    {
LABEL_83:
      ++a1[3];
      v32 = 0;
    }
    else
    {
      v32 = (v2 - v31) >> 12;
    }
    a1[4] = v32;
    return 1;
  }
  v38 = *(_DWORD *)(a1[1] + 8 * a1[3]) + (a1[4] << 12);
  if ( v38 > MmHighestUserAddress )
    return 1;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(unsigned __int8 *)(v4 + 0x3C8);
  if ( (v5 & 0xFFFFFF80) == 128 || (v5 & 2) != 0 || (v5 & 1) != 0 )
    return 1;
  v6 = *(_DWORD **)(v4 + 116);
  --*(_WORD *)(v4 + 310);
  v7 = v6 + 63;
  v8 = KeAbPreAcquire((unsigned int)(v6 + 63), 0, 1);
  do
    v9 = __ldrex(v7);
  while ( !v9 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( !v9 || (v10 = ExfTryAcquirePushLockShared(v6 + 63)) != 0 )
  {
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    *(_BYTE *)(v4 + 968) |= 2u;
    v13 = 17;
  }
  else
  {
    if ( v8 )
      v10 = KeAbPostReleaseEx((int)(v6 + 63), v8);
    v11 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v11;
    if ( !v11 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v10);
    v12 = v6 + 123;
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v6 + 123);
    }
    else
    {
      v14 = *v12 & 0x7FFFFFFF;
      do
        v15 = __ldrex(v12);
      while ( v15 == v14 && __strex(v14 + 1, v12) );
      __dmb(0xBu);
      if ( v15 != v14 )
        ExpWaitForSpinLockSharedAndAcquire(v6 + 123);
    }
  }
  if ( (v6[48] & 0x20) == 0 && v6[161] )
  {
    v20 = (_DWORD *)v6[159];
    v21 = v38 >> 12;
    while ( 1 )
    {
      v23 = (unsigned int)v20;
      if ( !v20 )
        goto LABEL_67;
      if ( v21 < v20[3] )
      {
        v22 = (_DWORD *)*v20;
      }
      else
      {
        if ( v21 <= v20[4] )
        {
          if ( v13 == 17 )
          {
            UNLOCK_ADDRESS_SPACE_SHARED(v4, (int)v6);
          }
          else
          {
            v24 = v6 + 123;
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v24);
            }
            else
            {
              __dmb(0xBu);
              do
                v25 = __ldrex(v24);
              while ( __strex(v25 & 0xBFFFFFFF, v24) );
              __dmb(0xBu);
              do
                v26 = __ldrex(v24);
              while ( __strex(v26 - 1, v24) );
            }
            KfLowerIrql(v13);
          }
          return 1;
        }
        v22 = (_DWORD *)v20[1];
      }
      if ( !v22 )
        break;
      v20 = v22;
    }
    if ( v20[3] < v21 )
    {
      v23 = v20[1];
      if ( v23 )
      {
        for ( i = *(_DWORD **)v23; i; i = (_DWORD *)*i )
          v23 = (unsigned int)i;
      }
      else
      {
        v28 = v20[2];
        while ( 1 )
        {
          v23 = v28 & 0xFFFFFFFC;
          if ( (v28 & 0xFFFFFFFC) == 0 || *(_DWORD **)v23 == v20 )
            break;
          v28 = *(_DWORD *)(v23 + 8);
          v20 = (_DWORD *)v23;
        }
      }
      if ( !v23 )
      {
LABEL_67:
        if ( v13 == 17 )
        {
          UNLOCK_ADDRESS_SPACE_SHARED(v4, (int)v6);
        }
        else
        {
          v29 = v6 + 123;
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v29);
          }
          else
          {
            __dmb(0xBu);
            do
              v36 = __ldrex(v29);
            while ( __strex(v36 & 0xBFFFFFFF, v29) );
            __dmb(0xBu);
            do
              v37 = __ldrex(v29);
            while ( __strex(v37 - 1, v29) );
          }
          KfLowerIrql(v13);
        }
        goto LABEL_83;
      }
    }
    v2 = *(_DWORD *)(v23 + 12) << 12;
    if ( v13 == 17 )
    {
      UNLOCK_ADDRESS_SPACE_SHARED(v4, (int)v6);
    }
    else
    {
      v33 = v6 + 123;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v33);
      }
      else
      {
        __dmb(0xBu);
        do
          v34 = __ldrex(v33);
        while ( __strex(v34 & 0xBFFFFFFF, v33) );
        __dmb(0xBu);
        do
          v35 = __ldrex(v33);
        while ( __strex(v35 - 1, v33) );
      }
      KfLowerIrql(v13);
    }
    goto LABEL_72;
  }
  if ( v13 == 17 )
  {
    UNLOCK_ADDRESS_SPACE_SHARED(v4, (int)v6);
  }
  else
  {
    v16 = v6 + 123;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v16);
    }
    else
    {
      __dmb(0xBu);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 & 0xBFFFFFFF, v16) );
      __dmb(0xBu);
      do
        v18 = __ldrex(v16);
      while ( __strex(v18 - 1, v16) );
    }
    KfLowerIrql(v13);
  }
  return 0;
}
