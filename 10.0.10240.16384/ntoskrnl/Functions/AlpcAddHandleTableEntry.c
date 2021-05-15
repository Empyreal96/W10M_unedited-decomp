// AlpcAddHandleTableEntry 
 
int __fastcall AlpcAddHandleTableEntry(int *a1, _DWORD *a2)
{
  unsigned __int8 *v2; // r5
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r4
  _DWORD *v10; // r2
  _BYTE *v12; // r0
  int v13; // r7
  int v14; // r4
  int v15; // r4
  int v16; // r3
  unsigned int v17; // r1
  int result; // r0
  unsigned int v19; // r1

  v2 = (unsigned __int8 *)(a1 + 3);
  v5 = KeAbPreAcquire((unsigned int)(a1 + 3), 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v2);
  while ( __strex(v7 | 1, v2) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v2, v5, (unsigned int)v2);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = a1[1];
  v9 = 0;
  if ( v8 )
  {
    v10 = (_DWORD *)*a1;
    while ( *v10++ )
    {
      if ( ++v9 >= v8 )
        goto LABEL_11;
    }
    *(v10 - 1) = *a2;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)v2);
    while ( __strex(v19 - 1, (unsigned int *)v2) );
    if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v2);
    KeAbPostRelease((unsigned int)v2);
    result = v9 + 16;
  }
  else
  {
LABEL_11:
    v12 = (_BYTE *)ExAllocatePoolWithTag(1, 8 * v8, 1632136257);
    v13 = (int)v12;
    v14 = -1;
    if ( v12 )
    {
      memset(v12, 0, 8 * a1[1]);
      memmove(v13, *a1, 4 * a1[1]);
      v15 = a1[1];
      *(_DWORD *)(v13 + 4 * v15) = *a2;
      if ( a1[1] == 16 )
        ExFreeToPagedLookasideList((int)&unk_643600, (_DWORD *)*a1);
      else
        ExFreePoolWithTag(*a1);
      v16 = a1[1];
      *a1 = v13;
      a1[1] = 2 * v16;
      v14 = v15 + 16;
    }
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v2);
    while ( __strex(v17 - 1, (unsigned int *)v2) );
    if ( (v17 & 2) != 0 )
    {
      result = sub_7F7D28();
    }
    else
    {
      KeAbPostRelease((unsigned int)v2);
      result = v14;
    }
  }
  return result;
}
