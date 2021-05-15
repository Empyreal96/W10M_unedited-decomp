// PiSwMakePdoInactive 
 
int __fastcall PiSwMakePdoInactive(int result)
{
  _DWORD *v1; // r2

  v1 = *(_DWORD **)(result + 40);
  if ( result == *(_DWORD *)(*v1 + 64) )
    *(_DWORD *)(*v1 + 64) = 0;
  v1[1] |= 0x20u;
  return result;
}
