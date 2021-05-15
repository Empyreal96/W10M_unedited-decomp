// PspCreateUserContext 
 
int __fastcall PspCreateUserContext(int result, int a2, __int64 a3)
{
  int v3; // r5

  v3 = *(_DWORD *)(result + 68);
  *(_DWORD *)result = 2097159;
  *(_DWORD *)(result + 64) = a2;
  *(_DWORD *)(result + 68) = v3 & 0xF9FF03F0 | 0x10;
  if ( (a2 & 1) != 0 )
    *(_DWORD *)(result + 68) = v3 & 0xF9FF03F0 | 0x30;
  *(_QWORD *)(result + 4) = a3;
  *(_DWORD *)(result + 72) = 0;
  return result;
}
