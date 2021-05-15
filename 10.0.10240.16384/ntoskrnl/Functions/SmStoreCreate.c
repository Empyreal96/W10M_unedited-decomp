// SmStoreCreate 
 
int __fastcall SmStoreCreate(int a1, int a2, int *a3)
{
  int result; // r0
  int v7; // r3
  int v8[6]; // [sp+8h] [bp-60h] BYREF
  int v9[18]; // [sp+20h] [bp-48h] BYREF

  v8[2] = 1;
  v8[3] = 3;
  v8[4] = (int)v9;
  v8[5] = 56;
  memset(v9, 0, 56);
  v9[0] = v9[0] & 0xFFFFFF00 | 6;
  memmove((int)&v9[1], a2, 0x30u);
  if ( a1 )
  {
    if ( a1 != 1 )
      return -1073741811;
    result = ZwSetSystemInformation();
    v7 = v9[13];
  }
  else
  {
    result = SmStorePhysicalRequestIssue(dword_636C98, 2261400, v9, 56, 0, v8);
    v7 = v8[0];
  }
  if ( result >= 0 )
  {
    *a3 = v7;
    result = 0;
  }
  return result;
}
