// NtCreateKeyTransacted 
 
int __fastcall NtCreateKeyTransacted(_DWORD *a1, unsigned int a2, int a3, int a4, unsigned int *a5, int a6, int a7, _DWORD *a8)
{
  int v11; // r3
  unsigned int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r5
  unsigned int v15; // r1
  __int16 v16; // r3
  int v17; // r5
  char v18; // r3
  int v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r1
  bool v22; // zf
  int v23; // r4
  unsigned int v24; // r1
  unsigned int v25; // r1
  __int16 v26; // r3
  int v28[8]; // [sp+10h] [bp-20h] BYREF

  v11 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v11 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v12 = CmpShutdownRundown & 0xFFFFFFFE;
  v13 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v14 == v12 && __strex(v13, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v14 == v12 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v18 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v19 = ObReferenceObjectByHandle(a7, 4, TmTransactionObjectType, v18, (int)v28, 0);
    v17 = v19;
    if ( v19 >= 0 )
    {
      v23 = v28[0];
      v17 = CmCreateKey(a1, a2, a3, (int)a5, a5, a6, a8, v28[0]);
      ObfDereferenceObject(v23);
      __pld(&CmpShutdownRundown);
      v19 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v24 == v19 && __strex(v19 - 2, (unsigned int *)&CmpShutdownRundown) );
      v22 = v24 == v19;
    }
    else
    {
      __pld(&CmpShutdownRundown);
      v20 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v21 == v20 && __strex(v20 - 2, (unsigned int *)&CmpShutdownRundown) );
      v22 = v21 == v20;
    }
    if ( !v22 )
      v19 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = *(_WORD *)(v25 + 0x134) + 1;
    *(_WORD *)(v25 + 308) = v26;
    if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
  else
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(0);
    v17 = -1073741431;
  }
  return v17;
}
