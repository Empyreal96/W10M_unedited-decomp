// PsReferenceImpersonationTokenEx 
 
int __fastcall PsReferenceImpersonationTokenEx(_DWORD *a1, char a2, bool *a3, bool *a4, int *a5, _BYTE *a6)
{
  unsigned int v11; // r4
  unsigned int *v12; // r10
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r6
  bool v16; // r3
  unsigned int v17; // r2
  int v18; // r0
  __int16 v19; // r3
  int v20; // [sp+0h] [bp-20h]

  if ( (a1[240] & 8) == 0 )
    return 0;
  v20 = a1[84];
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 0x134);
  v12 = a1 + 236;
  v13 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
  do
    v14 = __ldrex(v12);
  while ( !v14 && __strex(0x11u, v12) );
  __dmb(0xBu);
  if ( v14 )
    return sub_7FA0A8(v13, 17);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  if ( (a1[240] & 8) != 0 )
  {
    v16 = 0;
    if ( (a2 & 1) == 0 || (v15 = a1[263]) == 0 )
    {
      v15 = a1[226] & 0xFFFFFFF8;
      if ( (a1[240] & 0x100) != 0 )
        v16 = 1;
    }
    *a3 = v16;
    ObfReferenceObject(v15);
    *a5 = a1[226] & 3;
    *a4 = (a1[226] & 4) != 0;
    if ( a6 )
      *a6 = *(_BYTE *)(v20 + 734);
  }
  else
  {
    v15 = 0;
  }
  __dmb(0xBu);
  do
    v17 = __ldrex(v12);
  while ( v17 == 17 && __strex(0, v12) );
  if ( v17 != 17 )
    ExfReleasePushLockShared(a1 + 236);
  v18 = KeAbPostRelease((unsigned int)(a1 + 236));
  v19 = *(_WORD *)(v11 + 308) + 1;
  *(_WORD *)(v11 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return v15;
}
