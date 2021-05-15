// KiVerifyPdata 
 
int __fastcall KiVerifyPdata(unsigned int a1)
{
  int v2[8]; // [sp+10h] [bp-20h] BYREF

  if ( a1 < dword_616494 )
  {
    RtlpxLookupFunctionTable(a1, v2);
    JUMPOUT(0x96D5D2);
  }
  return sub_96D5BC();
}
