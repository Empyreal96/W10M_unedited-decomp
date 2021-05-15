// CmpFindNameInList 
 
BOOL CmpFindNameInList()
{
  int v0; // r0

  v0 = CmpFindNameInListWithStatus();
  return v0 >= 0 || v0 == -1073741772;
}
