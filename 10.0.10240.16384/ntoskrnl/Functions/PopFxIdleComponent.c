// PopFxIdleComponent 
 
int __fastcall PopFxIdleComponent(_DWORD *a1, unsigned int a2, char a3, int a4)
{
  int v8; // r10
  unsigned int *v9; // r9
  __int64 v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  unsigned int v13; // lr
  int v14; // r3
  unsigned int v15; // r9
  unsigned int v16; // r4
  unsigned int v17; // r10
  unsigned int v18; // r1
  unsigned __int64 v19; // r2
  unsigned int v20; // r1
  unsigned int *v21; // r1
  unsigned int v22; // r2
  unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r2
  unsigned int v28; // r2
  __int64 v30; // [sp+0h] [bp-38h]
  unsigned int v31; // [sp+8h] [bp-30h]
  unsigned int v32; // [sp+8h] [bp-30h]
  int v33; // [sp+Ch] [bp-2Ch]
  char v34[40]; // [sp+10h] [bp-28h] BYREF

  if ( (a3 & 3) == 3 )
    PopFxBugCheck(1556, a1, a2, 1);
  if ( a2 >= a1[97] )
    sub_5404B0();
  v8 = *(_DWORD *)(a1[98] + 4 * a2);
  v33 = v8;
  v9 = (unsigned int *)(v8 + 52);
  if ( PopFxActiveIdleLevel == 2 )
    JUMPOUT(0x5404BE);
  LODWORD(v10) = v8 + 96;
  v30 = *(_QWORD *)(v8 + 96);
  if ( (*v9 & 0x3FFFFFFF) == 0 )
  {
    v26 = *v9;
    __dmb(0xBu);
    PopFxBugCheck(1544, v8, v26, 0);
  }
  __dmb(0xBu);
  do
  {
    v11 = __ldrex(v9);
    v12 = v11 - 1;
  }
  while ( __strex(v12, v9) );
  if ( v12 == 0x80000000 )
  {
    v10 = RtlGetInterruptTimePrecise(v34);
    v13 = v10;
    LODWORD(v10) = v8 + 96;
    v31 = HIDWORD(v10);
    v14 = *(_DWORD *)(v8 + 56);
    __dmb(0xBu);
    if ( (v14 & 2) == 0
      && !PopFxLowPowerEpoch
      && __PAIR64__(HIDWORD(v10), v13) - v30 < (unsigned int)PopFxActiveIdleThreshold )
    {
      __dmb(0xBu);
      do
        v20 = __ldrex(v9);
      while ( v20 == 0x80000000 && __strex(0x80000001, v9) );
      __dmb(0xBu);
      if ( v20 != 0x80000000 )
        return v10;
      v21 = (unsigned int *)(v8 + 60);
      do
      {
        v22 = __ldrex(v21);
        v23 = v22 + 1;
      }
      while ( __strex(v23, v21) );
      __dmb(0xBu);
      if ( v23 == 1 )
      {
        do
        {
          v24 = __ldrex((unsigned int *)&PopFxResidentComponentCount);
          v25 = v24 + 1;
        }
        while ( __strex(v25, (unsigned int *)&PopFxResidentComponentCount) );
        __dmb(0xBu);
        if ( v25 == 1 )
          LODWORD(v10) = PopFxArmResidentTimer(0);
        return v10;
      }
      do
        v27 = __ldrex(v21);
      while ( __strex(v27 - 1, v21) );
      __dmb(0xBu);
      do
        v28 = __ldrex(v9);
      while ( __strex(v28 - 1, v9) );
      __dmb(0xBu);
      HIDWORD(v10) = v31;
    }
    if ( PopFxActiveIdleLevel == 1 )
    {
      v15 = *(_DWORD *)(v8 + 100);
      if ( v15 <= HIDWORD(v10) && (v15 < HIDWORD(v10) || *(_DWORD *)v10 < v13) )
      {
        v17 = *(_DWORD *)v10;
        v16 = v31;
        do
        {
          v18 = v17;
          v32 = v15;
          do
            v19 = __ldrexd((unsigned __int64 *)v10);
          while ( v19 == __PAIR64__(v15, v17) && __strexd(__PAIR64__(v16, v13), (unsigned __int64 *)v10) );
          v15 = HIDWORD(v19);
          v17 = v19;
          if ( __PAIR64__(v32, v18) == v19 )
            break;
          __dmb(0xAu);
          __yield();
        }
        while ( v19 < __PAIR64__(v16, v13) );
        v8 = v33;
      }
    }
    if ( (a3 & 2) != 0 )
      LODWORD(v10) = PopFxQueueWorkOrder((int)&PopFxSystemWorkQueue, (_DWORD *)(v8 + 20), (int)a1, 0);
    else
      LODWORD(v10) = PopFxIdleWorker(a1, a2, a4);
  }
  return v10;
}
