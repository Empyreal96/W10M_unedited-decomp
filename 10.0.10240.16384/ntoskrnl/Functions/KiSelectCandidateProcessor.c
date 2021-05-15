// KiSelectCandidateProcessor 
 
int __fastcall KiSelectCandidateProcessor(int a1, int a2, int a3)
{
  _DWORD *v3; // r7
  int v5; // r5
  int v6; // r9
  unsigned int *v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  unsigned int *v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r2

  v3 = *(_DWORD **)(a1 + 2360);
  v5 = a1;
  v6 = v3[65] & *(_DWORD *)(a2 + 356);
  v7 = v3 + 35;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v3 + 35);
  }
  else
  {
    v8 = *v7 & 0x7FFFFFFF;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 1, v7) );
    __dmb(0xBu);
    if ( v9 != v8 )
      ExpWaitForSpinLockSharedAndAcquire(v3 + 35);
  }
  v10 = v3[34] & v6;
  if ( (v10 & a3) != 0 )
    v10 &= a3;
  if ( v10 )
    v5 = (int)*(&KiProcessorBlock
              + (((unsigned __int8)__clz(__rbit(__ROR4__(v10, *(_BYTE *)(v5 + 1053)))) + *(_BYTE *)(v5 + 1053)) & 0x1F));
  v11 = (unsigned int *)(v5 + 24);
  while ( 1 )
  {
    do
      v12 = __ldrex(v11);
    while ( __strex(1u, v11) );
    __dmb(0xBu);
    if ( !v12 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v11 );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3 + 35);
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(v7);
    while ( __strex(v13 & 0xBFFFFFFF, v7) );
    __dmb(0xBu);
    do
      v14 = __ldrex(v7);
    while ( __strex(v14 - 1, v7) );
  }
  return v5;
}
