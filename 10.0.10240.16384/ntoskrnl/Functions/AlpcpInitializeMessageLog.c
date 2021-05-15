// AlpcpInitializeMessageLog 
 
int __fastcall AlpcpInitializeMessageLog(unsigned int a1, unsigned int a2)
{
  _DWORD *v4; // r0
  int v6; // r3
  int *v7; // r5
  unsigned int v8; // r0
  int *v9; // r0
  unsigned int i; // r2
  int **v11; // r1
  unsigned int v12; // r1
  int **v13; // r2

  AlpcpMessageLogLock = 0;
  AlpcpFreeMessageLogListHead = (int)&AlpcpFreeMessageLogListHead;
  dword_6212D4 = (int)&AlpcpFreeMessageLogListHead;
  AlpcpFreeMessageSnapshotListHead = (int)&AlpcpFreeMessageSnapshotListHead;
  dword_6212CC = (int)&AlpcpFreeMessageSnapshotListHead;
  AlpcpMessageLogListHead = (int)&AlpcpMessageLogListHead;
  dword_6212BC = (int)&AlpcpMessageLogListHead;
  if ( a1 && a2 )
  {
    v4 = (_DWORD *)ExAllocatePoolWithTag(1, 0x2000, 1817013313);
    AlpcpMessageLogLookupTable = (int)v4;
    if ( !v4 )
      return -1073741670;
    v6 = 1024;
    do
    {
      *v4 = v4;
      v4[1] = v4;
      v4 += 2;
      --v6;
    }
    while ( v6 );
    v7 = (int *)ExAllocatePoolWithTag(1, 36 * a1, 1817013313);
    if ( !v7 )
    {
      v8 = AlpcpMessageLogLookupTable;
LABEL_9:
      ExFreePoolWithTag(v8);
      return -1073741670;
    }
    v9 = (int *)ExAllocatePoolWithTag(1, 72 * a2, 1934453825);
    if ( !v9 )
    {
      ExFreePoolWithTag(AlpcpMessageLogLookupTable);
      v8 = (unsigned int)v7;
      goto LABEL_9;
    }
    for ( i = 0; i < a1; v7 += 9 )
    {
      v7[7] = (int)(v7 + 7);
      v7[8] = (int)(v7 + 7);
      v11 = (int **)dword_6212D4;
      *v7 = (int)&AlpcpFreeMessageLogListHead;
      v7[1] = (int)v11;
      if ( *v11 != &AlpcpFreeMessageLogListHead )
        __fastfail(3u);
      *v11 = v7;
      dword_6212D4 = (int)v7;
      ++i;
    }
    v12 = 0;
    if ( a2 )
    {
      v13 = (int **)dword_6212CC;
      do
      {
        *v9 = (int)&AlpcpFreeMessageSnapshotListHead;
        v9[1] = (int)v13;
        if ( *v13 != &AlpcpFreeMessageSnapshotListHead )
          __fastfail(3u);
        *v13 = v9;
        v13 = (int **)v9;
        dword_6212CC = (int)v9;
        ++v12;
        v9 += 18;
      }
      while ( v12 < a2 );
    }
  }
  return 0;
}
