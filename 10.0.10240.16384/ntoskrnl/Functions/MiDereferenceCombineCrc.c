// MiDereferenceCombineCrc 
 
int __fastcall MiDereferenceCombineCrc(int a1)
{
  unsigned int v1; // r1

  v1 = *(_DWORD *)(a1 + 16);
  if ( v1 < 0x100 || !*(_QWORD *)(v1 + 16) )
    return 0;
  MiDecrementCombinedPte(v1 + 32);
  return 1;
}
