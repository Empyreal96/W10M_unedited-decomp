// PnprRecopyAddress 
 
int __fastcall PnprRecopyAddress(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  unsigned int v5; // r6
  int result; // r0
  _DWORD v7[6]; // [sp+8h] [bp-18h] BYREF

  v4 = a1 & 0xFFFFF000;
  v5 = a1 + a2;
  if ( (a1 & 0xFFFFF000) >= a1 + a2 )
    return 0;
  while ( 1 )
  {
    MmGetPhysicalAddress((int)v7, v4, a3, a4);
    result = PnprMarkOrMirrorPages(v7[0], v7[1], 4096, 0);
    if ( result < 0 )
      break;
    v4 += 4096;
    if ( v4 >= v5 )
      return 0;
  }
  return result;
}
