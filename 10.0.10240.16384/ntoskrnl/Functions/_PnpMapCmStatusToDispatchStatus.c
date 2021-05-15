// _PnpMapCmStatusToDispatchStatus 
 
int __fastcall PnpMapCmStatusToDispatchStatus(int result)
{
  switch ( result )
  {
    case -1073741810:
      return -1073741772;
    case -1073741767:
      return -1073741773;
    case -1073741766:
      return -1073741772;
    case -1073741637:
      return -1073741275;
    case -1073741632:
      return -1073741772;
  }
  return result;
}
