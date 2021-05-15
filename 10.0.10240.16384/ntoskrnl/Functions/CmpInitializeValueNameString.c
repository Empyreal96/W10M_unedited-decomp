// CmpInitializeValueNameString 
 
_WORD *__fastcall CmpInitializeValueNameString(_WORD *result, int a2, _WORD *a3)
{
  if ( (result[8] & 1) != 0 )
  {
    *(_WORD *)a2 = 2 * result[1];
    result = CmpCopyCompressedName(a3, 0x7FFFu, (int)(result + 10), (unsigned __int16)result[1]);
    *(_DWORD *)(a2 + 4) = a3;
    *(_WORD *)(a2 + 2) = 0x7FFF;
  }
  else
  {
    *(_WORD *)a2 = result[1];
    *(_DWORD *)(a2 + 4) = result + 10;
    *(_WORD *)(a2 + 2) = *(_WORD *)a2;
  }
  return result;
}
