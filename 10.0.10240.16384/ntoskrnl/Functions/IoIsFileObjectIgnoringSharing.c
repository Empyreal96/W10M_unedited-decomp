// IoIsFileObjectIgnoringSharing 
 
BOOL __fastcall IoIsFileObjectIgnoringSharing(int a1)
{
  _DWORD *v1; // r3

  v1 = *(_DWORD **)(a1 + 124);
  return v1 && (*v1 & 1) != 0;
}
