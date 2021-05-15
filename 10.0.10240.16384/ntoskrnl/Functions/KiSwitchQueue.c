// KiSwitchQueue 
 
unsigned int __fastcall KiSwitchQueue(int a1, int a2, int a3)
{
  _DWORD *v4; // r5
  unsigned int result; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r2
  _DWORD *v9; // r1
  unsigned int v10; // r1

  v4 = (_DWORD *)(a1 + 312);
  if ( a3 )
    return sub_52377C();
  *(_DWORD *)(a1 + 152) = a2;
  __dmb(0xBu);
  v6 = (unsigned int *)(a2 + 24);
  do
  {
    v7 = __ldrex(v6);
    result = v7 + 1;
  }
  while ( __strex(result, v6) );
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v8 | 0x80, (unsigned __int8 *)a2) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v8 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a2 & 0x80) != 0 );
    do
      v8 = __ldrex((unsigned __int8 *)a2);
    while ( __strex(v8 | 0x80, (unsigned __int8 *)a2) );
  }
  v9 = *(_DWORD **)(a2 + 36);
  *v4 = a2 + 32;
  v4[1] = v9;
  if ( *v9 != a2 + 32 )
    __fastfail(3u);
  *v9 = v4;
  *(_DWORD *)(a2 + 36) = v4;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)a2);
  while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)a2) );
  return result;
}
