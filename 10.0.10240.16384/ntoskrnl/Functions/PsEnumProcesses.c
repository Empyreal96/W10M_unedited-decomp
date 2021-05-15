// PsEnumProcesses 
 
int __fastcall PsEnumProcesses(int (__fastcall *a1)(int *, int), int a2)
{
  int v3; // r0
  int *v5; // r0
  int *v6; // r5
  bool v7; // nf

  v3 = 0;
  while ( 1 )
  {
    v5 = PsGetNextProcess(v3);
    v6 = v5;
    if ( !v5 )
      break;
    v7 = a1(v5, a2) < 0;
    v3 = (int)v6;
    if ( v7 )
      return sub_7D00D4(v6);
  }
  return 0;
}
