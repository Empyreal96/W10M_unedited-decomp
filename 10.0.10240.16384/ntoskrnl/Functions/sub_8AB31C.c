// sub_8AB31C 
 
int __fastcall sub_8AB31C(int a1)
{
  unsigned __int64 v3; // [sp+0h] [bp-40h] BYREF
  _DWORD v4[14]; // [sp+8h] [bp-38h] BYREF

  v3 = (unsigned __int64)(unsigned int)MmGetNumberOfPhysicalPages(0) << 12;
  if ( !*(_BYTE *)(a1 + 12) )
  {
    memset(v4, 0, 32);
    LOBYTE(v4[1]) = 2;
    v4[3] = 1720761527;
    v4[4] = 1173005465;
    v4[5] = -143083076;
    v4[6] = -2009365076;
  }
  return sub_8AA490((__int64 *)a1, (int)v4, (int)&v3, 8u);
}
