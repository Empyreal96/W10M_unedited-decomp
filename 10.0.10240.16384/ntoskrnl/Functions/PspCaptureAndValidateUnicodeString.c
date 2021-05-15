// PspCaptureAndValidateUnicodeString 
 
int __fastcall PspCaptureAndValidateUnicodeString(_DWORD *a1, unsigned __int16 *a2)
{
  unsigned int v2; // r2
  unsigned int v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r2

  *(_DWORD *)a2 = *a1;
  *((_DWORD *)a2 + 1) = a1[1];
  v2 = *a2;
  if ( (v2 & 1) != 0 )
    return -1073741811;
  v4 = *((_DWORD *)a2 + 1);
  if ( !v4 )
  {
    if ( !*a2 )
    {
      a2[1] = 0;
      goto LABEL_7;
    }
    return -1073741811;
  }
  v5 = (unsigned __int16)(v2 + 2);
  a2[1] = v5;
  if ( v5 < v2 )
    return -1073741811;
LABEL_7:
  if ( v2 )
  {
    v6 = v2 + v4;
    if ( v6 > MmUserProbeAddress || v6 < v4 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  return 0;
}
