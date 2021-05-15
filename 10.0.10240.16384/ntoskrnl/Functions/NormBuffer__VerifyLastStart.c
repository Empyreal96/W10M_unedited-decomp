// NormBuffer__VerifyLastStart 
 
int __fastcall NormBuffer__VerifyLastStart(int result)
{
  int v1; // r2
  int v2; // r3

  v1 = *(unsigned __int8 *)(result + 40);
  if ( !*(_BYTE *)(result + 40) || v1 == 63 || !*(_BYTE *)(result + 41) || *(_BYTE *)(result + 41) == 64 )
  {
    v2 = *(_DWORD *)(result + 36);
    *(_BYTE *)(result + 52) = v1;
    *(_DWORD *)(result + 44) = v2 + 2;
    *(_DWORD *)(result + 48) = *(_DWORD *)(result + 32);
    *(_BYTE *)(result + 53) = *(_BYTE *)(result + 41);
    *(_DWORD *)(result + 56) = 0;
    *(_DWORD *)(result + 60) = 0;
  }
  return result;
}
