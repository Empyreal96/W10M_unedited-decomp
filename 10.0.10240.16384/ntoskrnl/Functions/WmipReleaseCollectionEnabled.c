// WmipReleaseCollectionEnabled 
 
int __fastcall WmipReleaseCollectionEnabled(int result)
{
  if ( (*(_DWORD *)(result + 8) & 8) != 0 )
    result = sub_815AA8();
  return result;
}
