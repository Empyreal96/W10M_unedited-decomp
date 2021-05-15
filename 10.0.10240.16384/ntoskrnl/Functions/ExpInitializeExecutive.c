// ExpInitializeExecutive 
 
int __fastcall ExpInitializeExecutive(int a1, int a2)
{
  int result; // r0

  if ( !a1 )
    return InitBootProcessor(a2);
  result = HalInitSystem(1, 0);
  if ( !result )
    sub_694454();
  return result;
}
