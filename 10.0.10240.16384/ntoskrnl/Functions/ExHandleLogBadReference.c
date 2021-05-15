// ExHandleLogBadReference 
 
int __fastcall ExHandleLogBadReference(int result, int a2, char a3)
{
  int v3; // r4
  int v4; // r5

  v3 = result;
  v4 = a3;
  if ( (*(_BYTE *)(result + 28) & 2) != 0 )
  {
    if ( *(_DWORD *)(result + 60) )
    {
      __mrc(15, 0, 13, 0, 3);
      result = ExpUpdateDebugInfo();
    }
    if ( v4 == 1 )
    {
      if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1
        && v3 == *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 336) )
      {
        if ( (NtGlobalFlag & 0x100) != 0 )
        {
          __mrc(15, 0, 13, 0, 3);
          DbgPrintEx(93, 0, (int)"AVRF: Invalid handle %p in process %p \n", a2);
        }
        result = KeRaiseUserException(-1073741816, a2);
      }
    }
    else if ( (NtGlobalFlag & 0x40000000) != 0 )
    {
      KeBugCheckEx(147, a2, v3, 0, 1);
    }
  }
  return result;
}
