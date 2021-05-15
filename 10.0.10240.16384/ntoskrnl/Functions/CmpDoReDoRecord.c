// CmpDoReDoRecord 
 
int __fastcall CmpDoReDoRecord(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v5; // r3

  v2 = *(_DWORD *)(a2 + 8);
  result = 0;
  if ( (v2 & 4) != 0 || (v2 & 8) != 0 || (v2 & 0x10) != 0 )
    return 0;
  v5 = *(_DWORD *)(a2 + 12);
  switch ( v5 )
  {
    case 1:
      result = CmpDoReDoCreateKey(a1, a2);
      break;
    case 2:
      result = CmpDoReDoDeleteKey(a1, a2, a1, v5);
      break;
    case 3:
    case 4:
      result = CmpDoReDoSetValueExisting(a1);
      break;
    case 5:
      result = CmpDoReDoDeleteValue(a1, a2, a1, v5);
      break;
    case 6:
      result = CmpDoReDoSetKeyUserFlags(a1);
      break;
    case 7:
      result = CmpDoReDoSetLastWriteTime(a1);
      break;
    case 8:
      result = CmpDoReDoSetSecurityDescriptor(a1);
      break;
    case 9:
      result = CmpDoReDoRenameKey(a1);
      break;
    default:
      return result;
  }
  return result;
}
