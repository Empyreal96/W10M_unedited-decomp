// KeSetTimer2 
 
int __fastcall KeSetTimer2(int *a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v5; // r6
  int v6; // r8
  unsigned int v7; // r4
  int v9; // r7
  unsigned int v10; // r9
  unsigned __int64 v11; // r0
  int v12; // r4
  int v13; // r8
  __int64 v14; // kr08_8
  int v15; // r6
  unsigned int v16; // r2
  char v17; // r3
  char v18; // r0
  int v19; // r3
  int v20; // r2
  bool v21; // r1
  int v22; // r2
  bool v23; // zf
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r6
  int v28; // r0
  int v29; // r6
  unsigned int v31; // r2
  __int64 v32; // r0
  __int64 v33; // r0
  unsigned int v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r4
  unsigned int v37; // r1
  char v38[4]; // [sp+0h] [bp-58h] BYREF
  int v39; // [sp+4h] [bp-54h]
  int v40; // [sp+8h] [bp-50h]
  int v41; // [sp+Ch] [bp-4Ch]
  int v42; // [sp+10h] [bp-48h]
  __int64 v43; // [sp+14h] [bp-44h]
  int v44; // [sp+1Ch] [bp-3Ch]
  int v45; // [sp+20h] [bp-38h]
  BOOL v46; // [sp+24h] [bp-34h]
  int v47; // [sp+28h] [bp-30h]
  int v48[10]; // [sp+30h] [bp-28h] BYREF

  v5 = HIDWORD(a2);
  v6 = (unsigned __int8)(*((_BYTE *)a1 + 81) & 4) >> 2;
  v47 = v6;
  v7 = a2;
  v41 = 0;
  v42 = 0;
  v46 = a2 > 0;
  if ( a2 <= 0 )
  {
LABEL_2:
    v9 = -v7;
    v10 = (unsigned __int64)-__SPAIR64__(v5, v7) >> 32;
    if ( v6 )
    {
      v11 = RtlGetInterruptTimePrecise(v48);
    }
    else
    {
      while ( 1 )
      {
        HIDWORD(v11) = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        LODWORD(v11) = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( HIDWORD(v11) == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    v12 = (v11 + __PAIR64__(v10, v9)) >> 32;
    v13 = v11 + v9;
    v44 = v12;
    if ( v11 + __PAIR64__(v10, v9) < v11 || (v13 & v12) == -1 )
    {
      v12 = -1;
      v44 = -1;
      v13 = -2;
    }
    if ( (*((_BYTE *)a1 + 81) & 8) == 0 )
      goto LABEL_47;
    if ( !a4 )
    {
      v41 = v12;
      v42 = 1;
      v15 = v13;
      goto LABEL_11;
    }
    v14 = *(_QWORD *)(a4 + 8);
    if ( ((unsigned int)v14 & HIDWORD(v14)) == -1 )
    {
LABEL_47:
      v15 = 0;
    }
    else
    {
      v15 = v14 + v13;
      v41 = (v14 + __PAIR64__(v12, v13)) >> 32;
      v42 = 1;
      if ( v14 + __PAIR64__(v12, v13) < __PAIR64__(v12, v13) || (v15 & ((v14 + __PAIR64__(v12, v13)) >> 32)) == -1 )
      {
        v41 = -1;
        v15 = -2;
      }
    }
LABEL_11:
    v43 = a3;
    if ( a3 && a3 < (unsigned int)KeMinimumIncrement )
      v43 = (unsigned int)KeMinimumIncrement;
    v39 = 0;
    v45 = 0;
    v38[0] = 0;
    v40 = 1;
    v48[0] = KfRaiseIrql(2);
    do
      v16 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v16 | 0x80, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( v16 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*a1 & 0x80) != 0 );
        do
          v34 = __ldrex((unsigned __int8 *)a1);
        while ( __strex(v34 | 0x80, (unsigned __int8 *)a1) );
        __dmb(0xBu);
      }
      while ( v34 >> 7 );
    }
    if ( (*((_BYTE *)a1 + 1) & 0x20) != 0 )
    {
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)a1);
      while ( __strex(v35 & 0xFFFFFF7F, (unsigned int *)a1) );
    }
    if ( (*((_BYTE *)a1 + 1) & 0x20) != 0 )
    {
      v29 = 0;
LABEL_38:
      KfLowerIrql(v48[0]);
      return v29;
    }
    if ( (*((_BYTE *)a1 + 1) & 1) != 0 )
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(&KiTimer2CollectionLock);
      }
      else
      {
        do
          v31 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
        while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
        __dmb(0xBu);
        if ( v31 )
          KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
      }
      if ( (*((_BYTE *)a1 + 1) & 1) != 0 )
      {
        KiRemoveTimer2(a1);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
        }
        else
        {
          __dmb(0xBu);
          KiTimer2CollectionLock = 0;
        }
        v39 = 1;
LABEL_19:
        v19 = v41;
        v18 = v42;
        v20 = HIDWORD(v43);
        v21 = v46;
        a1[12] = v15;
        a1[13] = v19;
        a1[14] = v43;
        a1[15] = v20;
        LOBYTE(v19) = *((_BYTE *)a1 + 81);
        *((_BYTE *)a1 + 80) = v21;
        a1[1] = 0;
        v22 = v40;
        v23 = v40 == 1;
        a1[10] = v13;
        a1[11] = v12;
        *((_BYTE *)a1 + 81) = (v19 ^ (16 * v18)) & 0x10 ^ v19;
        if ( v23 )
        {
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(&KiTimer2CollectionLock);
          }
          else
          {
            do
              v24 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
            while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
            __dmb(0xBu);
            if ( v24 )
              KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
          }
          KiInsertTimer2WithCollectionLockHeld(a1, 1, v38);
          v22 = v40;
          v45 = (unsigned __int8)v38[0];
        }
        if ( (dword_682608 & 0x20000) != 0 )
        {
          v29 = v39;
          v28 = KiTraceSetTimer2(a1, v39);
        }
        else
        {
          v25 = *a1;
          v26 = *a1 & 0xFFFFF07F | (v22 << 8);
          __dmb(0xBu);
          do
            v27 = __ldrex((unsigned int *)a1);
          while ( v27 == v25 && __strex(v26, (unsigned int *)a1) );
          __dmb(0xBu);
          v23 = v25 == v27;
          v28 = v40;
          if ( !v23 )
          {
            do
            {
              v36 = v27;
              __dmb(0xBu);
              do
                v37 = __ldrex((unsigned int *)a1);
              while ( v37 == v27 && __strex(v27 & 0xFFFFF07F | (v28 << 8), (unsigned int *)a1) );
              v27 = v37;
              __dmb(0xBu);
            }
            while ( v36 != v37 );
            v12 = v44;
          }
          if ( v28 == 1 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              v28 = KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
            }
            else
            {
              __dmb(0xBu);
              KiTimer2CollectionLock = 0;
            }
          }
          v29 = v39;
        }
        if ( v45 )
        {
          KiRequestTimer2Expiration();
        }
        else if ( v47 )
        {
          v33 = KeQueryInterruptTime(v28);
          if ( KiShouldSetClockIntervalForHighResolutionTimers(v33, __PAIR64__(v12, v13)) )
            KiSendClockInterruptToClockOwner();
        }
        goto LABEL_38;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
      }
      else
      {
        __dmb(0xBu);
        KiTimer2CollectionLock = 0;
      }
    }
    v17 = *((_BYTE *)a1 + 1);
    if ( (v17 & 0xF) != 0 )
    {
      v40 = 8;
      if ( (v17 & 4) == 0 )
        v39 = 1;
    }
    goto LABEL_19;
  }
  if ( !v6 )
  {
    while ( 1 )
    {
      HIDWORD(v32) = MEMORY[0xFFFF9018];
      __dmb(0xBu);
      LODWORD(v32) = MEMORY[0xFFFF9014];
      __dmb(0xBu);
      if ( HIDWORD(v32) == MEMORY[0xFFFF901C] )
        break;
      __dmb(0xAu);
      __yield();
    }
    if ( a2 < v32 )
    {
      v5 = HIDWORD(v32);
      v7 = v32;
    }
    v5 = (v32 - __PAIR64__(v5, v7)) >> 32;
    v7 = v32 - v7;
    goto LABEL_2;
  }
  return sub_52C31C();
}
