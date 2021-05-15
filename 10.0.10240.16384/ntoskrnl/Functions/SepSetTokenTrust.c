// SepSetTokenTrust 
 
int __fastcall SepSetTokenTrust(int a1, int a2)
{
  int v2; // r6
  int v3; // r4
  unsigned int v5; // r0
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v2 = 0;
  v3 = 0;
  v7[0] = 0;
  if ( a2 )
  {
    v3 = SepDuplicateSid(a2, v7);
    if ( v3 < 0 )
      return v3;
    v2 = v7[0];
  }
  v5 = *(_DWORD *)(a1 + 640);
  if ( v5 )
  {
    ExFreePoolWithTag(v5);
    *(_DWORD *)(a1 + 640) = 0;
  }
  *(_DWORD *)(a1 + 640) = v2;
  return v3;
}
