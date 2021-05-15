// SdbReadBinaryTag 
 
int __fastcall SdbReadBinaryTag(int a1, int a2, int a3, unsigned int a4)
{
  if ( (SdbGetTagFromTagID(a1, a2, a3, a4) & 0xF000) != 36864 )
    return sub_7CE0E4(a1, a2);
  if ( !SdbpReadTagData(a1, a2, a3, a4) )
    JUMPOUT(0x7CE0FC);
  return 1;
}
