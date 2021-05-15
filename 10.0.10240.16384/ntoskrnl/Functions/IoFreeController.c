// IoFreeController 
 
int __fastcall IoFreeController(int a1)
{
  int result; // r0

  do
  {
    result = KeRemoveDeviceQueue(a1 + 8);
    if ( !result )
      break;
    result = (*(int (__fastcall **)(int, _DWORD, _DWORD, _DWORD))(result + 16))(
               result - 52,
               *(_DWORD *)(result - 32),
               0,
               *(_DWORD *)(result + 20));
  }
  while ( result == 2 );
  return result;
}
