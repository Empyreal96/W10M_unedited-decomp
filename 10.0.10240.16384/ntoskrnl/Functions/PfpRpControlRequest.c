// PfpRpControlRequest 
 
int __fastcall PfpRpControlRequest(int a1, char a2)
{
  int v2; // r2
  int v3; // r4
  unsigned int v4; // r1
  char *v5; // r5
  char *v7; // [sp+8h] [bp-38h] BYREF
  char v8[48]; // [sp+10h] [bp-30h] BYREF

  v7 = 0;
  v2 = a2;
  if ( (dword_637340 & 1) == 0 )
    return -1073741696;
  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 < 0x14 )
    return -1073741306;
  v3 = PfpRpControlRequestCopy(*(_DWORD *)(a1 + 12), v4, &v7, v8, v2);
  v5 = v7;
  if ( v3 >= 0 )
  {
    if ( PfpRpControlRequestVerify(v7) )
      v3 = -1073741701;
    else
      v3 = PfpRpControlRequestPerform(&unk_6372E0, v5);
  }
  if ( v5 && v5 != v8 )
    ExFreePoolWithTag((unsigned int)v5);
  return v3;
}
