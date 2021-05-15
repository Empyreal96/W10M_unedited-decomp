// PpInitGetGroupOrderIndex 
 
int __fastcall PpInitGetGroupOrderIndex(int a1, int a2, char *a3, int a4)
{
  unsigned int v4; // r5
  unsigned int v6; // r1
  unsigned int v7; // r4
  unsigned int v8; // r7
  int v9; // r6
  char *v10; // [sp+0h] [bp-18h] BYREF
  int v11; // [sp+4h] [bp-14h]

  v10 = a3;
  v11 = a4;
  if ( !PiInitGroupOrderTable )
    return 0xFFFF;
  if ( !a1 )
    return (unsigned __int16)(PiInitGroupOrderTableCount + 1);
  if ( IopGetRegistryValue(a1, L"Group", 0, (int *)&v10) < 0 )
    return (unsigned __int16)PiInitGroupOrderTableCount;
  v4 = (unsigned int)v10;
  if ( *((_DWORD *)v10 + 1) != 1 )
    return sub_969150();
  v6 = *((_DWORD *)v10 + 3);
  if ( !v6 )
    return sub_969150();
  PnpRegSzToString(&v10[*((_DWORD *)v10 + 2)], v6, &v10);
  v7 = 0;
  HIWORD(v10) = *(_DWORD *)(v4 + 12);
  v11 = *(_DWORD *)(v4 + 8) + v4;
  v8 = (unsigned __int16)PiInitGroupOrderTableCount;
  if ( PiInitGroupOrderTableCount )
  {
    v9 = PiInitGroupOrderTable;
    do
    {
      if ( RtlEqualUnicodeString((unsigned __int16 *)&v10, (unsigned __int16 *)(v9 + 8 * v7), 1) )
        break;
      v7 = (unsigned __int16)(v7 + 1);
    }
    while ( v7 < v8 );
  }
  ExFreePoolWithTag(v4);
  return v7;
}
