// KeInsertByKeyDeviceQueue 
 
int __fastcall KeInsertByKeyDeviceQueue(int a1, int a2, unsigned int a3, int a4)
{
  int v7; // r6
  unsigned int *v8; // r0
  int v9; // r3
  _DWORD *v10; // r2
  int *v11; // r1
  int v12; // r0
  unsigned int *v13; // r1
  int *v14; // r4
  unsigned int *v15; // r2
  unsigned int v16; // r4
  int v18; // [sp+0h] [bp-20h] BYREF
  unsigned int *v19; // [sp+4h] [bp-1Ch]
  int v20; // [sp+8h] [bp-18h]
  int vars4; // [sp+24h] [bp+4h]

  v18 = a2;
  v19 = (unsigned int *)a3;
  v20 = a4;
  *(_DWORD *)(a2 + 8) = a3;
  v7 = 0;
  v8 = (unsigned int *)(a1 + 12);
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    KeAcquireInStackQueuedSpinLock(v8, (unsigned int)&v18);
  else
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v8, &v18);
  v9 = *(unsigned __int8 *)(a1 + 16);
  *(_BYTE *)(a1 + 16) = 1;
  if ( v9 == 1 )
  {
    v10 = (_DWORD *)(a1 + 4);
    if ( *(_DWORD *)(a1 + 4) != a1 + 4 && a3 < *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) )
    {
      do
        v10 = (_DWORD *)*v10;
      while ( a3 >= v10[2] );
    }
    v11 = (int *)v10[1];
    *(_DWORD *)a2 = v10;
    *(_DWORD *)(a2 + 4) = v11;
    if ( (_DWORD *)*v11 != v10 )
      __fastfail(3u);
    *v11 = a2;
    v10[1] = a2;
    v7 = 1;
  }
  *(_BYTE *)(a2 + 12) = v7;
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    KeReleaseInStackQueuedSpinLock((int)&v18);
    return v7;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v18, vars4);
    return v7;
  }
  v12 = v18;
  if ( v18 )
    goto LABEL_21;
  v13 = v19;
  __dmb(0xBu);
  do
    v14 = (int *)__ldrex(v13);
  while ( v14 == &v18 && __strex(0, v13) );
  if ( v14 != &v18 )
  {
    v12 = KxWaitForLockChainValid(&v18);
LABEL_21:
    v18 = 0;
    __dmb(0xBu);
    v15 = (unsigned int *)(v12 + 4);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 ^ 1, v15) );
  }
  return v7;
}
