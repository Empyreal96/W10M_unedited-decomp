// KeQueryTimerDueTime 
 
__int64 __fastcall KeQueryTimerDueTime(int a1)
{
  __int64 v2; // r6
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r4

  v2 = 0i64;
  v3 = KfRaiseIrql(2);
  do
    v4 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v4 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)a1) );
  }
  if ( (*(_BYTE *)(a1 + 3) & 0x40) != 0 )
    v2 = *(_QWORD *)(a1 + 16);
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)a1);
  while ( __strex(v5 & 0xFFFFFF7F, (unsigned int *)a1) );
  KfLowerIrql(v3);
  return v2;
}
