// AlpcReferenceBlobByHandle 
 
int __fastcall AlpcReferenceBlobByHandle(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned int *v5; // r7
  unsigned int v6; // r6
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  int v10; // r4
  int v11; // r5
  bool v12; // zf
  unsigned int *v13; // r6
  int v14; // r0
  int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r0
  unsigned int v19; // r2

  if ( !a1 )
    return 0;
  v5 = a1 + 3;
  v6 = a2 - 16;
  v7 = KeAbPreAcquire((unsigned int)(a1 + 3), 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v5);
  while ( !v9 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(v5, v7, (unsigned int)v5);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( v6 >= a1[1] || (v10 = *(_DWORD *)(*a1 + 4 * v6)) == 0 || *(unsigned __int8 *)(v10 - 15) != *a3 )
  {
LABEL_27:
    __dmb(0xBu);
    do
      v19 = __ldrex(v5);
    while ( v19 == 17 && __strex(0, v5) );
    if ( v19 != 17 )
      ExfReleasePushLockShared(v5);
    KeAbPostRelease((unsigned int)v5);
    return 0;
  }
  v11 = *(_DWORD *)(v10 - 12);
  v12 = v11 == 0;
  if ( v11 <= 0 )
  {
LABEL_36:
    if ( !v12 )
      KeBugCheckEx(24, 0, v10, 32, v11);
    goto LABEL_27;
  }
  v13 = (unsigned int *)(v10 - 12);
  while ( 1 )
  {
    v14 = v11;
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( v15 == v11 && __strex(v11 + 1, v13) );
    v11 = v15;
    __dmb(0xBu);
    if ( v15 == v14 )
      break;
    if ( v15 <= 0 )
    {
      v12 = v15 == 0;
      goto LABEL_36;
    }
  }
  if ( v15 == -1 )
    goto LABEL_27;
  __dmb(0xBu);
  do
    v16 = __ldrex(v5);
  while ( v16 == 17 && __strex(0, v5) );
  if ( v16 != 17 )
    ExfReleasePushLockShared(v5);
  v17 = KeAbPostRelease((unsigned int)v5);
  if ( (*(_BYTE *)(v10 - 16) & 4) != 0 )
    return sub_7F7EDC(v17);
  return v10;
}
