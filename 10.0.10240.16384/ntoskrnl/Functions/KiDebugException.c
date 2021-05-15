// KiDebugException 
 
int __fastcall KiDebugException(int a1)
{
  unsigned int v1; // r3
  int v2; // r1
  int v3; // r3

  v1 = __mrc(14, 0, 0, 2, 2);
  if ( (v1 & 0x4000) != 0 )
    return 0;
  v3 = (v1 >> 2) & 0xF;
  switch ( v3 )
  {
    case 1:
LABEL_8:
      KiUpdateDbgdscr(0, 1);
      return v2;
    case 2:
      goto LABEL_7;
    case 3:
      *(_DWORD *)(a1 + 128) += 2;
      goto LABEL_8;
    case 10:
LABEL_7:
      *(_DWORD *)(a1 + 8) = __mrc(14, 0, 0, 6, 0) - 4;
      goto LABEL_8;
  }
  return 0;
}
