// CmpUpdateReorganizeRegistryValues 
 
int __fastcall CmpUpdateReorganizeRegistryValues(int result, int a2)
{
  if ( CmpReorganizeTotalBytesSaved )
    result = sub_80FF44(
               result,
               a2,
               CmpReorganizeTotalBytesSaved,
               HIDWORD(CmpReorganizeTotalBytesSaved) | CmpReorganizeTotalBytesSaved);
  return result;
}
