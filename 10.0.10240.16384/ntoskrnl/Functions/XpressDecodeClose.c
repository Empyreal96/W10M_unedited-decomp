// XpressDecodeClose 
 
int __fastcall XpressDecodeClose(int result)
{
  if ( CMFFreeFn && result && *(_DWORD *)(result + 56) == 903790814 )
  {
    *(_DWORD *)(result + 56) = 0;
    result = CMFFreeFn(0, result);
  }
  return result;
}
