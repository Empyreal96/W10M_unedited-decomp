// RtlInitializeUnicodePrefix 
 
int __fastcall RtlInitializeUnicodePrefix(int result)
{
  *(_WORD *)result = 2048;
  *(_WORD *)(result + 2) = 0;
  *(_DWORD *)(result + 4) = result;
  *(_DWORD *)(result + 8) = 0;
  return result;
}
