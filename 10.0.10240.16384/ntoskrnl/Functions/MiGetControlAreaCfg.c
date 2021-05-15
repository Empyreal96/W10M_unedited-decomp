// MiGetControlAreaCfg 
 
int __fastcall MiGetControlAreaCfg(int a1)
{
  int v1; // r3
  int result; // r0

  v1 = **(_DWORD **)(a1 + 56);
  if ( v1 )
    result = *(_DWORD *)(v1 + 36);
  else
    result = 0;
  return result;
}
