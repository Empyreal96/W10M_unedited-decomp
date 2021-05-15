// _RegRtlCreateKeyTransacted 
 
int __fastcall RegRtlCreateKeyTransacted(int a1, unsigned __int16 *a2, char a3, int a4, int a5, char a6, int a7, int a8, int a9)
{
  int v14; // r5
  int v15; // r2
  char v16[8]; // [sp+18h] [bp-38h] BYREF
  int v17[12]; // [sp+20h] [bp-30h] BYREF

  if ( RegRtlIsPredefinedKey(a1) )
    return sub_7C73A8();
  v14 = RtlInitUnicodeStringEx((int)v16, a2);
  if ( v14 >= 0 )
  {
    v15 = 192;
    if ( (a3 & 8) != 0 )
      v15 = 448;
    if ( a6 )
      v15 |= 2u;
    v17[0] = 24;
    v17[1] = a1;
    v17[3] = v15 | 0x200;
    v17[2] = (int)v16;
    v17[4] = a5;
    v17[5] = 0;
    if ( a9 )
    {
      v14 = NtCreateKeyTransacted_Stub(a7, a4, v17);
      if ( v14 == -1073741702 )
        v14 = -1072103420;
    }
    else
    {
      v14 = ZwCreateKey();
    }
  }
  return v14;
}
