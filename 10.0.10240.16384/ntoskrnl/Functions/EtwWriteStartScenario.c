// EtwWriteStartScenario 
 
int __fastcall EtwWriteStartScenario(int a1, int a2, int a3, int a4)
{
  if ( !a3 || !a4 )
    return -1073741811;
  if ( EtwEventEnabled(a1, a2, a3) )
    return sub_7BDB18();
  return -1073741816;
}
