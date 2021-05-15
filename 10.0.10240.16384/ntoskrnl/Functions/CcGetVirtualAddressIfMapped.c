// CcGetVirtualAddressIfMapped 
 
int __fastcall CcGetVirtualAddressIfMapped(int a1, int a2, unsigned int a3, int a4, int *a5, _DWORD *a6)
{
  int v6; // r10
  unsigned int *v7; // r5
  int v10; // r8
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r6
  unsigned int v14; // r4
  int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2

  v6 = a3 & 0x3FFFF;
  v7 = (unsigned int *)(a1 + 72);
  *a6 = 0x40000 - (a3 & 0x3FFFF);
  v10 = 0;
  v11 = KeAbPreAcquire(a1 + 72, 0, 0);
  v13 = v11;
  do
  {
    v14 = __ldrex(v7);
    if ( v14 )
      break;
    v12 = __strex(0x11u, v7);
  }
  while ( v12 );
  __dmb(0xBu);
  if ( v14 )
    ExfAcquirePushLockSharedEx(v7, v11, v7);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  if ( *(__int64 *)(a1 + 24) > 0x2000000 )
    v15 = CcGetVacbLargeOffset(a1, v12, a3, a4);
  else
    v15 = *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4 * (a3 >> 18));
  *a5 = v15;
  if ( v15 )
  {
    __dmb(0xBu);
    v16 = (unsigned int *)(v15 + 8);
    do
    {
      v17 = __ldrex(v16);
      v18 = v17 + 1;
    }
    while ( __strex(v18, v16) );
    __dmb(0xBu);
    if ( !(_WORD)v18 )
      sub_53B280();
    v10 = *(_DWORD *)*a5 + v6;
  }
  __pld(v7);
  v19 = *v7;
  if ( (*v7 & 0xFFFFFFF0) > 0x10 )
    v20 = v19 - 16;
  else
    v20 = 0;
  if ( (v19 & 2) != 0 )
    goto LABEL_25;
  __dmb(0xBu);
  do
    v21 = __ldrex(v7);
  while ( v21 == v19 && __strex(v20, v7) );
  if ( v21 != v19 )
LABEL_25:
    ExfReleasePushLock(v7);
  KeAbPostRelease((unsigned int)v7);
  return v10;
}
