// PopFxCompleteDevicePowerRequired 
 
int __fastcall PopFxCompleteDevicePowerRequired(int a1, int a2)
{
  int result; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r5
  signed int v7; // r5

  result = 0;
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 20);
  do
  {
    v6 = __ldrex(v5);
    v7 = v6 - 1;
  }
  while ( __strex(v7, v5) );
  __dmb(0xBu);
  if ( v7 < 0 )
    sub_53F014(0);
  if ( !v7 )
  {
    PopDiagTraceFxDevicePowered(*(_DWORD *)(a1 + 28), a2);
    result = PopPluginDevicePower(a1, 1, a2);
  }
  return result;
}
