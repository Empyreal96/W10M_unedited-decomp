// IoFindDeviceThatFailedIrp 
 
int __fastcall IoFindDeviceThatFailedIrp(int a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r1
  int v3; // r2

  v1 = *(char *)(a1 + 34);
  if ( *(int *)(a1 + 24) >= 0 )
    return 0;
  v2 = 0;
  v3 = a1 + 40 * v1 + 72;
  if ( !*(_BYTE *)(a1 + 34) )
    return 0;
  while ( (*(_BYTE *)(v3 + 3) & 2) == 0 )
  {
    ++v2;
    v3 -= 40;
    if ( v2 >= v1 )
      return 0;
  }
  return *(_DWORD *)(v3 + 24);
}
