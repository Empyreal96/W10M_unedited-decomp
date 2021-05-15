// PopFxAcpiUnregisterDevice 
 
int __fastcall PopFxAcpiUnregisterDevice(int a1, int a2)
{
  unsigned int *v4; // r0
  unsigned int v5; // r2
  int v6; // r6
  unsigned int v7; // r2
  unsigned int v8; // r2
  int v9; // r0
  unsigned int *v10; // r2
  unsigned int v11; // r4

  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 136);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 + 1, v4) );
  __dmb(0xBu);
  if ( *(_BYTE *)(a1 + 132) )
  {
    __dmb(0xBu);
    do
    {
      v7 = __ldrex(v4);
      v8 = v7 - 1;
    }
    while ( __strex(v8, v4) );
    __dmb(0xBu);
    if ( !v8 )
      KeSetEvent(a1 + 140, 0, 0);
    v6 = -1073741738;
  }
  else
  {
    v6 = 0;
  }
  v9 = *(_DWORD *)(a1 + 28);
  if ( v9 )
    v9 = PoFxAbandonDevice();
  if ( *(_DWORD *)(a1 + 92) != a1 + 92 )
    PopFxRemoveAcpiDevice(v9, a1);
  IoReleaseRemoveLockAndWaitEx(a1 + 132, 1917218640, 24);
  PopPluginAcpiNotificationStrict(*(_DWORD *)(a1 + 44), 4, a2);
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 384);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0xFFFFFFFB, v10) );
  __dmb(0xBu);
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  PopFxDestroyDeviceCommon(a1);
  return v6;
}
