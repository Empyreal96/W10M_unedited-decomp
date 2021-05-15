// PiResetProblemDevicesWorker 
 
int __fastcall PiResetProblemDevicesWorker(int a1, _DWORD *a2)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 268) & 0x2000) != 0 && *(_DWORD *)(a1 + 276) == *a2 )
    result = sub_7E08CC();
  else
    result = 0;
  return result;
}
