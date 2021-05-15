// PopSqmFanEnumeration 
 
void PopSqmFanEnumeration()
{
  int v0[10]; // [sp+8h] [bp-28h] BYREF

  if ( (unsigned int)dword_6163C8 > 5 )
  {
    if ( TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64) )
      TlgWrite(&dword_6163C8, (unsigned __int8 *)&byte_41475D[1], 0, 0, 2, v0);
  }
}
