// CmpInitializeKeyNameString 
 
_WORD *__fastcall CmpInitializeKeyNameString(_WORD *result, int a2, _WORD *a3)
{
  if ( (result[1] & 0x20) != 0 )
  {
    *(_WORD *)a2 = 2 * result[36];
    result = CmpCopyCompressedName(a3, 0x200u, (int)(result + 38), (unsigned __int16)result[36]);
    *(_DWORD *)(a2 + 4) = a3;
    *(_WORD *)(a2 + 2) = 512;
  }
  else
  {
    *(_WORD *)a2 = result[36];
    *(_DWORD *)(a2 + 4) = result + 38;
    *(_WORD *)(a2 + 2) = *((_DWORD *)result + 13);
  }
  return result;
}
