// KiIntSteerInitPrcb 
 
int __fastcall KiIntSteerInitPrcb(int a1)
{
  *(_DWORD *)(a1 + 3272) = 0;
  *(_DWORD *)(a1 + 3276) = 1;
  return 0;
}
