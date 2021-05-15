// _PnpSetGenericStoreProperty 
 
int __fastcall PnpSetGenericStoreProperty(int *a1, int a2, char *a3, int a4, int a5, int a6, unsigned int a7)
{
  int result; // r0

  if ( a5 )
    result = PnpSetPropertyWorker(a1, a2, a3, a4, a5, a6, a7);
  else
    result = PnpDeletePropertyWorker(a1, a2, a3, a4, 0);
  return result;
}
