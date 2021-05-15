// SmStoreCompressionStop 
 
int SmStoreCompressionStop()
{
  int result; // r0
  int v1; // r4
  int v2[14]; // [sp+8h] [bp-38h] BYREF

  v2[0] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  result = SmpKeyedStoreEntryGet((int)&byte_636CC4, (int)v2, 0, 0);
  if ( result )
  {
    v1 = *(unsigned __int16 *)(result + 8);
  }
  else
  {
    v1 = dword_636CDC;
    __dmb(0xBu);
  }
  if ( v1 != -1 )
    result = sub_7E9AFC();
  return result;
}
