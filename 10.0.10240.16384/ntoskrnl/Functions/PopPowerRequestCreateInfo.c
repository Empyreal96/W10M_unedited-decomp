// PopPowerRequestCreateInfo 
 
int __fastcall PopPowerRequestCreateInfo(unsigned int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r5
  int v8; // [sp+8h] [bp-20h] BYREF
  int v9[7]; // [sp+Ch] [bp-1Ch] BYREF

  v8 = 0;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return -1073741637;
  v5 = PoCaptureReasonContext(a1, 1, 0, 1, 0, &v8);
  if ( v5 >= 0 )
  {
    v6 = v8;
    v5 = PopCreateUserPowerRequest(v9, a2, v8);
    if ( v5 >= 0 )
    {
      v6 = 0;
      v5 = ObInsertObject(v9[0], 0, 0, 0, 0, a3);
    }
    if ( v6 )
      return sub_7F2CB8();
  }
  return v5;
}
