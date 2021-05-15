// ViCommonBufferCalculatePadding 
 
int __fastcall ViCommonBufferCalculatePadding(int result, _DWORD *a2, _DWORD *a3)
{
  int v3; // r3

  *a2 = 4096;
  if ( (unsigned int)(result + 8) <= 0x1000 )
  {
    v3 = 4096 - result;
LABEL_5:
    *a3 = v3;
    return result;
  }
  if ( (result & 0xFFF) != 0 )
  {
    v3 = ((result + 8) & 0xFFFFF000) + (((((_WORD)result + 8) & 0xFFF) != 0) << 12) - result;
    goto LABEL_5;
  }
  *a3 = 4096;
  return result;
}
