// WmipRegisterDevice 
 
int __fastcall WmipRegisterDevice(int a1, int a2)
{
  int v2; // r7
  unsigned int v3; // r6
  _DWORD *v5; // r5
  int v6; // r8
  int v7; // r4
  int v8; // r4
  int v9; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r0

  v2 = 0;
  v3 = 0;
  if ( a2 < 0 )
    v3 = 0x10000000;
  if ( (a2 & 0x10000) != 0 )
    v3 |= 16 * (a2 & 0xF00000 | 0x4000000);
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v5 = (_DWORD *)WmipFindRegEntryByDevice(a1);
  if ( v5 )
  {
    KeReleaseMutex((int)&WmipSMMutex);
    v8 = 0x40000000;
  }
  else
  {
    v6 = (v3 >> 28) & 1;
    if ( v6 )
    {
      v8 = 0;
    }
    else
    {
      v7 = IoGetAttachedDeviceReference(a1);
      WmipUpdateDeviceStackSize((char)(*(_BYTE *)(v7 + 48) + 1));
      ObfDereferenceObject(v7);
      v8 = ObReferenceObjectByPointer(a1, 0, 0, 0);
    }
    if ( v8 < 0 )
    {
      KeReleaseMutex((int)&WmipSMMutex);
      goto LABEL_18;
    }
    v9 = WmipAllocRegEntry(a1, v3);
    v5 = (_DWORD *)v9;
    if ( !v9 )
      return sub_7EF07C();
    __dmb(0xBu);
    v11 = (unsigned int *)(v9 + 24);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    __dmb(0xBu);
    KeReleaseMutex((int)&WmipSMMutex);
    if ( v6 )
      v13 = WmipRegisterOrUpdateDS(v5, 0);
    else
      v13 = WmipQueueRegWork(0, v5);
    v8 = v13;
    if ( v13 < 0 )
      v2 = 1;
  }
  WmipUnreferenceRegEntry((int)v5);
LABEL_18:
  if ( v2 )
    WmipDeregisterRegEntry(v5);
  return v8;
}
