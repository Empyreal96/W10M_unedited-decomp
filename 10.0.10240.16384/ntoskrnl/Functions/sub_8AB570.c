// sub_8AB570 
 
int __fastcall sub_8AB570(_DWORD *a1, unsigned __int16 *a2, int a3, int a4)
{
  unsigned int v4; // r3
  int v6; // r4
  unsigned __int16 *v7; // r5
  unsigned int v8; // r2
  unsigned __int16 *v9; // r2
  int v10; // r6
  unsigned int v12[2]; // [sp+0h] [bp-20h] BYREF
  _DWORD v13[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = (unsigned int)a1;
  v12[1] = (unsigned int)a2;
  v13[0] = a3;
  v13[1] = a4;
  v4 = *a2;
  if ( !*a2 )
    return 0;
  v7 = (unsigned __int16 *)*((_DWORD *)a2 + 2);
  v8 = v4 >> 1;
  if ( (v4 & 1) != 0 )
    return -1073741762;
  if ( v8 < 2 )
    return -1073741762;
  v9 = &v7[v8];
  if ( *(v9 - 2) || *(v9 - 1) )
    return -1073741762;
  v10 = 0;
  while ( 1 )
  {
    RtlInitUnicodeString((unsigned int)v13, v7);
    v6 = RtlHashUnicodeString((unsigned __int16 *)v13, 1, 0, v12);
    if ( v6 < 0 )
      break;
    v10 += v12[0];
    v7 += wcslen(v7) + 1;
    if ( !*v7 )
    {
      *a1 += v10;
      return v6;
    }
  }
  return v6;
}
