// SepAssemblePrivileges 
 
_DWORD *__fastcall SepAssemblePrivileges(_DWORD *result, int a2, int a3, int a4, _DWORD *a5)
{
  if ( a5 )
  {
    if ( result )
    {
      result = (_DWORD *)ExAllocatePoolWithTag(1, 12 * ((_DWORD)result - 1) + 20, 1917871443);
      if ( result )
      {
        *result = 0;
        result[1] = 0;
        if ( a2 )
        {
          result = (_DWORD *)sub_819984();
        }
        else
        {
          if ( a3 )
          {
            *(_QWORD *)&result[3 * *result + 2] = SeTakeOwnershipPrivilege;
            result[3 * (*result)++ + 4] = 0x80000000;
          }
          if ( a4 )
          {
            *(_QWORD *)&result[3 * *result + 2] = SeRelabelPrivilege;
            result[3 * (*result)++ + 4] = 0x80000000;
          }
          *a5 = result;
        }
      }
    }
  }
  return result;
}
