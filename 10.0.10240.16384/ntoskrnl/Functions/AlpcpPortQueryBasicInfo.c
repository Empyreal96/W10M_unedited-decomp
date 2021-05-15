// AlpcpPortQueryBasicInfo 
 
int __fastcall AlpcpPortQueryBasicInfo(_DWORD *a1, int *a2, unsigned int a3, _DWORD *a4)
{
  int result; // r0

  if ( !a1 )
    return -1073741811;
  if ( a3 >= 0xC )
  {
    *a2 = a1[38] & 0x1FF0000;
    a2[1] = a1[58];
    a2[2] = a1[7];
    result = 0;
  }
  else
  {
    result = -1073741820;
  }
  if ( a4 )
    *a4 = 12;
  return result;
}
