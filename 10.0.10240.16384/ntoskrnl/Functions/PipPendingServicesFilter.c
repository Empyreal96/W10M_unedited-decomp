// PipPendingServicesFilter 
 
int __fastcall PipPendingServicesFilter(int a1, int a2, int a3, _BYTE *a4)
{
  *a4 = 0;
  if ( !wcsicmp(a1, L"EventLog") )
    *a4 = 1;
  return 0;
}
