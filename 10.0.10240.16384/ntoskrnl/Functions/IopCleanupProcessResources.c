// IopCleanupProcessResources 
 
int __fastcall IopCleanupProcessResources(int a1, int a2, int a3)
{
  int result; // r0

  result = IopCancelIrpsInFileObjectList(a1, a2, 0, 0, 1, 1);
  if ( a3 )
    result = sub_7F36B4(result);
  return result;
}
