// MiCreateDecayPfn 
 
int __fastcall MiCreateDecayPfn(int a1)
{
  int v2; // r0
  int v3; // r5
  int v5; // r4
  char v6; // r2
  int v7; // r3
  int v8; // r4
  unsigned __int8 *v9; // r1
  unsigned int v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r3
  unsigned int v14; // r2

  v2 = RtlpInterlockedPopEntrySList((unsigned __int64 *)&dword_634698);
  v3 = v2;
  if ( !v2 )
    return sub_51F798();
  __mrc(15, 0, 13, 0, 3);
  v5 = (v2 - MmPfnDatabase) / 24;
  v6 = *(_BYTE *)(v2 + 19);
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0xFFF | (v5 << 12);
  v7 = *(_DWORD *)(v2 + 20);
  *(_BYTE *)(v2 + 19) = v6 | 8;
  *(_DWORD *)(v2 + 20) = v7 & 0xFF00000 | v5 & 0xFFFFF | (a1 << 28);
  v8 = KfRaiseIrql(2);
  v9 = (unsigned __int8 *)(v3 + 15);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v13 = *(_DWORD *)(v3 + 12);
        __dmb(0xBu);
      }
      while ( v13 < 0 );
      do
        v14 = __ldrex(v9);
      while ( __strex(v14 | 0x80, v9) );
      __dmb(0xBu);
    }
    while ( v14 >> 7 );
  }
  *(_BYTE *)(v3 + 19) = *(_BYTE *)(v3 + 19) & 0xF8 | 5;
  MiInsertPageInList(v3, 4);
  __dmb(0xBu);
  v11 = (unsigned int *)(v3 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  KfLowerIrql(v8);
  return v3;
}
