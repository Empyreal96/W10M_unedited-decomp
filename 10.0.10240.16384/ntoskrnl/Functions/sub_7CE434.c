// sub_7CE434 
 
void __fastcall sub_7CE434(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v14; // r5
  int v15; // r6
  _DWORD *v16; // r8
  int i; // r0
  int v18; // r7
  int j; // r0
  int v20; // r7

  if ( !SdbTagRefToTagID(v15, a1, &a9, &a10) )
    JUMPOUT(0x787A40);
  for ( i = SdbFindFirstTag(a9, a10, 28691); ; i = SdbFindNextTag(a9, a10, v18) )
  {
    v18 = i;
    if ( !i )
      break;
    if ( KsepDbReadKFlag(a9, i, &a11) < 0 || KsepCacheDeviceInsertData(v14, a11, a14, a12) < 0 )
      goto LABEL_14;
  }
  for ( j = SdbFindFirstTag(a9, a10, 28712); ; j = SdbFindNextTag(a9, a10, v20) )
  {
    v20 = j;
    if ( !j )
      break;
    if ( KsepDbReadKData(a9, j, &a11) < 0 || KsepCacheDeviceInsertData(v14, a11, a14, a12) < 0 )
      goto LABEL_14;
  }
  *v16 = v14;
LABEL_14:
  JUMPOUT(0x787A42);
}
