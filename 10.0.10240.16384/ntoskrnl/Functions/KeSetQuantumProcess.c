// KeSetQuantumProcess 
 
int __fastcall KeSetQuantumProcess(int result, char a2)
{
  if ( *(char *)(result + 105) != a2 )
    result = sub_524580();
  return result;
}
