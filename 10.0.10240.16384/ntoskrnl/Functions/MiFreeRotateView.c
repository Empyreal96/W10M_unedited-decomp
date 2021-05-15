// MiFreeRotateView 
 
unsigned int __fastcall MiFreeRotateView(int a1)
{
  unsigned int result; // r0
  unsigned int v2; // r4
  unsigned int v3; // r0

  result = MiGetVadWakeList(a1, 8);
  v2 = result;
  if ( result )
  {
    v3 = *(_DWORD *)(result + 8);
    if ( v3 )
      ExFreePoolWithTag(v3);
    result = ExFreePoolWithTag(v2);
  }
  return result;
}
