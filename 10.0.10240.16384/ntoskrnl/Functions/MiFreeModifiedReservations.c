// MiFreeModifiedReservations 
 
int __fastcall MiFreeModifiedReservations(int result)
{
  __int16 v1; // r3
  int v2; // r10
  int v3; // r7
  int i; // r4
  int v5; // r5
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned __int8 *v8; // r1
  int v9; // r3
  unsigned int v10; // r2
  int v11; // r0
  unsigned int *v12; // r1
  int *v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int v18; // r8
  int v19; // r2
  int v20; // r0
  unsigned int *v21; // r1
  int *v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r4
  unsigned int *v25; // r2
  unsigned int v26; // r4
  int v27; // [sp+0h] [bp-30h]
  int v28; // [sp+8h] [bp-28h] BYREF
  unsigned int *v29; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  v1 = *(_WORD *)(result + 96);
  if ( (v1 & 0x40) == 0 )
  {
    v2 = *(_DWORD *)(result + 128);
    v3 = v2 + 20 * ((v1 & 0xF) + 96);
    for ( i = *(_DWORD *)(v3 + 8); i != 0xFFFFF; i = *(_DWORD *)(v3 + 8) )
    {
      v5 = MmPfnDatabase + 24 * i;
      v27 = KfRaiseIrql(2);
      v6 = (unsigned __int8 *)(v5 + 15);
      do
        v7 = __ldrex(v6);
      while ( __strex(v7 | 0x80, v6) );
      __dmb(0xBu);
      if ( v7 >> 7 )
      {
        v8 = (unsigned __int8 *)(v5 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v9 = *(_DWORD *)(v5 + 12);
            __dmb(0xBu);
          }
          while ( v9 < 0 );
          do
            v10 = __ldrex(v8);
          while ( __strex(v10 | 0x80, v8) );
          __dmb(0xBu);
        }
        while ( v10 >> 7 );
      }
      KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v2 + 3984), &v28);
      if ( i == *(_DWORD *)(v3 + 8) )
      {
        MiUnlinkPageFromList(v5, 1);
        v18 = *(_DWORD *)(v5 + 8);
        *(_DWORD *)(v5 + 8) = v18 & 0xFFFFFFF7;
        MiInsertPageInList(v5, 136, v19);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(&v28, vars4);
        }
        else
        {
          v20 = v28;
          if ( !v28 )
          {
            v21 = v29;
            __dmb(0xBu);
            do
              v22 = (int *)__ldrex(v21);
            while ( v22 == &v28 && __strex(0, v21) );
            if ( v22 == &v28 )
              goto LABEL_34;
            v20 = KxWaitForLockChainValid(&v28);
          }
          v28 = 0;
          __dmb(0xBu);
          v23 = (unsigned int *)(v20 + 4);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 ^ 1, v23) );
        }
LABEL_34:
        __dmb(0xBu);
        v25 = (unsigned int *)(v5 + 12);
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 & 0x7FFFFFFF, v25) );
        MiReleasePageFileInfo(v2, v18, 1, 0);
        result = KfLowerIrql(v27);
        continue;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v28, vars4);
      }
      else
      {
        v11 = v28;
        if ( !v28 )
        {
          v12 = v29;
          __dmb(0xBu);
          do
            v13 = (int *)__ldrex(v12);
          while ( v13 == &v28 && __strex(0, v12) );
          if ( v13 == &v28 )
            goto LABEL_21;
          v11 = KxWaitForLockChainValid(&v28);
        }
        v28 = 0;
        __dmb(0xBu);
        v14 = (unsigned int *)(v11 + 4);
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 ^ 1, v14) );
      }
LABEL_21:
      __dmb(0xBu);
      v16 = (unsigned int *)(v5 + 12);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 & 0x7FFFFFFF, v16) );
      result = KfLowerIrql(v27);
    }
  }
  return result;
}
