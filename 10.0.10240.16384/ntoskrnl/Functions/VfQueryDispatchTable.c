// VfQueryDispatchTable 
 
int __fastcall VfQueryDispatchTable(int a1, unsigned int a2)
{
  int result; // r0
  _DWORD *v4; // r2

  result = 0;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( !a1 )
    {
      v4 = &VfWdmDispatchTable;
LABEL_9:
      if ( a2 <= v4[1] )
        result = (int)v4;
      return result;
    }
    if ( a1 != 2 )
    {
      if ( a1 != 3 )
        return result;
      v4 = &VfXdvDispatchTable;
      goto LABEL_9;
    }
    if ( ViFnXdvQueryDispatchTable )
      result = ViFnXdvQueryDispatchTable(2);
  }
  return result;
}
