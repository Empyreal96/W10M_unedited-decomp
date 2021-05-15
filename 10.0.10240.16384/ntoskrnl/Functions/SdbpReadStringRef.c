// SdbpReadStringRef 
 
int __fastcall SdbpReadStringRef(int a1, int a2, int a3, int a4)
{
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[1] = a4;
  v7[0] = 0;
  if ( (SdbGetTagFromTagID(a1, a2, a3, 0) & 0xF000) != 24576 )
    return sub_817AC0(a1, a2);
  if ( !SdbpReadTagData(a1, a2, (int)v7, 4u) )
    JUMPOUT(0x817AD8);
  return v7[0];
}
