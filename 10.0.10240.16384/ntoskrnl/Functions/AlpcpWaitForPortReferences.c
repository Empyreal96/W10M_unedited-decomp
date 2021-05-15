// AlpcpWaitForPortReferences 
 
int __fastcall AlpcpWaitForPortReferences(_DWORD *a1, int *a2, int a3, _DWORD *a4, char a5)
{
  int v6; // r4
  unsigned __int8 *v7; // r6
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r9
  unsigned int v14; // r2
  unsigned int v15; // r1
  _BYTE v17[16]; // [sp+10h] [bp-30h] BYREF
  int v18; // [sp+20h] [bp-20h]
  _DWORD *varg_r0; // [sp+48h] [bp+8h]
  int *varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  _DWORD *varg_r3; // [sp+54h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = a1;
  if ( !a1 || a3 != 4 )
    return -1073741811;
  if ( a5 )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      a2 = (int *)MmUserProbeAddress;
    v18 = *a2;
    if ( a4 )
      *a4 = 0;
  }
  else
  {
    v18 = *a2;
    if ( a4 )
      *a4 = 0;
  }
  if ( a1[59] == v18 )
    return 0;
  KeInitializeEvent((int)v17, 1, 0);
  v7 = (unsigned __int8 *)(a1 + 52);
  v8 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 52, v8, (unsigned int)(a1 + 52));
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( a1[60] )
  {
    v6 = -1073741811;
  }
  else if ( a1[59] == v18 )
  {
    v6 = 0;
  }
  else
  {
    a1[60] = v17;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)v7);
    while ( __strex(v11 - 1, (unsigned int *)v7) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock(a1 + 52);
    KeAbPostRelease((unsigned int)(a1 + 52));
    while ( 1 )
    {
      v6 = KeWaitForSingleObject((unsigned int)v17, 13, 0, (_DWORD *)1, 0);
      if ( !v6 )
        break;
      if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) != 0 )
      {
        v6 = -1073741749;
        break;
      }
    }
    v12 = KeAbPreAcquire((unsigned int)(a1 + 52), 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v7);
    while ( __strex(v14 | 1, v7) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 52, v12, (unsigned int)(a1 + 52));
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    a1[60] = 0;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v7);
  while ( __strex(v15 - 1, (unsigned int *)v7) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 52);
  KeAbPostRelease((unsigned int)(a1 + 52));
  return v6;
}
