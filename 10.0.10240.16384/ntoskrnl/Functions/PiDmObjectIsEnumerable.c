// PiDmObjectIsEnumerable 
 
int __fastcall PiDmObjectIsEnumerable(unsigned int *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  BOOL v6; // r5
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  do
    v4 = __ldrex(a1);
  while ( !v4 && __strex(0x11u, a1) );
  __dmb(0xBu);
  if ( v4 )
    return sub_7E6490(v3, 17);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = (a1[6] & 1) != 0;
  __pld(a1);
  v7 = *a1;
  if ( (*a1 & 0xFFFFFFF0) > 0x10 )
    v8 = v7 - 16;
  else
    v8 = 0;
  if ( (v7 & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v9 = __ldrex(a1);
  while ( v9 == v7 && __strex(v8, a1) );
  if ( v9 != v7 )
LABEL_19:
    ExfReleasePushLock(a1, v7);
  v10 = KeAbPostRelease((unsigned int)a1);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v6;
}
