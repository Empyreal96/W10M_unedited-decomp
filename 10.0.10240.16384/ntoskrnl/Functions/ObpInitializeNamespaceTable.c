// ObpInitializeNamespaceTable 
 
void ObpInitializeNamespaceTable()
{
  _DWORD *v0; // r3
  int v1; // r2

  v0 = &ObpPrivateNamespaceLookupTable;
  dword_620C08 = 0;
  v1 = 37;
  do
  {
    *v0 = v0;
    v0[1] = v0;
    v0 += 2;
    --v1;
  }
  while ( v1 );
}
