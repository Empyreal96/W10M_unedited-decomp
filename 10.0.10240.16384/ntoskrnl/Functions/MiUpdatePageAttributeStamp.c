// MiUpdatePageAttributeStamp 
 
int __fastcall MiUpdatePageAttributeStamp(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r2
  int v6; // r3
  int v7; // r2
  int v8; // r0
  unsigned int *v9; // r1
  unsigned int *v10; // r2
  int v11; // [sp+0h] [bp-10h] BYREF
  unsigned int *v12; // [sp+4h] [bp-Ch]
  int v13; // [sp+8h] [bp-8h]
  int vars4; // [sp+14h] [bp+4h]

  v11 = a2;
  v12 = (unsigned int *)a3;
  v13 = a4;
  v4 = result;
  if ( *(_WORD *)(result + 16) )
    return result;
  v5 = *(_BYTE *)(result + 18) & 7;
  if ( v5 != 2 )
    return sub_526154(*(_DWORD *)&MiSystemPartition[2 * v5 + 1226]);
  if ( (*(_BYTE *)(result + 19) & 8) != 0 )
    v6 = 5;
  else
    v6 = *(_BYTE *)(result + 19) & 7;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_63FD00[5 * v6 + 4], &v11, 5 * v6, dword_63FD00);
  __dmb(0xFu);
  v7 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  *(_DWORD *)(v4 + 12) ^= (*(_DWORD *)(v4 + 12) ^ (v7 << 20)) & 0xF00000;
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(&v11, vars4);
  v8 = v11;
  if ( v11 )
  {
LABEL_14:
    v11 = 0;
    __dmb(0xBu);
    v10 = (unsigned int *)(v8 + 4);
    do
      result = __ldrex(v10);
    while ( __strex(result ^ 1, v10) );
    return result;
  }
  v9 = v12;
  __dmb(0xBu);
  do
    result = __ldrex(v9);
  while ( (int *)result == &v11 && __strex(0, v9) );
  if ( (int *)result != &v11 )
  {
    v8 = KxWaitForLockChainValid(&v11);
    goto LABEL_14;
  }
  return result;
}
