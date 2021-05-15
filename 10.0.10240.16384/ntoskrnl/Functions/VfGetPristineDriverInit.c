// VfGetPristineDriverInit 
 
int __fastcall VfGetPristineDriverInit(int a1)
{
  int *v2; // r3
  int result; // r0

  if ( !MmIsDriverVerifying(a1) || (v2 = *(int **)(*(_DWORD *)(a1 + 24) + 32)) == 0 || (result = *v2) == 0 )
    result = *(_DWORD *)(a1 + 44);
  return result;
}
