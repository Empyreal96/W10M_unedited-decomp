// PsIsSystemProcess 
 
BOOL __fastcall PsIsSystemProcess(int a1)
{
  return a1 == PsInitialSystemProcess;
}
