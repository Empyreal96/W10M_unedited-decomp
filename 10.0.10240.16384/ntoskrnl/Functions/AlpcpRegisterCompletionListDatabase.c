// AlpcpRegisterCompletionListDatabase 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AlpcpRegisterCompletionListDatabase(int a1)
{
  int v2; // r0
  unsigned int v3; // r2
  int *v5; // r1 OVERLAPPED
  int **v6; // r2 OVERLAPPED
  int v7; // r5
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r3

  v2 = KeAbPreAcquire((unsigned int)&AlpcpCompletionListDatabase, 0, 0);
  do
    v3 = __ldrex((unsigned __int8 *)&AlpcpCompletionListDatabase);
  while ( __strex(v3 | 1, (unsigned __int8 *)&AlpcpCompletionListDatabase) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    return sub_817184(v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v5 = (int *)dword_6212A8;
  if ( (int *)dword_6212A8 != &dword_6212A8 )
  {
    v9 = *(_DWORD *)(a1 + 8);
    do
    {
      v10 = v5[2];
      if ( v10 > v9 )
        break;
      if ( v10 == v9 )
      {
        if ( (unsigned int)v5[5] >= *(_DWORD *)(a1 + 24) )
          break;
        if ( (unsigned int)v5[6] > *(_DWORD *)(a1 + 20) )
        {
          v7 = 0;
          goto LABEL_10;
        }
      }
      v5 = (int *)*v5;
    }
    while ( v5 != &dword_6212A8 );
  }
  v6 = (int **)v5[1];
  *(_QWORD *)a1 = *(_QWORD *)&v5;
  if ( *v6 != v5 )
    __fastfail(3u);
  *v6 = (int *)a1;
  v5[1] = a1;
  ++dword_6212A4;
  v7 = 1;
LABEL_10:
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&AlpcpCompletionListDatabase);
  while ( __strex(v8 - 1, (unsigned int *)&AlpcpCompletionListDatabase) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpCompletionListDatabase);
  KeAbPostRelease((unsigned int)&AlpcpCompletionListDatabase);
  return v7;
}
