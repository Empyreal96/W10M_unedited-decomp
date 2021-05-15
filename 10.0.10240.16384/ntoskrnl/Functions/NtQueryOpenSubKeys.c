// NtQueryOpenSubKeys 
 
int __fastcall NtQueryOpenSubKeys(int a1, _DWORD *a2)
{
  int v4; // r3
  unsigned int v5; // r4
  unsigned int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r1
  __int16 v9; // r3
  int v10; // r5
  _DWORD *v11; // r0
  unsigned __int8 *v12; // r0
  int v13; // r4
  _DWORD *v14; // r2
  int v15; // r1
  int v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r1
  __int16 v20; // r3
  int v22[3]; // [sp+18h] [bp-78h] BYREF
  _BYTE v23[76]; // [sp+24h] [bp-6Ch] BYREF
  int anonymous0; // [sp+98h] [bp+8h]
  _DWORD *anonymous1; // [sp+9Ch] [bp+Ch]

  anonymous1 = a2;
  anonymous0 = a1;
  v22[0] = 0;
  v22[2] = 0;
  memset(v23, 0, sizeof(v23));
  v4 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v5 = CmpShutdownRundown & 0xFFFFFFFE;
  v6 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v7 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v7 == v5 || ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1 )
    {
      v11 = a2;
      if ( (unsigned int)a2 >= MmUserProbeAddress )
        v11 = (_DWORD *)MmUserProbeAddress;
      *v11 = *v11;
    }
    v12 = (unsigned __int8 *)ObReferenceObjectByNameEx(a1);
    v10 = (int)v12;
    if ( (int)v12 >= 0 )
    {
      CmpLockRegistryExclusive();
      v13 = v22[0];
      v14 = *(_DWORD **)(v22[0] + 4);
      if ( (v14[1] & 0x20000) != 0 )
      {
        if ( (*(_DWORD *)(v22[0] + 24) & 1) != 0 )
          v10 = -1073740763;
        else
          v10 = -1073741444;
        CmpUnlockRegistry();
        v12 = (unsigned __int8 *)ObfDereferenceObject(v22[0]);
      }
      else
      {
        v15 = *(_DWORD *)(v14[5] + 32);
        if ( v14[6] == *(_DWORD *)(v15 + 36) )
        {
          RtlInitUnicodeString((unsigned int)v22, (unsigned __int16 *)(v15 + 48));
          CmpOpenSubKeys = CmpSearchForOpenSubKeys(*(_DWORD *)(v13 + 4), 2, v16, 0);
          CmpUnlockRegistry();
          v12 = (unsigned __int8 *)ObfDereferenceObject(v13);
          *a2 = CmpOpenSubKeys;
        }
        else
        {
          CmpUnlockRegistry();
          v12 = (unsigned __int8 *)ObfDereferenceObject(v22[0]);
          v10 = -1073741811;
        }
      }
    }
    __pld(&CmpShutdownRundown);
    v17 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v18 == v17 && __strex(v17 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v18 != v17 )
      v12 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery((int)v12);
  }
  else
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = *(_WORD *)(v8 + 0x134) + 1;
    *(_WORD *)(v8 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(0);
    v10 = -1073741431;
  }
  return v10;
}
