// PfSnActiveTraceGetNext 
 
int __fastcall PfSnActiveTraceGetNext(int a1)
{
  unsigned int v3; // r1
  _DWORD *v4; // r3
  int i; // r6
  int v6; // r8
  unsigned int *v7; // r0
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v13; // [sp+0h] [bp-20h]

  v13 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5476A0();
  do
    v3 = __ldrex((unsigned int *)&dword_637378);
  while ( __strex(1u, (unsigned int *)&dword_637378) );
  __dmb(0xBu);
  if ( v3 )
    KxWaitForSpinLockAndAcquire(&dword_637378);
  if ( a1 )
    v4 = (_DWORD *)(a1 + 4);
  else
    v4 = &PfSnGlobals;
  for ( i = v4[1]; (_UNKNOWN *)i != &PfSnGlobals; i = *(_DWORD *)(i + 4) )
  {
    v6 = i - 4;
    v7 = (unsigned int *)(i + 264);
    __pld((void *)(i + 264));
    v8 = *(_DWORD *)(i + 264) & 0xFFFFFFFE;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 2, v7) );
    __dmb(0xBu);
    if ( v9 == v8 || ExfAcquireRundownProtection(v7) )
      goto LABEL_11;
  }
  v6 = 0;
LABEL_11:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_637378);
  }
  else
  {
    __dmb(0xBu);
    dword_637378 = 0;
  }
  KfLowerIrql(v13);
  if ( a1 )
  {
    v10 = (unsigned int *)(a1 + 268);
    __pld((void *)(a1 + 268));
    v11 = *(_DWORD *)(a1 + 268) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v12 = __ldrex(v10);
    while ( v12 == v11 && __strex(v11 - 2, v10) );
    if ( v12 != v11 )
      ExfReleaseRundownProtection((unsigned __int8 *)v10);
  }
  return v6;
}
