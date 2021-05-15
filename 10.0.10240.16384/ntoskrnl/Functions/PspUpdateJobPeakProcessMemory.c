// PspUpdateJobPeakProcessMemory 
 
int __fastcall PspUpdateJobPeakProcessMemory(int result, unsigned int a2)
{
  if ( a2 > *(_DWORD *)(result + 340) )
    result = sub_7C22D0();
  return result;
}
