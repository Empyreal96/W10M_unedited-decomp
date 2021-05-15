// MxDescriptorSort 
 
int __fastcall MxDescriptorSort(_DWORD **a1, _DWORD **a2)
{
  _DWORD *v2; // r3
  int result; // r0

  v2 = *a1;
  result = -1;
  if ( *v2 >= **a2 )
    result = 1;
  return result;
}
