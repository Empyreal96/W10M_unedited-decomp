// sub_81B674 
 
void __fastcall sub_81B674(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // r6
  _BYTE *v6; // r7
  unsigned int v7; // r2
  int v8; // r8
  unsigned int *v9; // r4
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2

  if ( v5 <= 0x1A )
  {
    PsGetMonitorContextServerSilo(ObSiloMonitor, -1, &a5);
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 310);
    v8 = a5;
    v9 = (unsigned int *)(a5 + 112);
    v10 = KeAbPreAcquire(a5 + 112, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v9, v10, (unsigned int)v9);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    if ( *(_DWORD *)(v8 + 4 * v5 + 4) )
      *v6 = 1;
    else
      *v6 = 0;
    __pld(v9);
    if ( (*v9 & 2) != 0 )
      JUMPOUT(0x81B700);
    JUMPOUT(0x7BA84A);
  }
  JUMPOUT(0x7BA846);
}
