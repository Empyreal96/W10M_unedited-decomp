// CpGetByte 
 
int __fastcall CpGetByte(int a1, _BYTE *a2, int a3, int a4)
{
  int v7; // r4
  char v8; // r0

  if ( !*(_DWORD *)a1 )
    return 1;
  if ( a3 )
    v7 = 204800;
  else
    v7 = 1;
  while ( 1 )
  {
    --v7;
    v8 = CpReadLsr(a1, 1);
    if ( (v8 & 1) == 0 )
      goto LABEL_10;
    if ( (v8 & 0xC) != 0 )
      break;
    if ( a4 )
      return 0;
    *a2 = READ_UCHAR(*(_DWORD *)a1);
    if ( (*(_WORD *)(a1 + 8) & 2) == 0 || (READ_UCHAR(*(_DWORD *)a1 + 6 * CpRegisterWidth) & 0x80) != 0 )
      return 0;
LABEL_10:
    if ( !v7 )
    {
      CpReadLsr(a1, 0);
      return 1;
    }
  }
  *a2 = 0;
  return 2;
}
