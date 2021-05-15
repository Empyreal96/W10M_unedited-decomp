// KeRemoveDeviceQueue 
 
__int64 *__fastcall KeRemoveDeviceQueue(int a1, int a2, int a3, int a4)
{
  __int64 *v5; // r5
  unsigned int *v6; // r0
  __int64 **v7; // r2
  __int64 v8; // kr00_8
  int v9; // r0
  unsigned int *v10; // r1
  int *v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r4
  int v15; // [sp+0h] [bp-20h] BYREF
  unsigned int *v16; // [sp+4h] [bp-1Ch]
  int v17; // [sp+8h] [bp-18h]
  int v18; // [sp+Ch] [bp-14h]
  int vars4; // [sp+24h] [bp+4h]

  v15 = a1;
  v16 = (unsigned int *)a2;
  v17 = a3;
  v18 = a4;
  v5 = 0;
  v6 = (unsigned int *)(a1 + 12);
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    KeAcquireInStackQueuedSpinLock(v6, (unsigned int)&v15);
  else
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v6, &v15);
  v7 = (__int64 **)(a1 + 4);
  if ( *(_DWORD *)(a1 + 4) == a1 + 4 )
  {
    *(_BYTE *)(a1 + 16) = 0;
  }
  else
  {
    v5 = *v7;
    v8 = **v7;
    if ( (__int64 **)HIDWORD(v8) != v7 || *(__int64 **)(v8 + 4) != v5 )
      __fastfail(3u);
    *v7 = (__int64 *)v8;
    *(_DWORD *)(v8 + 4) = v7;
    *((_BYTE *)v5 + 12) = 0;
  }
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    KeReleaseInStackQueuedSpinLock((int)&v15);
    return v5;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v15, vars4);
    return v5;
  }
  v9 = v15;
  if ( v15 )
    goto LABEL_19;
  v10 = v16;
  __dmb(0xBu);
  do
    v11 = (int *)__ldrex(v10);
  while ( v11 == &v15 && __strex(0, v10) );
  if ( v11 != &v15 )
  {
    v9 = KxWaitForLockChainValid(&v15);
LABEL_19:
    v15 = 0;
    __dmb(0xBu);
    v12 = (unsigned int *)(v9 + 4);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 ^ 1, v12) );
  }
  return v5;
}
