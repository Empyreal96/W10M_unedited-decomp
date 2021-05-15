// RtlGetControlSecurityDescriptor 
 
int __fastcall RtlGetControlSecurityDescriptor(unsigned __int8 *a1, _WORD *a2, _DWORD *a3)
{
  __int16 v3; // r3
  int result; // r0

  *a3 = *a1;
  if ( *a1 != 1 )
    return -1073741736;
  v3 = *((_WORD *)a1 + 1);
  result = 0;
  *a2 = v3;
  return result;
}
