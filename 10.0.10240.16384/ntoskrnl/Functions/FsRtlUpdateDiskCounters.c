// FsRtlUpdateDiskCounters 
 
int __fastcall FsRtlUpdateDiskCounters(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // r3
  unsigned __int64 *v5; // r4
  unsigned __int64 v6; // kr00_8
  unsigned __int64 *v7; // r3
  unsigned __int64 v8; // kr08_8

  v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( a1 )
  {
    __dmb(0xBu);
    v5 = (unsigned __int64 *)(v4 + 3896);
    do
      v6 = __ldrexd(v5);
    while ( __strexd(v6 + a1, v5) );
    __dmb(0xBu);
  }
  if ( a2 | a3 )
  {
    __dmb(0xBu);
    v7 = (unsigned __int64 *)(v4 + 3904);
    do
      v8 = __ldrexd(v7);
    while ( __strexd(v8 + __PAIR64__(a3, a2), v7) );
    __dmb(0xBu);
  }
  return a1;
}
