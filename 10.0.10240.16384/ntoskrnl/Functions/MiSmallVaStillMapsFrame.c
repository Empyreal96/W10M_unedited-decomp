// MiSmallVaStillMapsFrame 
 
BOOL __fastcall MiSmallVaStillMapsFrame(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r3
  int *v6; // r2
  int v7; // r1
  int v8; // r0
  int *v9; // r2
  int *v10; // t1
  int v11; // r3
  int v13[2]; // [sp+0h] [bp-18h] BYREF
  int v14; // [sp+8h] [bp-10h] BYREF

  v13[0] = a2;
  v13[1] = a3;
  v14 = a4;
  v5 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v6 = v13;
  v7 = 2;
  v8 = 2;
  do
  {
    *v6++ = v5;
    v5 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
    --v7;
  }
  while ( v7 );
  v9 = &v14;
  while ( 1 )
  {
    v10 = (int *)*--v9;
    --v8;
    v11 = *v10;
    if ( (*v10 & 2) == 0 )
      break;
    if ( v8 == 1 )
      return (v11 & 0x400) == 0 && (a2 == -1 || (*(_DWORD *)v13[0] & 2) != 0 && *(_DWORD *)v13[0] >> 12 == a2);
  }
  return 0;
}
