// _PnpStringFromGuid 
 
int __fastcall PnpStringFromGuid(int a1, int a2)
{
  return RtlStringCchPrintfExW(a2, 39, 0, 0, 2048, L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}");
}
