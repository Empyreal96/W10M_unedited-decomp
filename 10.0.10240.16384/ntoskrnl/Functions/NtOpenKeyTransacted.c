// NtOpenKeyTransacted 
 
int __fastcall NtOpenKeyTransacted(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r5
  char v13; // r3
  int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  bool v17; // zf
  int v18; // r4
  unsigned int v19; // r1
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // [sp+8h] [bp-28h] BYREF
  unsigned int v24; // [sp+Ch] [bp-24h]
  _DWORD *v25; // [sp+10h] [bp-20h]

  v24 = a2;
  v25 = a1;
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
    v13 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v14 = ObReferenceObjectByHandle(a4, 4, TmTransactionObjectType, v13, (int)&v23, 0);
    v12 = v14;
    if ( v14 >= 0 )
    {
      v18 = v23;
      v12 = CmOpenKey(v25, v24, a3, 0, v23);
      ObfDereferenceObject(v18);
      __pld(&CmpShutdownRundown);
      v14 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v19 == v14 && __strex(v14 - 2, (unsigned int *)&CmpShutdownRundown) );
      v17 = v19 == v14;
    }
    else
    {
      __pld(&CmpShutdownRundown);
      v15 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v16 == v15 && __strex(v15 - 2, (unsigned int *)&CmpShutdownRundown) );
      v17 = v16 == v15;
    }
    if ( !v17 )
      v14 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v14);
  }
  else
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(0);
    v12 = -1073741431;
  }
  return v12;
}
