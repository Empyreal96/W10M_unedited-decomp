// ExpFreeLowLevelTable 
 
int __fastcall ExpFreeLowLevelTable(int a1, _DWORD *a2)
{
  int result; // r0

  if ( *a2 )
    result = sub_7E9604();
  else
    result = ExpFreeTablePagedPool(a1, a2, 4096);
  return result;
}
