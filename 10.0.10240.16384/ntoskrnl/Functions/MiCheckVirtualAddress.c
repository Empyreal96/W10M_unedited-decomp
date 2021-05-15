// MiCheckVirtualAddress 
 
int __fastcall MiCheckVirtualAddress(unsigned int a1, _DWORD *a2, int *a3)
{
  int result; // r0
  int v7; // r0

  *a3 = 0;
  if ( a1 > MmHighestUserAddress )
    return sub_538038();
  if ( (a1 & 0xFFFFF000) != 2147352576
    || (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 736) & 1) != 0 )
  {
    v7 = MiLocateAddress(a1);
    *a3 = v7;
    if ( v7 )
    {
      result = MiCheckUserVirtualAddress(a1, a2, v7, 0);
    }
    else
    {
      *a2 = 24;
      result = 0;
    }
  }
  else
  {
    *a2 = 1;
    result = dword_6337D8;
  }
  return result;
}
