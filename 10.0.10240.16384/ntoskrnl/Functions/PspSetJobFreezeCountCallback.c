// PspSetJobFreezeCountCallback 
 
int __fastcall PspSetJobFreezeCountCallback(_DWORD *a1, _DWORD *a2)
{
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v8; // r2
  int v9; // r9
  __int64 v10; // r0
  int v11; // r0
  unsigned int *v12; // r5
  int v13; // r1
  unsigned int v14; // r2
  _DWORD *v15; // r6
  int v16; // r0
  int v17; // r10
  unsigned int *v18; // r5
  int v19; // r1
  unsigned int v20; // r2
  _DWORD *v21; // r6
  int v22; // r3
  unsigned int v23; // [sp+8h] [bp-30h]
  __int64 v24; // [sp+8h] [bp-30h]
  unsigned int v25; // [sp+Ch] [bp-2Ch]
  unsigned __int64 v26[5]; // [sp+10h] [bp-28h] BYREF

  if ( (*(_DWORD *)*a2 & 1) == 0 )
    goto LABEL_2;
  v8 = a1[102];
  if ( *(_BYTE *)(*a2 + 4) )
  {
    if ( !v8 && (a1[186] & 0x40000) != 0 )
    {
      v9 = KfRaiseIrql(2);
      v10 = KeQueryInterruptTime(v9);
      v23 = HIDWORD(v10);
      v25 = v10;
      v11 = KeQuerySystemTime(v26);
      v12 = a1 + 173;
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_526108(v11);
      v13 = 1;
      do
        v14 = __ldrex(v12);
      while ( __strex(1u, v12) );
      __dmb(0xBu);
      if ( v14 )
        KxWaitForSpinLockAndAcquire(a1 + 173);
      v15 = (_DWORD *)a1[174];
      if ( v15 != a1 + 174 )
      {
        do
        {
          ExpTimerPause((int)(v15 - 41), v13, v26[0], __PAIR64__(v23, v25));
          v15 = (_DWORD *)*v15;
        }
        while ( v15 != a1 + 174 );
        v12 = a1 + 173;
      }
      ++a1[102];
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v12);
      }
      else
      {
        __dmb(0xBu);
        *v12 = 0;
      }
      v16 = v9;
      goto LABEL_26;
    }
    v22 = v8 + 1;
LABEL_44:
    a1[102] = v22;
    goto LABEL_2;
  }
  if ( v8 != 1 || (a1[186] & 0x40000) == 0 )
  {
    v22 = v8 - 1;
    goto LABEL_44;
  }
  v17 = KfRaiseIrql(2);
  v24 = KeQueryInterruptTime(v17);
  v18 = a1 + 173;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 173);
  }
  else
  {
    v19 = 1;
    do
      v20 = __ldrex(v18);
    while ( __strex(1u, v18) );
    __dmb(0xBu);
    if ( v20 )
      KxWaitForSpinLockAndAcquire(a1 + 173);
  }
  v21 = (_DWORD *)a1[174];
  if ( v21 != a1 + 174 )
  {
    do
    {
      ExTimerResume((int)v21, v19, v24, SHIDWORD(v24));
      v21 = (_DWORD *)*v21;
    }
    while ( v21 != a1 + 174 );
    v18 = a1 + 173;
  }
  --a1[102];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v18);
  }
  else
  {
    __dmb(0xBu);
    *v18 = 0;
  }
  v16 = v17;
LABEL_26:
  KfLowerIrql(v16);
LABEL_2:
  if ( (*(_DWORD *)*a2 & 4) != 0 )
  {
    v4 = a1[104];
    if ( *(_BYTE *)(*a2 + 5) )
      v5 = v4 + 1;
    else
      v5 = v4 - 1;
    a1[104] = v5;
  }
  v6 = 0;
  if ( a1[104] )
    v6 = 2;
  if ( a1[102] )
    v6 |= 1u;
  a2[1] = v6;
  return 0;
}
