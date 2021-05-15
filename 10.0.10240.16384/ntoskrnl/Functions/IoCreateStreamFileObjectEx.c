// IoCreateStreamFileObjectEx 
 
int __fastcall IoCreateStreamFileObjectEx(int a1, _DWORD *a2, _DWORD *a3)
{
  int v4; // [sp+8h] [bp-18h] BYREF
  __int16 v5; // [sp+10h] [bp-10h] BYREF
  int v6; // [sp+12h] [bp-Eh]
  __int16 v7; // [sp+16h] [bp-Ah]

  v7 = 0;
  v6 = 1;
  v5 = 8;
  IoCreateStreamFileObjectEx2((int)&v5, a1, a2, &v4, a3);
  return v4;
}
