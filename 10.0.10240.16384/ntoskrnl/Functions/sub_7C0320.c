// sub_7C0320 
 
void __fastcall sub_7C0320(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r5
  int v8; // r6

  if ( (*(_DWORD *)(v7 + 136) & 0x80000) != 0 )
    EtwTraceJob(a7, v8);
  JUMPOUT(0x6A655A);
}
