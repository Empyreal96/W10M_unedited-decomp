// SdbGetTagFromTagID 
 
int __fastcall SdbGetTagFromTagID(int a1, int a2, int a3, int a4)
{
  int result; // r0
  __int16 v5[2]; // [sp+0h] [bp-8h] BYREF
  int v6; // [sp+4h] [bp-4h]

  v5[1] = HIWORD(a3);
  v6 = a4;
  v5[0] = 0;
  if ( SdbpReadMappedData(a1, a2, v5, 2) )
    result = (unsigned __int16)v5[0];
  else
    result = sub_7CCCA4();
  return result;
}
