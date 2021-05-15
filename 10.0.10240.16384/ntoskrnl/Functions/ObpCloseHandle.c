// ObpCloseHandle 
 
int __fastcall ObpCloseHandle(int a1, char a2, int a3, int a4)
{
  int v4; // r8
  unsigned int v6; // r5
  _DWORD *v7; // r7
  int result; // r0
  int v9; // r6
  int v10; // r0
  __int16 v11; // r3
  int v12; // r1
  _DWORD v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = a2;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_DWORD **)(v6 + 0x74);
  if ( !a2 )
    return sub_7F7704();
  v9 = v7[84];
  if ( v9 == ObpKernelHandleTable )
    return -1073741816;
  --*(_WORD *)(v6 + 308);
  v10 = ExMapHandleToPointer(v9, a1);
  if ( v10 )
    return ObCloseHandleTableEntry(v9, v10, v7, a1);
  v11 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(0);
  if ( a1 > 0 || a1 < -6 )
  {
    ExQueryHandleExceptionsPermanency(v9, (_BYTE *)v13 + 1, v13);
    if ( ExQueryRaiseUMExceptionOnInvalidHandleClose(v9) && LOBYTE(v13[0]) )
      ExHandleLogBadReference(v9, a1, v4);
    if ( v4 )
    {
      if ( (NtGlobalFlag & 0x400000) != 0 || v7[85] || *(_DWORD *)(v9 + 60) )
      {
        result = -1073741816;
        if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1 )
          result = KeRaiseUserException(-1073741816, v12);
        return result;
      }
    }
    else if ( (*(_DWORD *)(v6 + 960) & 1) == 0 && v7[80] && KdDebuggerEnabled )
    {
      KeBugCheckEx(147, a1, 1, 0, 0);
    }
  }
  result = -1073741816;
  if ( (unsigned int)(a1 + 6) <= 5 )
    result = 0;
  return result;
}
