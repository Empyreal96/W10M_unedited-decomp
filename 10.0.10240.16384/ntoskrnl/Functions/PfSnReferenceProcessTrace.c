// PfSnReferenceProcessTrace 
 
int __fastcall PfSnReferenceProcessTrace(int a1)
{
  unsigned int *v1; // r6
  unsigned int v3; // r1
  unsigned int v4; // r4
  unsigned int v5; // r5
  _DWORD *v7; // r4
  unsigned int v8; // r1
  int i; // r3
  unsigned int v10; // r0
  int v11; // r6
  int v12; // r9
  unsigned int v13; // r1
  unsigned int *v14; // r6
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int *v19; // r0
  unsigned int v20; // r1
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1

  v1 = (unsigned int *)(a1 + 420);
  __pld((void *)(a1 + 420));
  v3 = *(_DWORD *)(a1 + 420);
  if ( (v3 & 7) != 0 )
  {
    do
    {
      do
        v4 = __ldrex(v1);
      while ( v4 == v3 && __strex(v3 - 1, v1) );
      __dmb(0xBu);
      if ( v4 == v3 )
        break;
      v3 = v4;
    }
    while ( (v4 & 7) != 0 );
  }
  v5 = v3 & 0xFFFFFFF8;
  if ( (v3 & 0xFFFFFFF8) == 0 || (v3 & 7) > 1 )
    return v5;
  if ( (v3 & 7) != 0 )
  {
    v7 = (_DWORD *)(v5 + 268);
    if ( ExAcquireRundownProtectionEx((int *)(v5 + 268), 7) )
    {
      __pld(v1);
      v8 = *v1;
      for ( i = *v1 & 7; (unsigned int)(i + 7) <= 7 && v5 == (v8 & 0xFFFFFFF8); i = v10 & 7 )
      {
        do
          v10 = __ldrex(v1);
        while ( v10 == v8 && __strex(v8 + 7, v1) );
        __dmb(0xBu);
        if ( v10 == v8 )
          return v5;
        v8 = v10;
      }
      __pld(v7);
      v17 = *v7;
      if ( (*v7 & 1) != 0 )
      {
LABEL_42:
        v19 = (unsigned int *)(v17 & 0xFFFFFFFE);
        __dmb(0xBu);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 - 7, v19) );
        __dmb(0xBu);
        if ( v20 == 7 )
        {
          __dmb(0xBu);
          v21 = (unsigned __int8 *)(v19 + 5);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 & 0xFE, v21) );
          __dmb(0xBu);
          if ( (v22 & 1) == 0 )
            KeSetEvent((int)(v19 + 1), 0, 0);
        }
      }
      else
      {
        while ( 1 )
        {
          __dmb(0xBu);
          do
            v18 = __ldrex(v7);
          while ( v18 == v17 && __strex(v17 - 14, v7) );
          __dmb(0xBu);
          if ( v18 == v17 )
            break;
          v17 = v18;
          if ( (v18 & 1) != 0 )
            goto LABEL_42;
        }
      }
    }
    return v5;
  }
  v11 = 1;
  v12 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) == 0 )
  {
    do
      v13 = __ldrex((unsigned int *)&dword_637378);
    while ( __strex(1u, (unsigned int *)&dword_637378) );
    __dmb(0xBu);
    if ( v13 )
      KxWaitForSpinLockAndAcquire(&dword_637378);
    v5 = *(_DWORD *)(a1 + 420) & 0xFFFFFFF8;
    if ( v5 )
    {
      v14 = (unsigned int *)(v5 + 268);
      __pld((void *)(v5 + 268));
      v15 = *(_DWORD *)((*(_DWORD *)(a1 + 420) & 0xFFFFFFF8) + 0x10C) & 0xFFFFFFFE;
      do
        v16 = __ldrex(v14);
      while ( v16 == v15 && __strex(v15 + 2, v14) );
      __dmb(0xBu);
      if ( v16 == v15 )
        v11 = 1;
      else
        v11 = ExfAcquireRundownProtection((_DWORD *)(v5 + 268));
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&dword_637378);
    }
    else
    {
      __dmb(0xBu);
      dword_637378 = 0;
    }
    KfLowerIrql(v12);
    if ( !v11 )
      v5 = 0;
    return v5;
  }
  return sub_5475E0();
}
