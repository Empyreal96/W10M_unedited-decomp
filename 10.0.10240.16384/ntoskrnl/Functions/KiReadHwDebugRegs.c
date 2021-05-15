// KiReadHwDebugRegs 
 
_DWORD *__fastcall KiReadHwDebugRegs(_DWORD *result, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v4; // r5

  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( *(_DWORD *)(v4 + 2704) != 6 )
    return (_DWORD *)sub_51B580();
  result[5] = __mrc(14, 0, 0, 5, 4);
  a2[5] = __mrc(14, 0, 0, 5, 5);
  result[4] = __mrc(14, 0, 0, 4, 4);
  a2[4] = __mrc(14, 0, 0, 4, 5);
  result[3] = __mrc(14, 0, 0, 3, 4);
  a2[3] = __mrc(14, 0, 0, 3, 5);
  result[2] = __mrc(14, 0, 0, 2, 4);
  a2[2] = __mrc(14, 0, 0, 2, 5);
  result[1] = __mrc(14, 0, 0, 1, 4);
  a2[1] = __mrc(14, 0, 0, 1, 5);
  *result = __mrc(14, 0, 0, 0, 4);
  *a2 = __mrc(14, 0, 0, 0, 5);
  if ( *(_DWORD *)(v4 + 2708) )
  {
    *a3 = __mrc(14, 0, 0, 0, 6);
    *a4 = __mrc(14, 0, 0, 0, 7);
  }
  return result;
}
