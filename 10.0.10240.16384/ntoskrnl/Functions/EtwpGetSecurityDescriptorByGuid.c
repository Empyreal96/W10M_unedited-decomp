// EtwpGetSecurityDescriptorByGuid 
 
int __fastcall EtwpGetSecurityDescriptorByGuid(int *a1, _DWORD *a2)
{
  int result; // r0
  char v4[8]; // [sp+28h] [bp-60h] BYREF
  unsigned __int16 v5[44]; // [sp+30h] [bp-58h] BYREF

  RtlStringCbPrintfW(v5, 0x4Cu, (int)L"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x", *a1);
  RtlInitUnicodeString((unsigned int)v4, v5);
  EtwpGetGuidSecurityDescriptor(v4, a2);
  if ( *a2 )
    return 1;
  result = 0;
  *a2 = EtwpDefaultTraceSecurityDescriptor;
  return result;
}
