// IoCreateDisk 
 
int __fastcall IoCreateDisk(int a1, int *a2, int a3, int a4)
{
  if ( a2 )
  {
    a4 = *a2;
    if ( !*a2 )
      return FstubCreateDiskMBR(a1, a2 + 1);
    if ( a4 == 1 )
      return FstubCreateDiskEFI(a1, a2 + 1);
    if ( a4 != 2 )
      return -1073741637;
  }
  return FstubCreateDiskRaw(a1, (int)a2, a3, a4);
}
