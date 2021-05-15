// IoGetDumpStack 
 
int __fastcall IoGetDumpStack(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = IopLoadCrashdumpDriver();
  if ( result >= 0 )
    result = dword_637650(L"hiber_", a2, 2, a4);
  return result;
}
