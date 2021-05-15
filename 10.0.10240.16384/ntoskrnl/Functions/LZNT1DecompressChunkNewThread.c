// LZNT1DecompressChunkNewThread 
 
int __fastcall LZNT1DecompressChunkNewThread(int a1, unsigned int a2, int a3, unsigned int a4, int a5, signed int a6)
{
  _DWORD *v10; // r0
  __int64 v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1
  unsigned int v16; // [sp+4h] [bp-24h]
  _DWORD v17[8]; // [sp+8h] [bp-20h] BYREF

  v16 = a2;
  v17[0] = a3;
  v17[1] = a4;
  if ( a2 <= MmUserProbeAddress )
    return ((int (__fastcall *)(unsigned int, int, unsigned int, int, _DWORD *, unsigned int))LZNT1DecompressChunk)(
             a2,
             a3,
             a4,
             a5,
             v17,
             v16);
  if ( a4 <= MmUserProbeAddress )
    return ((int (__fastcall *)(unsigned int, int, unsigned int, int, _DWORD *, unsigned int))LZNT1DecompressChunk)(
             a2,
             a3,
             a4,
             a5,
             v17,
             v16);
  if ( (int)(a3 - a2) < a6 )
    return ((int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))LZNT1DecompressChunk)(
             a2,
             a3,
             a4,
             a5,
             v17,
             v16);
  v10 = (_DWORD *)ExAllocateFromNPagedLookasideList((int)&RtlLznt1DecompressChunkLookaside);
  HIDWORD(v11) = v10;
  if ( !v10 )
    return ((int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))LZNT1DecompressChunk)(
             a2,
             a3,
             a4,
             a5,
             v17,
             v16);
  LODWORD(v11) = LZNT1DecompressChunkWorkItem;
  *v10 = 0;
  *(_QWORD *)(HIDWORD(v11) + 8) = v11;
  v10[4] = a2;
  v10[6] = a4;
  v10[7] = a5;
  v10[8] = v10 + 9;
  v10[5] = a3;
  v10[10] = a1;
  __dmb(0xBu);
  v12 = (unsigned int *)(a1 + 16);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + 1, v12) );
  __dmb(0xBu);
  v14 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 32;
  ExQueueWorkItem((_DWORD *)HIDWORD(v11), v14);
  return 0;
}
