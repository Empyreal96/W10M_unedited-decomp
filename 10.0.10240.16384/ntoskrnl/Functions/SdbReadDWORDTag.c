// SdbReadDWORDTag 
 
int __fastcall SdbReadDWORDTag(int a1, int a2, int a3)
{
  int v3; // r4
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v3 = a3;
  v7[0] = a3;
  if ( (SdbGetTagFromTagID() & 0xF000) != 0x4000 )
    return sub_7CCAE8(a1, a2);
  if ( SdbpReadTagData(a1, a2, v7, 4) )
    v3 = v7[0];
  return v3;
}
