// NtOpenKeyTransactedEx 
 
int __fastcall NtOpenKeyTransactedEx(_DWORD *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v7; // r4
  unsigned int v8; // r7
  unsigned int v9; // r5
  unsigned int v10; // r6
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r5
  char v14; // r3
  int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // r1
  bool v18; // zf
  int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  int v24; // [sp+8h] [bp-28h] BYREF
  unsigned int v25; // [sp+Ch] [bp-24h]
  _DWORD *v26; // [sp+10h] [bp-20h]

  v25 = a2;
  v26 = a1;
  v7 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v8 = CmpShutdownRundown & 0xFFFFFFFE;
  v9 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v10 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v10 == v8 && __strex(v9, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v10 == v8 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v14 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v15 = ObReferenceObjectByHandle(a5, 4, TmTransactionObjectType, v14, (int)&v24, 0);
    v13 = v15;
    if ( v15 >= 0 )
    {
      v19 = v24;
      v13 = CmOpenKey(v26, v25, a3, a4, v24);
      ObfDereferenceObject(v19);
      __pld(&CmpShutdownRundown);
      v15 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v20 == v15 && __strex(v15 - 2, (unsigned int *)&CmpShutdownRundown) );
      v18 = v20 == v15;
    }
    else
    {
      __pld(&CmpShutdownRundown);
      v16 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)&CmpShutdownRundown) );
      v18 = v17 == v16;
    }
    if ( !v18 )
      v15 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(_WORD *)(v21 + 0x134) + 1;
    *(_WORD *)(v21 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(v15);
  }
  else
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(0);
    v13 = -1073741431;
  }
  return v13;
}
