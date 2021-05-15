// PnpFindBestConfiguration 
 
int __fastcall PnpFindBestConfiguration(int a1, int a2, int a3)
{
  int result; // r0

  result = PnpFindBestConfigurationWorker(a1, a2, a3, 0);
  if ( result < 0 )
    result = sub_80DB70();
  return result;
}
