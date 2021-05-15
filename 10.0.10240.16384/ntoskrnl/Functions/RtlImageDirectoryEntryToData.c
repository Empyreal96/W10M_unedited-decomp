// RtlImageDirectoryEntryToData 
 
int __fastcall RtlImageDirectoryEntryToData(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( RtlpImageDirectoryEntryToDataEx() < 0 )
    result = 0;
  else
    result = a4;
  return result;
}
