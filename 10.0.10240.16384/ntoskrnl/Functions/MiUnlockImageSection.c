// MiUnlockImageSection 
 
int __fastcall MiUnlockImageSection(unsigned int *a1, int a2, int a3)
{
  unsigned int v5; // r5
  int result; // r0
  int v7; // r8
  unsigned int v8; // r6
  unsigned int v9; // r6
  unsigned int v10; // r2
  __int16 v11; // r3

  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = KeGetCurrentIrql(a1);
  v7 = result;
  if ( !result )
    --*(_WORD *)(v5 + 308);
  __dmb(0xBu);
  do
  {
    v8 = __ldrex(a1);
    v9 = v8 - 1;
  }
  while ( __strex(v9, a1) );
  if ( !v9 || v9 == -1 )
    KeBugCheckEx(26, 4112, a2 << 10);
  if ( v9 == 1 )
  {
    result = MiUnlockCodePage(a2, a3);
    __dmb(0xBu);
    do
      v10 = __ldrex(a1);
    while ( __strex(v10 - 1, a1) );
    __dmb(0xFu);
    if ( dword_632F60 )
      result = ExpUnblockPushLock(&dword_632F60, 0, 0);
  }
  if ( !v7 )
  {
    v11 = *(_WORD *)(v5 + 308) + 1;
    *(_WORD *)(v5 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v5 + 100) != v5 + 100 )
      result = sub_50B9DC(result);
  }
  return result;
}
