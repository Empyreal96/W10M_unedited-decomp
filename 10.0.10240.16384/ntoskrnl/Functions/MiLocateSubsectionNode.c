// MiLocateSubsectionNode 
 
int __fastcall MiLocateSubsectionNode(unsigned int *a1, __int64 a2, int a3)
{
  unsigned int *v7; // r7
  int v8; // r6
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r7
  unsigned int v12; // r0
  __int64 v13; // kr00_8
  unsigned int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r2
  unsigned int v17; // lr
  unsigned int *v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r2
  __int16 v21; // r3
  _DWORD *v22; // r4
  int v23; // r0
  _DWORD *v24; // r4
  unsigned int *v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // r2
  unsigned int *v28; // r0
  unsigned int v29; // r1
  unsigned int v30; // r2
  int v31; // [sp+0h] [bp-60h] BYREF
  __int16 v32; // [sp+10h] [bp-50h]
  unsigned int v33; // [sp+14h] [bp-4Ch]

  if ( (unsigned __int64)a2 >= 0x3FFFFFFFFFF000i64 )
    return sub_545FFC();
  if ( a3 == 1 )
  {
    v8 = 17;
  }
  else
  {
    v7 = a1 + 9;
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      v9 = *v7 & 0x7FFFFFFF;
      do
        v10 = __ldrex(v7);
      while ( v10 == v9 && __strex(v9 + 1, v7) );
      __dmb(0xBu);
      if ( v10 != v9 )
        ExpWaitForSpinLockSharedAndAcquire(a1 + 9);
    }
  }
  v11 = a1[39];
  v12 = a2 >> 12;
  v13 = *(_QWORD *)(v11 + 20);
  v14 = HIDWORD(a2) >> 12;
  v15 = *(unsigned __int16 *)(v11 + 16) >> 6;
  v17 = (__PAIR64__(v15, *(_DWORD *)(v11 + 24)) + (unsigned int)v13 - 1) >> 32;
  v16 = *(_DWORD *)(v11 + 24) + v13 - 1;
  if ( (*(_WORD *)(v11 + 18) & 0xFFF0) != 0 )
  {
    v17 = (__PAIR64__(v17, v16) + 1) >> 32;
    v16 = *(_DWORD *)(v11 + 24) + v13;
  }
  if ( v14 >= v15 && (v14 > v15 || v12 >= (unsigned int)v13) && v14 <= v17 && (v14 < v17 || v12 <= v16) )
  {
    if ( v8 != 17 )
    {
      v18 = a1 + 9;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v18);
      }
      else
      {
        __dmb(0xBu);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 & 0xBFFFFFFF, v18) );
        __dmb(0xBu);
        do
          v20 = __ldrex(v18);
        while ( __strex(v20 - 1, v18) );
      }
      KfLowerIrql(v8);
    }
    return v11;
  }
  v33 = v12;
  v21 = v32 & 0x3F | ((_WORD)v14 << 6);
  v22 = (_DWORD *)a1[37];
  v32 = v21;
  if ( !v22 )
  {
LABEL_42:
    if ( v8 != 17 )
    {
      v28 = a1 + 9;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v28);
      }
      else
      {
        __dmb(0xBu);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 & 0xBFFFFFFF, v28) );
        __dmb(0xBu);
        do
          v30 = __ldrex(v28);
        while ( __strex(v30 - 1, v28) );
      }
      KfLowerIrql(v8);
    }
    return 0;
  }
  while ( 1 )
  {
    v23 = MiSubsectionCompare((int)&v31, (int)v22);
    if ( v23 < 0 )
    {
      v22 = (_DWORD *)*v22;
      goto LABEL_41;
    }
    if ( v23 <= 0 )
      break;
    v22 = (_DWORD *)v22[1];
LABEL_41:
    if ( !v22 )
      goto LABEL_42;
  }
  v24 = v22 - 10;
  a1[39] = (unsigned int)v24;
  if ( v8 != 17 )
  {
    v25 = a1 + 9;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v25);
    }
    else
    {
      __dmb(0xBu);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0xBFFFFFFF, v25) );
      __dmb(0xBu);
      do
        v27 = __ldrex(v25);
      while ( __strex(v27 - 1, v25) );
    }
    KfLowerIrql(v8);
  }
  return (int)v24;
}
