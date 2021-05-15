// KdLogDbgPrint 
 
int __fastcall KdLogDbgPrint(unsigned __int16 *a1)
{
  unsigned int v3; // r1
  int v4; // r3
  unsigned int v5; // r3
  unsigned int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  char *v13; // r8
  unsigned int v14; // r9
  bool v15; // zf
  unsigned int v16; // r4
  unsigned int v17; // r1
  char *v18; // r0
  int v19; // r2
  unsigned int v20; // [sp+10h] [bp-28h] BYREF
  int v21; // [sp+14h] [bp-24h]

  v15 = dword_641D68 == ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  __dmb(0xBu);
  if ( v15 )
    return sub_903A88();
  do
    v3 = __ldrex((unsigned int *)algn_641D64);
  while ( __strex(v3 + 1, (unsigned int *)algn_641D64) );
  __dmb(0xBu);
  while ( 1 )
  {
    v4 = KdpPrintSpinLock;
    __dmb(0xBu);
    if ( !v4 )
      break;
    __dmb(0xAu);
    __yield();
  }
  v21 = KfRaiseIrql(15);
  if ( KdPrintCircularBuffer )
  {
    v5 = (unsigned int)KdPrintBufferSize >> 3;
    if ( (unsigned int)KdPrintBufferSize >> 3 > 0x200 )
      v5 = 512;
    v6 = *a1;
    if ( v6 > v5 )
    {
      v6 = v5;
      __dmb(0xBu);
      do
        v17 = __ldrex(&KdPrintTruncatedCount);
      while ( __strex(v17 + 1, &KdPrintTruncatedCount) );
      __dmb(0xBu);
    }
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&KdPrintWritePointer);
    while ( !v7 && __strex(0, (unsigned int *)&KdPrintWritePointer) );
    __dmb(0xBu);
    do
    {
      v8 = v7 + v6;
      v9 = v7;
      if ( v7 + v6 >= (unsigned int)&KdPrintCircularBuffer[KdPrintBufferSize] )
        v8 -= KdPrintBufferSize;
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&KdPrintWritePointer);
      while ( v10 == v7 && __strex(v8, (unsigned int *)&KdPrintWritePointer) );
      v7 = v10;
      __dmb(0xBu);
    }
    while ( v10 != v9 );
    if ( v8 < v9 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)&KdPrintRolloverCount);
      while ( __strex(v12 + 1, (unsigned int *)&KdPrintRolloverCount) );
      __dmb(0xBu);
    }
    if ( v9 + v6 > (unsigned int)&KdPrintCircularBuffer[KdPrintBufferSize] )
    {
      v13 = &KdPrintCircularBuffer[KdPrintBufferSize - v9];
      KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, v9, v13, 0, 4, &v20);
      v14 = v20;
      v15 = v20 == (_DWORD)v13;
      if ( v20 < (unsigned int)v13 )
      {
        memset((_BYTE *)(v20 + v9), 0, (int)&v13[-v20]);
        v15 = v14 == (_DWORD)v13;
      }
      if ( v15 )
      {
        v16 = v6 - (_DWORD)v13;
        KdpCopyMemoryChunks(&v13[*((_DWORD *)a1 + 1)], 0, KdPrintCircularBuffer, v16, 0, 4, &v20);
        if ( v20 >= v16 )
          goto LABEL_23;
        v19 = v16 - v20;
        v18 = &KdPrintCircularBuffer[v20];
      }
      else
      {
        v18 = KdPrintCircularBuffer;
        v19 = v6 - (_DWORD)v13;
      }
    }
    else
    {
      KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, v9, v6, 0, 4, &v20);
      if ( v20 >= v6 )
        goto LABEL_23;
      v19 = v6 - v20;
      v18 = (char *)(v20 + v9);
    }
    memset(v18, 0, v19);
  }
LABEL_23:
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)algn_641D64);
  while ( __strex(v11 - 1, (unsigned int *)algn_641D64) );
  __dmb(0xBu);
  return KfLowerIrql(v21);
}
