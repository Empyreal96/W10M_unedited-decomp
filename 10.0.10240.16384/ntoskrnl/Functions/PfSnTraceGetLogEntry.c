// PfSnTraceGetLogEntry 
 
int __fastcall PfSnTraceGetLogEntry(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned int *v6; // r8
  unsigned int v7; // r4
  signed int v8; // r4
  int v10; // r4
  unsigned int *v11; // r0
  unsigned int v12; // r2
  signed int v13; // r2
  unsigned int v14; // r1
  unsigned int *v15; // r0
  unsigned int v16; // r2
  int v17; // r3
  _DWORD *v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  _DWORD *v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h]

  __dmb(0xBu);
  v6 = a1 + 65;
  do
  {
    v7 = __ldrex(v6);
    v8 = v7 + a2;
  }
  while ( __strex(v8, v6) );
  __dmb(0xBu);
  if ( v8 > a1[64] )
    return sub_5376D4();
  v10 = a1[20];
  __dmb(0xBu);
  v11 = (unsigned int *)(v10 + 8);
  do
  {
    v12 = __ldrex(v11);
    v13 = v12 + a2;
  }
  while ( __strex(v13, v11) );
  __dmb(0xBu);
  if ( v13 <= 0 )
  {
LABEL_32:
    __dmb(0xBu);
    do
      v20 = __ldrex(v6);
    while ( __strex(v20 - a2, v6) );
    __dmb(0xBu);
    return -1073741675;
  }
  while ( 1 )
  {
    if ( v13 <= *(_DWORD *)(v10 + 12) )
    {
      *a3 = v10 + 8 * (v13 - a2 + 2);
      return 0;
    }
    __dmb(0xBu);
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 - a2, v11) );
    __dmb(0xBu);
    v22 = (_DWORD *)PfSnTraceBufferAllocate();
    if ( !v22 )
      break;
    v23 = KfRaiseIrql(2);
    v15 = a1 + 24;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v15);
    }
    else
    {
      do
        v16 = __ldrex(v15);
      while ( __strex(1u, v15) );
      __dmb(0xBu);
      if ( !v16 )
        goto LABEL_19;
      KxWaitForSpinLockAndAcquire(v15);
    }
    v15 = a1 + 24;
LABEL_19:
    v17 = a1[20];
    __dmb(0xBu);
    if ( v17 == v10 )
    {
      v18 = (_DWORD *)a1[22];
      *v22 = a1 + 21;
      v22[1] = v18;
      if ( (_DWORD *)*v18 != a1 + 21 )
        __fastfail(3u);
      *v18 = v22;
      a1[22] = v22;
      ++a1[23];
      __dmb(0xBu);
      a1[20] = v22;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v15);
      }
      else
      {
        __dmb(0xBu);
        *v15 = 0;
      }
      KfLowerIrql(v23);
    }
    else
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v15);
      }
      else
      {
        __dmb(0xBu);
        *v15 = 0;
      }
      KfLowerIrql(v23);
      ExFreePoolWithTag(v22, 0);
    }
    v10 = a1[20];
    __dmb(0xBu);
    v11 = (unsigned int *)(v10 + 8);
    do
    {
      v19 = __ldrex(v11);
      v13 = v19 + a2;
    }
    while ( __strex(v13, v11) );
    __dmb(0xBu);
    if ( v13 <= 0 )
      goto LABEL_32;
  }
  __dmb(0xBu);
  do
    v21 = __ldrex(v6);
  while ( __strex(v21 - a2, v6) );
  __dmb(0xBu);
  return -1073741670;
}
