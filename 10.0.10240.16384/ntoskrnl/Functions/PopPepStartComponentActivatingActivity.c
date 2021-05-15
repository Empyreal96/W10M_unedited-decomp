// PopPepStartComponentActivatingActivity 
 
int __fastcall PopPepStartComponentActivatingActivity(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  result = 0;
  if ( a2 )
  {
    *a3 = 0;
    result = 1;
    a3[1] = *(_DWORD *)(a1 + 24);
    a3[2] = *(_DWORD *)(a2 + 8);
  }
  return result;
}
