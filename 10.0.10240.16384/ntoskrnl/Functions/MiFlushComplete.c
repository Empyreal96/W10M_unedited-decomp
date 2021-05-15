// MiFlushComplete 
 
int __fastcall MiFlushComplete(_DWORD *a1, int *a2)
{
  int v3; // r4
  int v5; // r2
  unsigned int v6; // r8
  _DWORD *v7; // r0
  int result; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1

  v3 = a1[10];
  if ( (*(_WORD *)(v3 + 6) & 0x200) != 0 )
    MiRetardMdl(a1[10]);
  v5 = ((unsigned __int16)*(_DWORD *)(v3 + 24) + (unsigned __int16)*(_DWORD *)(v3 + 16)) & 0xFFF;
  v6 = (unsigned int)(*(_DWORD *)(v3 + 20) + v5 + 4095) >> 12;
  if ( (*(_WORD *)(v3 + 6) & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(v3 + 12), v3, v5);
  MiUnlockMdlWritePages(v3 + 28, v3 + 28 + 4 * v6, a2);
  if ( *a2 < 0 )
    a2[1] = 0;
  v7 = (_DWORD *)MiDecrementModifiedWriteCount(a1[4], 0);
  if ( v7 )
    MiReleaseControlAreaWaiters(v7);
  if ( (_DWORD *)v3 != a1 + 11 )
  {
    ExFreePoolWithTag(v3);
    a1[10] = a1 + 11;
  }
  a1[2] = 0;
  KeSetEvent((int)(a1 + 6), 0, 0);
  result = a1[5];
  if ( result )
  {
    if ( *a2 < 0 )
      *(_DWORD *)(result + 12) = *a2;
    __dmb(0xBu);
    v9 = (unsigned int *)(result + 8);
    do
    {
      v10 = __ldrex(v9);
      v11 = v10 - 1;
    }
    while ( __strex(v11, v9) );
    if ( !v11 )
      result = MiFreeOverlappedFlushEntry();
  }
  return result;
}
