// PoGetFrequencyBucket 
 
unsigned int __fastcall PoGetFrequencyBucket(int a1)
{
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r1
  unsigned int result; // r0

  v1 = *(_DWORD *)(a1 + 3200);
  v2 = *(_DWORD *)(a1 + 3204);
  if ( v1 && v2 )
  {
    v3 = *(_DWORD *)(v2 + 44);
    if ( v3 >= *(_DWORD *)(v1 + 148) )
      v3 = *(_DWORD *)(v1 + 148);
  }
  else
  {
    v3 = 100;
  }
  result = v3 / 0x19;
  if ( v3 / 0x19 >= 3 )
    result = 3;
  return result;
}
