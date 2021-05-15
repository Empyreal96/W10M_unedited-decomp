// AlpcpCompleteDeferSignalRequest 
 
int __fastcall AlpcpCompleteDeferSignalRequest(int result)
{
  int v1; // r4
  char v2; // r2

  v1 = result;
  v2 = *(_BYTE *)(result + 24);
  *(_BYTE *)(result + 24) = v2 & 0xFB;
  if ( (unsigned __int8)(v2 & 4) >> 2 )
  {
    AlpcpSignal(result, 0);
    result = *(_DWORD *)(v1 + 16);
    if ( result )
      result = ObfDereferenceObject(result);
  }
  return result;
}
