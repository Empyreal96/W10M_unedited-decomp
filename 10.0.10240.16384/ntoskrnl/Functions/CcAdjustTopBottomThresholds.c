// CcAdjustTopBottomThresholds 
 
int __fastcall CcAdjustTopBottomThresholds(int result)
{
  int v1; // r6
  unsigned int v2; // r1
  unsigned int v3; // r3

  v1 = (unsigned __int8)dword_681280;
  v2 = (CcAverageDirtyPages + CcAverageAvailablePages) >> 1;
  *(_DWORD *)(result + 4) = v2;
  *(_DWORD *)(result + 8) = v2 >> 2;
  if ( v2 >> 2 < 0x8000 )
    *(_DWORD *)(result + 8) = 0x8000;
  v3 = *(_DWORD *)(result + 8);
  if ( v2 < v3 || !v1 )
    *(_DWORD *)(result + 4) = v3;
  return result;
}
