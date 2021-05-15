// RtlGUIDFromString 
 
int __fastcall RtlGUIDFromString(unsigned __int16 *a1, _BYTE *a2)
{
  char v3; // r2
  char v4; // r1
  char v5; // r3
  char v6; // r2
  char v7; // r3
  char v8; // r2
  char v9; // r1
  __int16 v11; // [sp+28h] [bp-18h] BYREF
  int v12; // [sp+2Ah] [bp-16h] BYREF
  int v13; // [sp+2Eh] [bp-12h] BYREF
  int v14; // [sp+32h] [bp-Eh] BYREF
  __int16 v15[5]; // [sp+36h] [bp-Ah] BYREF

  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15[0] = 0;
  if ( sub_6C9A60(
         *((_DWORD *)a1 + 1),
         *a1 >> 1,
         L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
         a2,
         a2 + 4,
         a2 + 6,
         &v11,
         &v12,
         (char *)&v12 + 2,
         &v13,
         (char *)&v13 + 2,
         &v14,
         (char *)&v14 + 2,
         v15) == -1 )
    return -1073741811;
  v3 = v12;
  v4 = BYTE2(v12);
  a2[8] = v11;
  v5 = v13;
  a2[9] = v3;
  v6 = BYTE2(v13);
  a2[11] = v5;
  v7 = BYTE2(v14);
  a2[12] = v6;
  v8 = v15[0];
  a2[10] = v4;
  v9 = v14;
  a2[14] = v7;
  a2[15] = v8;
  a2[13] = v9;
  return 0;
}
