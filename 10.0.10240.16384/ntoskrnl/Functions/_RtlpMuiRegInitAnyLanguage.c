// _RtlpMuiRegInitAnyLanguage 
 
int __fastcall RtlpMuiRegInitAnyLanguage(int a1, _WORD *a2, unsigned __int16 *a3, int a4)
{
  __int16 v4; // r5
  int v8; // r2
  __int16 v9; // r3
  __int16 v10; // r3
  _WORD *v11; // r3
  _WORD *v12; // r3
  __int16 v14[2]; // [sp+0h] [bp-20h] BYREF
  _WORD *v15; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v16[6]; // [sp+8h] [bp-18h] BYREF

  v14[1] = HIWORD(a1);
  v15 = a2;
  v16[0] = a3;
  v16[1] = a4;
  v4 = a4;
  v14[0] = -1;
  RtlInitUnicodeString((unsigned int)v16, a3);
  if ( !RtlCultureNameToLCID((unsigned __int16 *)v16, (int *)&v15) )
    return -1073020924;
  v8 = RtlpMuiRegGetOrAddString(a1, a3, 1, v14);
  if ( v8 >= 0 )
  {
    v9 = (__int16)v15;
    a2[1] = 0;
    a2[2] = v9;
    v10 = v14[0];
    a2[5] = 0;
    a2[4] = 0;
    a2[3] = v10;
    v11 = a2 + 6;
    *a2 = v4;
    do
      *v11++ = 0;
    while ( v11 != a2 + 10 );
    v12 = a2 + 10;
    do
      *v12++ = 0;
    while ( v12 != a2 + 14 );
    if ( (v4 & 0x2000) == 0 )
      RtlpMuiRegAddNeutralLanguage(a1, a2);
  }
  return v8;
}
