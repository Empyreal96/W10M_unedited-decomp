// _RegRtlOpenPredefinedKey 
 
int __fastcall RegRtlOpenPredefinedKey(int a1, int a2)
{
  int *v2; // r3
  int v3; // r4
  __int16 v5; // [sp+8h] [bp-10h] BYREF
  int v6; // [sp+Ah] [bp-Eh]
  __int16 v7; // [sp+Eh] [bp-Ah]

  v5 = 0;
  v6 = 0;
  v7 = 0;
  switch ( a1 )
  {
    case -2147483646:
      v2 = &dword_405FC8;
LABEL_3:
      v3 = RegRtlOpenKeyTransacted(0, (unsigned __int16 *)v2[1], 0, 0x2000000, a2, 0);
      RtlFreeAnsiString(&v5);
      return v3;
    case -2147483648:
      v2 = &dword_41E1F8;
      goto LABEL_3;
    case -2147483645:
      v2 = &dword_405FD0;
      goto LABEL_3;
  }
  return sub_81AFC4();
}
