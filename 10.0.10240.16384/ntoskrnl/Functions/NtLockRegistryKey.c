// NtLockRegistryKey 
 
int __fastcall NtLockRegistryKey(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned __int8 *v10; // r0
  int v11; // r5
  int v12; // r4
  unsigned int v13; // r4
  unsigned int v14; // r1
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19[4]; // [sp+8h] [bp-10h] BYREF

  v19[0] = a4;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return sub_818614();
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 == v7 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v10 = (unsigned __int8 *)ObReferenceObjectByHandle(a1, 131078, (int)CmKeyObjectType, 0, (int)v19, 0);
    v11 = (int)v10;
    if ( (int)v10 >= 0 )
    {
      CmpLockRegistry();
      v12 = v19[0];
      v11 = CmLockKcbForWrite(*(_DWORD *)(v19[0] + 4));
      CmpUnlockRegistry();
      v10 = (unsigned __int8 *)ObfDereferenceObject(v12);
    }
    __pld(&CmpShutdownRundown);
    v13 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v14 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v14 != v13 )
      v10 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery((int)v10);
  }
  else
  {
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(0);
    v11 = -1073741431;
  }
  return v11;
}
