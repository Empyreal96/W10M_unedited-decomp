// CmpRemoveFromDelayedClose 
 
unsigned int __fastcall CmpRemoveFromDelayedClose(int a1)
{
  int v2; // r6
  int v3; // r7
  unsigned int v4; // r2
  int v5; // r3
  __int64 v7; // r0
  unsigned int v8; // r1

  v2 = KeAbPreAcquire((unsigned int)&CmpDelayedCloseTableLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&CmpDelayedCloseTableLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&CmpDelayedCloseTableLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpDelayedCloseTableLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_6322E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6322FC = v3;
  v5 = *(_DWORD *)(a1 + 8);
  if ( (v5 & 2) != 0 )
  {
    if ( (v5 & 4) != 0 )
      return sub_8061A4();
    v7 = *(_QWORD *)(a1 + 116);
    if ( *(_DWORD *)(v7 + 4) != a1 + 116 || *(_DWORD *)HIDWORD(v7) != a1 + 116 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    --CmpDelayedCloseElements;
    --qword_920968;
    *(_DWORD *)(a1 + 116) = a1 + 116;
    *(_DWORD *)(a1 + 120) = a1 + 116;
    __dmb(0xFu);
    *(_DWORD *)(a1 + 8) &= 0xFFFFFFFD;
    LOBYTE(v3) = dword_6322FC;
  }
  dword_6322E4 = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex(&CmpDelayedCloseTableLock);
  while ( !v8 && __strex(1u, &CmpDelayedCloseTableLock) );
  if ( v8 )
    ExpReleaseFastMutexContended(&CmpDelayedCloseTableLock, v8);
  KfLowerIrql((unsigned __int8)v3);
  return KeAbPostRelease((unsigned int)&CmpDelayedCloseTableLock);
}
