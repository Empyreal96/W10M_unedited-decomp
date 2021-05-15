// DbgkpOpenHandles 
 
_DWORD *__fastcall DbgkpOpenHandles(_DWORD *result, int a2, int a3)
{
  _DWORD *v3; // r4
  int v4; // r3
  int v6; // r6
  int v7; // r2
  int v8; // r2

  v3 = result;
  v4 = *result;
  if ( *result == 2 )
  {
    result = (_DWORD *)ObOpenObjectByPointer(a3, 0, 0, 1179771, PsThreadType, 0, result + 3);
    if ( (int)result < 0 )
      v3[3] = 0;
  }
  else if ( v4 == 3 )
  {
    if ( ObOpenObjectByPointer(a3, 0, 0, 1179771, PsThreadType, 0, result + 4) < 0 )
      v3[4] = 0;
    result = (_DWORD *)ObOpenObjectByPointer(a2, 0, 0, 1181307, PsProcessType, 0, v3 + 3);
    if ( (int)result < 0 )
      v3[3] = 0;
    v6 = v3[6];
    if ( v6 )
    {
      v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( ObDuplicateObject(v8, v6, v8, v3 + 6, 0, 0, 2, 0) < 0 )
        v3[6] = 0;
      return (_DWORD *)ObCloseHandle(v6);
    }
  }
  else if ( v4 == 9 )
  {
    v6 = result[3];
    if ( v6 )
    {
      v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      if ( ObDuplicateObject(v7, v6, v7, result + 3, 0, 0, 2, 0) < 0 )
        v3[3] = 0;
      return (_DWORD *)ObCloseHandle(v6);
    }
  }
  return result;
}
