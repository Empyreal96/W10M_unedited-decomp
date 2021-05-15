// MiStoreModifiedWriteComplete 
 
int __fastcall MiStoreModifiedWriteComplete(__int64 a1)
{
  int v1; // r4
  int v2; // r3
  int v3; // r0
  int v4; // r6
  int v5; // r5
  int v6; // r7
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 32);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(v2 + 120);
  if ( v3 < 0 )
  {
    MiStoreLogWriteCompleteFailure(v3);
    v5 = MmPfnDatabase + 24 * *(_DWORD *)(v1 + 64);
    v6 = KfRaiseIrql(2);
    v7 = (unsigned __int8 *)(v5 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v8 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v9 = *(_DWORD *)(v5 + 12);
        __dmb(0xBu);
      }
      while ( v9 < 0 );
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 | 0x80, v7) );
    }
    *(_BYTE *)(v5 + 18) |= 0x10u;
    __dmb(0xBu);
    v10 = (unsigned int *)(v5 + 12);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
    a1 = KfLowerIrql(v6);
    *(_DWORD *)(v4 + 684) = 32;
  }
  return MiStoreModifiedWriteDereference(*(_DWORD *)(v1 + 32), HIDWORD(a1));
}
