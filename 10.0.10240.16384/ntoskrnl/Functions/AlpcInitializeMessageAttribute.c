// AlpcInitializeMessageAttribute 
 
int __fastcall AlpcInitializeMessageAttribute(int a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v8; // r0

  v8 = AlpcGetHeaderSize(a1);
  *a4 = v8;
  if ( v8 > a3 )
    return -1073741789;
  if ( a2 )
  {
    *a2 = a1;
    a2[1] = 0;
  }
  return 0;
}
