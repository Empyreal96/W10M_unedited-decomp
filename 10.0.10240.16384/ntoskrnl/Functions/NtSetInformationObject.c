// NtSetInformationObject 
 
int __fastcall NtSetInformationObject(int a1, int a2, _WORD *a3, int a4)
{
  int v4; // r6
  int v5; // r4
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r9
  unsigned __int8 *v9; // r5
  int v10; // r0
  int v11; // r8
  unsigned int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r1
  int v20; // r9
  int v21; // r8
  int v22; // r3
  unsigned int v23; // r5
  _DWORD *v24; // r4
  unsigned int v25; // r1
  int v26; // r2
  int v27; // r3
  unsigned int v28; // r3
  unsigned int v29; // r1
  __int16 v30; // r3
  _DWORD v32[3]; // [sp+Ch] [bp-44h] BYREF
  _BYTE v33[56]; // [sp+18h] [bp-38h] BYREF

  v4 = a1;
  v32[1] = a1;
  v5 = -1073741821;
  if ( a2 == 4 )
  {
    if ( a4 == 2 )
    {
      v19 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
      if ( v19 )
      {
        a1 = MmUserProbeAddress;
        if ( (unsigned int)(a3 + 1) > MmUserProbeAddress || a3 + 1 < a3 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      LOWORD(v32[0]) = *a3;
      v20 = 0;
      if ( v19 || v4 >= 0 || v4 == -2 || v4 == -1 )
      {
        v21 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 336);
      }
      else
      {
        v4 ^= 0x80000000;
        v21 = ObpKernelHandleTable;
        v22 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        a1 = PsInitialSystemProcess;
        if ( v22 != PsInitialSystemProcess )
        {
          a1 = KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v33);
          v20 = 1;
        }
      }
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v23 + 308);
      if ( (v4 & 0x7FC) != 0 && (a1 = ExpLookupHandleTableEntry(v21, v4), (v24 = (_DWORD *)a1) != 0) )
      {
        do
        {
          while ( 1 )
          {
            __pld(v24);
            a1 = *v24;
            if ( (*v24 & 1) != 0 )
              break;
            if ( !a1 )
              goto LABEL_63;
            ExpBlockOnLockedHandleEntry(v21, v24, *v24);
          }
          do
            v25 = __ldrex(v24);
          while ( v25 == a1 && __strex(a1 - 1, v24) );
          __dmb(0xBu);
        }
        while ( v25 != a1 );
        a1 = LOBYTE(v32[0]);
        if ( !LOBYTE(v32[0])
          || (*(_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)((*v24 & 0xFFFFFFF8) + 12) ^ (unsigned __int8)((unsigned __int16)(*(_WORD *)v24 & 0xFFF8) >> 8) ^ (unsigned __int8)ObHeaderCookie]
                        + 48) & 2) == 0 )
        {
          v26 = 0;
          if ( LOBYTE(v32[0]) )
            v26 = 2;
          if ( BYTE1(v32[0]) )
            v26 |= 1u;
          *v24 ^= (*v24 ^ v26) & 2;
          v27 = v24[1];
          if ( (v26 & 1) != 0 )
            v28 = v27 | 0x2000000;
          else
            v28 = v27 & 0xFDFFFFFF;
          v24[1] = v28;
        }
        __dmb(0xBu);
        do
          v29 = __ldrex(v24);
        while ( __strex(v29 + 1, v24) );
        __dmb(0xBu);
        __dmb(0xFu);
        if ( *(_DWORD *)(v21 + 32) )
          a1 = ExfUnblockPushLock(v21 + 32, 0);
        v5 = 0;
      }
      else
      {
LABEL_63:
        v5 = -1073741790;
      }
      v30 = *(_WORD *)(v23 + 308) + 1;
      *(_WORD *)(v23 + 308) = v30;
      if ( !v30 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
        KiCheckForKernelApcDelivery(a1);
      if ( v20 )
        KiUnstackDetachProcess((unsigned int)v33, 0);
    }
    else
    {
      v5 = -1073741820;
    }
  }
  else if ( a2 == 5 )
  {
    v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v6, (int)&SeTcbPrivilege) )
    {
      v5 = ObReferenceObjectByHandle(v4, 0, ObpDirectoryObjectType, v6, v32);
      if ( v5 >= 0 )
      {
        v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v7 + 308);
        v8 = v32[0];
        v9 = (unsigned __int8 *)(v32[0] + 148);
        v10 = KeAbPreAcquire(v32[0] + 148, 0, 0);
        v11 = v10;
        do
          v12 = __ldrex(v9);
        while ( __strex(v12 | 1, v9) );
        __dmb(0xBu);
        if ( (v12 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v8 + 148), v10, v8 + 148);
        if ( v11 )
          *(_BYTE *)(v11 + 14) |= 1u;
        ObfReferenceObject(v8);
        *(_DWORD *)(v8 + 160) = PsGetCurrentProcessSessionId();
        __pld(v9);
        v13 = *(_DWORD *)v9;
        if ( (*(_DWORD *)v9 & 0xFFFFFFF0) <= 0x10 )
          v14 = 0;
        else
          v14 = v13 - 16;
        if ( (v13 & 2) != 0 )
          goto LABEL_20;
        __dmb(0xBu);
        do
          v15 = __ldrex((unsigned int *)v9);
        while ( v15 == v13 && __strex(v14, (unsigned int *)v9) );
        if ( v15 != v13 )
LABEL_20:
          ExfReleasePushLock((_DWORD *)(v8 + 148), v13);
        KeAbPostRelease(v8 + 148);
        v16 = ObfDereferenceObject(v8);
        v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v18 = *(_WORD *)(v17 + 0x134) + 1;
        *(_WORD *)(v17 + 308) = v18;
        if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
          KiCheckForKernelApcDelivery(v16);
        ObfDereferenceObject(v8);
      }
    }
    else
    {
      v5 = -1073741727;
    }
  }
  return v5;
}
