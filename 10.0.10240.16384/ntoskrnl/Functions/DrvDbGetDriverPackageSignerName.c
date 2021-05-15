// DrvDbGetDriverPackageSignerName 
 
int __fastcall DrvDbGetDriverPackageSignerName(int a1, int a2, int a3, int *a4, int a5, unsigned int *a6)
{
  int (**v7)[4]; // r5
  int v9; // r4
  unsigned int v10; // r0
  int (*v11)[4]; // t1
  int result; // r0
  unsigned int v13; // [sp+10h] [bp-20h] BYREF
  int v14[7]; // [sp+14h] [bp-1Ch] BYREF

  *a6 = 0;
  v7 = &off_402398;
  v9 = 0;
  while ( 1 )
  {
    v11 = *v7;
    v7 += 6;
    v10 = (unsigned int)v11;
    if ( (*v11)[4] == 7 && !memcmp(v10, (unsigned int)DEVPKEY_DriverPackage_SignerName, 16) )
      break;
    if ( (unsigned int)++v9 >= 0x1A )
      return -1073741595;
  }
  if ( !(&off_402398 + 6 * v9) )
    return -1073741595;
  result = DrvDbGetRegValueMappedProperty(0, a3, (int)(&off_402398 + 6 * v9), v14, a4, 2 * a5, &v13);
  if ( result >= 0 || result == -1073741789 )
    *a6 = v13 >> 1;
  return result;
}
