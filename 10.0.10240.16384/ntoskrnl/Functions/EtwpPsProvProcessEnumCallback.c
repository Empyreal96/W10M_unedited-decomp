// EtwpPsProvProcessEnumCallback 
 
int __fastcall EtwpPsProvProcessEnumCallback(_DWORD *a1, int a2)
{
  int v4; // r7
  unsigned int *v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r1
  int v8; // r4
  unsigned int *v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1
  int v13; // [sp+8h] [bp-1D0h] BYREF
  _DWORD v14[2]; // [sp+10h] [bp-1C8h] BYREF
  char v15[24]; // [sp+18h] [bp-1C0h] BYREF
  int v16[106]; // [sp+30h] [bp-1A8h] BYREF

  v4 = 0;
  if ( !EtwpIsProcessZombie((int)a1) )
  {
    if ( *(_BYTE *)(a2 + 9) )
    {
      if ( (*(_DWORD *)a2 & 1) != 0 && a1 != (_DWORD *)PsIdleProcess && a1 != (_DWORD *)PsInitialSystemProcess )
        PsSetProcessTelemetryAppState((int)a1, 5);
    }
    else
    {
      *(_BYTE *)(a2 + 8) = 0;
      if ( a1 != (_DWORD *)PsIdleProcess && *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
      {
        v5 = a1 + 43;
        __pld(a1 + 43);
        v6 = a1[43] & 0xFFFFFFFE;
        do
          v7 = __ldrex(v5);
        while ( v7 == v6 && __strex(v6 + 2, v5) );
        __dmb(0xBu);
        if ( v7 == v6 || ExfAcquireRundownProtection(v5) )
        {
          KiStackAttachProcess((int)a1, 0, (int)v15);
          v4 = 1;
          *(_BYTE *)(a2 + 8) = 1;
        }
      }
      if ( (*(_DWORD *)a2 & 0x10) != 0 )
      {
        v13 = 0;
        v8 = PsReferencePrimaryToken((int)a1);
        EtwpQueryTokenPackageInfo(v8, (int)v16, &v13);
        if ( *(_BYTE *)(a2 + 8) )
        {
          EtwpQueryProcessOtherInfo((int)a1, v14);
        }
        else
        {
          v14[0] = 0;
          v14[1] = 0;
        }
        ObFastDereferenceObject(a1 + 61, v8);
        EtwpPsProvTraceProcess(a1, v13, v16, (int)v14, 771);
      }
      if ( v4 )
      {
        KiUnstackDetachProcess((unsigned int)v15, 0);
        v9 = a1 + 43;
        __pld(a1 + 43);
        v10 = a1[43] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v11 = __ldrex(v9);
        while ( v11 == v10 && __strex(v10 - 2, v9) );
        if ( v11 != v10 )
          ExfReleaseRundownProtection((unsigned __int8 *)v9);
      }
    }
  }
  return 0;
}
