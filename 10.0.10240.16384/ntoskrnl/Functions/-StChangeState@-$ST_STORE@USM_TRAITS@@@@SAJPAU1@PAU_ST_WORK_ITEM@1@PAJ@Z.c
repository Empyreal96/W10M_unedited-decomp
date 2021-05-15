// -StChangeState@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@1@PAJ@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StChangeState(int a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // r3
  int result; // r0

  v4 = a2[1] & 7;
  if ( v4 )
  {
    if ( v4 == 4 || v4 == 5 )
    {
      result = ST_STORE<SM_TRAITS>::StAddRemoveRegions(a1, a2, (int)a3, v4);
      *a3 = 0;
    }
    else
    {
      result = -1073741811;
    }
  }
  else
  {
    ST_STORE<SM_TRAITS>::StEmptyStore(a1, 0);
    result = 0;
  }
  return result;
}
