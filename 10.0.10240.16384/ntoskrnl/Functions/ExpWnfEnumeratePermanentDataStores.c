// ExpWnfEnumeratePermanentDataStores 
 
int __fastcall ExpWnfEnumeratePermanentDataStores(int a1, int a2, int a3)
{
  int v4; // r3

  if ( a1 || a3 )
    return -1073741772;
  v4 = a2 == 3 || a2 == 2;
  return ExpWnfGetPermanentDataStoreHandleByScopeId(0, a2, 0, v4);
}
