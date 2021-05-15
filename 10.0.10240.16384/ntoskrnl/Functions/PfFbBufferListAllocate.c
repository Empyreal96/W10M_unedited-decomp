// PfFbBufferListAllocate 
 
int __fastcall PfFbBufferListAllocate(int a1, int a2, unsigned int a3)
{
  unsigned int *v6; // r8
  unsigned int v7; // r5
  int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r5
  _DWORD *v11; // r0
  _DWORD *v12; // r4
  unsigned int v13; // r0
  _DWORD *v14; // r8
  char *v15; // r9
  char *i; // r6

  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 64);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 + a2, v6) );
  __dmb(0xBu);
  if ( (signed int)(v7 + a2) > *(_DWORD *)(a1 + 52) )
  {
    v8 = -1073741523;
    goto LABEL_9;
  }
  v9 = a2 - 16;
  if ( !a3 )
    __brkdiv0();
  v10 = (v9 / a3) & 0xFFFFFFFC;
  v11 = (_DWORD *)ExAllocatePoolWithTag(*(_DWORD *)(a1 + 40), a2);
  v12 = v11;
  if ( !v11 )
  {
    v8 = -1073741670;
LABEL_9:
    __dmb(0xBu);
    do
      v13 = __ldrex(v6);
    while ( __strex(v13 - a2, v6) );
    __dmb(0xBu);
    return v8;
  }
  *v11 = 0;
  v11[1] = 0;
  v11[2] = 0;
  v11[3] = 0;
  v11[1] = a3;
  v11[2] = v10;
  v14 = v11 + 4;
  v15 = (char *)v11 + a2;
  v11[3] = a2;
  for ( i = (char *)v11 + v10 + 16; i <= v15; i += v10 )
  {
    PfFbBufferListInsertInFree(a1, v14, v10, 0);
    v14 = (_DWORD *)((char *)v14 + v10);
  }
  RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1 + 24), v12);
  return 0;
}
