// IopQueueIrpToFileObject 
 
int __fastcall IopQueueIrpToFileObject(_DWORD *a1, _DWORD *a2)
{
  unsigned int *v4; // r5
  int v5; // r6
  int result; // r0
  unsigned int v7; // r2
  int v8; // r0
  _DWORD *v9; // r1
  int v10; // r4

  v4 = a2 + 28;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52111C();
  do
    v7 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v7 )
    KxWaitForSpinLockAndAcquire(v4);
  if ( (a2[11] & 0x400) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    KfLowerIrql(v5);
    result = 0;
  }
  else
  {
    v8 = a2[29];
    v9 = a1 + 4;
    a1[4] = v8;
    a1[5] = a2 + 29;
    if ( *(_DWORD **)(v8 + 4) != a2 + 29 )
      __fastfail(3u);
    *(_DWORD *)(v8 + 4) = v9;
    a2[29] = v9;
    v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    ObfReferenceObjectWithTag(v10, 1883467593);
    ObfReferenceObjectWithTag(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1953261124);
    a1[2] |= 0x2000u;
    a1[12] = v10;
    sub_456A04(a1 + 12, 1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    KfLowerIrql(v5);
    result = 1;
  }
  return result;
}
