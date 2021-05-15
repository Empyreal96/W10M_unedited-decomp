// sub_808008 
 
void __fastcall sub_808008(int a1, unsigned int a2)
{
  int v2; // r5

  if ( !memcmp((unsigned int)SystemTraceControlGuid, a2, 16) )
  {
    if ( v2 == 1 || v2 == 2 )
      EtwpCheckGuidAccessAndDoRundown();
    JUMPOUT(0x75A144);
  }
  JUMPOUT(0x75A13E);
}
