// MmVirtualAccessFault 
 
int __fastcall MmVirtualAccessFault(int a1, char a2, _DWORD *a3)
{
  int v3; // r4
  unsigned int v6; // r6
  int v7; // r2
  unsigned int v8; // r2
  int result; // r0
  char v10; // [sp+0h] [bp-50h]
  char v11; // [sp+8h] [bp-48h] BYREF
  _BYTE v12[3]; // [sp+9h] [bp-47h] BYREF
  int v13; // [sp+1Ch] [bp-34h]
  unsigned int v14; // [sp+20h] [bp-30h]

  v3 = 0;
  if ( (a2 & 2) != 0 )
    v3 = 1;
  if ( (a2 & 4) != 0 )
    v3 |= 8u;
  v6 = a1 & 0xFFFFF000;
  v10 = 0;
  while ( 1 )
  {
    MiInitializeFaultVaListCore((int)&v11, 0x500000001i64, v10);
    v13 = -1;
    v8 = (v14 & 0xFFFFFFFE | ((v3 & v7) != 0)) ^ ((v14 & 0xFFFFFFFE | ((v3 & v7) != 0)) ^ (2 * ((v3 & 8) != 0))) & 2;
    v14 = ((unsigned __int8)v8 ^ (unsigned __int8)(4 * ((a2 & 8) != 0))) & 4 ^ v8;
    result = MmAccessFault(v3, v6, 1, (int)v12);
    if ( result < 0 )
      break;
    if ( v13 != -1 )
    {
      *a3 = v13;
      return 0;
    }
  }
  return result;
}
