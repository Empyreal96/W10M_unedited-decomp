// RtlpProcessIFEOKeyFilter 
 
int __fastcall RtlpProcessIFEOKeyFilter(int a1)
{
  int v1; // r4
  int v2; // r0
  char v4[24]; // [sp+10h] [bp-280h] BYREF
  int v5; // [sp+28h] [bp-268h]

  v5 = a1;
  v1 = RtlInitUnicodeStringEx((int)v4, L"UseFilter");
  if ( v1 >= 0 )
  {
    v2 = ZwQueryValueKey();
    if ( v2 >= 0 )
      JUMPOUT(0x7E87E4);
    if ( v2 != -1073741772 )
      return sub_7E87D4();
    v1 = 0;
  }
  return v1;
}
