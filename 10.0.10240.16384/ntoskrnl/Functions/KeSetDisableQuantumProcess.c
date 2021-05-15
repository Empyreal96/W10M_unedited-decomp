// KeSetDisableQuantumProcess 
 
int __fastcall KeSetDisableQuantumProcess(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  unsigned __int8 *v7; // r3
  unsigned int v9; // r1
  _DWORD *v10; // r0
  int v11; // r7
  unsigned __int8 *v12; // r3
  unsigned int v13; // r2
  _DWORD var18[7]; // [sp+0h] [bp-18h] BYREF

  var18[0] = a3;
  var18[1] = a4;
  v6 = KiAcquireProcessLockExclusive(a1, var18);
  __dmb(0xBu);
  v7 = (unsigned __int8 *)(a1 + 100);
  if ( a2 )
    return sub_515460(v6);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 & 0xFB, v7) );
  __dmb(0xBu);
  v10 = *(_DWORD **)(a1 + 40);
  v11 = (unsigned __int8)(v9 & 4) >> 2;
  while ( v10 != (_DWORD *)(a1 + 40) )
  {
    __dmb(0xBu);
    v12 = (unsigned __int8 *)(v10 - 97);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0x7F, v12) );
    __dmb(0xBu);
    v10 = (_DWORD *)*v10;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 48);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(a1 + 48) = 0;
  }
  KfLowerIrql(LOBYTE(var18[0]));
  return v11;
}
