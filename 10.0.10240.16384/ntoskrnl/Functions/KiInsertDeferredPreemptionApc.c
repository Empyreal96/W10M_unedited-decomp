// KiInsertDeferredPreemptionApc 
 
int __fastcall KiInsertDeferredPreemptionApc(int result, int a2, int a3)
{
  int v4; // r6
  unsigned __int8 *v5; // r3
  unsigned int v6; // r2
  unsigned __int8 *v7; // r3
  unsigned int v8; // r2
  unsigned int *v9; // r5
  unsigned int v10; // r2

  v4 = result;
  if ( a3 )
  {
    __dmb(0xBu);
    v5 = (unsigned __int8 *)(a2 + 81);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 & 0xFB, v5) );
    __dmb(0xBu);
  }
  else if ( (*(_DWORD *)(a2 + 80) & 0x200) != 0 )
  {
    return result;
  }
  __dmb(0xBu);
  v7 = (unsigned __int8 *)(a2 + 81);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 2, v7) );
  __dmb(0xBu);
  v9 = (unsigned int *)(a2 + 44);
  while ( 1 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex(1u, v9) );
    __dmb(0xBu);
    if ( !v10 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v9 );
  }
  if ( !*(_BYTE *)(a2 + 446) && (*(_DWORD *)(a2 + 76) & 0x4000) != 0 )
  {
    *(_BYTE *)(a2 + 446) = 1;
    KiInsertQueueApc(a2 + 400);
    result = KiSignalThreadForApc(v4, a2 + 400, 2);
  }
  __dmb(0xBu);
  *v9 = 0;
  return result;
}
