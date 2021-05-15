// SmKmStoreHelperCheckWaitCommand 
 
int __fastcall SmKmStoreHelperCheckWaitCommand(int a1)
{
  int v1; // r3
  int result; // r0

  v1 = *(_DWORD *)(a1 + 36);
  result = 0;
  if ( v1 )
    result = sub_511290(0);
  return result;
}
