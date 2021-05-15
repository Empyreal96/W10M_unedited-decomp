// SepGetSidManagementActionName 
 
__int16 *__fastcall SepGetSidManagementActionName(int a1, int *a2)
{
  __int16 *result; // r0
  int v3; // r3

  *a2 = 0;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        result = aAssignedNewOwn;
        v3 = 34;
        break;
      case 2:
        result = aAssignedExisti;
        v3 = 50;
        break;
      case 3:
        result = aUnassignedFrom_0;
        v3 = 44;
        break;
      case 4:
        result = aUnassignedFrom;
        v3 = 60;
        break;
      default:
        result = aDeallocated;
        v3 = 24;
        break;
    }
  }
  else
  {
    result = aAssignedNewSha;
    v3 = 40;
  }
  *a2 = v3;
  return result;
}
