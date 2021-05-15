// SdbpGetIndex 
 
int __fastcall SdbpGetIndex(int a1, int a2, unsigned int *a3)
{
  if ( SdbGetTagFromTagID() != 38913 )
    return sub_7CCA10();
  *a3 = SdbGetTagDataSize(a1, a2) / 0xCu;
  return SdbpGetMappedTagData(a1, a2);
}
