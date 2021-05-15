// EtwpQueueStackWalkApc 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpQueueStackWalkApc(int result, unsigned int a2, unsigned int a3, _QWORD *a4)
{
  int v6; // r8
  int v7; // r7
  char v8; // r4
  int v9; // r5
  unsigned __int8 *v10; // r6
  unsigned int v11; // r2
  _DWORD *v12; // r4
  int v13; // r1 OVERLAPPED
  int v14; // r2 OVERLAPPED
  unsigned int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v18; // r2

  v6 = result;
  v7 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C);
  if ( result == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0)
    && !(*(_DWORD *)(*(_DWORD *)(result + 336) + 148) + ((*(_DWORD *)(*(_DWORD *)(result + 336) + 100) >> 3) & 1))
    && !*(_BYTE *)(result + 396) )
  {
    v8 = ((BYTE2(a3) & 7) + 24) & 7;
    __dmb(0xBu);
    v9 = 1 << v8;
    v10 = (unsigned __int8 *)(result + ((int)((HIWORD(a3) & 7) + 24) >> 3) + 80);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | v9, v10) );
    __dmb(0xBu);
    if ( ((v11 >> v8) & 1) == 0 )
    {
      if ( (*(_DWORD *)(result + 76) & 0x4000) == 0
        || (result = RtlpInterlockedPopEntrySList((unsigned __int64 *)(v7 + 960)), (v12 = (_DWORD *)result) == 0) )
      {
LABEL_15:
        __dmb(0xBu);
        do
          v15 = __ldrex(v10);
        while ( __strex(v15 & ~(_BYTE)v9, v10) );
        __dmb(0xBu);
        return result;
      }
      KeInitializeApc(result, v6, 0, (int)EtwpStackWalkApc, 0, (int)EtwpStackWalkApc, 0, a3);
      *(_QWORD *)&v13 = *a4;
      if ( a2 <= 2 )
        result = KeInsertQueueApc((int)v12, v13, v14, 0);
      else
        result = KeTryToInsertQueueApc((int)v12, v13, v14);
      if ( !result )
      {
        result = RtlpInterlockedPushEntrySList((unsigned __int64 *)(v7 + 960), v12);
        if ( a2 > 2 )
          result = EtwpQueueStackWalkDpc(v6, a3, a4);
        goto LABEL_15;
      }
      __dmb(0xBu);
      v16 = (unsigned int *)(v7 + 1592);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 + 1, v16) );
      __dmb(0xBu);
      v18 = *(_DWORD *)(v7 + 1592);
      if ( v18 > *(_DWORD *)(v7 + 1596) )
        *(_DWORD *)(v7 + 1596) = v18;
    }
  }
  return result;
}
