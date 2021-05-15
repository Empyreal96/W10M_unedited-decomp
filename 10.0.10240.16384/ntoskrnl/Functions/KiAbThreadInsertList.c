// KiAbThreadInsertList 
 
int __fastcall KiAbThreadInsertList(int a1, _DWORD *a2, _DWORD *a3)
{
  int result; // r0
  unsigned int *v5; // r5
  unsigned int v6; // r4
  unsigned __int16 *v7; // r2
  unsigned int v8; // r1

  result = 0;
  v5 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  if ( *a3 == 1 )
  {
    result = 1;
    *a3 = *a2;
    *a2 = a3;
  }
  __dmb(0xBu);
  *v5 = 0;
  if ( result )
  {
    __dmb(0xBu);
    v7 = (unsigned __int16 *)(a1 + 808);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
    __dmb(0xBu);
  }
  return result;
}
