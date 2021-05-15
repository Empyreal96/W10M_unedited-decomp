// MiCaptureWriteWatchDirtyBit 
 
_DWORD *__fastcall MiCaptureWriteWatchDirtyBit(_DWORD *result, unsigned int a2, int a3)
{
  int v4; // r2

  if ( (result[48] & 0x20) == 0 )
  {
    if ( a3 || (result = MiLocateAddress(a2), (a3 = (int)result) != 0) )
    {
      if ( *(int *)(a3 + 28) >= 0 && (*(_DWORD *)(a3 + 28) & 7) == 4 )
      {
        result = MiLocateVadEvent(a3, 4);
        *(_DWORD *)(result[3] + 4 * (((a2 >> 12) - *(_DWORD *)(v4 + 12)) >> 5)) |= 1 << (((a2 >> 12)
                                                                                        - *(_BYTE *)(v4 + 12)) & 0x1F);
      }
    }
  }
  return result;
}
