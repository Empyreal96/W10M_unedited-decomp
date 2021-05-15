// PfCheckDeprioritizeImage 
 
int __fastcall PfCheckDeprioritizeImage(int a1, int a2)
{
  int v2; // r7
  int v3; // r8
  unsigned int v5; // r2
  int v6; // r6
  unsigned int v7; // r1
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r6
  int i; // r1
  _DWORD *v14; // r3

  v2 = a1;
  v3 = 0;
  if ( !a1 )
    return sub_7E74B4();
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)dword_637328, 0, 0);
  do
    v7 = __ldrex(dword_637328);
  while ( !v7 && __strex(0x11u, dword_637328) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(dword_637328, v6, (unsigned int)dword_637328);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( dword_637320 )
  {
    v12 = (dword_637320 - 1) & (37 * (37 * (37 * ((unsigned __int8)a1 + 11623883) + BYTE1(a1)) + BYTE2(a1)) + HIBYTE(a1));
    for ( i = 0; ; v12 = (i + v12) & (dword_637320 - 1) )
    {
      v14 = (_DWORD *)((v12 << algn_637314[8]) + *(_DWORD *)&algn_637314[4]);
      if ( !*v14 || *v14 == v2 )
        break;
      if ( !i )
      {
        i = -1640531535 * v2;
        if ( ((-1640531535 * v2) & 1) == 0 )
          ++i;
      }
    }
    if ( *v14 )
      v3 = 1;
  }
  __dmb(0xBu);
  do
    v8 = __ldrex(dword_637328);
  while ( v8 == 17 && __strex(0, dword_637328) );
  if ( v8 != 17 )
    ExfReleasePushLockShared(dword_637328);
  v9 = KeAbPostRelease((unsigned int)dword_637328);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v3;
}
