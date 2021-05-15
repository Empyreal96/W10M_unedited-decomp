// MiIdentifyPfnWrapper 
 
int __fastcall MiIdentifyPfnWrapper(int *a1, int *a2)
{
  int v4; // r7
  unsigned __int8 *v5; // r5
  unsigned int v6; // r2
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v4 = KfRaiseIrql(2);
  v5 = (unsigned __int8 *)a1 + 15;
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v6 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v7 = a1[3];
      __dmb(0xBu);
    }
    while ( v7 < 0 );
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
  }
  MiIdentifyPfn(a1, a2);
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 3);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  return KfLowerIrql(v4);
}
