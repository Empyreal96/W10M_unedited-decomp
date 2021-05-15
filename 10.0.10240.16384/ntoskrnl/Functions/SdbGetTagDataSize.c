// SdbGetTagDataSize 
 
unsigned int __fastcall SdbGetTagDataSize(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  unsigned int result; // r0
  unsigned int v8; // r4
  int v9; // [sp+0h] [bp-10h] BYREF
  int v10; // [sp+4h] [bp-Ch]

  v9 = a3;
  v10 = a4;
  v6 = SdbGetTagFromTagID(a1, a2) & 0xF000;
  switch ( v6 )
  {
    case 12288:
      result = 2;
      break;
    case 16384:
    case 24576:
      result = 4;
      break;
    case 20480:
      result = 8;
      break;
    case 4096:
      result = 0;
      break;
    case 8192:
      result = 1;
      break;
    default:
      v9 = 0;
      if ( !SdbpReadMappedData(a1, a2 + 2, &v9, 4) )
        return sub_7CCC74();
      result = v9;
      break;
  }
  v8 = a2 + result;
  if ( v8 < result || v8 > *(_DWORD *)(a1 + 12) )
  {
    AslLogCallPrintf(1, "SdbGetTagDataSize", 268, "Error reading size data", v9, v10);
    result = -1;
  }
  return result;
}
