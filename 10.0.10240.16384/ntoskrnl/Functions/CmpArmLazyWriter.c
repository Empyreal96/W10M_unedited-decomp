// CmpArmLazyWriter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpArmLazyWriter(int result, __int64 *a2, int a3)
{
  int v4; // r3
  unsigned int v5; // r1 OVERLAPPED
  unsigned int v6; // r2 OVERLAPPED
  unsigned int v7; // r0
  unsigned int v8; // r6
  unsigned __int64 v9; // kr00_8
  unsigned int v10; // r5
  unsigned int v11; // r8
  __int64 v12; // kr18_8
  unsigned int v13; // r9
  __int64 v14; // kr08_8
  unsigned int *v15; // r4
  int v16; // r7
  unsigned int v17; // r2
  int v18; // lr
  char *v19; // r8
  __int64 v20; // kr20_8
  unsigned int v21; // r3
  unsigned int v22; // r5
  int v23; // r0
  __int64 v24; // r2
  __int64 v25; // r0
  unsigned int v26; // [sp+4h] [bp-34h]
  int v27; // [sp+10h] [bp-28h]

  v27 = result;
  if ( !CmpWorkerDataInitialized )
    return result;
  v4 = CmpHoldLazyFlush;
  __dmb(0xBu);
  if ( v4 )
    return result;
  do
  {
    *(_QWORD *)&v5 = MEMORY[0xFFFF93B0];
    v7 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v8 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v7 != MEMORY[0xFFFF9010] )
      return sub_54876C(v7, v5, v6);
  }
  while ( v5 != MEMORY[0xFFFF93B0] || v6 != MEMORY[0xFFFF93B4] );
  v9 = __PAIR64__(v7, v8) - __PAIR64__(v6, v5);
  if ( a2 )
  {
    v11 = (*((unsigned int *)&CmpLazyWriterData + 32 * v27 + 29) * (unsigned __int64)(unsigned int)dword_989680 + v9) >> 32;
    v10 = *((_DWORD *)&CmpLazyWriterData + 32 * v27 + 29) * (_DWORD)dword_989680 + v9;
    v12 = *a2;
    if ( *((_DWORD *)a2 + 1) > v11 || HIDWORD(v12) >= v11 && (unsigned int)v12 >= v10 )
    {
      v13 = (*((unsigned int *)&CmpLazyWriterData + 32 * v27 + 29) * (unsigned __int64)(unsigned int)dword_989680 + v9) >> 32;
    }
    else
    {
      v14 = *a2;
      v13 = *((_DWORD *)a2 + 1);
      v10 = v14;
    }
  }
  else if ( a3 )
  {
    v13 = (v9 + 20000000) >> 32;
    v10 = v9 + 20000000;
  }
  else
  {
    v13 = (*((unsigned int *)&CmpLazyWriterData + 32 * v27 + 29) * (unsigned __int64)(unsigned int)dword_989680 + v9) >> 32;
    v10 = *((_DWORD *)&CmpLazyWriterData + 32 * v27 + 29) * (_DWORD)dword_989680 + v9;
  }
  v15 = (unsigned int *)&dword_60E290[32 * v27];
  v16 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v15);
  }
  else
  {
    do
      v17 = __ldrex(v15);
    while ( __strex(1u, v15) );
    __dmb(0xBu);
    if ( v17 )
      KxWaitForSpinLockAndAcquire(v15);
  }
  v18 = v27;
  v19 = (char *)&CmpLazyWriterData + 128 * v27;
  v20 = *((_QWORD *)v19 + 13);
  v21 = v20 & 7;
  if ( v21 <= 3 )
  {
    if ( v21 == 1 )
    {
      if ( a3 && KeCancelTimer((int)&CmpLazyWriterData + 128 * v27) )
      {
        v18 = v27;
        goto LABEL_39;
      }
    }
    else
    {
      if ( v21 == 2 )
        goto LABEL_27;
      if ( (v20 & 7) == 0 )
      {
LABEL_39:
        v13 = 0;
        v22 = 1;
        goto LABEL_28;
      }
      if ( v13 <= HIDWORD(v20) && (v13 < HIDWORD(v20) || v10 < ((unsigned int)v20 & 0xFFFFFFF8)) )
      {
LABEL_27:
        v22 = v10 & 0xFFFFFFF8 | 3;
LABEL_28:
        *((_DWORD *)v19 + 26) = v22;
        *((_DWORD *)v19 + 27) = v13;
        if ( v22 == 1 && !v13 )
        {
          if ( a3 )
          {
            v24 = -20000000i64;
            v23 = 1000;
          }
          else
          {
            v23 = *((_DWORD *)v19 + 30);
            v24 = -10000000i64 * *((int *)v19 + 29);
          }
          HIDWORD(v25) = (char *)&unk_60E260 + 128 * v18;
          v26 = v23;
          LODWORD(v25) = (char *)&CmpLazyWriterData + 128 * v18;
          KeSetCoalescableTimer(v25, v24, 0, v26, SHIDWORD(v25));
        }
        goto LABEL_19;
      }
    }
  }
LABEL_19:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v15);
  }
  else
  {
    __dmb(0xBu);
    *v15 = 0;
  }
  return KfLowerIrql(v16);
}
