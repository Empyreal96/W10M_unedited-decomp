// MiReferenceFileObjectForMap 
 
int __fastcall MiReferenceFileObjectForMap(int a1)
{
  int v1; // r3
  int result; // r0

  v1 = *(_DWORD *)(a1 + 20);
  if ( (v1 & 1) != 0 || (v1 & 2) != 0 )
    result = sub_802020();
  else
    result = 0;
  return result;
}
