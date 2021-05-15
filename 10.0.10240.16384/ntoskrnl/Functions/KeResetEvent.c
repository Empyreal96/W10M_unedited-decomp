// KeResetEvent 
 
int __fastcall KeResetEvent(int a1)
{
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r4
  unsigned int v5; // r1
  unsigned int v7; // r2

  v2 = KfRaiseIrql(2);
  do
    v3 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v3 | 0x80, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( v3 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( (*(_DWORD *)a1 & 0x80) != 0 );
      do
        v7 = __ldrex((unsigned __int8 *)a1);
      while ( __strex(v7 | 0x80, (unsigned __int8 *)a1) );
      __dmb(0xBu);
    }
    while ( v7 >> 7 );
  }
  v4 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)a1);
  while ( __strex(v5 & 0xFFFFFF7F, (unsigned int *)a1) );
  KfLowerIrql(v2);
  return v4;
}
