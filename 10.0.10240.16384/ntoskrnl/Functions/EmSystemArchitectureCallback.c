// EmSystemArchitectureCallback 
 
int __fastcall EmSystemArchitectureCallback(int a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  if ( a6 != 1 && !a5 )
    return 1;
  if ( *a5 == (unsigned __int16)KeProcessorArchitecture )
    return 2;
  return 0;
}
