// KeRemoveByKeyDeviceQueue 
 
// local variable allocation has failed, the output may be wrong!
_BYTE *__fastcall KeRemoveByKeyDeviceQueue(int a1, unsigned int a2, int a3, int a4)
{
  _BYTE *v6; // r5
  unsigned int *v7; // r0
  _DWORD *i; // r2
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  int v11; // r0
  unsigned int *v12; // r1
  int *v13; // r4
  unsigned int *v14; // r2
  unsigned int v15; // r4
  int v17; // [sp+0h] [bp-20h] BYREF
  unsigned int *v18; // [sp+4h] [bp-1Ch]
  int v19; // [sp+8h] [bp-18h]
  int v20; // [sp+Ch] [bp-14h]
  int vars4; // [sp+24h] [bp+4h]

  v17 = a1;
  v18 = (unsigned int *)a2;
  v19 = a3;
  v20 = a4;
  v6 = 0;
  v7 = (unsigned int *)(a1 + 12);
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    KeAcquireInStackQueuedSpinLock(v7, (unsigned int)&v17);
  else
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v7, &v17);
  if ( *(_DWORD *)(a1 + 4) == a1 + 4 )
  {
    *(_BYTE *)(a1 + 16) = 0;
  }
  else
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) >= a2 )
    {
      for ( i = *(_DWORD **)(a1 + 4); ; i = (_DWORD *)*i )
      {
        v6 = i;
        if ( a2 <= i[2] )
          break;
      }
    }
    else
    {
      v6 = *(_BYTE **)(a1 + 4);
    }
    *(_QWORD *)&v9 = *(_QWORD *)v6;
    if ( *(_BYTE **)(*(_DWORD *)v6 + 4) != v6 || (_BYTE *)*v10 != v6 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    v6[12] = 0;
  }
  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
  {
    KeReleaseInStackQueuedSpinLock((int)&v17);
    return v6;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v17, vars4);
    return v6;
  }
  v11 = v17;
  if ( v17 )
    goto LABEL_24;
  v12 = v18;
  __dmb(0xBu);
  do
    v13 = (int *)__ldrex(v12);
  while ( v13 == &v17 && __strex(0, v12) );
  if ( v13 != &v17 )
  {
    v11 = KxWaitForLockChainValid(&v17);
LABEL_24:
    v17 = 0;
    __dmb(0xBu);
    v14 = (unsigned int *)(v11 + 4);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 ^ 1, v14) );
  }
  return v6;
}
