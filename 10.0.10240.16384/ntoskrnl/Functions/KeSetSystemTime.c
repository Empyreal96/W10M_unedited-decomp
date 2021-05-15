// KeSetSystemTime 
 
int __fastcall KeSetSystemTime(int a1, int a2, int a3)
{
  char v4[4]; // [sp+0h] [bp-28h] BYREF
  int v5; // [sp+4h] [bp-24h]
  int v6; // [sp+8h] [bp-20h]
  int v7; // [sp+Ch] [bp-1Ch]
  char v8; // [sp+18h] [bp-10h]

  v6 = a1;
  v7 = a2;
  v4[0] = 0;
  v8 = 0;
  v5 = a3;
  return KeGenericCallDpc((int)KiSetSystemTimeDpc, (int)v4);
}
