// PspReadIFEONodeOptions 
 
int __fastcall PspReadIFEONodeOptions(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[4]; // [sp+8h] [bp-10h] BYREF

  v5[0] = a4;
  result = RtlQueryImageFileKeyOption(a2, L"NodeOptions", 4, v5, 4, 0);
  if ( result >= 0 )
    result = sub_7EAAE8();
  return result;
}
