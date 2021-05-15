// MmInitSystemDll 
 
_DWORD *MmInitSystemDll()
{
  _DWORD *result; // r0
  _DWORD *v1; // r4
  int v2; // r0

  result = (_DWORD *)PsQuerySystemDllInfo(0);
  v1 = result;
  if ( result )
  {
    v2 = ObFastReferenceObject(result - 2);
    if ( v2 )
    {
      dword_6337C0 = v1[3];
      result = ObFastDereferenceObject(v1 - 2, v2);
    }
    else
    {
      result = (_DWORD *)sub_9709CC();
    }
  }
  return result;
}
