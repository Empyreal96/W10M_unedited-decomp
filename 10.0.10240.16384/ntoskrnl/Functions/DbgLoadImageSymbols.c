// DbgLoadImageSymbols 
 
int __fastcall DbgLoadImageSymbols(int a1, int a2)
{
  if ( RtlImageNtHeader(a2) )
    DebugService2();
  return sub_50A634();
}
