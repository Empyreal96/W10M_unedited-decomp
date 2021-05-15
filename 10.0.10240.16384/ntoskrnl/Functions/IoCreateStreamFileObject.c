// IoCreateStreamFileObject 
 
int __fastcall IoCreateStreamFileObject(int a1, int a2)
{
  int v3; // [sp+8h] [bp-18h] BYREF
  __int16 v4; // [sp+10h] [bp-10h] BYREF
  int v5; // [sp+12h] [bp-Eh]
  __int16 v6; // [sp+16h] [bp-Ah]

  v6 = 0;
  v5 = 1;
  v4 = 8;
  IoCreateStreamFileObjectEx2(&v4, a1, a2, &v3, 0);
  return v3;
}
