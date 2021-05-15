// NtQueryOpenSubKeysEx 
 
int __fastcall NtQueryOpenSubKeysEx(int a1, unsigned int a2, char *a3, _DWORD *a4)
{
  _DWORD *v4; // r10
  int v6; // r3
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r4
  int v13; // r6
  unsigned __int8 *v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r0
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r0
  unsigned int v24; // r1
  unsigned int v25; // r1
  __int16 v26; // r3
  _DWORD *v27; // r2
  char *v28; // r0
  int v29; // r2
  char *v30; // r6
  unsigned int v31; // r1
  char *v32; // r2
  int v33; // t1
  int v34; // r0
  unsigned int v35; // r1
  unsigned int v36; // r1
  __int16 v37; // r3
  unsigned int v42; // [sp+28h] [bp-90h] BYREF
  char *v43; // [sp+2Ch] [bp-8Ch]
  int v44; // [sp+30h] [bp-88h]
  int v45; // [sp+34h] [bp-84h]
  int v46; // [sp+38h] [bp-80h]
  int v47; // [sp+3Ch] [bp-7Ch]
  char *v48; // [sp+40h] [bp-78h]
  int v49; // [sp+48h] [bp-70h]
  _BYTE v50[76]; // [sp+4Ch] [bp-6Ch] BYREF
  int varg_r0; // [sp+C0h] [bp+8h]
  unsigned int varg_r1; // [sp+C4h] [bp+Ch]
  char *varg_r2; // [sp+C8h] [bp+10h]
  _DWORD *varg_r3; // [sp+CCh] [bp+14h]

  v4 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  memset(v50, 0, sizeof(v50));
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
    v13 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v14 = (unsigned __int8 *)SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v13, (int)&SeRestorePrivilege);
    if ( v14 )
    {
      if ( a2 >= 4 )
      {
        if ( (a2 & 1) != 0 )
        {
          __pld(&CmpShutdownRundown);
          v23 = CmpShutdownRundown & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v24 = __ldrex((unsigned int *)&CmpShutdownRundown);
          while ( v24 == v23 && __strex(v23 - 2, (unsigned int *)&CmpShutdownRundown) );
          if ( v24 != v23 )
            v23 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
          v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v26 = *(_WORD *)(v25 + 0x134) + 1;
          *(_WORD *)(v25 + 308) = v26;
          if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
            KiCheckForKernelApcDelivery(v23);
          v12 = -1073741811;
        }
        else
        {
          v42 = a2;
          if ( v13 == 1 )
          {
            v27 = v4;
            if ( (unsigned int)a4 >= MmUserProbeAddress )
              v27 = (_DWORD *)MmUserProbeAddress;
            *v27 = *v27;
            ProbeForWrite((unsigned int)a3, a2, 4);
          }
          v12 = ObReferenceObjectByNameEx(a1);
          if ( v12 >= 0 )
          {
            CmpLockRegistryExclusive();
            if ( (*(_DWORD *)(MEMORY[4] + 4) & 0x20000) != 0 )
            {
              if ( (MEMORY[0x18] & 1) != 0 )
                v12 = -1073740763;
              else
                v12 = -1073741444;
              CmpUnlockRegistry();
              ObfDereferenceObject(0);
            }
            else if ( *(_DWORD *)(MEMORY[4] + 24) == *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(MEMORY[4] + 20) + 32) + 36) )
            {
              v28 = (char *)ExAllocatePoolWithTag(1, a2, 538987843);
              v43 = v28;
              if ( v28 )
              {
                *(_DWORD *)v28 = 0;
                v44 = 4;
                v46 = 4;
                v48 = &v28[a2];
                v47 = 0;
                v45 = 0;
                CmpSearchForOpenSubKeys(MEMORY[4], 2, v29, &v42);
                v12 = v45;
                CmpUnlockRegistry();
                ObfDereferenceObject(0);
                v30 = v43;
                if ( v12 >= 0 )
                {
                  v31 = 0;
                  if ( *(_DWORD *)v43 )
                  {
                    v32 = v43;
                    do
                    {
                      v33 = *((_DWORD *)v32 + 3);
                      v32 += 12;
                      *(_DWORD *)v32 = v33 + a3 - v30;
                      ++v31;
                    }
                    while ( v31 < *(_DWORD *)v30 );
                  }
                }
                *a4 = v44;
                if ( v12 < 0 )
                  *(_DWORD *)a3 = *(_DWORD *)v30;
                else
                  memmove((int)a3, (int)v30, a2);
                ExFreePoolWithTag((unsigned int)v30);
              }
              else
              {
                CmpUnlockRegistry();
                ObfDereferenceObject(0);
                v12 = -1073741670;
              }
            }
            else
            {
              CmpUnlockRegistry();
              ObfDereferenceObject(0);
              v12 = -1073741811;
            }
          }
          __pld(&CmpShutdownRundown);
          v34 = CmpShutdownRundown & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v35 = __ldrex((unsigned int *)&CmpShutdownRundown);
          while ( v35 == v34 && __strex(v34 - 2, (unsigned int *)&CmpShutdownRundown) );
          if ( v35 != v34 )
            v34 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
          v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v37 = *(_WORD *)(v36 + 0x134) + 1;
          *(_WORD *)(v36 + 308) = v37;
          if ( !v37 && *(_DWORD *)(v36 + 100) != v36 + 100 && !*(_WORD *)(v36 + 310) )
            KiCheckForKernelApcDelivery(v34);
        }
      }
      else
      {
        __pld(&CmpShutdownRundown);
        v19 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v20 == v19 && __strex(v19 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v20 != v19 )
          v19 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v22 = *(_WORD *)(v21 + 0x134) + 1;
        *(_WORD *)(v21 + 308) = v22;
        if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
          KiCheckForKernelApcDelivery(v19);
        v12 = -1073741789;
      }
    }
    else
    {
      __pld(&CmpShutdownRundown);
      v15 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v16 == v15 && __strex(v15 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v16 != v15 )
        v14 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x134) + 1;
      *(_WORD *)(v17 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
        KiCheckForKernelApcDelivery((int)v14);
      v12 = -1073741727;
    }
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
