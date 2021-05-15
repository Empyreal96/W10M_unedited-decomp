// PiSwInterfaceCreate 
 
int __fastcall PiSwInterfaceCreate(unsigned __int16 *a1, int a2, unsigned int a3, int *a4)
{
  _BYTE *v8; // r0
  int result; // r0

  v8 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 1466986064);
  *a4 = (int)v8;
  if ( !v8 )
    return sub_817580();
  memset(v8, 0, 24);
  if ( PnpAllocatePWSTR(a1, 0x7FFFFFFFu, 1466986064, (int *)(*a4 + 8)) < 0
    || (result = PnpCopyDevPropertyArray(a3, a2, *a4, (_DWORD *)(*a4 + 16), (_DWORD *)(*a4 + 12)), result < 0) )
  {
    JUMPOUT(0x817582);
  }
  return result;
}
