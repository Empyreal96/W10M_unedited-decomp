// FsRtlChangeBackingFileObject 
 
int __fastcall FsRtlChangeBackingFileObject(unsigned int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a4 )
    return -1073741582;
  switch ( a3 )
  {
    case 0:
      v5 = 1;
      return MmChangeSectionBackingFile(a1, a2, v5);
    case 1:
      v5 = 2;
      return MmChangeSectionBackingFile(a1, a2, v5);
    case 2:
      result = CcChangeBackingFileObject(a1, a2);
      break;
    default:
      result = -1073741583;
      break;
  }
  return result;
}
