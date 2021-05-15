// ExpWnfReleaseCapturedScopeInstanceId 
 
int __fastcall ExpWnfReleaseCapturedScopeInstanceId(int result, int *a2, char a3)
{
  switch ( result )
  {
    case 1:
      result = *a2;
      if ( *a2 )
        result = ObfDereferenceObject(result);
      break;
    case 2:
      result = *a2;
      if ( *a2 )
        result = SeReleaseSid(result, a3, 0);
      break;
    case 3:
      result = *a2;
      if ( *a2 )
        result = sub_7C48F8();
      break;
  }
  return result;
}
