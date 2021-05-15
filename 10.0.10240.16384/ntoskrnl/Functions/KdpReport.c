// KdpReport 
 
int __fastcall KdpReport(int a1, int a2, int *a3, int a4, int a5, char a6)
{
  int v6; // r5

  v6 = *a3;
  if ( *a3 == -2147483645 || v6 == -2147483644 || v6 == -1073740768 || (NtGlobalFlag & 1) != 0 )
    return sub_51BBEC();
  if ( a6 )
    JUMPOUT(0x51BC00);
  return 0;
}
