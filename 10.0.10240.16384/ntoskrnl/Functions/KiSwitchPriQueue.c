// KiSwitchPriQueue 
 
unsigned int *__fastcall KiSwitchPriQueue(int a1, int a2, int a3)
{
  _DWORD *v5; // r6
  unsigned int *result; // r0
  unsigned int v7; // r2
  unsigned int v8; // r2
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r1
  _DWORD *v12; // r1
  unsigned int v13; // r1

  v5 = (_DWORD *)(a1 + 312);
  if ( a3 )
    return (unsigned int *)sub_525C68();
  do
    v7 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)a2) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v7 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a2 & 0x80) != 0 );
    do
      v7 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v7 | 0x80, (unsigned __int8 *)a2) );
  }
  result = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v8 = __ldrex(result);
    while ( __strex(1u, result) );
    __dmb(0xBu);
    if ( !v8 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *result );
  }
  *(_DWORD *)(a1 + 152) = a2;
  v9 = *(char *)(a1 + 347);
  *(_DWORD *)(a1 + 332) = v9;
  __dmb(0xBu);
  v10 = (unsigned int *)(a2 + 4 * (v9 + 68));
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 + 1, v10) );
  __dmb(0xBu);
  *result = 0;
  v12 = *(_DWORD **)(a2 + 408);
  *v5 = a2 + 404;
  v5[1] = v12;
  if ( *v12 != a2 + 404 )
    __fastfail(3u);
  *v12 = v5;
  *(_DWORD *)(a2 + 408) = v5;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)a2);
  while ( __strex(v13 & 0xFFFFFF7F, (unsigned int *)a2) );
  return result;
}
