// SmStoreCompressionStart 
 
int __fastcall SmStoreCompressionStart(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r3
  int v6[6]; // [sp+0h] [bp-18h] BYREF

  v6[0] = a2;
  v6[1] = a3;
  v6[2] = a4;
  v6[0] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  result = SmpKeyedStoreEntryGet((int)&unk_636CC4, (int)v6, 0, 0);
  if ( result || (v5 = dword_636CDC, __dmb(0xBu), v5 != -1) )
    result = sub_7E9B5C();
  return result;
}
