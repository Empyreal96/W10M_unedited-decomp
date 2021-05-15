// PfSnCleanupPrefetchSectionInfo 
 
_BYTE *__fastcall PfSnCleanupPrefetchSectionInfo(_BYTE *result, int a2, int a3)
{
  _BYTE *v4; // r4
  int v5; // r3
  int v6; // r0
  int v7; // r3

  v4 = result;
  if ( a3 )
  {
    if ( (*((_DWORD *)result + 7) & 1) != 0 )
    {
      result = (_BYTE *)ObfDereferenceObject(*((_DWORD *)result + 5));
      v7 = *((_DWORD *)v4 + 7);
      *((_DWORD *)v4 + 5) = 0;
      *((_DWORD *)v4 + 7) = v7 & 0xFFFFFFFE;
    }
    if ( (*((_DWORD *)v4 + 7) & 2) != 0 )
    {
      result = (_BYTE *)ObfDereferenceObject(*((_DWORD *)v4 + 6));
      v5 = *((_DWORD *)v4 + 7);
      *((_DWORD *)v4 + 6) = 0;
      *((_DWORD *)v4 + 7) = v5 & 0xFFFFFFFD;
    }
    if ( (*((_DWORD *)v4 + 7) & 4) != 0 )
    {
      PfpOpenHandleClose(v4, a2 + 4);
      result = memset(v4, 0, 20);
      *((_DWORD *)v4 + 4) |= 2u;
      *((_DWORD *)v4 + 7) &= 0xFFFFFFFB;
    }
  }
  else
  {
    v6 = *((_DWORD *)result + 5);
    if ( v6 )
      ObfDereferenceObject(v6);
    result = (_BYTE *)*((_DWORD *)v4 + 6);
    if ( result )
      result = (_BYTE *)ObfDereferenceObject((int)result);
    if ( (*((_DWORD *)v4 + 4) & 4) != 0 )
      result = (_BYTE *)sub_8069A4();
  }
  return result;
}
