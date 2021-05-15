// CcAllocateInitializeMbcb 
 
_BYTE *CcAllocateInitializeMbcb()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4
  _BYTE *v2; // r1

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 136, 1649238851);
  v1 = v0;
  if ( !v0 )
    return 0;
  memset(v0, 0, 136);
  *(_WORD *)v1 = 763;
  v2 = v1 + 40;
  *((_DWORD *)v1 + 4) = v1 + 16;
  *((_DWORD *)v1 + 5) = v1 + 16;
  *((_DWORD *)v1 + 10) = v1 + 16;
  *((_DWORD *)v1 + 11) = v1 + 16;
  if ( *((_BYTE **)v1 + 4) != v1 + 16 )
    sub_523F6C();
  *((_DWORD *)v1 + 4) = v2;
  *((_DWORD *)v1 + 5) = v2;
  *((_DWORD *)v1 + 14) = -1;
  *((_DWORD *)v1 + 8) = -1;
  *((_DWORD *)v1 + 9) = -1;
  *((_DWORD *)v1 + 17) = v1 + 72;
  return v1;
}
