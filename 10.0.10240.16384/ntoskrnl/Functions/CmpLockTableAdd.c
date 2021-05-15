// CmpLockTableAdd 
 
int __fastcall CmpLockTableAdd(int a1, int a2)
{
  int v4; // r0
  unsigned int *v5; // r2
  int result; // r0
  unsigned int *v7; // r2
  signed int v8; // r1
  int v9; // r4

  v4 = RtlpInterlockedPopEntrySList((unsigned __int64 *)CmpLockTable);
  v5 = (unsigned int *)v4;
  if ( !v4 )
    KeBugCheckEx(81, 20, 0, 0, 0);
  result = (v4 - CmpLockTable - 16) >> 3;
  *v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5[1] = (a2 != 0) | a1;
  do
  {
    v9 = *(_DWORD *)(CmpLockTable + 12);
    if ( v9 >= result )
      break;
    __dmb(0xBu);
    v7 = (unsigned int *)(CmpLockTable + 12);
    do
      v8 = __ldrex(v7);
    while ( v8 == v9 && __strex(result, v7) );
    __dmb(0xBu);
  }
  while ( v8 < result );
  return result;
}
