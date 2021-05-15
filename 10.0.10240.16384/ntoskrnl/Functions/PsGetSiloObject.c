// PsGetSiloObject 
 
int __fastcall PsGetSiloObject(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r6
  int v7; // r8
  unsigned int *v8; // r7
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  int v12; // r5
  int result; // r0
  unsigned int v14; // r2
  int v15; // r0
  __int16 v16; // r3
  int v17; // r3
  int v18; // r5
  int v19; // r4
  int v20[8]; // [sp+8h] [bp-20h] BYREF

  v20[0] = a4;
  if ( a1 == -1 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(_DWORD *)(v6 + 0x150);
    --*(_WORD *)(v6 + 308);
    v8 = (unsigned int *)(v7 + 168);
    v9 = KeAbPreAcquire(v7 + 168, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex(v8);
    while ( !v11 && __strex(0x11u, v8) );
    __dmb(0xBu);
    if ( v11 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v7 + 168), v9, v7 + 168);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    v12 = *(_DWORD *)(v6 + 1096);
    if ( v12 == -3 )
      v12 = *(_DWORD *)(v7 + 804);
    if ( v12 )
    {
      result = sub_7FF428();
    }
    else
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v8);
      while ( v14 == 17 && __strex(0, v8) );
      if ( v14 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v7 + 168));
      v15 = KeAbPostRelease(v7 + 168);
      v16 = *(_WORD *)(v6 + 308) + 1;
      *(_WORD *)(v6 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
        KiCheckForKernelApcDelivery(v15);
      result = -1073741816;
    }
  }
  else
  {
    v17 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    result = ObReferenceObjectByHandle(a1, 4, PsSiloType, v17, v20);
    v18 = v20[0];
    if ( result >= 0 )
    {
      v19 = PsGetSiloObjectByPointer(v20[0], a2, a3);
      PspDereferenceSiloObject(v18);
      result = v19;
    }
  }
  return result;
}
