// KeInsertDeviceQueue 
 
int __fastcall KeInsertDeviceQueue(int a1, int a2, int a3, int a4)
{
  int v6; // r6
  unsigned int *v7; // r0
  int v8; // r3
  int *v9; // r1
  int v10; // r0
  unsigned int *v11; // r1
  int *v12; // r4
  unsigned int *v13; // r2
  unsigned int v14; // r4
  int v16; // [sp+0h] [bp-20h] BYREF
  unsigned int *v17; // [sp+4h] [bp-1Ch]
  int v18; // [sp+8h] [bp-18h]
  int v19; // [sp+Ch] [bp-14h]
  int vars4; // [sp+24h] [bp+4h]

  v16 = a1;
  v17 = (unsigned int *)a2;
  v18 = a3;
  v19 = a4;
  v6 = 0;
  v7 = (unsigned int *)(a1 + 12);
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    KeAcquireInStackQueuedSpinLock(v7, (unsigned int)&v16);
  else
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v7, &v16);
  v8 = *(unsigned __int8 *)(a1 + 16);
  *(_BYTE *)(a1 + 16) = 1;
  if ( v8 == 1 )
  {
    v9 = *(int **)(a1 + 8);
    *(_DWORD *)a2 = a1 + 4;
    *(_DWORD *)(a2 + 4) = v9;
    if ( *v9 != a1 + 4 )
      __fastfail(3u);
    *v9 = a2;
    *(_DWORD *)(a1 + 8) = a2;
    v6 = 1;
  }
  *(_BYTE *)(a2 + 12) = v6;
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    KeReleaseInStackQueuedSpinLock((int)&v16);
    return v6;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v16, vars4);
    return v6;
  }
  v10 = v16;
  if ( v16 )
    goto LABEL_18;
  v11 = v17;
  __dmb(0xBu);
  do
    v12 = (int *)__ldrex(v11);
  while ( v12 == &v16 && __strex(0, v11) );
  if ( v12 != &v16 )
  {
    v10 = KxWaitForLockChainValid(&v16);
LABEL_18:
    v16 = 0;
    __dmb(0xBu);
    v13 = (unsigned int *)(v10 + 4);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 ^ 1, v13) );
  }
  return v6;
}
