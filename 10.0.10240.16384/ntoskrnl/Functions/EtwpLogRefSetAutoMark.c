// EtwpLogRefSetAutoMark 
 
int __fastcall EtwpLogRefSetAutoMark(int a1, int a2)
{
  unsigned int v3; // r4
  int v4; // r3
  int v6; // [sp+8h] [bp-28h] BYREF
  char v7[36]; // [sp+Ch] [bp-24h] BYREF

  if ( a1 )
  {
    v3 = 26;
    v4 = 1;
  }
  else
  {
    v3 = 25;
    v4 = 0;
  }
  v6 = v4;
  RtlStringCbCopyA((int)v7);
  return EtwpSetMark(a2, (char *)&v6, v3, 1, 0);
}
