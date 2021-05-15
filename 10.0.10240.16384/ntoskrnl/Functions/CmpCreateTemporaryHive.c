// CmpCreateTemporaryHive 
 
int __fastcall CmpCreateTemporaryHive(int a1, int a2, int a3)
{
  int result; // r0
  int v6; // [sp+20h] [bp-138h] BYREF
  int v7; // [sp+28h] [bp-130h] BYREF
  char v8[284]; // [sp+2Ch] [bp-12Ch] BYREF

  v7 = 0;
  memset(v8, 0, sizeof(v8));
  if ( CmpInitializeHive((int)&v6, 0, 1, 0, 0, 0, 0, 0x1000000, a2, a3, 0, &v7) < 0 )
    result = 0;
  else
    result = v6;
  return result;
}
