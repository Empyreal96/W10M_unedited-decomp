// SdbpReadTagData 
 
int __fastcall SdbpReadTagData(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v8; // r4
  int v10; // r0

  v8 = SdbGetTagDataSize(a1, a2);
  if ( v8 > a4 )
    return sub_7CCB7C();
  v10 = SdbpGetTagHeadSize(a1, a2);
  if ( !SdbpReadMappedData(a1, v10 + a2, a3, v8) )
    JUMPOUT(0x7CCB90);
  return 1;
}
