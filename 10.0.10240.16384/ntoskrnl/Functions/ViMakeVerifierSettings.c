// ViMakeVerifierSettings 
 
int __fastcall ViMakeVerifierSettings(_DWORD *a1, _DWORD *a2)
{
  unsigned int v3; // r3
  int v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  VfVerifyMode = 1;
  MmVerifyDriverLevel = a1[1];
  v3 = *a1 >> 19;
  if ( v3 )
  {
    v4 = (int)(a1 + 2);
  }
  else
  {
    if ( !a2 )
    {
      v5 = wcslen(L"*");
      VfInitSetVerifyDriverTargets((int)L"*", 2 * (v5 + 1));
      DbgPrintEx(93, 3, (int)"CRASH TRIAGE: all drivers will be targetted.\n", v6);
      goto LABEL_7;
    }
    v4 = (int)(a2 + 2);
    v3 = *a2 >> 19;
  }
  VfInitSetVerifyDriverTargets(v4, v3);
  DbgPrintEx(93, 3, (int)"CRASH TRIAGE: target drivers are `%ws'.\n", v4);
LABEL_7:
  VerifierTriageActionTaken = 1;
  DbgPrintEx(93, 3, (int)"CRASH TRIAGE: system will enable verification features %X.\n", a1[1]);
  ViVerifyFlags = a1[1];
  return RtlStringCbCopyW((int)&ViVerifyTargets, 0x200u);
}
