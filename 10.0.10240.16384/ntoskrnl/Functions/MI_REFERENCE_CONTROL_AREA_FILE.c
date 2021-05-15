// MI_REFERENCE_CONTROL_AREA_FILE 
 
int __fastcall MI_REFERENCE_CONTROL_AREA_FILE(int a1)
{
  unsigned int *v1; // r5
  unsigned int v3; // r1
  unsigned int v4; // r4
  int v5; // r4
  unsigned int *v7; // r6
  int v8; // r7
  int v9; // r4
  unsigned int v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int *v15; // r7
  unsigned int v16; // r1

  v1 = (unsigned int *)(a1 + 32);
  __pld((void *)(a1 + 32));
  v3 = *(_DWORD *)(a1 + 32);
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
  if ( (v3 & 7) > 1 )
  {
LABEL_6:
    if ( v5 )
      return v5;
LABEL_9:
    v7 = (unsigned int *)(a1 + 36);
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v7);
    }
    else
    {
      v9 = *v7 & 0x7FFFFFFF;
      do
        v10 = __ldrex(v7);
      while ( v10 == v9 && __strex(v9 + 1, v7) );
      __dmb(0xBu);
      if ( v10 != v9 )
        ExpWaitForSpinLockSharedAndAcquire(v7);
    }
    v5 = ObFastReferenceObjectLocked(v1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
    }
    else
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v7);
      while ( __strex(v11 & 0xBFFFFFFF, v7) );
      __dmb(0xBu);
      do
        v12 = __ldrex(v7);
      while ( __strex(v12 - 1, v7) );
    }
    KfLowerIrql(v8);
    return v5;
  }
  if ( (v3 & 7) == 0 )
    goto LABEL_9;
  ObReferenceObjectExWithTag(v5, 7);
  __pld(v1);
  v13 = *v1;
  if ( (*v1 & 7) != 0 || v5 != (v13 & 0xFFFFFFF8) )
  {
    v15 = (unsigned int *)(v5 - 24);
    if ( ObpTraceFlags )
      ObpPushStackInfo(v5 - 24, 0, 7, 1953261124);
    __dmb(0xBu);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 - 7, v15) );
    if ( (int)(v16 - 7) <= 0 )
    {
      if ( v16 != 7 )
        KeBugCheckEx(24, 0, v5);
      ObpDeferObjectDeletion(v5 - 24);
    }
    goto LABEL_6;
  }
  do
    v14 = __ldrex(v1);
  while ( v14 == v13 && __strex(v13 + 7, v1) );
  __dmb(0xBu);
  if ( v14 == v13 )
    goto LABEL_6;
  return sub_54496C();
}
