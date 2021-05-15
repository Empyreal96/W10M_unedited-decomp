// ViFindTriageDriverTargets 
 
int *__fastcall ViFindTriageDriverTargets(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  int *v5; // r1
  const char *v6; // r2

  v4 = &ViVerifyTriageRules;
  v5 = (int *)((char *)&ViVerifyTriageRules + a2);
  while ( 1 )
  {
    if ( v4 >= v5 )
    {
      v6 = "CRASH TRIAGE: no `targets' rule found.\n";
      goto LABEL_9;
    }
    a4 = HIWORD(*v4) & 7;
    if ( !a4 )
      break;
    if ( a4 == 1 )
    {
      a4 = (int)v4 + ((unsigned int)*v4 >> 19);
      v4 = (int *)(a4 + 8);
    }
    else if ( a4 == 2 )
    {
      DbgPrintEx(93, 3, (int)"CRASH TRIAGE: found a `targets' rule.\n", 2);
      return v4;
    }
  }
  v6 = "CRASH TRIAGE: zeroed rules structure (hit an invalid type rule).\n";
LABEL_9:
  DbgPrintEx(93, 3, (int)v6, a4);
  return 0;
}
