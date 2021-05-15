// MiGetInPageSupportBlock 
 
int __fastcall MiGetInPageSupportBlock(int a1)
{
  int v2; // r6
  BOOL v3; // r1
  int v4; // r4
  int v6; // r1

  v2 = a1 & 1;
  v3 = v2 == 0;
  if ( LOWORD(MiState[2 * v3 + 1939]) )
  {
    v4 = RtlpInterlockedPopEntrySList((unsigned __int64 *)&unk_6348C8 + v3);
    if ( v4 )
      goto LABEL_3;
  }
  if ( (a1 & 4) != 0 )
    return 0;
  v6 = 248;
  if ( v2 )
    v6 = 1208;
  v4 = ExAllocatePoolWithTag(512, v6, 1850305869);
  if ( v4 )
LABEL_3:
    MiInitializeInPageSupport(v4, a1);
  return v4;
}
