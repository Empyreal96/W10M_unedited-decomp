// sub_4FEB60 
 
int __fastcall sub_4FEB60(_DWORD *a1)
{
  int v1; // r3
  int v2; // r2

  v1 = a1[1] - 1;
  a1[1] = v1;
  if ( v1 < 0 )
    v2 = HvlGetLpIndexFromApicId();
  else
    v2 = *(unsigned __int8 *)(*a1)++;
  return v2;
}
