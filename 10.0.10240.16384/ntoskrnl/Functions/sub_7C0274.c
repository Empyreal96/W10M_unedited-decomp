// sub_7C0274 
 
void sub_7C0274()
{
  unsigned __int16 v0; // r5
  _DWORD *v1; // r6
  int v2; // r9

  if ( v0 >= 0xC000u )
    RtlpAtomMapAtomToHandleEntry(v2, v0 & 0x3FFF);
  if ( v1 )
    *v1 = 0;
  JUMPOUT(0x6A6474);
}
