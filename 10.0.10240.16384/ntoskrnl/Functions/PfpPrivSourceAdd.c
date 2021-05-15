// PfpPrivSourceAdd 
 
int __fastcall PfpPrivSourceAdd(_DWORD *a1, int a2)
{
  _DWORD *v2; // r4
  unsigned int v3; // r2

  v2 = a1;
  v3 = a1[2];
  if ( v3 >= a1[3] )
    return -1073741789;
  memmove(*a1 + (v3 << 6) + 12, a2, 0x40u);
  ++*(_DWORD *)(*v2 + 8);
  ++v2[2];
  return 0;
}
