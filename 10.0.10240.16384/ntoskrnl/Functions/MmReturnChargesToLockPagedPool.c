// MmReturnChargesToLockPagedPool 
 
unsigned int __fastcall MmReturnChargesToLockPagedPool(unsigned int result, int a2)
{
  int v2; // r5
  _DWORD v3[6]; // [sp+8h] [bp-18h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v2 = ((result & 0xFFF) + a2 + 4095) >> 12;
  if ( (dword_681250 & 2) == 0 )
  {
    MiDeleteSystemPagableVm(&dword_634E80, 0, ((result >> 10) & 0x3FFFFC) - 0x40000000, v2, 8, v3);
    MiReturnResidentAvailable(v2);
    do
      result = __ldrex(&dword_634A2C[73]);
    while ( __strex(result + v2, &dword_634A2C[73]) );
  }
  return result;
}
