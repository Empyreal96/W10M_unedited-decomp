// sub_96F0A0 
 
void __fastcall sub_96F0A0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  int v15; // r4
  _DWORD *v16; // r5
  int v17; // r6
  int v18; // r7
  _DWORD *v19; // r1
  int v20; // r8
  int v21; // r3
  int v22; // r9
  int v23; // r7
  _DWORD *v24; // r4
  int v25; // r3
  int v26; // r3

  if ( a4 )
  {
    if ( a4 < 0 )
    {
      v17 = (unsigned __int16)a4;
      *v16 = 1;
      DbgPrintEx(93, 3, (int)"CRASH TRIAGE: simulated crash code %X.\n", (unsigned __int16)a4);
    }
    v19 = *(_DWORD **)(v18 + 132);
    if ( v19 )
    {
      if ( *v19 >= 0x908u )
      {
        v20 = v19[7];
        if ( TriageGetBugcheckData(v20, &a11, &a12, &a13) >= 0 )
        {
          DbgPrintEx(93, 3, (int)"CRASH TRIAGE: a real crash happened.\n", v21);
          v17 = a11;
          v22 = 1;
        }
        else
        {
          if ( !v17 )
            goto LABEL_23;
          v22 = 0;
          a11 = v17;
          a12 = v15;
          a13 = v15;
          a14 = v15;
          a15 = v15;
          DbgPrintEx(93, 3, (int)"CRASH TRIAGE: a fake crash will be simulated.\n", v21);
        }
        DbgPrintEx(93, 3, (int)"CRASH TRIAGE: previous crash was %Ix %Ix %Ix %Ix %Ix.\n", v17);
        ViTriageCrashData = a11;
        unk_61D064 = a12;
        unk_61D068 = a13;
        unk_61D06C = a14;
        dword_61D070 = a15;
        if ( (!v22 || MmTriageActiveInLastCrash(v18) != 1 && ViTriageSameDriversFromDump(v18, v20))
          && ViValidateTriageRules(&ViVerifyTriageRules, ViVerifyTriageRulesSize)
          && ViValidateTriageRules(&ViInternalTriageRules, 64) )
        {
          v23 = 0;
          v24 = (_DWORD *)ViFindTriageRule(&ViVerifyTriageRules, ViVerifyTriageRulesSize, v17);
          if ( !v24 )
          {
            v24 = (_DWORD *)ViFindTriageRule(&ViInternalTriageRules, 64, v17);
            if ( !v24 )
            {
              DbgPrintEx(93, 3, (int)"CRASH TRIAGE: crash code %Ix will not be triaged.\n", v17);
              JUMPOUT(0x962856);
            }
          }
          if ( (*v24 & 0xFFF80000) == 0 )
          {
            v23 = ViFindTriageDriverTargets();
            if ( v23 )
              DbgPrintEx(93, 3, (int)"CRASH TRIAGE: no `targets' rule found.\n", v25);
          }
          if ( v24[1] )
          {
            ViMakeVerifierSettings(v24, v23);
            DbgPrintEx(93, 3, (int)"CRASH TRIAGE: triage enabled!\n", v26);
            JUMPOUT(0x962858);
          }
        }
      }
    }
  }
LABEL_23:
  JUMPOUT(0x96284E);
}
