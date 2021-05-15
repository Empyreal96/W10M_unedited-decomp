// KeTestAlertThread 
 
int __fastcall KeTestAlertThread(char a1)
{
  int v1; // r6
  unsigned int v2; // r4
  int v3; // r0
  unsigned int *v4; // r1
  unsigned int v5; // r2
  int v6; // r5

  v1 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = KfRaiseIrql(2);
  v4 = (unsigned int *)(v2 + 44);
  while ( 1 )
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( !v5 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v4 );
  }
  v6 = *(unsigned __int8 *)(v1 + v2 + 74);
  if ( v6 == 1 )
  {
    *(_BYTE *)(v1 + v2 + 74) = 0;
  }
  else if ( v1 == 1 && *(_DWORD *)(v2 + 108) != v2 + 108 )
  {
    *(_BYTE *)(v2 + 122) = 1;
  }
  __dmb(0xBu);
  *v4 = 0;
  KfLowerIrql(v3);
  return v6;
}
