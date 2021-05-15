// CmpDereferenceNameControlBlockWithLock 
 
unsigned int __fastcall CmpDereferenceNameControlBlockWithLock(int *a1)
{
  unsigned int v2; // r6
  unsigned __int8 *v3; // r8
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r3
  int v8; // r3
  int **v9; // r2
  int *v10; // r3
  int v11; // r3
  int v12; // r2
  unsigned int *v13; // r4
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2

  v2 = 101027 * (a1[1] ^ ((unsigned int)a1[1] >> 9));
  v3 = (unsigned __int8 *)(CmpNameCacheTable + 8 * (((unsigned __int16)v2 ^ (unsigned __int16)(v2 >> 9)) & 0x7FF));
  v4 = KeAbPreAcquire((unsigned int)v3, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *a1 & 1 | (2 * (((unsigned int)*a1 >> 1) - 1));
  *a1 = v7;
  if ( (v7 & 0xFFFFFFFE) == 0 )
  {
    v8 = CmpNameCacheTable + 8 * (((unsigned __int16)v2 ^ (unsigned __int16)(v2 >> 9)) & 0x7FF);
    v9 = (int **)(v8 + 4);
    if ( v8 != -4 )
    {
      do
      {
        v10 = *v9;
        if ( !*v9 )
          break;
        if ( v10 == a1 + 1 )
        {
          *v9 = (int *)v10[1];
          break;
        }
        v9 = (int **)(v10 + 1);
      }
      while ( v10 != (int *)-4 );
    }
    ExFreePoolWithTag((unsigned int)a1);
  }
  v11 = CmpNameCacheTable;
  v12 = ((unsigned __int16)v2 ^ (unsigned __int16)(v2 >> 9)) & 0x7FF;
  __pld((void *)(CmpNameCacheTable + 8 * v12));
  v13 = (unsigned int *)(v11 + 8 * v12);
  v14 = *v13;
  if ( (*v13 & 0xFFFFFFF0) > 0x10 )
    v15 = v14 - 16;
  else
    v15 = 0;
  if ( (v14 & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v16 = __ldrex(v13);
  while ( v16 == v14 && __strex(v15, v13) );
  if ( v16 != v14 )
LABEL_24:
    ExfReleasePushLock(v13, v14);
  return KeAbPostRelease((unsigned int)v13);
}
