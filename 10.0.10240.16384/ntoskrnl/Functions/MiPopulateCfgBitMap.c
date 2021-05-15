// MiPopulateCfgBitMap 
 
int __fastcall MiPopulateCfgBitMap(int *a1, _DWORD *a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r9
  unsigned int v6; // r10
  unsigned int *v8; // r6
  _DWORD *v9; // r7
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r5
  unsigned int v16; // r1
  int v18; // [sp+10h] [bp-38h]
  _DWORD v19[12]; // [sp+18h] [bp-30h] BYREF

  v5 = 2 * ((a4 - a3) >> 4);
  v6 = 2 * (a3 >> 4);
  v18 = *a1;
  if ( (unsigned int)a2 <= 1 )
  {
    v8 = 0;
  }
  else
  {
    v19[0] = 0;
    v19[1] = 0;
    v19[2] = 0;
    v8 = v19;
  }
  v9 = (_DWORD *)a1[2];
  v10 = (unsigned __int8 *)(v9 + 6);
  v11 = KeAbPreAcquire((unsigned int)(v9 + 6), 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( __strex(v13 | 1, v10) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v9 + 6, v11, (unsigned int)(v9 + 6));
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  if ( MiVadDeleted((int)v9) )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v10);
    while ( __strex(v14 - 1, (unsigned int *)v10) );
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock(v9 + 6);
    KeAbPostRelease((unsigned int)(v9 + 6));
    v15 = -1073741558;
  }
  else
  {
    v15 = MiCopyToCfgBitMap(v18 + (v6 >> 3), v9, a2, 0, v8, v5 >> 3, a5);
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v10);
    while ( __strex(v16 - 1, (unsigned int *)v10) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock(v9 + 6);
    KeAbPostRelease((unsigned int)(v9 + 6));
  }
  return v15;
}
