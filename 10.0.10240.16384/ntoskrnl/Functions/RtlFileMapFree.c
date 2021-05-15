// RtlFileMapFree 
 
_BYTE *__fastcall RtlFileMapFree(_BYTE *result)
{
  _BYTE *v1; // r4

  v1 = result;
  if ( result )
  {
    if ( *((_DWORD *)result + 6) )
      MmUnsecureVirtualMemory();
    if ( v1[28] && *(_DWORD *)v1 )
      ZwClose();
    if ( v1[29] )
    {
      result = (_BYTE *)sub_518AB4();
    }
    else
    {
      if ( v1[30] )
      {
        if ( *((_DWORD *)v1 + 4) )
          ZwUnmapViewOfSection();
      }
      result = memset(v1, 0, 32);
    }
  }
  return result;
}
