// TraceLoggingProviderEnabled 
 
BOOL __fastcall TraceLoggingProviderEnabled(_DWORD *a1)
{
  return *a1 && TlgKeywordOn();
}
