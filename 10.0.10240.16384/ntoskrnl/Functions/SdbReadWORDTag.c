// SdbReadWORDTag 
 
int __fastcall SdbReadWORDTag(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned __int16 v8[8]; // [sp+8h] [bp-10h] BYREF

  v8[1] = HIWORD(a4);
  v4 = a3;
  v8[0] = a3;
  if ( (SdbGetTagFromTagID(a1, a2) & 0xF000) != 12288 )
    return sub_7CCB5C(a1, a2);
  if ( SdbpReadTagData(a1, a2, v8, 2) )
    v4 = v8[0];
  return v4;
}
