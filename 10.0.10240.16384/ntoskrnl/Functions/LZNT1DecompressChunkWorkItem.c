// LZNT1DecompressChunkWorkItem 
 
int __fastcall LZNT1DecompressChunkWorkItem(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r2
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1

  v5 = LZNT1DecompressChunk(a1[4], a1[5], a1[6], a1[7], a1[8], a3, a4);
  if ( v5 < 0 )
  {
    v6 = a1[10];
    if ( *(int *)(v6 + 20) >= 0 )
      *(_DWORD *)(v6 + 20) = v5;
  }
  __dmb(0xBu);
  v7 = (unsigned int *)(a1[10] + 16);
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 - 1;
  }
  while ( __strex(v9, v7) );
  __dmb(0xBu);
  if ( !v9 )
    KeSetEvent(a1[10], 0, 0);
  return ExFreeToNPagedLookasideList((int)&RtlLznt1DecompressChunkLookaside, a1);
}
