// PopPepComponentGetResidencyIdleState 
 
int __fastcall PopPepComponentGetResidencyIdleState(int a1, unsigned __int64 a2)
{
  int result; // r0
  int v5; // r4

  result = *(_DWORD *)(a1 + 156) - 1;
  if ( result && !(_BYTE)PopPepLowPowerEpoch )
  {
    v5 = *(_DWORD *)(a1 + 160) + 24 * result;
    do
    {
      if ( *(_QWORD *)(v5 + 8) <= a2 )
        break;
      --result;
      v5 -= 24;
    }
    while ( result );
  }
  return result;
}
