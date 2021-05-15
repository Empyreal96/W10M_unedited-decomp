// HvResetLogFileStatusAll 
 
int __fastcall HvResetLogFileStatusAll(int result)
{
  int v1; // r2
  char v2; // r1

  if ( *(_DWORD *)(result + 96) == 1 )
  {
    *(_BYTE *)(result + 120) = 0;
  }
  else
  {
    *(_BYTE *)(result + 120) = 0;
    result = HvpLogTypeToLogArrayIndex(5);
    *(_BYTE *)(result + v1 + 120) = v2;
  }
  return result;
}
