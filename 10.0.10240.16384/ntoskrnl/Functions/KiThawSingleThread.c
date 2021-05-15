// KiThawSingleThread 
 
int __fastcall KiThawSingleThread(int result, int a2, int a3)
{
  unsigned __int8 *v4; // r6
  unsigned int v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r1

  v4 = (unsigned __int8 *)(a2 + 452);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_52B0D4();
  if ( (*(_DWORD *)(a2 + 80) & 0x2000) != 0 || a3 )
  {
    __dmb(0xBu);
    v6 = (unsigned __int8 *)(a2 + 81);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 & 0xDF, v6) );
    __dmb(0xBu);
    if ( !*(_BYTE *)(a2 + 396) )
      result = KiResumeThread(a2, result, a3);
  }
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v4);
  while ( __strex(v8 & 0xFFFFFF7F, (unsigned int *)v4) );
  return result;
}
