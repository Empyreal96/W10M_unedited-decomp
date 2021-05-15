// VfTriageAddDrivers 
 
int __fastcall VfTriageAddDrivers(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r8
  unsigned int v7; // r6
  unsigned int i; // r5
  int v9; // r0
  int v10; // r7
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  if ( (VerifierTriageActionTaken & 0x40000000) == 0 )
  {
    DbgPrintEx(
      93,
      3,
      (int)"CRASH TRIAGE: no suspect drivers will be selected for verification.\n",
      VerifierTriageActionTaken);
    return 0;
  }
  DbgPrintEx(93, 3, (int)"CRASH TRIAGE: will select target drivers for verification.\n", VerifierTriageActionTaken);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 28);
  if ( TriageGetDriverCount(v6, v12) < 0 )
    return 0;
  v7 = v12[0];
  v5 = 0;
  for ( i = 0; i < v7; ++i )
  {
    v9 = TriageGetLoaderEntry(v6, i);
    v10 = v9;
    if ( v9 )
    {
      if ( (*(_DWORD *)(v9 + 52) & 0x8000000) == 0 )
      {
        DbgPrintEx(93, 3, (int)"VfTriageAddDrivers: Marking %wZ for verification when it is loaded\n", v9 + 44);
        if ( VfSuspectDriversAdd(v10) == 1 )
          v5 = 1;
      }
    }
  }
  return v5;
}
