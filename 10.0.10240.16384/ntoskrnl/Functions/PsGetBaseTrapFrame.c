// PsGetBaseTrapFrame 
 
int __fastcall PsGetBaseTrapFrame(int a1)
{
  int i; // r2

  for ( i = *(_DWORD *)(a1 + 32); (*(_DWORD *)(i + 4) & 1) != 0; i = *(_DWORD *)(i + 20) )
    ;
  return i - 408;
}
